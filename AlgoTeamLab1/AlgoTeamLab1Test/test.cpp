#include "pch.h"
#include "../AlgoTeamLab1/RationalNum.h"
#include "../AlgoTeamLab1/RationalNum.cpp"

TEST(RationalNumTest, ZeroArgumentConstructor) {
	RationalNum a;
	EXPECT_EQ(a.get_numerator(), 0);
	EXPECT_EQ(a.get_denominator(), 1);
}
TEST(RationalNumTest, TwoArgumentConstructor) {
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

TEST(RationalNumTest, simlify) {
	RationalNum r1(5, 7);
	r1.simlify();
	EXPECT_EQ(r1.get_numerator(), 5);
	EXPECT_EQ(r1.get_denominator(), 7);

	RationalNum r2(12, 3);
	r2.simlify();
	EXPECT_EQ(r2.get_numerator(), 4);
	EXPECT_EQ(r2.get_denominator(), 1);

	RationalNum r3(0, 3);
	r3.simlify();
	EXPECT_EQ(r3.get_numerator(), 0);
	EXPECT_EQ(r3.get_denominator(), 1);

	RationalNum r4(3, 9);
	r4.simlify();
	EXPECT_EQ(r4.get_numerator(), 1);
	EXPECT_EQ(r4.get_denominator(), 3);

	RationalNum r5(-5, 7);
	r5.simlify();
	EXPECT_EQ(r5.get_numerator(), -5);
	EXPECT_EQ(r5.get_denominator(), 7);

	RationalNum r6(-12, 3);
	r6.simlify();
	EXPECT_EQ(r6.get_numerator(), -4);
	EXPECT_EQ(r6.get_denominator(), 1);

	RationalNum r7(-3, 9);
	r7.simlify();
	EXPECT_EQ(r7.get_numerator(), -1);
	EXPECT_EQ(r7.get_denominator(), 3);
}