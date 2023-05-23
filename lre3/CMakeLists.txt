cmake_minimum_required(VERSION 3.11-3.25)

project(lre3)

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(Cereal REQUIRED)
find_package(fmt REQUIRED)
find_package(Lua REQUIRED)
include_directories(
    ${SDL2_INCLUDE_DIRS} 
    ${GLEW_INCLUDE_DIRS} 
    ${GLM_INCLUDE_DIRS}
    ${LUA_INCLUDE_DIR} 
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

    src/lre3_engine_subsystems.cpp
    src/lre3_sprite_renderer.cpp
    src/lre3_script_system.cpp

    src/lre3_asset_manager.cpp
    src/lre3_scene_manager.cpp

    src/lre3_bindings.cpp
    src/bindings/lre3_asset_manager_binding.cpp
    src/bindings/lre3_camera_binding.cpp
    src/bindings/lre3_input_binding.cpp
    src/bindings/lre3_object_binding.cpp
    src/bindings/lre3_scene_manager_binding.cpp
    src/bindings/lre3_scene_root_binding.cpp
    src/bindings/lre3_shader_binding.cpp
    src/bindings/lre3_sprite_object_binding.cpp
    src/bindings/lre3_texture_binding.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(
    lre3 PRIVATE 
    ${SDL2_LIBRARIES} 
    ${GLEW_LIBRARIES} 
    ${OPENGL_LIBRARIES} 
    ${LUA_LIBRARIES} 
    GLEW::glew
    fmt::fmt
    PUBLIC
    cereal::cereal)
target_compile_features(lre3 PUBLIC cxx_std_20)