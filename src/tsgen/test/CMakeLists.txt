add_executable(tsgen_test
        "src/TypescriptModuleTest.cpp"
        "src/TypescriptModuleBuilderTest.cpp"
        "src/SimpleTypeImpTest.cpp"
        "src/restrictions/StringRestrictionHandlerTest.cpp"
        "src/mocks/MockXMLElement.h"
        "src/mocks/MockXMLAttribute.h")

target_link_libraries(tsgen_test
        PRIVATE
        tsgen
        XMLParse
        CONAN_PKG::gtest
        CONAN_PKG::tinyxml2
        )

enable_testing()
add_test(tsgen_test tsgen_test)