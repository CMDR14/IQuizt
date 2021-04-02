cmake_minimum_required(VERSION 3.16.0)

if (WIN32)
    project(IQuizt_Tests LANGUAGES CXX)
elseif(UNIX)
    project(IQuizt_Tests)
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

add_subdirectory(PersistenceTest)
add_subdirectory(quizitemedtiortest)
add_subdirectory(QuizItemTest)