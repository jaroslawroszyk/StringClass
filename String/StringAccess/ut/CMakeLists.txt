set(This ${MODULE_NAME}_test)

set(TESTSRC
        src/ElementAccessTests.cpp
)

add_executable(${This} ${TESTSRC})
target_link_libraries(${This}  
    ${MODULE_NAME}
    GTest::gmock GTest::gmock_main
    GTest::gtest GTest::gtest_main
)
