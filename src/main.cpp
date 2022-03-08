
#include <iostream>
#include <Eigen/Dense>

typedef Eigen::Matrix<double, Eigen::Dynamic, 1> cvec;
typedef Eigen::Matrix<double, 1, Eigen::Dynamic> rvec;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> mat;

cvec leastSquares(cvec x, cvec y, rvec (*phi) (double));
rvec phi(double x);

int main()
{
	cvec x{{1, 2, 3, 4, 5}};
	cvec y{{2, 4, 6, 8, 10}};
	std::cout << leastSquares(x, y, &phi);
	return 0;
}

cvec leastSquares(cvec x, cvec y, rvec (*phi) (double))
{
	mat X(x.size(), 1);
	for (int i = 0; i < x.size(); i++)
		X.row(i) = phi(x[i]);
	return (X.transpose() * X).inverse() * X.transpose() * y;
}

rvec phi(double x)
{
	rvec c(1);
	c << x;
	return c;
}