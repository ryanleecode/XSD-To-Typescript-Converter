cmake_minimum_required(VERSION 3.1...3.12)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

project(tsgen VERSION 1.0.0 LANGUAGES CXX)

add_library(tsgen
        src/XSDToTypescriptParseTree.cpp
        src/XSDSimpleTypeElementProcessor.cpp
        src/XSDElementProcessorImp.cpp
        src/XSDRestrictionElementProcessor.cpp
        src/XSDStringRestrictionElementProcessor.cpp
        src/XSDEnumerationsProcessorImp.cpp
        src/XSDStringEnumerationsProcessor.cpp
        src/XSDDecimalRestrictionElementProcessor.cpp
        src/XSDIntegerRestrictionElementProcessor.cpp src/XSDDatetimeRestrictionElementProcessor.cpp include/XSDDatetimeRestrictionElementProcessor.h)

target_include_directories(tsgen
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )
target_compile_options(tsgen PRIVATE -Werror)
target_compile_features(tsgen PRIVATE cxx_std_17)

target_link_libraries(tsgen
    PUBLIC
        XMLParse
    PRIVATE
        Util
        CONAN_PKG::boost_algorithm
        )

add_subdirectory(test)
