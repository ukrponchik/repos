cmake_minimum_required(VERSION 3.18.0)
project(BoolMatrix LANGUAGES CXX VERSION 0.0.1
    DESCRIPTION "BoolMatrix")

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(
    ${PROJECT_NAME}
        PRIVATE ${CMAKE_SOURCE_DIR}/include/
)

install(
    TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Debug
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/
)
