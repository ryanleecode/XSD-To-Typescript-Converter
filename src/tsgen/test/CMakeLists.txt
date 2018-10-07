add_executable(tsgen_test
        "src/mocks/MockXMLElement.h"
        "src/mocks/MockXMLAttribute.h"
        src/XSDToTypescriptParseTreeTest.cpp
        src/mocks/MockXSDElementProcessor.h
        src/XSDSimpleTypeElementProcessorTest.cpp
        src/XSDStringRestrictionElementProcessorTest.cpp
        src/XSDEnumerationProcessorImpTest.cpp src/mocks/MockEnumerationsProcessor.h src/XSDStringEnumerationsProcessorTest.cpp)

target_link_libraries(tsgen_test
        PRIVATE
        tsgen
        XMLParse
        CONAN_PKG::gtest
        CONAN_PKG::tinyxml2
        )

enable_testing()
add_test(tsgen_test tsgen_test)