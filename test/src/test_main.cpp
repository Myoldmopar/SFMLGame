// Google Test Headers
#include <gtest/gtest.h>

// Google Test main
int main(int argc, char **argv)
{
#ifdef ENABLE_GTEST_DEBUG_MODE
    ::testing::GTEST_FLAG(break_on_failure) = true;
    ::testing::GTEST_FLAG(catch_exceptions) = false;
#endif
#ifdef ENABLE_GTEST_SHUFFLE
    ::testing::GTEST_FLAG(shuffle) = true;
#endif
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
