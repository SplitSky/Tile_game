
#include <gtest/gtest.h>
#include "example.h"

TEST(ExampleTest, TestMessage) {
    // Your test code here
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
