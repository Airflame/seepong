#include "seepong.h"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

static const wchar_t CLASS_NAME[] = L"SeepongWindowClass";

static PLAYER leftPlayer  = { .x = 100, .y = 150, .width = 20, .height = 100 };
static PLAYER rightPlayer = { .x = 300, .y = 350, .width = 20, .height = 100 };
static double timer = 0;

static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            const RECT left  = getRect(&leftPlayer);
            const RECT right = getRect(&rightPlayer);
            FillRect(hdc, &left,  GetStockObject(BLACK_BRUSH));
            FillRect(hdc, &right, GetStockObject(BLACK_BRUSH));

            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    (void)hPrevInstance;
    (void)pCmdLine;

    WNDCLASSEXW wc = {0};
    wc.cbSize        = sizeof(wc);
    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.hCursor       = LoadCursorW(NULL, IDC_ARROW);
    wc.hIcon         = LoadIconW(NULL, IDI_APPLICATION);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = CLASS_NAME;

    if (!RegisterClassExW(&wc)) {
        MessageBoxW(NULL, L"Failed to register window class.", L"Error", MB_ICONERROR);
        return 1;
    }

    const DWORD style = WS_OVERLAPPEDWINDOW;
    RECT rect = {.left = 0, .top = 0, .right = WINDOW_WIDTH, .bottom = WINDOW_HEIGHT};
    AdjustWindowRect(&rect, style, FALSE);

    HWND hwnd = CreateWindowExW(
        0, CLASS_NAME, L"seepong", style,
        CW_USEDEFAULT, CW_USEDEFAULT,
        rect.right - rect.left, rect.bottom - rect.top,
        NULL, NULL, hInstance, NULL);

    if (!hwnd) {
        MessageBoxW(NULL, L"Failed to create window.", L"Error", MB_ICONERROR);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return (int)msg.wParam;
}
