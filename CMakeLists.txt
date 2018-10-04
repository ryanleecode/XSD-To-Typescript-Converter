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
        src/tsgen/TypescriptModule.cpp
        src/tsgen/TypescriptModule.h
        src/tsgen/TypescriptModuleFactory.cpp
        src/xmlparse/IncorrectXMLElementNameException.cpp
        src/xmlparse/IncorrectXMLElementNameException.h
        src/xmlparse/MissingXMLAttributeException.cpp
        src/xmlparse/MissingXMLAttributeException.h
        src/tsgen/SimpleType.cpp
        src/tsgen/SimpleType.h
        src/tsgen/TypescriptPrimitive.h
        src/util/NotImplementedException.h
        src/xmlparse/XMLAttributeProcessor.cpp
        src/xmlparse/XMLAttributeProcessor.h
        src/xmlparse/XMLElementNameToCamelCaseConverter.cpp
        src/xmlparse/XMLElementNameToCamelCaseConverter.h
        src/xmlparse/XMLElement.h
        src/tsgen/TypescriptModuleFactory.h
        src/xmlparse/XMLAttribute.h
        src/xmlparse/XMLElementImp.cpp
        src/xmlparse/XMLElementImp.h
        src/xmlparse/XMLAttributeImp.cpp
        src/xmlparse/XMLAttributeImp.h)
target_link_libraries(xsdToTypescript ${CONAN_LIBS})

enable_testing()
add_executable(runUnitTests
        test/IncorrectXMLElementNameExceptionTest.cpp
        src/xmlparse/IncorrectXMLElementNameException.cpp
        src/xmlparse/IncorrectXMLElementNameException.h
        test/TypescriptModuleBuilderTest.cpp
        src/tsgen/TypescriptModule.cpp
        src/tsgen/TypescriptModule.h
        src/tsgen/TypescriptModuleFactory.cpp
        test/MissingXMLAttributeExceptionTest.cpp
        src/xmlparse/MissingXMLAttributeException.cpp
        src/xmlparse/MissingXMLAttributeException.h
        test/SimpleTypeTest.cpp
        src/tsgen/SimpleType.cpp
        src/tsgen/SimpleType.h
        src/tsgen/TypescriptPrimitive.h
        src/util/NotImplementedException.h
        src/xmlparse/XMLAttributeProcessor.cpp
        src/xmlparse/XMLAttributeProcessor.h
        src/xmlparse/XMLElementNameToCamelCaseConverter.cpp
        src/xmlparse/XMLElementNameToCamelCaseConverter.h
        test/MockXMLElement.h
        src/xmlparse/XMLElement.h
        src/tsgen/TypescriptModuleFactory.h
        src/xmlparse/XMLAttribute.h
        src/xmlparse/XMLElementImp.cpp
        src/xmlparse/XMLElementImp.h
        src/xmlparse/XMLAttributeImp.cpp
        src/xmlparse/XMLAttributeImp.h test/MockXMLAttribute.h test/TypescriptModuleTest.cpp)
target_link_libraries(runUnitTests ${CONAN_LIBS})
add_test(runUnitTests runUnitTests)

configure_file(Elements.xsd bin/Elements.xsd COPYONLY)