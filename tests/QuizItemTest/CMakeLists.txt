cmake_minimum_required(VERSION 3.5)

project(QuizItemTest LANGUAGES CXX)

find_package(QT NAMES Qt5 Qt6 COMPONENTS Gui Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if(NOT CMAKE_CXX_CPPCHECK)
message(FATAL_ERROR "Could not find the program cppcheck.")
endif()
list(APPEND CMAKE_CXX_CPPCHECK "--enable=all"  "--suppress=unmatchedSuppression:*"   "--suppress=missingIncludeSystem"  "--suppress=preprocessorErrorDirective"  "--error-exitcode=10" )

add_executable(QuizItemTest tst_quizitemtest.cpp ../../src/model/quizitem.cpp)
add_test(NAME QuizItemTest COMMAND QuizItemTest)

target_link_libraries(QuizItemTest PRIVATE Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Test)

