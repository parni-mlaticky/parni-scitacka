#include "gtest/gtest.h"
#include "steammath.h"

#include <iostream>
#include <string>

#define EPSILON 1e-15

using namespace sm;

class doubles : public :: testing ::Test{
protected:
	virtual void SetUp(){
		a = 1.5;
		b = 1.5;
	}
	double a;
	double b;
};

class integers : public :: testing ::Test{
protected:
	virtual void SetUp(){
		a = 4;
		b = 8;
	}
	int a;
	int b;
};


TEST_F(doubles, addTest){
	EXPECT_TRUE(SteamMath::sum(a, b) == 3.0);
	EXPECT_TRUE(SteamMath::sum(a, -5) == -3.5);
}

TEST_F(doubles, subTest){
EXPECT_TRUE(SteamMath::sub(a, b) == 0.0);
EXPECT_TRUE(SteamMath::sub(a, -5) == 6.5);
}

TEST_F(doubles, mulTest){
	EXPECT_TRUE(SteamMath::mul(a, b) == 2.25);
	EXPECT_TRUE(SteamMath::mul(a, 0.0) == 0.0);
	EXPECT_TRUE(SteamMath::mul(a, -2) == -3);
}

TEST_F(doubles, divTest){
	EXPECT_TRUE(SteamMath::div(a, b) == 1);
	EXPECT_TRUE(SteamMath::div(a, -1) == -a);
	EXPECT_THROW(SteamMath::div(a, 0.0), sm::DivisionByZero);
}

TEST_F(integers, factTest){
	EXPECT_TRUE(SteamMath::fact(a) == 24);
	EXPECT_TRUE(SteamMath::fact(b) == 1);
	EXPECT_THROW(SteamMath::fact(-1), sm::OutputUndefined);
}

TEST_F(doubles, powTest){
	EXPECT_TRUE(SteamMath::pow(a, 2) == 2.25);
	EXPECT_TRUE(SteamMath::pow(a, 0.0) == 1);
}

TEST_F(integers, rootTest){
	EXPECT_TRUE(SteamMath::root(a, 2) == 2);
	EXPECT_TRUE(SteamMath::root(b, 3) == 2);
	double result = SteamMath::root(b, -2);
	EXPECT_TRUE(std::abs(result) - 0.353553390593273 < EPSILON);
	EXPECT_THROW(SteamMath::root(a, 0), sm::OutputUndefined);
	EXPECT_THROW(SteamMath::root(-4, 2), sm::OutputUndefined);
}

TEST_F(integers, rootTest){
	auto rootVector = std::vector<double>;
	rootVector = SteamMath::quadRoot(1, 3, 2);
	EXPECT_TRUE(rootVector[0] == -1.0 && rootVector[1] == -2.0);
	rootVector = SteamMath::quadRoot(-2.5, 2.5, 4.5);
	EXPECT_TRUE(std::abs(rootVector[0]) - (-0.931782106327635) < EPSILON);
	EXPECT_TRUE(std::abs(rootVector[1]) - 1.931782106327635 < EPSILON);
	EXPECT_THROW(SteamMath::quadRoot(3.0, 1.0, 5.0), sm::OutputUndefined);
}


int main(int argc, char **argv) {
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
