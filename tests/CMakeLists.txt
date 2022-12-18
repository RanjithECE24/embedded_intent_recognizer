cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

find_package(jsoncpp REQUIRED)

add_definitions(-w)

set(TEST_SOURCES 
    ${PROJECT_SOURCE_DIR}/source/config_parser.cpp
    ${PROJECT_SOURCE_DIR}/source/embedded_intent_recognizer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/embedded_intent_recognizer_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/config_parser_tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    
include_directories(${PROJECT_SOURCE_DIR}/include ${GTEST_INCLUDE_DIR})

add_executable(gtest_EmbeddedIntentRecognizer ${TEST_SOURCES})

target_link_libraries(gtest_EmbeddedIntentRecognizer gtest gtest_main gmock pthread jsoncpp)
