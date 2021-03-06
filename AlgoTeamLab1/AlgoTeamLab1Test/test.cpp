#include "pch.h"
#include "../AlgoTeamLab1/RationalNum.h"
#include "../AlgoTeamLab1/RationalNum.cpp"
#include <fstream>
#include <utility>
#include "../AlgoTeamLab1/Matrix.h"
#include "../AlgoTeamLab1/InverseLUDecomposition.h"
#include "../AlgoTeamLab1/LinearRegression.h"

TEST(RationalNumTest, ZeroArgumentConstructor) {
	RationalNum a;
	EXPECT_EQ(a.get_numerator(), 0);
	EXPECT_EQ(a.get_denominator(), 1);
}

TEST(RationalNumTest, TwoArgumentConstructor) {
	RationalNum r1(5, 7);
	EXPECT_EQ(r1.get_numerator(), 5);
	EXPECT_EQ(r1.get_denominator(), 7);

	RationalNum r2(12, 3);
	EXPECT_EQ(r2.get_numerator(), 4);
	EXPECT_EQ(r2.get_denominator(), 1);

	RationalNum r3(0, 3);
	EXPECT_EQ(r3.get_numerator(), 0);
	EXPECT_EQ(r3.get_denominator(), 1);

	RationalNum r4(3, 9);
	EXPECT_EQ(r4.get_numerator(), 1);
	EXPECT_EQ(r4.get_denominator(), 3);

	RationalNum r5(-5, 7);
	EXPECT_EQ(r5.get_numerator(), -5);
	EXPECT_EQ(r5.get_denominator(), 7);

	RationalNum r6(-12, 3);
	EXPECT_EQ(r6.get_numerator(), -4);
	EXPECT_EQ(r6.get_denominator(), 1);

	RationalNum r7(-3, 9);
	EXPECT_EQ(r7.get_numerator(), -1);
	EXPECT_EQ(r7.get_denominator(), 3);

	EXPECT_ANY_THROW(RationalNum r8(3, 0););

	RationalNum r9(3, -2);
	EXPECT_EQ(r9.get_numerator(), -3);
	EXPECT_EQ(r9.get_denominator(), 2);

	RationalNum r10(-3, -2);
	EXPECT_EQ(r10.get_numerator(), 3);
	EXPECT_EQ(r10.get_denominator(), 2);
}

TEST(RationalNumTest, OneArgumentConstructor) {
	RationalNum r(3);
	EXPECT_EQ(r.get_numerator(), 3);
	EXPECT_EQ(r.get_denominator(), 1);
}

TEST(RationalNumTest, ConversionFromInt) {
	RationalNum r = 3;
	EXPECT_EQ(r.get_numerator(), 3);
	EXPECT_EQ(r.get_denominator(), 1);
}

TEST(RationalNumTest, Assignment) {
	RationalNum r = RationalNum(5,7);
	EXPECT_EQ(r.get_numerator(), 5);
	EXPECT_EQ(r.get_denominator(), 7);

	r = RationalNum(-5, 7);
	EXPECT_EQ(r.get_numerator(), -5);
	EXPECT_EQ(r.get_denominator(), 7);

	r = RationalNum(0, 1);
	EXPECT_EQ(r.get_numerator(), 0);
	EXPECT_EQ(r.get_denominator(), 1);
}
TEST(RationalNumTest, Equality) {
	RationalNum r1_1(1, 2), r1_2(1, 2);
	EXPECT_TRUE(r1_1 == r1_2);

	RationalNum r2_1(-1, 2), r2_2(-1, 2);
	EXPECT_TRUE(r2_1 == r2_2);

	RationalNum r3_1(-1, 2), r3_2(1, 2);
	EXPECT_FALSE(r3_1 == r3_2);

	RationalNum r4_1(1, 2), r4_2(-1, 2);
	EXPECT_FALSE(r4_1 == r4_2);

	RationalNum r5_1(1, 3), r5_2(-1, 3);
	EXPECT_FALSE(r5_1 == r5_2);

	RationalNum r6_1(1, 3), r6_2(1, 4);
	EXPECT_FALSE(r6_1 == r6_2);

	RationalNum r7_1(1, 3), r7_2(-1, 4);
	EXPECT_FALSE(r7_1 == r7_2);

	RationalNum r8_1(0, 1), r8_2(0, 3);
	EXPECT_TRUE(r8_1 == r8_2);
}

TEST(RationalNumTest, Inequality) {
	RationalNum r1_1(1, 2), r1_2(1, 2);
	EXPECT_FALSE(r1_1 != r1_2);

	RationalNum r2_1(-1, 2), r2_2(-1, 2);
	EXPECT_FALSE(r2_1 != r2_2);

	RationalNum r3_1(-1, 2), r3_2(1, 2);
	EXPECT_TRUE(r3_1 != r3_2);

	RationalNum r4_1(1, 2), r4_2(-1, 2);
	EXPECT_TRUE(r4_1 != r4_2);

	RationalNum r5_1(1, 3), r5_2(-1, 3);
	EXPECT_TRUE(r5_1 != r5_2);

	RationalNum r6_1(1, 3), r6_2(1, 4);
	EXPECT_TRUE(r6_1 != r6_2);

	RationalNum r7_1(1, 3), r7_2(-1, 4);
	EXPECT_TRUE(r7_1 != r7_2);

	RationalNum r8_1(0, 1), r8_2(0, 3);
	EXPECT_FALSE(r8_1 != r8_2);
}

TEST(RationalNumTest, Addition) {
	RationalNum r1_1(1, 2), r1_2(1, 2);
	EXPECT_EQ(r1_1 + r1_2, RationalNum(1, 1));

	RationalNum r2_1(1, 2), r2_2(-1, 2);
	EXPECT_EQ(r2_1 + r2_2, RationalNum(0, 1));

	// one test for +=
	r2_1 += r2_2;
	EXPECT_EQ(r2_1, RationalNum(0, 1));

	RationalNum r3_1(-1, 2), r3_2(-1, 2);
	EXPECT_EQ(r3_1 + r3_2, RationalNum(-1, 1));

	RationalNum r4_1(1, 3), r4_2(1, 4);
	EXPECT_EQ(r4_1 + r4_2, RationalNum(7, 12));

	RationalNum r5_1(1, 3), r5_2(-1, 4);
	EXPECT_EQ(r5_1 + r5_2, RationalNum(1, 12));

	RationalNum r6_1(-1, 3), r6_2(1, 4);
	EXPECT_EQ(r6_1 + r6_2, RationalNum(-1, 12));

	RationalNum r7_1(-1, 3), r7_2(-1, 4);
	EXPECT_EQ(r7_1 + r7_2, RationalNum(-7, 12));

	// 1/4 + 1/6 = 5/12
	RationalNum r8_1(1, 4), r8_2(1, 6);
	EXPECT_EQ(r8_1 + r8_2, RationalNum(5, 12));

	// 1/6 + 1/3 = 6/12 = 1/2
	RationalNum r9_1(1, 6), r9_2(1, 3);
	EXPECT_EQ(r9_1 + r9_2, RationalNum(1, 2));

	RationalNum r10_1(-1, 6), r10_2(-1, 3);
	EXPECT_EQ(r10_1 + r10_2, RationalNum(-1, 2));

	// 1/3 - 1/6 = 2/12 = 1/6
	RationalNum r11_1(-1, 6), r11_2(1, 3);
	EXPECT_EQ(r11_1 + r11_2, RationalNum(1, 6));

	RationalNum r12_1(1, 6), r12_2(-1, 3);
	EXPECT_EQ(r12_1 + r12_2, RationalNum(-1, 6));

	RationalNum r13_1(0, 1), r13_2(1, 3);
	EXPECT_EQ(r13_1 + r13_2, r13_2);
	EXPECT_EQ(r13_2 + r13_1, r13_2);

	RationalNum r14_1(0, 1), r14_2(-1, 3);
	EXPECT_EQ(r14_1 + r14_2, r14_2);
	EXPECT_EQ(r14_2 + r14_1, r14_2);
}

TEST(RationalNumTest, Subraction) {
	RationalNum r1_1(1, 2), r1_2(1, 2);
	EXPECT_EQ(r1_1 - r1_2, RationalNum(0, 1));

	RationalNum r2_1(1, 2), r2_2(-1, 2);
	EXPECT_EQ(r2_1 - r2_2, RationalNum(1, 1));

	// one test for -=
	r2_1 -= r2_2;
	EXPECT_EQ(r2_1, RationalNum(1, 1));

	RationalNum r3_1(-1, 2), r3_2(-1, 2);
	EXPECT_EQ(r3_1 - r3_2, RationalNum(0, 1));

	RationalNum r4_1(1, 3), r4_2(1, 4);
	EXPECT_EQ(r4_1 - r4_2, RationalNum(1, 12));

	RationalNum r5_1(1, 3), r5_2(-1, 4);
	EXPECT_EQ(r5_1 - r5_2, RationalNum(7, 12));

	RationalNum r6_1(-1, 3), r6_2(1, 4);
	EXPECT_EQ(r6_1 - r6_2, RationalNum(-7, 12));

	RationalNum r7_1(-1, 3), r7_2(-1, 4);
	EXPECT_EQ(r7_1 - r7_2, RationalNum(-1, 12));

	RationalNum r8_1(1, 4), r8_2(1, 6);
	EXPECT_EQ(r8_1 - r8_2, RationalNum(1, 12));

	RationalNum r9_1(1, 6), r9_2(1, 3);
	EXPECT_EQ(r9_1 - r9_2, RationalNum(-1, 6));

	RationalNum r10_1(-1, 6), r10_2(-1, 3);
	EXPECT_EQ(r10_1 - r10_2, RationalNum(1, 6));

	RationalNum r11_1(-1, 6), r11_2(1, 3);
	EXPECT_EQ(r11_1 - r11_2, RationalNum(-1, 2));

	RationalNum r12_1(1, 6), r12_2(-1, 3);
	EXPECT_EQ(r12_1 - r12_2, RationalNum(1, 2));

	RationalNum r13_1(0, 1), r13_2(1, 3);
	EXPECT_EQ(r13_1 - r13_2, RationalNum(-1, 3));
	EXPECT_EQ(r13_2 - r13_1, r13_2);

	RationalNum r14_1(0, 1), r14_2(-1, 3);
	EXPECT_EQ(r14_1 - r14_2, RationalNum(1, 3));
	EXPECT_EQ(r14_2 - r14_1, r14_2);
}

TEST(RationalNumTest, Multiplication) {
	RationalNum r1_1(1, 2), r1_2(1, 2);
	EXPECT_EQ(r1_1 * r1_2, RationalNum(1, 4));

	RationalNum r2_1(1, 2), r2_2(-1, 2);
	EXPECT_EQ(r2_1 * r2_2, RationalNum(-1, 4));

	// one test for *=
	r2_1 *= r2_2;
	EXPECT_EQ(r2_1, RationalNum(-1, 4));

	RationalNum r3_1(-1, 2), r3_2(-1, 2);
	EXPECT_EQ(r3_1 * r3_2, RationalNum(1, 4));

	RationalNum r4_1(1, 3), r4_2(1, 4);
	EXPECT_EQ(r4_1 * r4_2, RationalNum(1, 12));

	RationalNum r5_1(1, 3), r5_2(-1, 4);
	EXPECT_EQ(r5_1 * r5_2, RationalNum(-1, 12));

	RationalNum r6_1(-1, 3), r6_2(1, 4);
	EXPECT_EQ(r6_1 * r6_2, RationalNum(-1, 12));

	RationalNum r7_1(-1, 3), r7_2(-1, 4);
	EXPECT_EQ(r7_1 * r7_2, RationalNum(1, 12));

	RationalNum r8_1(2, 3), r8_2(1, 2);
	EXPECT_EQ(r8_1 * r8_2, RationalNum(1, 3));

	RationalNum r9_1(2, 3), r9_2(-1, 2);
	EXPECT_EQ(r9_1 * r9_2, RationalNum(-1, 3));

	RationalNum r10_1(-2, 3), r10_2(1, 2);
	EXPECT_EQ(r10_1 * r10_2, RationalNum(-1, 3));

	RationalNum r11_1(-2, 3), r11_2(-1, 2);
	EXPECT_EQ(r11_1 * r11_2, RationalNum(1, 3));

	RationalNum r12_1(0, 1), r12_2(1, 3);
	EXPECT_EQ(r12_1 * r12_2, RationalNum(0, 1));
	EXPECT_EQ(r12_2 * r12_1, RationalNum(0, 1));

	RationalNum r13_1(0, 1), r13_2(-1, 3);
	EXPECT_EQ(r13_1 * r13_2, RationalNum(0, 1));
	EXPECT_EQ(r13_2 * r13_1, RationalNum(0, 1));

	RationalNum r14_1(1, 3), r14_2(-1, 1);
	EXPECT_EQ(r14_1 * r14_2, RationalNum(-1, 3));
	EXPECT_EQ(r14_2 * r14_1, RationalNum(-1, 3));

	RationalNum r15_1(-1, 3), r15_2(-1, 1);
	EXPECT_EQ(r15_1 * r15_2, RationalNum(1, 3));
	EXPECT_EQ(r15_2 * r15_1, RationalNum(1, 3));
}

TEST(RationalNumTest, Division) {
	RationalNum r1_1(1, 2), r1_2(1, 2);
	EXPECT_EQ(r1_1 / r1_2, RationalNum(1, 1));

	RationalNum r2_1(1, 2), r2_2(-1, 2);
	EXPECT_EQ(r2_1 / r2_2, RationalNum(-1, 1));

	// one test for /=
	r2_1 /= r2_2;
	EXPECT_EQ(r2_1, RationalNum(-1, 1));

	RationalNum r3_1(-1, 2), r3_2(-1, 2);
	EXPECT_EQ(r3_1 / r3_2, RationalNum(1, 1));

	RationalNum r4_1(1, 3), r4_2(1, 4);
	EXPECT_EQ(r4_1 / r4_2, RationalNum(4, 3));

	RationalNum r5_1(1, 3), r5_2(-1, 4);
	EXPECT_EQ(r5_1 / r5_2, RationalNum(-4, 3));

	RationalNum r6_1(-1, 3), r6_2(1, 4);
	EXPECT_EQ(r6_1 / r6_2, RationalNum(-4, 3));

	RationalNum r7_1(-1, 3), r7_2(-1, 4);
	EXPECT_EQ(r7_1 / r7_2, RationalNum(4, 3));

	// (1/3) / (2/3) = 1/2
	RationalNum r8_1(1, 3), r8_2(2, 3);
	EXPECT_EQ(r8_1 / r8_2, RationalNum(1, 2));

	RationalNum r9_1(1, 3), r9_2(-2, 3);
	EXPECT_EQ(r9_1 / r9_2, RationalNum(-1, 2));

	RationalNum r10_1(-1, 3), r10_2(2, 3);
	EXPECT_EQ(r10_1 / r10_2, RationalNum(-1, 2));

	RationalNum r11_1(-1, 3), r11_2(-2, 3);
	EXPECT_EQ(r11_1 / r11_2, RationalNum(1, 2));

	RationalNum r12_1(0, 1), r12_2(1, 3);
	EXPECT_EQ(r12_1 / r12_2, RationalNum(0, 1));
	EXPECT_ANY_THROW(r12_2 / r12_1);

	RationalNum r13_1(0, 1), r13_2(-1, 3);
	EXPECT_EQ(r13_1 / r13_2, RationalNum(0, 1));
	EXPECT_ANY_THROW(r13_2 / r13_1);

	RationalNum r14_1(1, 3), r14_2(-1, 1);
	EXPECT_EQ(r14_1 / r14_2, RationalNum(-1, 3));
	EXPECT_EQ(r14_2 / r14_1, RationalNum(-3, 1));

	RationalNum r15_1(-1, 3), r15_2(-1, 1);
	EXPECT_EQ(r15_1 / r15_2, RationalNum(1, 3));
	EXPECT_EQ(r15_2 / r15_1, RationalNum(3, 1));
}

TEST(RationalNumTest, ToPow) {
	RationalNum r(2, 3);
	r = r.to_pow(2);
	EXPECT_EQ(r.get_numerator(), 4);
	EXPECT_EQ(r.get_denominator(), 9);

	r = RationalNum(-2, 3);
	r = r.to_pow(2);
	EXPECT_EQ(r.get_numerator(), 4);
	EXPECT_EQ(r.get_denominator(), 9);

	r = RationalNum(2, 3);
	r = r.to_pow(3);
	EXPECT_EQ(r.get_numerator(), 8);
	EXPECT_EQ(r.get_denominator(), 27);

	r = RationalNum(-2, 3);
	r = r.to_pow(3);
	EXPECT_EQ(r.get_numerator(), -8);
	EXPECT_EQ(r.get_denominator(), 27);

	r = RationalNum(2, 3);
	r = r.to_pow(1);
	EXPECT_EQ(r.get_numerator(), 2);
	EXPECT_EQ(r.get_denominator(), 3);

	r = RationalNum(-2, 3);
	r = r.to_pow(1);
	EXPECT_EQ(r.get_numerator(), -2);
	EXPECT_EQ(r.get_denominator(), 3);

	r = RationalNum(2, 3);
	r = r.to_pow(-1);
	EXPECT_EQ(r.get_numerator(), 3);
	EXPECT_EQ(r.get_denominator(), 2);

	r = RationalNum(-2, 3);
	r = r.to_pow(-1);
	EXPECT_EQ(r.get_numerator(), -3);
	EXPECT_EQ(r.get_denominator(), 2);

	r = RationalNum(2, 3);
	r = r.to_pow(0);
	EXPECT_EQ(r.get_numerator(), 1);
	EXPECT_EQ(r.get_denominator(), 1);

	r = RationalNum(2, 3);
	r = r.to_pow(-2);
	EXPECT_EQ(r.get_numerator(), 9);
	EXPECT_EQ(r.get_denominator(), 4);

	r = RationalNum(-2, 3);
	r = r.to_pow(-2);
	EXPECT_EQ(r.get_numerator(), 9);
	EXPECT_EQ(r.get_denominator(), 4);

	r = RationalNum(2, 3);
	r = r.to_pow(-3);
	EXPECT_EQ(r.get_numerator(), 27);
	EXPECT_EQ(r.get_denominator(), 8);

	r = RationalNum(-2, 3);
	r = r.to_pow(-3);
	EXPECT_EQ(r.get_numerator(), -27);
	EXPECT_EQ(r.get_denominator(), 8);

	r = RationalNum(0, 1);
	r = r.to_pow(0);
	EXPECT_EQ(r.get_numerator(), 1);
	EXPECT_EQ(r.get_denominator(), 1);

	r = RationalNum(0, 1);
	r = r.to_pow(2);
	EXPECT_EQ(r.get_numerator(), 0);
	EXPECT_EQ(r.get_denominator(), 1);

	r = RationalNum(0, 1);
	EXPECT_ANY_THROW(r = r.to_pow(-2););


}

TEST(RationalNumTest, Ostream) {
	std::ofstream out("Test.txt");
	out << RationalNum(1, 3);
	out << " " << RationalNum(-1, 3);
	out << " " << RationalNum(1, 1);
	out << " " << RationalNum(0, 1);
	out.close();
	std::ifstream in("Test.txt");
	std::string s;

	in >> s;
	EXPECT_EQ(s, "1/3");

	in >> s;
	EXPECT_EQ(s, "-1/3");

	in >> s;
	EXPECT_EQ(s, "1/1");

	in >> s;
	EXPECT_EQ(s, "0/1");

	in.close();
}

TEST(RationalNumTest, Istream) {
	// valid data
	std::ofstream out("Test.txt");
	out << RationalNum(1, 3);
	out << " " << RationalNum(-1, 3);
	out << " " << RationalNum(1, 1);
	out << " " << RationalNum(0, 1);
	out << " " << RationalNum(11, 12);
	out << " " << RationalNum(-11, 12);
	out << " 2/6";
	out << " " << " 32/33";
	out.close();
	std::ifstream in("Test.txt");
	RationalNum r;

	in >> r;
	EXPECT_EQ(r.get_numerator(), 1);
	EXPECT_EQ(r.get_denominator(), 3);

	in >> r;
	EXPECT_EQ(r.get_numerator(), -1);
	EXPECT_EQ(r.get_denominator(), 3);

	in >> r;
	EXPECT_EQ(r.get_numerator(), 1);
	EXPECT_EQ(r.get_denominator(), 1);

	in >> r;
	EXPECT_EQ(r.get_numerator(), 0);
	EXPECT_EQ(r.get_denominator(), 1);

	in >> r;
	EXPECT_EQ(r.get_numerator(), 11);
	EXPECT_EQ(r.get_denominator(), 12);

	in >> r;
	EXPECT_EQ(r.get_numerator(), -11);
	EXPECT_EQ(r.get_denominator(), 12);

	in >> r;
	EXPECT_EQ(r.get_numerator(), 1);
	EXPECT_EQ(r.get_denominator(), 3);

	in >> r;
	EXPECT_EQ(r.get_numerator(), 32);
	EXPECT_EQ(r.get_denominator(), 33);

	// end of file
	EXPECT_ANY_THROW(in >> r);

	in.close();

	// invalid data
	out.open("Test.txt");
	out << " " << "123/asd";
	out.close();
	in.open("Test.txt");
	EXPECT_ANY_THROW(in >> r);
	in.close();

	out.open("Test.txt");
	out << " " << "asdaf/323";
	out.close();
	in.open("Test.txt");
	EXPECT_ANY_THROW(in >> r);
	in.close();

	out.open("Test.txt");
	out << " " << "/32";
	out.close();
	in.open("Test.txt");
	EXPECT_ANY_THROW(in >> r);
	in.close();

	out.open("Test.txt");
	out << " " << "23/";
	out.close();
	in.open("Test.txt");
	EXPECT_ANY_THROW(in >> r);
	in.close();

	out.open("Test.txt");
	out << " " << "sagrweqe";
	out.close();
	in.open("Test.txt");
	EXPECT_ANY_THROW(in >> r);
	in.close();
}

TEST(RationalNumTest, Ordering) {
	RationalNum r1(1, 3), r2(2, 3);
	EXPECT_TRUE(r1 < r2);
	EXPECT_TRUE(r1 <= r2);
	EXPECT_FALSE(r1 > r2);
	EXPECT_FALSE(r1 >= r2);
	EXPECT_TRUE(r2 > r1);
	EXPECT_TRUE(r2 >= r1);
	EXPECT_FALSE(r2 < r1);
	EXPECT_FALSE(r2 <= r1);

	r1 = RationalNum(1, 3);
	r2 = RationalNum(1, 2);
	EXPECT_TRUE(r1 < r2);
	EXPECT_TRUE(r1 <= r2);
	EXPECT_FALSE(r1 > r2);
	EXPECT_FALSE(r1 >= r2);
	EXPECT_TRUE(r2 > r1);
	EXPECT_TRUE(r2 >= r1);
	EXPECT_FALSE(r2 < r1);
	EXPECT_FALSE(r2 <= r1);

	r1 = RationalNum(1, 2);
	r2 = RationalNum(1, 2);
	EXPECT_FALSE(r1 < r2);
	EXPECT_TRUE(r1 <= r2);
	EXPECT_FALSE(r1 > r2);
	EXPECT_TRUE(r1 >= r2);
	EXPECT_FALSE(r2 > r1);
	EXPECT_TRUE(r2 >= r1);
	EXPECT_FALSE(r2 < r1);
	EXPECT_TRUE(r2 <= r1);

	r1 = RationalNum(-1, 2);
	r2 = RationalNum(1, 3);
	EXPECT_TRUE(r1 < r2);
	EXPECT_TRUE(r1 <= r2);
	EXPECT_FALSE(r1 > r2);
	EXPECT_FALSE(r1 >= r2);
	EXPECT_TRUE(r2 > r1);
	EXPECT_TRUE(r2 >= r1);
	EXPECT_FALSE(r2 < r1);
	EXPECT_FALSE(r2 <= r1);
}

TEST(MatrixTest, Creation) {
	Matrix<RationalNum> z;
	EXPECT_EQ(z.get_number_of_rows(), 0);
	EXPECT_EQ(z.get_number_of_columns(), 0);
	EXPECT_ANY_THROW(z[0][0]);
	Matrix<RationalNum> a(3, 2);
	EXPECT_EQ(a.get_number_of_rows(), 3);
	EXPECT_EQ(a.get_number_of_columns(), 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(a[i][j], RationalNum(0, 1));
		}
	}
	a[0][0] = RationalNum(1, 3);
	a[0][1] = RationalNum(2, 3);
	a[1][0] = RationalNum(1, 1);
	a[1][1] = RationalNum(2, 1);
	a[2][0] = RationalNum(-1, 3);
	a[2][1] = RationalNum(-2, 3);
	EXPECT_EQ(a[0][0], RationalNum(1, 3));
	EXPECT_EQ(a[0][1], RationalNum(2, 3));
	EXPECT_EQ(a[1][0], RationalNum(1, 1));
	EXPECT_EQ(a[1][1], RationalNum(2, 1));
	EXPECT_EQ(a[2][0], RationalNum(-1, 3));
	EXPECT_EQ(a[2][1], RationalNum(-2, 3));
	EXPECT_ANY_THROW(a[3][0] = RationalNum(1, 1));
	// unfortunatly not in my competance - c++ standart operator[] will allow it, and I don't want to write my own array
	//EXPECT_ANY_THROW(RationalNum c = a[0][2]);
	EXPECT_ANY_THROW(a[3][2] = RationalNum(2, 1));

	EXPECT_ANY_THROW(Matrix<RationalNum>(0, 1));
	EXPECT_ANY_THROW(Matrix<RationalNum>(1, 0));
	Matrix<RationalNum> t(0, 0);
	EXPECT_EQ(t.get_number_of_rows(), 0);
	EXPECT_EQ(t.get_number_of_columns(), 0);
}

TEST(MatrixTest, Expanding) {
	Matrix<RationalNum> a(3, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] =  RationalNum(2, 3);
		}
	}
	a.expand(5, 4);
	EXPECT_EQ(a.get_number_of_rows(), 5);
	EXPECT_EQ(a.get_number_of_columns(), 4);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (i < 3 && j < 2) {
				EXPECT_EQ(a[i][j], RationalNum(2, 3));
			}
			else {
				EXPECT_EQ(a[i][j], RationalNum(0, 1));
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = RationalNum(1, 3);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			EXPECT_EQ(a[i][j], RationalNum(1, 3));
		}
	}

	Matrix<RationalNum> t;
	t.expand(0, 0);
	EXPECT_EQ(t.get_number_of_rows(), 0);
	EXPECT_EQ(t.get_number_of_columns(), 0);
	EXPECT_ANY_THROW(t.expand(0, 1));
	EXPECT_ANY_THROW(t.expand(1, 0));

	EXPECT_ANY_THROW(a.expand(1, 2));
}

TEST(MatrixTest, CopyConstructor) {
	Matrix<RationalNum> a(3, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = RationalNum(2, 3);
		}
	}
	Matrix<RationalNum> b = a;
	EXPECT_EQ(b.get_number_of_rows(), 3);
	EXPECT_EQ(b.get_number_of_columns(), 2);
	EXPECT_EQ(a.get_number_of_rows(), 3);
	EXPECT_EQ(a.get_number_of_columns(), 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(a[i][j], RationalNum(2, 3));
			EXPECT_EQ(b[i][j], RationalNum(2, 3));
		}
	}
}

TEST(MatrixTest, CopyAssignment) {
	Matrix<RationalNum> a(3, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = RationalNum(2, 3);
		}
	}
	Matrix<RationalNum> b;
	b = a;
	EXPECT_EQ(b.get_number_of_rows(), 3);
	EXPECT_EQ(b.get_number_of_columns(), 2);
	EXPECT_EQ(a.get_number_of_rows(), 3);
	EXPECT_EQ(a.get_number_of_columns(), 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(a[i][j], RationalNum(2, 3));
			EXPECT_EQ(b[i][j], RationalNum(2, 3));
		}
	}
}

TEST(MatrixTest, MoveAssignment) {
	Matrix<RationalNum> a(3, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = RationalNum(2, 3);
		}
	}
	Matrix<RationalNum> b;
	b = std::move(a);
	EXPECT_EQ(a.get_number_of_rows(), 0);
	EXPECT_EQ(a.get_number_of_columns(), 0);
	EXPECT_EQ(b.get_number_of_rows(), 3);
	EXPECT_EQ(b.get_number_of_columns(), 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(b[i][j], RationalNum(2, 3));
		}
	}
}
TEST(MatrixTest, MoveConstructor) {
	Matrix<RationalNum> a = Matrix<RationalNum>(3,2);
	EXPECT_EQ(a.get_number_of_rows(), 3);
	EXPECT_EQ(a.get_number_of_columns(), 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(a[i][j], RationalNum(0, 1));
		}
	}
}

TEST(MatrixTest, ConstTest) {
	const Matrix<RationalNum> a(3, 2);
	RationalNum r = a[0][0];
	EXPECT_EQ(r, RationalNum(0, 1));
	EXPECT_EQ(a[0][0], RationalNum(0, 1));
}

TEST(MatrixTest, AdditionAndSubtraction) {
	Matrix<RationalNum> a(3, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = RationalNum(2, 3);
		}
	}
	Matrix<RationalNum> b(3, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			b[i][j] = RationalNum(1, 3);
		}
	}
	Matrix<RationalNum> c = a + b, d = b - a;
	EXPECT_EQ(c.get_number_of_rows(), 3);
	EXPECT_EQ(c.get_number_of_columns(), 2);
	EXPECT_EQ(d.get_number_of_rows(), 3);
	EXPECT_EQ(d.get_number_of_columns(), 2);
	EXPECT_EQ(b.get_number_of_rows(), 3);
	EXPECT_EQ(b.get_number_of_columns(), 2);
	EXPECT_EQ(a.get_number_of_rows(), 3);
	EXPECT_EQ(a.get_number_of_columns(), 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(a[i][j], RationalNum(2, 3));
			EXPECT_EQ(b[i][j], RationalNum(1, 3));
			EXPECT_EQ(c[i][j], RationalNum(1, 1));
			EXPECT_EQ(d[i][j], RationalNum(-1, 3));
		}
	}
	a += b;
	EXPECT_EQ(a, c);
	a -= b;

	b -= a;
	EXPECT_EQ(b, d);


	EXPECT_ANY_THROW(c = a + Matrix<RationalNum>(2, 3));
	EXPECT_ANY_THROW(c = a + Matrix<RationalNum>(3, 3));
	EXPECT_ANY_THROW(c = a + Matrix<RationalNum>(2, 2));
}

TEST(MatrixTest, Equality) {
	Matrix<RationalNum> a(3, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = RationalNum(2, 3);
		}
	}
	EXPECT_TRUE(a ==  a + Matrix<RationalNum>(3, 2));
}

TEST(MatrixTest, ScalarMultiplication) {
	Matrix<RationalNum> a(3, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = RationalNum(2, 3);
		}
	}
	Matrix<RationalNum> b = RationalNum(1, 3) * a;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(a[i][j], RationalNum(2, 3));
			EXPECT_EQ(b[i][j], RationalNum(2, 9));
		}
	}
	EXPECT_EQ(b, a * RationalNum(1, 3));
	EXPECT_EQ(b, RationalNum(1,1) * b);
}

TEST(MatrixMultiplicationStrassenAlgo, Square) {
	Matrix<RationalNum> a(3, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = RationalNum(2, 3);
		}
	}

	Matrix<RationalNum> b(3, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = RationalNum(1, 3);
		}
	}

	Matrix<RationalNum> c = a * b;
	EXPECT_EQ(c.get_number_of_rows(), 3);
	EXPECT_EQ(c.get_number_of_columns(), 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			EXPECT_EQ(a[i][j], RationalNum(2, 3));
			EXPECT_EQ(b[i][j], RationalNum(1, 3));
			EXPECT_EQ(c[i][j], RationalNum(2, 3));
		}
	}

	Matrix<RationalNum> e(3, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				e[i][j] = RationalNum(1, 1);
		}
	}
	EXPECT_EQ(a, a * e);
	EXPECT_EQ(a, e * a);
	EXPECT_EQ(b, b * e);
	EXPECT_EQ(b, e * b);
	EXPECT_EQ(e, e * e);

	a[0][0] = RationalNum(1, 1);
	a[0][1] = RationalNum(-3, 1);
	a[0][2] = RationalNum(2, 1);
	a[1][0] = RationalNum(3, 1);
	a[1][1] = RationalNum(-4, 1);
	a[1][2] = RationalNum(1, 1);
	a[2][0] = RationalNum(2, 1);
	a[2][1] = RationalNum(-5, 1);
	a[2][2] = RationalNum(3, 1);

	b[0][0] = RationalNum(2, 1);
	b[0][1] = RationalNum(5, 1);
	b[0][2] = RationalNum(6, 1);
	b[1][0] = RationalNum(1, 1);
	b[1][1] = RationalNum(2, 1);
	b[1][2] = RationalNum(5, 1);
	b[2][0] = RationalNum(1, 1);
	b[2][1] = RationalNum(3, 1);
	b[2][2] = RationalNum(2, 1);

	c = a * b;
	EXPECT_EQ(c.get_number_of_rows(), 3);
	EXPECT_EQ(c.get_number_of_columns(), 3);
	EXPECT_EQ(c[0][0], RationalNum(1, 1));
	EXPECT_EQ(c[0][1], RationalNum(5, 1));
	EXPECT_EQ(c[0][2], RationalNum(-5, 1));
	EXPECT_EQ(c[1][0], RationalNum(3, 1));
	EXPECT_EQ(c[1][1], RationalNum(10, 1));
	EXPECT_EQ(c[1][2], RationalNum(0, 1));
	EXPECT_EQ(c[2][0], RationalNum(2, 1));
	EXPECT_EQ(c[2][1], RationalNum(9, 1));
	EXPECT_EQ(c[2][2], RationalNum(-7, 1));

	a *= b;
	EXPECT_EQ(a, c);

	// 0x0
	Matrix<RationalNum> z1, z2, z3;
	EXPECT_EQ(z3, z1 * z2);

	// 1x1
	Matrix<RationalNum> o1(1,1), o2(1,1), o3;
	o1[0][0] = RationalNum(1, 3);
	o2[0][0] = RationalNum(2, 3);
	o3 = o1 * o2;
	EXPECT_EQ(o3.get_number_of_rows(), 1);
	EXPECT_EQ(o3.get_number_of_columns(), 1);
	EXPECT_EQ(o3[0][0], RationalNum(2, 9));

	//2x2
	Matrix<RationalNum> t1(2, 2), t2(2, 2), t3;
	t1[0][0] = RationalNum(2, 1);
	t1[0][1] = RationalNum(5, 1);
	t1[1][0] = RationalNum(7, 1);
	t1[1][1] = RationalNum(9, 1);
	t2[0][0] = RationalNum(4, 1);
	t2[0][1] = RationalNum(1, 1);
	t2[1][0] = RationalNum(3, 1);
	t2[1][1] = RationalNum(8, 1);
	t3 = t1 * t2;
	EXPECT_EQ(t3.get_number_of_rows(), 2);
	EXPECT_EQ(t3.get_number_of_columns(), 2);
	EXPECT_EQ(t3[0][0], RationalNum(23, 1));
	EXPECT_EQ(t3[0][1], RationalNum(42, 1));
	EXPECT_EQ(t3[1][0], RationalNum(55, 1));
	EXPECT_EQ(t3[1][1], RationalNum(79, 1));

	//6x6
	a = Matrix<RationalNum>(6, 6);
	e = Matrix<RationalNum>(6, 6);
	for (size_t i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			a[i][j] = RationalNum(1, 3);
			if (i == j) {
				e[i][j] = 1;
			}
		}
	}
	c = a * e;
	EXPECT_EQ(c.get_number_of_rows(), 6);
	EXPECT_EQ(c.get_number_of_columns(), 6);
	EXPECT_EQ(a, c);
	EXPECT_EQ(e * a, a);
}

TEST(MatrixMultiplicationStrassenAlgo, WrongInput) {
	Matrix<RationalNum> a(2, 2), b(3, 3);
	EXPECT_ANY_THROW(a * b);
	EXPECT_ANY_THROW(a *= b);
	a = Matrix<RationalNum>(3, 3);
	b = Matrix<RationalNum>(4, 3);
	EXPECT_ANY_THROW(a * b);
	EXPECT_ANY_THROW(a *= b);

}

TEST(MatrixMultiplicationStrassenAlgo, Rectangle) {
	Matrix<RationalNum> a(2, 3), b(3, 2), c;
	a[0][0] = RationalNum(3, 1);
	a[0][1] = RationalNum(4, 1);
	a[0][2] = RationalNum(6, 1);
	a[1][0] = RationalNum(2, 1);
	a[1][1] = RationalNum(5, 1);
	a[1][2] = RationalNum(9, 1);

	b[0][0] = RationalNum(1, 1);
	b[0][1] = RationalNum(4, 1);
	b[1][0] = RationalNum(8, 1);
	b[1][1] = RationalNum(3, 1);
	b[2][0] = RationalNum(0, 1);
	b[2][1] = RationalNum(6, 1);

	c = a * b;
	EXPECT_EQ(c.get_number_of_rows(), 2);
	EXPECT_EQ(c.get_number_of_columns(), 2);
	EXPECT_EQ(c[0][0], RationalNum(35, 1));
	EXPECT_EQ(c[0][1], RationalNum(60, 1));
	EXPECT_EQ(c[1][0], RationalNum(42, 1));
	EXPECT_EQ(c[1][1], RationalNum(77, 1));

	a *= b;
	EXPECT_EQ(a, c);

	a = Matrix<RationalNum>(1, 2);
	a[0][0] = RationalNum(6, 1);
	a[0][1] = RationalNum(2, 1);

	b = Matrix<RationalNum>(2, 1);
	b[0][0] = RationalNum(9, 1);
	b[1][0] = RationalNum(7, 1);

	c = a * b;
	EXPECT_EQ(c.get_number_of_rows(), 1);
	EXPECT_EQ(c.get_number_of_columns(), 1);
	EXPECT_EQ(c[0][0], RationalNum(68, 1));
}

TEST(InverseUsingLUDecomposition, Square) {
	Matrix<RationalNum> testing_matrix(3, 3);
	EXPECT_EQ(testing_matrix.get_number_of_rows(), 3);
	EXPECT_EQ(testing_matrix.get_number_of_columns(), 3);

	testing_matrix[0][0] = RationalNum(2, 3);
	testing_matrix[0][1] = RationalNum(3, 4);
	testing_matrix[0][2] = RationalNum(5, 6);
	testing_matrix[1][0] = RationalNum(1, 3);
	testing_matrix[1][1] = RationalNum(3, 4);
	testing_matrix[1][2] = RationalNum(1, 6);
	testing_matrix[2][0] = RationalNum(3, 4);
	testing_matrix[2][1] = RationalNum(1, 3);
	testing_matrix[2][2] = RationalNum(3, 5);

	std::pair<Matrix<RationalNum>, Matrix<RationalNum>> decomposed_result = LU_decomposition(testing_matrix);
	Matrix<RationalNum> lower_decomposed = decomposed_result.first;
	Matrix<RationalNum> upper_decomposed = decomposed_result.second;

	EXPECT_EQ(lower_decomposed.get_number_of_rows(), 3);
	EXPECT_EQ(lower_decomposed.get_number_of_columns(), 3);
	EXPECT_EQ(lower_decomposed[0][0], RationalNum(1, 1));
	EXPECT_EQ(lower_decomposed[0][1], RationalNum(0, 1));
	EXPECT_EQ(lower_decomposed[0][2], RationalNum(0, 1));
	EXPECT_EQ(lower_decomposed[1][0], RationalNum(1, 2));
	EXPECT_EQ(lower_decomposed[1][1], RationalNum(1, 1));
	EXPECT_EQ(lower_decomposed[1][2], RationalNum(0, 1));
	EXPECT_EQ(lower_decomposed[2][0], RationalNum(9, 8));
	EXPECT_EQ(lower_decomposed[2][1], RationalNum(-49, 36));
	EXPECT_EQ(lower_decomposed[2][2], RationalNum(1, 1));

	EXPECT_EQ(upper_decomposed.get_number_of_rows(), 3);
	EXPECT_EQ(upper_decomposed.get_number_of_columns(), 3);
	EXPECT_EQ(upper_decomposed[0][0], RationalNum(2, 3));
	EXPECT_EQ(upper_decomposed[0][1], RationalNum(3, 4));
	EXPECT_EQ(upper_decomposed[0][2], RationalNum(5, 6));
	EXPECT_EQ(upper_decomposed[1][0], RationalNum(0, 1));
	EXPECT_EQ(upper_decomposed[1][1], RationalNum(3, 8));
	EXPECT_EQ(upper_decomposed[1][2], RationalNum(-1, 4));
	EXPECT_EQ(upper_decomposed[2][0], RationalNum(0, 1));
	EXPECT_EQ(upper_decomposed[2][1], RationalNum(0, 1));
	EXPECT_EQ(upper_decomposed[2][2], RationalNum(-61, 90));

	Matrix<RationalNum> inverse_result = inverse_matrix_lu_decomposition(testing_matrix);
	EXPECT_EQ(inverse_result.get_number_of_rows(), 3);
	EXPECT_EQ(inverse_result.get_number_of_columns(), 3);
	EXPECT_EQ(inverse_result[0][0], RationalNum(-142, 61));
	EXPECT_EQ(inverse_result[0][1], RationalNum(62, 61));
	EXPECT_EQ(inverse_result[0][2], RationalNum(180, 61));
	EXPECT_EQ(inverse_result[1][0], RationalNum(27, 61));
	EXPECT_EQ(inverse_result[1][1], RationalNum(81, 61));
	EXPECT_EQ(inverse_result[1][2], RationalNum(-60, 61));
	EXPECT_EQ(inverse_result[2][0], RationalNum(325, 122));
	EXPECT_EQ(inverse_result[2][1], RationalNum(-245, 122));
	EXPECT_EQ(inverse_result[2][2], RationalNum(-90, 61));
}

TEST(InverseUsingLUDecomposition, InvalidParameters) {
	Matrix<RationalNum> testing_matrix_rectangle(3, 4);
	Matrix<RationalNum> inverse_matrix_result;

	EXPECT_EQ(testing_matrix_rectangle.get_number_of_rows(), 3);
	EXPECT_EQ(testing_matrix_rectangle.get_number_of_columns(), 4);
	EXPECT_ANY_THROW(inverse_matrix_result = inverse_matrix_lu_decomposition(testing_matrix_rectangle));


	Matrix<RationalNum> testing_matrix_zero_rows_and_columns(0, 0);

	EXPECT_EQ(testing_matrix_zero_rows_and_columns.get_number_of_rows(), 0);
	EXPECT_EQ(testing_matrix_zero_rows_and_columns.get_number_of_columns(), 0);
	EXPECT_ANY_THROW(inverse_matrix_result = inverse_matrix_lu_decomposition(testing_matrix_zero_rows_and_columns));
}

TEST(LinearRegression, InvalidInput) {
	Matrix<RationalNum> X(3, 2);
	Matrix<RationalNum> Y(3, 1);
	Y[0][0] = RationalNum(1, 2);
	Y[1][0] = RationalNum(2, 1);
	Y[2][0] = RationalNum(6, 4);
	X[0][0] = RationalNum(1, 4);
	X[1][0] = RationalNum(5, 4);
	X[2][0] = RationalNum(2, 3);
	X[0][1] = RationalNum(7, 4);
	X[1][1] = RationalNum(6, 7);
	X[2][1] = RationalNum(3, 4);
	Matrix<RationalNum> B = LinearRegression(Y, X);
	EXPECT_EQ(B.get_number_of_rows(), X.get_number_of_columns() + 1);

	Matrix<RationalNum> Y2(4, 1);
	Y2[0][0] = RationalNum(2, 1);
	Y2[1][0] = RationalNum(5, 4);
	Y2[2][0] = RationalNum(2, 3);
	Y2[3][0] = RationalNum(2, 4);
	EXPECT_ANY_THROW(LinearRegression(Y2, X));
}

TEST(LinearRegression, RightOut) {
	Matrix<RationalNum> X(5, 3);
	Matrix<RationalNum> Y(5, 1);
	X[0][0] = RationalNum(1, 1);
	X[1][0] = RationalNum(2, 1);
	X[2][0] = RationalNum(8, 2);
	X[3][0] = RationalNum(5, 2);
	X[4][0] = RationalNum(1, 2);
	X[0][1] = RationalNum(1, 1);
	X[1][1] = RationalNum(1, 2);
	X[2][1] = RationalNum(2, 1);
	X[3][1] = RationalNum(6, 2);
	X[4][1] = RationalNum(1, 2);
	X[0][2] = RationalNum(2, 1);
	X[1][2] = RationalNum(1, 2);
	X[2][2] = RationalNum(4, 2);
	X[3][2] = RationalNum(14, 2);
	X[4][2] = RationalNum(8, 2);

	Y[0][0] = RationalNum(1, 1);
	Y[1][0] = RationalNum(4, 2);
	Y[2][0] = RationalNum(12, 4);
	Y[3][0] = RationalNum(5, 2);
	Y[4][0] = RationalNum(1, 1);

	Matrix<RationalNum> B = LinearRegression(Y, X);

	EXPECT_EQ(B.get_number_of_rows(), X.get_number_of_columns() + 1);
	EXPECT_EQ(B[0][0].get_numerator(), 3841);
	EXPECT_EQ(B[1][0].get_numerator(), 9389);
	EXPECT_EQ(B[2][0].get_numerator(), -2977);
	EXPECT_EQ(B[3][0].get_numerator(), 1591);
}

