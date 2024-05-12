#include "include/gtest/gtest.h"

int add(int a, int b);

TEST(mainTest, PositiveNumbers) {
    EXPECT_EQ(8, add(5, 3));
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(-8, add(-5, -3));
}


/*
Testing of the individual functions for board class
*/
// play turn function

/*
Testing for the utils header
*/


/*
Testing for the main
*/


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
