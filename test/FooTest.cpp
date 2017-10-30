#include <gtest/gtest.h>

/* this is a test that can pass*/
TEST(Test, CanPass) {
	EXPECT_EQ(1, 1);
}

/* make a tast that can not pass*/
TEST(Test, CannotPass) {
	EXPECT_EQ(1, 0);
}