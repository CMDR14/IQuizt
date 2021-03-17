cmake_minimum_required(VERSION 3.16.0)

if (WIN32)
    project(IQuizt LANGUAGES CXX)
elseif(UNIX)
    project(IQuizt)
endif()

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

include_directories("${CMAKE_SOURCE_DIR}/src/model")
include_directories("${CMAKE_SOURCE_DIR}/src/view")
include_directories("${CMAKE_SOURCE_DIR}/src")


if (WIN32)
    add_executable(IQuizt WIN32
    src/view/mainwidget.cpp
    src/main.cpp
)
elseif(UNIX)
    add_executable(IQuizt
    src/view/mainwidget.cpp
    src/main.cpp
)
endif()

target_include_directories(IQuizt PRIVATE "${CMAKE_SOURCE_DIR}/src/model")
target_include_directories(IQuizt PRIVATE "${CMAKE_SOURCE_DIR}/src/view")
target_include_directories(IQuizt PRIVATE "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(IQuizt Qt5::Widgets)
