#pragma once
#include <functional>

void biseccion(std::function<double(double)> f, double a, double b, double tol, int max_iter, double& c, int& i);