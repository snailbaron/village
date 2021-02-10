#pragma once

#include "math.hpp"

// Real dimensions are not supported yet, so just slap vectors everywhere.

template <class T>
class XYVector : public Vector<T, 2> {
public:
    T& x = (*this)[0];
    T& y = (*this)[1];
};

using Time = double;
using Distance = double;
using Position = XYVector<double>;
using Velocity = XYVector<double>;
using Acceleration = XYVector<double>;

inline constexpr Distance operator"" _m(long double x)
{
    return Distance(x);
}

inline constexpr Distance operator"" _m(unsigned long long x)
{
    return Distance(x);
}

inline constexpr Time operator"" _sec(long double x)
{
    return Time(x);
}

inline constexpr Time operator"" _sec(unsigned long long x)
{
    return Time(x);
}
