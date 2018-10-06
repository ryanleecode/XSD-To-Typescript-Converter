cmake_minimum_required(VERSION 3.1...3.12)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif ()

project(xmlparse VERSION 1.0.0 LANGUAGES CXX)

add_library(XMLParse
        "src/XMLElementNameToCamelCaseConverter.cpp"
        "src/MissingXMLAttributeException.cpp"
        "src/IncorrectXMLElementNameException.cpp"
        "src/XMLElement/XMLNullElement.cpp"
        "src/XMLElement/XMLElementAdapter.cpp"
        "src/XMLAttribute/XMLAttributeAdapter.cpp"
        "src/XMLAttribute/XMLNullAttribute.cpp")

target_include_directories(XMLParse
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_compile_options(XMLParse PRIVATE -Werror)
target_compile_features(XMLParse PRIVATE cxx_std_17)

target_link_libraries(XMLParse
    PRIVATE
        CONAN_PKG::tinyxml2
        CONAN_PKG::boost_algorithm
)

add_subdirectory(test)
