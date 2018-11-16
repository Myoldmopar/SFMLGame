#include <gtest/gtest.h>

#include <config.hpp>

TEST(Config, DefaultConfiguration) {
    Configuration c;
    EXPECT_GT(c.initialWidth, 0);
    EXPECT_GT(c.initialHeight, 0);
}