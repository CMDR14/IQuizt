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


add_subdirectory(model)
add_subdirectory(view)
add_subdirectory(persistence)

if (WIN32)
    add_executable(IQuizt WIN32
    main.cpp
)
elseif(UNIX)
    add_executable(IQuizt
    main.cpp
)
endif()

target_include_directories(IQuizt PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(IQuizt
    Qt5::Widgets
    IQuizt_View
)
