cmake_minimum_required(VERSION 3.10)
project(OpenGL_WASM)

set(CMAKE_CXX_STANDARD 14)

set(OGL_LIBS -lSDL2)
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Emscripten")
    set(CMAKE_CXX_FLAGS "-O3 -s WASM=1 ${OGL_LIBS} ${CMAKE_CXX_FLAGS}")
endif ()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/index.html DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


add_executable(oglwasm ${SOURCES})
target_link_libraries(oglwasm ${OGL_LIBS})