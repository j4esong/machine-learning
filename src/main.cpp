
#include <iostream>
#include <Eigen/Dense>

typedef Eigen::Matrix<double, Eigen::Dynamic, 1> vec;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> mat;

vec leastSquares(mat X, vec y, vec beta);

int main()
{
	return 0;
}

vec leastSquares(mat X, vec y, vec beta)
{
	return (X.transpose() * X).inverse() * X.transpose() * y;
}