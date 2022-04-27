#include "gtest/gtest.h"
#include "steammath.h"

#include <iostream>
#include <string>
#include <cmath>

#define EPSILON 1e-15
#define _USE_MATH_DEFINES

using namespace sm;

TEST(basic, addTest){
	EXPECT_TRUE(SteamMath::sum(1.5, 1.5) == 3.0);
	EXPECT_TRUE(SteamMath::sum(1.5, -5) == -3.5);
	EXPECT_TRUE(SteamMath::sum(0.25, 0.25) == 0.5);
	EXPECT_TRUE(SteamMath::sum(0.1, 0.4) == 0.5);
}

TEST(basic, subTest){
	EXPECT_TRUE(SteamMath::sub(1.5, 1.5) == 0.0);
	EXPECT_TRUE(SteamMath::sub(1.5, -5) == 6.5);
}

TEST(basic, mulTest){
	EXPECT_TRUE(SteamMath::mul(1.5, 1.5) == 2.25);
	EXPECT_TRUE(SteamMath::mul(1.5, 0.0) == 0.0);
	EXPECT_TRUE(SteamMath::mul(1.5, -2) == -3);
}

TEST(basic, divTest){
	EXPECT_TRUE(SteamMath::div(1.5, 1.5) == 1);
	EXPECT_TRUE(SteamMath::div(1.5, -1) == -1.5);
	EXPECT_THROW(SteamMath::div(1.5, 0.0), sm::DivisionByZero);
}

TEST(advanced, factTest){
	EXPECT_TRUE(SteamMath::fact(4) == 24);
	EXPECT_TRUE(SteamMath::fact(8) == 40320);
	EXPECT_THROW(SteamMath::fact(-1), sm::OutputUndefined);
}

TEST(advanced, powTest){
	EXPECT_TRUE(SteamMath::pow(1.5, 2) == 2.25);
	EXPECT_TRUE(SteamMath::pow(1.5, 0.0) == 1);
}

TEST(advanced, rootTest){
	EXPECT_TRUE(SteamMath::root(4, 2) == 2);
	EXPECT_TRUE(SteamMath::root(8, 3) == 2);
	double result = SteamMath::root(8, -2);
	EXPECT_TRUE(std::abs(result) - 0.353553390593273 < EPSILON);
	EXPECT_THROW(SteamMath::root(4, 0), sm::OutputUndefined);
	EXPECT_THROW(SteamMath::root(-4, 2), sm::OutputUndefined);
}

TEST(advanced, quadRootTest){
	std::vector<double> rootVector;
	rootVector = SteamMath::quadRoot(1, 3, 2);
	EXPECT_TRUE(rootVector.at(0) == -1.0 && rootVector.at(1) == -2.0);
	rootVector = SteamMath::quadRoot(-2.5, 2.5, 4.5);
	EXPECT_TRUE(std::abs(rootVector.at(0) - (-0.931782106327635)) < EPSILON);
	EXPECT_TRUE(std::abs(rootVector.at(1) - 1.931782106327635) < EPSILON);
	rootVector = SteamMath::quadRoot(0, 3, 3);
	EXPECT_TRUE(rootVector.at(0) == -1.0);
	EXPECT_TRUE(rootVector.at(1) == -1.0);
	rootVector = SteamMath::quadRoot(1.0, 0, -1.0);
	EXPECT_TRUE(rootVector.at(0) == -1.0);
	EXPECT_TRUE(rootVector.at(1) == 1.0);
	rootVector = SteamMath::quadRoot(2, 4, 0);
	EXPECT_TRUE(rootVector.at(0) == 0.0);
	EXPECT_TRUE(rootVector.at(1) == -2.0);
	rootVector = SteamMath::quadRoot(3, 0, 0);
	EXPECT_TRUE(rootVector.at(0) == 0.0);
	EXPECT_TRUE(rootVector.at(1) == 0.0);

	EXPECT_THROW(SteamMath::quadRoot(0, 0, 3), sm::OutputUndefined);
	EXPECT_THROW(SteamMath::quadRoot(0, 0, 0), sm::OutputUndefined);
	EXPECT_THROW(SteamMath::quadRoot(3.0, 1.0, 5.0), sm::OutputUndefined);
}

TEST(goniometric, sineTest){
	EXPECT_TRUE(std::abs(SteamMath::sin(1) - 0.841470984807896) < EPSILON);
	EXPECT_TRUE(std::abs(SteamMath::sin(M_PI)) < EPSILON);
	EXPECT_TRUE(SteamMath::sin(0) == 0);
	EXPECT_TRUE(std::abs(SteamMath::sin(-1) - (-0.841470984807896)) < EPSILON);
}

TEST(goniometric, cosine){
	EXPECT_TRUE(std::abs(SteamMath::cos(1) - 0.5403023058681397) < EPSILON);
	EXPECT_TRUE(std::abs(SteamMath::cos(M_PI) - (-1)) < EPSILON);
	EXPECT_TRUE(SteamMath::cos(0) == 1);
	EXPECT_TRUE(std::abs(SteamMath::cos(-1) - 0.5403023058681397) < EPSILON);
}

TEST(goniometric, tangent){
	EXPECT_TRUE(std::abs(SteamMath::tan(1) - 1.557407724654902) < EPSILON);
	EXPECT_TRUE(std::abs(SteamMath::tan(M_PI)) < EPSILON);
	EXPECT_TRUE(std::abs(SteamMath::tan(0)) < EPSILON);
	EXPECT_TRUE(std::abs(SteamMath::tan(-1) - (-1.557407724654902)) < EPSILON);

	EXPECT_THROW(SteamMath::tan(M_PI_2), sm::OutputUndefined);
}

TEST(goniometric, cotangent){
	EXPECT_TRUE(std::abs(SteamMath::cotan(1) - 0.642092615934330) < EPSILON);
	EXPECT_TRUE(std::abs(SteamMath::cotan(-1) - (-0.642092615934330)) < EPSILON);

	EXPECT_THROW(SteamMath::cotan(0), sm::OutputUndefined);
}

int main(int argc, char **argv) {
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
