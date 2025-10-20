cmake_minimum_required(VERSION 4.0)
project(SDLTEST)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)


add_executable(SDLTEST
        main.cpp
      )


FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG a8589a84226a6202831a3d49ff4edda4acab9acd
)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(SDL3)

FetchContent_Declare(
        SDL_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG 45a898564b3450c49023c282b5e60ee85598755d
)
FetchContent_MakeAvailable(SDL_image)
FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG 8c661469c9507d3ad6fbd2fea3f1aa71669c2fe3
)
FetchContent_MakeAvailable(box2d)
target_link_libraries(SDLTEST PUBLIC SDL3::SDL3)
target_include_directories(SDLTEST PUBLIC ${SDL_SOURCE_DIR}/include)
target_link_libraries(SDLTEST PUBLIC SDL3_image::SDL3_image)
target_include_directories(SDLTEST PUBLIC ${SDL3_image_SOURCE_DIR}/include)
target_include_directories(SDLTEST PUBLIC ${CMAKE_SOURCE_DIR}/deps/Imgui)

target_link_libraries(SDLTEST PUBLIC box2d::box2d)
target_include_directories(SDLTEST PUBLIC ${box2d_SOURCE_DIR}/include)

add_subdirectory(core)
target_link_libraries(SDLTEST PUBLIC CORE)
target_include_directories(SDLTEST PUBLIC ${PROJECT_SOURCE_DIR}/core)