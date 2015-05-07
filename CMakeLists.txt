#cmake_minimum_required (VERSION 3.1.2)
cmake_minimum_required (VERSION 2.8.8)
project (simandconc)

SET(CMAKE_CXX_FLAGS "")

IF(MINGW)
    list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
    add_definitions(-DOPEN_GL)
ELSEIF(WIN32)
    add_definitions(-DDIRECT_X)
    add_definitions(-DUNICODE -D_UNICODE)
    list(APPEND CMAKE_CXX_FLAGS "/EHsc")
ELSE()
    list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
    add_definitions(-DOPEN_GL)
ENDIF()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/GameEngine/cmake" )
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

IF(USE_ANT)
    message(STATUS "Using AntTweakBar")
    add_definitions(-DUSE_ANT)
    find_package(AntTweakBar REQUIRED)
    IF(NOT TW_FOUND)
        message(FATAL_ERROR "AntTweakBar not found")
    ENDIF()
    list(APPEND ${PROJECT_NAME}_INCLUDE_DIRS ${TW_INCLUDE_DIRS})
    list(APPEND ${PROJECT_NAME}_LIBRARY_PATHS ${TW_LIBRARIES})
ENDIF()

include_directories(${${PROJECT_NAME}_INCLUDE_DIRS})
add_executable (${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC gameengine)
