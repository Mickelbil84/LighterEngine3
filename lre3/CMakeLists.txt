cmake_minimum_required(VERSION 3.11-3.25)

project(lre3)

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(Cereal REQUIRED)
find_package(fmt REQUIRED)
include_directories(
    ${SDL2_INCLUDE_DIRS} 
    ${GLEW_INCLUDE_DIRS} 
    ${GLM_INCLUDE_DIRS} 
    ${PROJECT_SOURCE_DIR}/../thirdparty/include)

add_library(lre3
    src/lre3_application.cpp
    src/lre3_print.cpp

    src/lre3_shader.cpp
    src/lre3_texture.cpp

    src/lre3_object.cpp
    src/lre3_scene_root.cpp
    src/lre3_camera.cpp
    src/lre3_sprite_object.cpp

    src/lre3_sprite_renderer.cpp
    src/lre3_asset_manager.cpp
    src/lre3_scene_manager.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(
    lre3 PRIVATE 
    ${SDL2_LIBRARIES} 
    ${GLEW_LIBRARIES} 
    ${OPENGL_LIBRARIES} 
    GLEW::glew
    fmt::fmt
    PUBLIC
    cereal::cereal)
target_compile_features(lre3 PUBLIC cxx_std_20)