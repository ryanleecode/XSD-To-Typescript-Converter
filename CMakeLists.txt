cmake_minimum_required(VERSION 3.10)
project(xsdToTypescript)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else ()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif ()

add_executable(xsdToTypescript
        src/main.cpp
        src/tsgen/typescript_module.cpp
        src/tsgen/typescript_module.h
        src/tsgen/typescript_module_factory.cpp
        src/xmlparse/incorrect_xml_element_name_exception.cpp
        src/xmlparse/incorrect_xml_element_name_exception.h
        src/xmlparse/missing_xml_attribute_exception.cpp
        src/xmlparse/missing_xml_attribute_exception.h
        src/tsgen/simple_type.cpp
        src/tsgen/simple_type.h
        src/tsgen/xsd_primitive.h)
target_link_libraries(xsdToTypescript ${CONAN_LIBS})

enable_testing()
add_executable(runUnitTests
        test/incorrect_xml_element_name_exception_test.cpp
        src/xmlparse/incorrect_xml_element_name_exception.cpp
        src/xmlparse/incorrect_xml_element_name_exception.h
        test/typescript_module_factory_test.cpp
        src/tsgen/typescript_module.cpp
        src/tsgen/typescript_module.h
        src/tsgen/typescript_module_factory.cpp
        test/missing_xml_attribute_exception_test.cpp
        src/xmlparse/missing_xml_attribute_exception.cpp
        src/xmlparse/missing_xml_attribute_exception.h
        test/simple_type_test.cpp
        src/tsgen/simple_type.cpp
        src/tsgen/simple_type.h
        src/tsgen/xsd_primitive.h)
target_link_libraries(runUnitTests ${CONAN_LIBS})
add_test(runUnitTests runUnitTests)

configure_file(Elements.xsd bin/Elements.xsd COPYONLY)