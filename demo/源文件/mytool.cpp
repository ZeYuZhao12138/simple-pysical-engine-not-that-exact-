//
// Created by zhao.zeyu on 2022/04/27.
//
#include <iostream>
#include <math.h>
#include "mytool.h"


double myround(double value, int precision)
{
    return round(value * pow(10, precision)) / pow(10, precision);
}

double angle_from_radian(double value)
{
    return value / PI * 180;
}
