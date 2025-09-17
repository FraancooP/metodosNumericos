#pragma once
#include <functional>

void punto_fijo(std::function<double(double)> f, double tol, int max_iter, int& i, double& x0, double& x1, double& error);