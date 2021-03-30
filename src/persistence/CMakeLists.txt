cmake_minimum_required(VERSION 3.16.0)

if (WIN32)
    project(IQuizt LANGUAGES CXX)
elseif(UNIX)
    project(IQuizt)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

if (WIN32)
    add_library(IQuizt_Persistence
    persistence.cpp
)
elseif(UNIX)
    add_library(IQuizt_Persistence
    persistence.cpp
)
endif()

#target_include_directories(IQuizt_Persistence PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(IQuizt_Persistence Qt5::Widgets)
