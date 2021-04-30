cmake_minimum_required(VERSION 3.16.0)

if (WIN32)
    project(IQuizt_View LANGUAGES CXX)
elseif(UNIX)
    project(IQuizt_View)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

if (WIN32)
    add_library(IQuizt_View
    mainwidget.cpp
    quizitemeditor.cpp
    quizitemselector.cpp
    profilecreationdialog.cpp
)
elseif(UNIX)
    add_library(IQuizt_View
    mainwidget.cpp
    quizitemeditor.cpp
    quizitemselector.cpp
    profilecreationdialog.cpp
)
endif()

#target_include_directories(IQuizt_View PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(IQuizt_View 
    Qt5::Widgets
    IQuizt_Model)
