#include <vector>

/*
 * 根据 data 提供的观测数据，使用最小二乘法计算线性函数的a和b
 * y = ax + b
 */
int least_square(const std::vector<std::pair<double, double>>& data, double& a, double& b);

int polyfit(const std::vector<std::pair<double, double>>& data, size_t n, std::vector<double>& result);
