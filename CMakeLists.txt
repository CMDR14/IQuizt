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

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#set(CMAKE_PREFIX_PATH "C:/Qt/5.15.0/mingw81_64") #$ENV{QTDIR})
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

#find_package(Qt6 COMPONENTS Core)
#find_package(Qt6 COMPONENTS Widgets)

#set(SRC "${CMAKE_SOURCE_DIR}/src")
#set(SRC_MODEL "${CMAKE_SOURCE_DIR}/src/model")
#set(SRC_VIEW "${CMAKE_SOURCE_DIR}/src/view")

#include_directories(${SRC})
#include_directories(${SRC_MODEL})
#include_directories(${SRC_VIEW})

#file(GLOB MODEL_FILES ${SRC_MODEL}/*.cpp)
#file(GLOB VIEW_FILES ${SRC_VIEW}/*.cpp)


find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if(NOT CMAKE_CXX_CPPCHECK)
message(FATAL_ERROR "Could not find the program cppcheck.")
endif()
list(APPEND CMAKE_CXX_CPPCHECK "--enable=all"  "--suppress=unmatchedSuppression:*"   "--suppress=missingIncludeSystem") #"--error-exitcode=10" )


add_subdirectory(tests)
add_subdirectory(src)

#if (WIN32)
#    add_executable(IQuizt.exe WIN32
#    src/main.cpp
#)
#elseif(UNIX)
#    add_executable(IQuizt
#    src/main.cpp
#)
#endif()

#target_include_directories(IQuizt PRIVATE ${SRC})
#target_include_directories(IQuizt PRIVATE ${SRC_MODEL})
#target_include_directories(IQuizt PRIVATE ${SRC_VIEW})

#target_link_libraries(IQuizt Qt5::Widgets)
