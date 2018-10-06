add_executable(xmlparse_test
        "src/IncorrectXSDElementNameExceptionTest.cpp"
        "src/MissingXSDAttributeExceptionTest.cpp"
        "src/XMLNullAttributeTest.cpp"
        "src/XMLNullElementTest.cpp"
        "../../tsgen/test/src/mocks/MockXMLAttribute.h"
        "../../tsgen/test/src/mocks/MockXMLElement.h")

target_link_libraries(xmlparse_test
        PRIVATE
        XMLParse
        CONAN_PKG::gtest
        )

enable_testing()
add_test(xmlparse_test xmlparse_test)
