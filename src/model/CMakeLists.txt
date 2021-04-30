cmake_minimum_required(VERSION 3.16.0)

if (WIN32)
    project(IQuizt_Model LANGUAGES CXX)
elseif(UNIX)
    project(IQuizt_Model)
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


if (WIN32)
    add_library(IQuizt_Model
    model.cpp
    quizitem.cpp
)
elseif(UNIX)
    add_library(IQuizt_Model
    model.cpp
    quizitem.cpp
)
endif()

#target_include_directories(IQuizt_Model PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(IQuizt_Model 
    Qt5::Widgets
    IQuizt_Persistence
	IQuizt_Profile)
