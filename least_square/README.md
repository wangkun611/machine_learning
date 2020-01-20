# 最小二乘法学习笔记 #

$$ \bigg(\sum_{i=1}^n\begin{bmatrix} x_i^2 & x_i\\ x_i & 1 \end{bmatrix} \bigg)\begin{bmatrix} a \\ b \end{bmatrix} = \bigg(\sum_{i=1}^n\begin{bmatrix} x_iy_i \\ y_i \end{bmatrix} \bigg)\\ $$  (1)

$$ \sum_{i=1}^n\big(x_i^2\big)a + \sum_{i=1}^n\big(x_i\big) b = \sum_{i=1}^nx_iy_i $$ (2)
$$ \sum_{i=1}^n\big(x_i\big)a + nb = \sum_{i=1}^ny_i \\ $$  (3)

公式(2)乘以：$\frac{n}{\sum_{i=1}^n\big(x_i\big)}$

$$ \frac{n}{\sum_{i=1}^n\big(x_i\big)}\sum_{i=1}^n\big(x_i^2\big)a+nb= \frac{n}{\sum_{i=1}^n\big(x_i\big)}\sum_{i=1}^nx_iy_i $$ (4)

公示(3) - 公示(4) 消除 b 的系数:

$$(\sum_{i=1}^n\big(x_i\big)-\frac{n}{\sum_{i=1}^n\big(x_i\big)}\sum_{i=1}^n\big(x_i^2\big))a=\sum_{i=1}^ny_i-\frac{n}{\sum_{i=1}^n\big(x_i\big)}\sum_{i=1}^nx_iy_i$$

$$a=\frac{\sum_{i=1}^ny_i-\frac{n}{\sum_{i=1}^n\big(x_i\big)}\sum_{i=1}^nx_iy_i}{\sum_{i=1}^n\big(x_i\big)-\frac{n}{\sum_{i=1}^n\big(x_i\big)}\sum_{i=1}^n\big(x_i^2\big)}$$ (5)

公式(2)乘以：$\frac{\sum_{i=1}^n\big(x_i\big)}{\sum_{i=1}^n\big(x_i^2\big)}$

$$\sum_{i=1}^n\big(x_i\big)a + \frac{\sum_{i=1}^n\big(x_i\big)}{\sum_{i=1}^n\big(x_i^2\big)}\sum_{i=1}^n\big(x_i\big) b = \frac{\sum_{i=1}^n\big(x_i\big)}{\sum_{i=1}^n\big(x_i^2\big)}\sum_{i=1}^nx_iy_i$$ (6)

公示(3) - 公示(6) 消除 a 的系数:

$$(n-\frac{\sum_{i=1}^n\big(x_i\big)}{\sum_{i=1}^n\big(x_i^2\big)}\sum_{i=1}^n\big(x_i\big))b = \sum_{i=1}^ny_i-\frac{\sum_{i=1}^n\big(x_i\big)}{\sum_{i=1}^n\big(x_i^2\big)}\sum_{i=1}^nx_iy_i$$

$$b=\frac{\sum_{i=1}^ny_i-\frac{\sum_{i=1}^n\big(x_i\big)}{\sum_{i=1}^n\big(x_i^2\big)}\sum_{i=1}^nx_iy_i}{n-\frac{\sum_{i=1}^n\big(x_i\big)}{\sum_{i=1}^n\big(x_i^2\big)}\sum_{i=1}^n\big(x_i\big)}$$  (7)

根据公式(5),(7)写代码

