cmake_minimum_required(VERSION 3.16.0)

if (WIN32)
    project(IQuizt_Main LANGUAGES CXX)
elseif(UNIX)
    project(IQuizt_Main)
endif()

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)


#find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
#if(NOT CMAKE_CXX_CPPCHECK)
#message(FATAL_ERROR "Could not find the program cppcheck.")
#endif()
#list(APPEND CMAKE_CXX_CPPCHECK "--enable=all"  "--suppress=unmatchedSuppression:*"   "--suppress=missingIncludeSystem"  "--suppress=preprocessorErrorDirective"  "--suppress=unusedFunction"  "--error-exitcode=10" )


add_subdirectory(tests)
add_subdirectory(src)
