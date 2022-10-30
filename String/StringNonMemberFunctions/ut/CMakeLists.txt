set(This ${MODULE_NAME}_Test)

set(TESTSRC
        src/StringNonMemberFunctionsTests.cpp
)

add_executable(${This} ${TESTSRC})
target_link_libraries(${This}  
    ${MODULE_NAME}
    GTest::gmock GTest::gmock_main
    GTest::gtest GTest::gtest_main
)
