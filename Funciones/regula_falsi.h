#pragma once
#include <functional>

void regula_falsi(std::function<double(double)> f, double a, double b, double tol, int max_iter, double& c, int& i);