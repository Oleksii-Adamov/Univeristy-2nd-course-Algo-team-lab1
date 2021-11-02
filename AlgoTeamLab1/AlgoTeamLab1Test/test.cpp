#include "pch.h"
#include "../AlgoTeamLab1/RationalNum.h"
#include "../AlgoTeamLab1/RationalNum.cpp"
#include <fstream>
// clone
#include "../AlgoTeamLab1/Matrix.h"

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

// needed operator+ to test
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