#include <gtest/gtest.h>

#include <utilities.hpp>

TEST(Addition, A) {
    EXPECT_EQ(1, 1);
}

TEST(OurAddition, A) {
    int i = 1;
    int j = 2;
    EXPECT_EQ(3, add(i, j));
}
