#cmake_minimum_required (VERSION 3.1.2)
cmake_minimum_required (VERSION 2.8.8)
project (snowglobe)

SET(CMAKE_CXX_FLAGS "")

IF(MINGW)
    list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
    add_definitions(-DOPEN_GL)
ELSEIF(WIN32)
    add_definitions(-DDIRECT_X)
    list(APPEND CMAKE_CXX_FLAGS "/EHsc")
ELSE()
    list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
    add_definitions(-DOPEN_GL)
ENDIF()

add_subdirectory(GameEngine)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*.cpp")
file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "src/*.h")

set (${PROJECT_NAME}_INCLUDE_DIRS "")
foreach (headerFile ${${PROJECT_NAME}_HEADERS})
    get_filename_component(dir ${headerFile} PATH)
    list (APPEND ${PROJECT_NAME}_INCLUDE_DIRS ${dir})
endforeach()
list(REMOVE_DUPLICATES ${PROJECT_NAME}_INCLUDE_DIRS)

list(APPEND ${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_HEADERS})

include_directories(${${PROJECT_NAME}_INCLUDE_DIRS})
add_executable (${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC gameengine)
