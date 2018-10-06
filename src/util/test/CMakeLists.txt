add_executable(util_test
        "src/NotImplementedExceptionTest.cpp")

target_link_libraries(util_test
        PRIVATE
        Util
        CONAN_PKG::gtest
        )

enable_testing()
add_test(util_test util_test)