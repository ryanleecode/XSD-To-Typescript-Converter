add_executable(xmlparse_test
        "src/XMLNullAttributeTest.cpp"
        "src/XMLNullElementTest.cpp")

target_link_libraries(xmlparse_test
        PRIVATE
        XMLParse
        CONAN_PKG::gtest
        )

enable_testing()
add_test(xmlparse_test xmlparse_test)
