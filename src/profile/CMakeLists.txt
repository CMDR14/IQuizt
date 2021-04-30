cmake_minimum_required(VERSION 3.16.0)

if (WIN32)
    project(IQuizt_Profile LANGUAGES CXX)
elseif(UNIX)
    project(IQuizt_Profile)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

if (WIN32)
    add_library(IQuizt_Profile
    profile.cpp
)
elseif(UNIX)
    add_library(IQuizt_Profile
    profile.cpp
)
endif()

#target_include_directories(IQuizt_Profile PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(IQuizt_Profile 
    Qt5::Widgets
    Qt5::Core
    IQuizt_Model)
