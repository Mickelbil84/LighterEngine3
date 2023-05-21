cmake_minimum_required(VERSION 3.11-3.25)

project(main)

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(Lua REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS} ${LUA_INCLUDE_DIR})
link_libraries(${GLEW_LIBRARIES})

add_executable(
    main
    main.cpp
)
target_link_libraries(main PRIVATE lre3 GLEW::glew)
target_compile_features(main PUBLIC cxx_std_20)