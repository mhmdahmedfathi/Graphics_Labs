cmake_minimum_required(VERSION 3.0.0)
project(Labs VERSION 0.1.0)

add_subdirectory(vendor/glfw)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)        # Don't build Documentation
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)       # Don't build Tests
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)    # Don't build Examples
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)           # Don't build Installation Information
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)     # Add variables to use High Performance Graphics Card if available important if there are external graphics card so we حددنا to use high performance card

include_directories(
    vendor/glfw/include
    vendor/glad/include
) #to make shortcut to the lib inside this path


set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin ) #to set the directory of the .exe file

#vendor folder to put every external lib


add_executable(Labs main.cpp vendor/glad/src/gl.c) #compile two files

target_link_libraries(Labs glfw)
