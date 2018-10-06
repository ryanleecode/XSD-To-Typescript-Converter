cmake_minimum_required(VERSION 3.1...3.12)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

project(XSDToTypescriptConverter VERSION 1.0
        DESCRIPTION "Converts XSD Defintion files to Typescript definition files"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
else ()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif ()

add_subdirectory(tsgen)
add_subdirectory(xmlparse)
add_subdirectory(util)

add_executable(xsdtotypescript main.cpp)
target_include_directories(xsdtotypescript INTERFACE
        "${PROJECT_SOURCE_DIR}/xmlparse"
        "${PROJECT_SOURCE_DIR}/util"
        "${PROJECT_SOURCE_DIR}/tsgen")
target_compile_features(xsdtotypescript PRIVATE cxx_auto_type)

target_link_libraries(xsdtotypescript
        PRIVATE
        XMLParse
        tsgen
        Util
        CONAN_PKG::tinyxml2
        )

configure_file(Elements.xsd bin/Elements.xsd COPYONLY)
