cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

find_package(jsoncpp REQUIRED)

add_definitions(-w)

include_directories(include)

set(SOURCE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/embedded_intent_recognizer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/config_parser.cpp)

add_executable(EmbeddedIntentRecognizer ${SOURCE_FILES})
target_link_libraries(EmbeddedIntentRecognizer jsoncpp)

enable_testing ()
add_subdirectory(tests)