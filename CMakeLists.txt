cmake_minimum_required (VERSION 3.1.2)
project (snowglobe CXX)

SET(CMAKE_CXX_FLAGS "-std=c++11")

add_subdirectory(GameEngine)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*.cpp")
file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "src/*.h")

set (${PROJECT_NAME}_INCLUDE_DIRS "")
foreach (headerFile ${${PROJECT_NAME}_HEADERS})
    get_filename_component(dir ${headerFile} PATH)
    list (APPEND ${PROJECT_NAME}_INCLUDE_DIRS ${dir})
endforeach()
list(REMOVE_DUPLICATES ${PROJECT_NAME}_INCLUDE_DIRS)

include_directories(${${PROJECT_NAME}_INCLUDE_DIRS})
add_executable (${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC gameengine)