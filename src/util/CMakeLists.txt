cmake_minimum_required(VERSION 3.1...3.12)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

project(util VERSION 1.0.0 LANGUAGES CXX)

add_library(Util
        "src/NotImplementedException.cpp")

target_include_directories(Util
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )
target_compile_options(Util PRIVATE -Werror)
target_compile_features(Util PRIVATE cxx_std_17)

add_subdirectory(test)
