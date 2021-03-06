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

    std::vector<double> result;
    r = polyfit(testData, 1, result);
    EXPECT_NEAR(result[0], 1, 0.0001);
    EXPECT_NEAR(result[1], 0, 0.0001);
}

TEST(LEAST_SQUQRE, Sample2) {
    std::vector<std::pair<double, double>> testData = {{0.1,1.1},{0.1,1.1},{0.2,1.9},{0.3,3.1},{0.4,3.9}};
    double a,b;
    int r = least_square(testData, a, b);
    EXPECT_EQ(r, 0);
    EXPECT_NEAR(a, 9.52941, 0.0001);
    EXPECT_NEAR(b, 0.12353, 0.0001);

    std::vector<double> result;
    r = polyfit(testData, 1, result);
    EXPECT_NEAR(result[0], 9.52941, 0.0001);
    EXPECT_NEAR(result[1], 0.12353, 0.0001);

    r = polyfit(testData, 2, result);
    EXPECT_NEAR(result[0], 0.51282, 0.0001);
    EXPECT_NEAR(result[1], 9.28205, 0.0001);
    EXPECT_NEAR(result[2], 0.14615, 0.0001);

    r = polyfit(testData, 3, result);
    EXPECT_NEAR(result[0], -133.3333, 0.0001);
    EXPECT_NEAR(result[1], 100.0000, 0.0001);
    EXPECT_NEAR(result[2], -12.6667, 0.0001);
    EXPECT_NEAR(result[3], 1.5000, 0.0001);
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

    std::vector<double> result;
    r = polyfit(testData, 1, result);
    EXPECT_NEAR(result[0], 2.79371, 0.0001);
    EXPECT_NEAR(result[1], -0.15400, 0.0001);
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

    std::vector<double> result;
    r = polyfit(testData, 1, result);
    EXPECT_NEAR(result[0], 0, 0.0001);
    EXPECT_NEAR(result[1], 1, 0.0001);
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

    std::vector<double> result;
    r = polyfit(testData, 1, result);
    EXPECT_NEAR(result[0], -1, 0.0001);
    EXPECT_NEAR(result[1], 1, 0.0001);
}


TEST(LEAST_SQUQRE, Sample6) {
    std::vector<std::pair<double, double>> testData = {
        {0.00000,0.00000},{1.39626,0.98481},{2.79253,0.34202},{4.18879,-0.86603},{5.58505,-0.64279},
        {6.98132,0.64279},{8.37758,0.86603},{9.77384,-0.34202},{11.17011,-0.98481},{12.56637,-0.00000}
    };

    std::vector<double> result;
    int r = polyfit(testData, 7, result);
    EXPECT_NEAR(result[0], -0.000062606, 0.0001);
    EXPECT_NEAR(result[1],  0.002753569, 0.0001);
    EXPECT_NEAR(result[2], -0.046384694, 0.0001);
    EXPECT_NEAR(result[3],  0.370152528, 0.0001);
    EXPECT_NEAR(result[4], -1.380829644, 0.0001);
    EXPECT_NEAR(result[5],  1.908384839, 0.0001);
    EXPECT_NEAR(result[6], -0.114145411, 0.0001);
    EXPECT_NEAR(result[7],  0.000197271, 0.0001);
}
