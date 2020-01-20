#include <vector>
#include <algorithm>
#include <numeric>
/*
 * 根据 data 提供的观测数据，使用最小二乘法计算线性函数的a和b
 * y = ax + b
 * @return
 */
int least_square(const std::vector<std::pair<double, double>>& data, double& a, double& b)
{
    if (data.size() <= 1) {
        return 1;
    }
    
    double sum_x_square = 0;
    double sum_x = 0;
    double sum_xy = 0;
    double sum_y = 0;
    double n = data.size();
    std::for_each(data.begin(), data.end(), [&sum_x_square,&sum_x,&sum_xy,&sum_y](auto& v) {
        sum_x_square += v.first*v.first;
        sum_x += v.first;
        sum_xy += v.first*v.second;
        sum_y += v.second;
    });

    double a_deno = sum_x-n*sum_x_square/sum_x;
    double b_deno = n - sum_x*sum_x/sum_x_square;
    if (a_deno == 0.0 || b_deno == 0.0) {
        return 2;
    }

    a = (sum_y - sum_xy*n/sum_x)/a_deno;
    b = (sum_y - sum_x*sum_xy/sum_x_square)/b_deno;
    return 0;
}
