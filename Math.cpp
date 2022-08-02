#include "Math.hpp"

double Root(double num)
{
    double error = 10e-6;
    double toRoot = num;

    while ((toRoot - num / toRoot) > error)
    {
        toRoot = (toRoot + num / toRoot) / 2;
    }
    return toRoot;
}
