#include "pch.h"
#include "../AlgoTeamLab1/RationalNum.h"
#include "../AlgoTeamLab1/RationalNum.cpp"
TEST(RationalNumConstructor, ZeroArguments) {
	RationalNum a;
	EXPECT_EQ(a.get_numerator(), 0);
	EXPECT_EQ(a.get_denominator(), 1);
}
TEST(RationalNumConstructor, TwoArguments) {
	RationalNum r1(5,7);
	EXPECT_EQ(r1.get_numerator(), 5);
	EXPECT_EQ(r1.get_denominator(), 7);

	RationalNum r2(12, 3);
	EXPECT_EQ(r2.get_numerator(), 12);
	EXPECT_EQ(r2.get_denominator(), 3);

	RationalNum r3(0, 3);
	EXPECT_EQ(r3.get_numerator(), 0);
	EXPECT_EQ(r3.get_denominator(), 3);

	RationalNum r4(-5, 7);
	EXPECT_EQ(r4.get_numerator(), -5);
	EXPECT_EQ(r4.get_denominator(), 7);

	RationalNum r5(-12, 3);
	EXPECT_EQ(r5.get_numerator(), -12);
	EXPECT_EQ(r5.get_denominator(), 3);

	EXPECT_ANY_THROW(RationalNum r6(3, 0););

	EXPECT_ANY_THROW(RationalNum r7(3, -2););
}