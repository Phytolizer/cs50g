# CMakeList.txt : CMake project for cs50g, include source and define project
# specific logic here.
#
cmake_minimum_required(VERSION 3.8)

project(
    "cs50g"
    LANGUAGES "CXX"
    VERSION "0.1.0"
    DESCRIPTION "Harvard's CS50g, in C++"
    HOMEPAGE_URL "https://github.com/Phytolizer/cs50g"
)

find_package(
    "SDL2"
    CONFIG
    REQUIRED
)
find_package(
    "sdl2-image"
    CONFIG
    REQUIRED
)
find_package(
    "sdl2-ttf"
    CONFIG
    REQUIRED
)

# Add source to this project's executable.
add_executable(
    cs50g
    "src/cs50g.cpp"
    "src/GraphicsContext.cpp"
    "src/GraphicsContext.hpp"
    "src/MySDL.cpp"
    "src/MySDL.hpp"
    "src/SmartRenderer.cpp"
    "src/SmartRenderer.hpp"
    "src/SmartSurface.cpp"
    "src/SmartSurface.hpp"
    "src/SmartTexture.cpp"
    "src/SmartTexture.hpp"
    "src/SmartWindow.cpp"
    "src/SmartWindow.hpp"
    "src/Sprite.cpp"
    "src/Sprite.hpp"
)
target_link_libraries(
    cs50g
    PRIVATE "SDL2::SDL2-static"
            "SDL2::SDL2_image"
            "SDL2::SDL2_ttf"
)
if(WIN32)
    target_link_libraries(cs50g PRIVATE "SDL2::SDL2main")
endif()

# TODO: Add tests and install targets if needed.
