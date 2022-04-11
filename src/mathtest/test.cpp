#include "gtest/gtest.h"
#include "steammath.h"

#include <iostream>
#include <string>

using namespace sm;

class testCase1 : public :: testing ::Test{
protected:
    virtual void SetUp(){
        a = 1.5;
        b = 1.5;
    }
    double a;
    double b;
};

class testCase2 : public :: testing ::Test{
protected:
    virtual void SetUp(){
        a = 4.0;
        b = 8.0;
    }
    double a;
    double b;
};


TEST_F(testCase1, addTest){
    EXPECT_TRUE(SteamMath :: sum(a, b) == 3.0);
}

TEST_F(testCase1, subTest){
    EXPECT_TRUE(SteamMath :: sub(a, b) == 0.0);
}

TEST_F(testCase1, mulTest){
    EXPECT_TRUE(SteamMath :: mul(a, b) == 2.25);
    EXPECT_TRUE(SteamMath :: mul(a, 0.0) == 0.0);
}

TEST_F(testCase1, divTest){
    EXPECT_TRUE(SteamMath :: div(a, b) == 1);
}

TEST_F(testCase2, factTest){
    EXPECT_TRUE(SteamMath :: fact(a) == 24);
    EXPECT_TRUE(SteamMath :: fact(b) == 1);
    EXPECT_THROW(SteamMath :: fact(-1), sm::PositiveNonZeroNumberRequired);
}

TEST_F(testCase1, powTest){
    EXPECT_TRUE(SteamMath :: pow(a, 2) == 2.25);
}

TEST_F(testCase2, rootTest){
    EXPECT_TRUE(SteamMath :: root(a, 2.0) == 2);
    EXPECT_TRUE(SteamMath :: root(b, 3.0) == 2);
}

TEST_F(testCase2, divTest){
    EXPECT_THROW(SteamMath :: div(a, 0.0), sm :: DivisionByZero);
}

TEST_F(testCase2, powTest){
    EXPECT_TRUE(SteamMath :: pow(a, 0.0) == 1);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
