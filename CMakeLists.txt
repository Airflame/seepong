cmake_minimum_required(VERSION 3.20)
project(seepong C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# WIN32 makes this a GUI app (WinMain entry point, no console window)
add_executable(seepong WIN32 src/main.c src/seepong.h
        src/seepong.c)

target_include_directories(seepong PRIVATE include)
target_compile_definitions(seepong PRIVATE UNICODE _UNICODE WIN32_LEAN_AND_MEAN)
target_link_libraries(seepong PRIVATE user32 gdi32)

# MinGW needs -municode to pick up the wWinMain entry point
if(MINGW)
    target_link_options(seepong PRIVATE -municode)
endif()
