file(GLOB_RECURSE CORE_SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

add_library(CORE STATIC ${CORE_SOURCES})

target_link_libraries(CORE PUBLIC SDL3::SDL3)
target_include_directories(CORE PUBLIC ${SDL_SOURCE_DIR}/include)
target_link_libraries(CORE PUBLIC SDL3_image::SDL3_image)
target_include_directories(CORE PUBLIC ${SDL3_image_SOURCE_DIR}/include)
target_include_directories(CORE PUBLIC ${PROJECT_SOURCE_DIR}/deps/Imgui)

target_link_libraries(CORE PUBLIC box2d::box2d)
target_include_directories(CORE PUBLIC ${box2d_SOURCE_DIR}/include)