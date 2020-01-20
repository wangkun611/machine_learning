#include "gtest/gtest.h"
#include "least_square.h"

TEST(LEAST_SQUQRE, ReturnError) {
    std::vector<std::pair<double, double>> testData;
    double a,b;
    int r1 = least_square(testData, a, b);
    EXPECT_EQ(r1, 1);

    testData = { {1,1} };
    int r2 = least_square(testData, a, b);
    EXPECT_EQ(r2, 1);
}

TEST(LEAST_SQUQRE, Sample1) {
    std::vector<std::pair<double, double>> testData = {{0,0},{1,1},{2,2},{3,3}};
    double a,b;
    int r = least_square(testData, a, b);
    EXPECT_EQ(r, 0);
    EXPECT_NEAR(a, 1, 0.0001);
    EXPECT_NEAR(b, 0, 0.0001);
}

TEST(LEAST_SQUQRE, Sample2) {
    std::vector<std::pair<double, double>> testData = {{0.1,1.1},{0.1,1.1},{0.2,1.9},{0.3,3.1},{0.4,3.9}};
    double a,b;
    int r = least_square(testData, a, b);
    EXPECT_EQ(r, 0);
    EXPECT_NEAR(a, 9.52941, 0.0001);
    EXPECT_NEAR(b, 0.12353, 0.0001);
}

TEST(LEAST_SQUQRE, Sample3) {
    std::vector<std::pair<double, double>> testData = {
        {0.5,1.75},{1.0,2.45},{1.5,3.81},{2.0,4.80},{2.5,7.00},{3.0,8.60}
    };
    double a,b;
    int r = least_square(testData, a, b);
    EXPECT_EQ(r, 0);
    EXPECT_NEAR(a, 2.79371, 0.0001);
    EXPECT_NEAR(b, -0.15400, 0.0001);
}

TEST(LEAST_SQUQRE, Sample4) {
    std::vector<std::pair<double, double>> testData = {
        {1,1},{2,1},{3,1},{4,1},{5,1},{6,1}
    };
    double a,b;
    int r = least_square(testData, a, b);
    EXPECT_EQ(r, 0);
    EXPECT_NEAR(a, 0, 0.0001);
    EXPECT_NEAR(b, 1, 0.0001);
}

TEST(LEAST_SQUQRE, Sample5) {
    std::vector<std::pair<double, double>> testData = {
        {0,1},{1,0}
    };
    double a,b;
    int r = least_square(testData, a, b);
    EXPECT_EQ(r, 0);
    EXPECT_NEAR(a, -1, 0.0001);
    EXPECT_NEAR(b, 1, 0.0001);
}
