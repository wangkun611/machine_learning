#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;
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
    double n = (double)data.size();
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

int polyfit(const std::vector<std::pair<double, double>>& data, size_t n, vector<double>& result)
{
    double *matrix = (double*)malloc(sizeof(double)*(n + 1)*(n + 2));
    if (!matrix) {
        return 1;
    }

    const size_t m = n + 2;
    n = n + 1;
    for (size_t i = 0; i < n*m; i++) {
        matrix[i] = 0;
    }

    std::for_each(data.begin(), data.end(), [=,&matrix](auto &v) {
        for (size_t i = 0; i < n; i++) {
            double x_pow_i = std::pow(v.first, i);
            matrix[i] += x_pow_i;
            if (i != 0) {
                matrix[(i+1)*m - 2] += std::pow(v.first, i + n - 1);
            }
            matrix[(i+1)*m - 1] += v.second*x_pow_i;
        }
    });
    for (size_t i = 1; i < n; i++) {
        for (size_t j = 0; j < m - 2; j++) {
            matrix[i*m + j] = matrix[(i-1)*m + j + 1];
        }
    }

    for (size_t i = 0; i < n - 1; i++) {
        for (size_t i2 = i + 1; i2 < n; i2++) {
            double frac = matrix[i*m + i]/matrix[i2*m + i];
            for (size_t j = i; j < m; j++) {
                matrix[i2*m + j] = matrix[i*m + j] - matrix[i2*m + j]*frac;
            }
        }
    }

    for (int64_t i = n - 1; i >= 0; i--) {
        for (int64_t i2 = i - 1; i2 >= 0; i2--)  {
            if (fabs(matrix[i2*m + i]) < 1e-20) {
                continue;
            }
            
            double frac = matrix[i*m + i]/matrix[i2*m + i];
            for (int64_t j = m - 1; j >= i2; j--) {
                matrix[i2*m + j] = matrix[i*m + j] - matrix[i2*m + j]*frac;
            }
            
        }
        matrix[i*m + m - 1] = matrix[i*m + m - 1]/matrix[i*m + i];
        matrix[i*m + i] = 1;
    }

    result.clear();
    result.reserve(n);
    for (int64_t i = n - 1; i >= 0; i--) {
        result.push_back(matrix[i*m + m - 1]);
    }

    free(matrix);
    return 0;
}
