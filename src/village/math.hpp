#pragma once

#include <array>
#include <cmath>
#include <concepts>
#include <initializer_list>
#include <type_traits>
#include <utility>

template <class T, size_t N>
class Vector {
public:
    constexpr Vector() {}
    constexpr Vector(std::initializer_list<T> l) : _values(l) {}

    template <class... Args>
    constexpr Vector(Args&&... args) : _values(std::forward<Args>(args)...) {}

    template <class U> requires std::convertible_to<U, T>
    Vector(const Vector<U, N>& other) : _values(other._values) {}

    template <class U> requires std::convertible_to<U, T>
    Vector(Vector<U, N>&& other) : _values(std::move(other._values)) {}

    Vector& operator+=(const Vector& other)
    {
        for (size_t i = 0; i < N; i++) {
            _values[i] += other._values[i];
        }
        return *this;
    }

    Vector& operator-=(const Vector& other)
    {
        for (size_t i = 0; i < N; i++) {
            _values[i] -= other._values[i];
        }
        return *this;
    }

    Vector& operator*=(const T& scalar)
    {
        for (size_t i = 0; i < N; i++) {
            _values[i] *= scalar;
        }
        return *this;
    }

    Vector& operator/=(const T& scalar)
    {
        for (size_t i = 0; i < N; i++) {
            _values[i] /= scalar;
        }
        return *this;
    }

    const T& operator[](size_t index) const
    {
        return _values[index];
    }

    T& operator[](size_t index)
    {
        return _values[index];
    }

    T length() const requires std::is_arithmetic_v<T>
    {
        auto sqsum = T{0};
        for (size_t i = 0; i < N; i++) {
            sqsum += _values[i] * _values[i];
        }
        return std::sqrt(sqsum);
    }

private:
    std::array<T, N> _values {};
};

template <class T, size_t N>
Vector<T, N> operator+(Vector<T, N> lhs, const Vector<T, N>& rhs)
{
    lhs += rhs;
    return lhs;
}

template <class T, size_t N>
Vector<T, N> operator-(Vector<T, N> lhs, const Vector<T, N>& rhs)
{
    lhs -= rhs;
    return lhs;
}

template <class T, size_t N>
auto operator*(Vector<T, N> lhs, const T& scalar)
{
    lhs *= scalar;
    return lhs;
}

template <class T, size_t N>
auto operator*(const T& scalar, Vector<T, N> lhs)
{
    return lhs * scalar;
}

template <class T, size_t N>
auto operator/(Vector<T, N> lhs, const T& scalar)
{
    lhs /= scalar;
    return lhs;
}

template <class T, size_t N>
class Point {
public:
    constexpr Point() {}
    constexpr Point(std::initializer_list<T> l) : _values(l) {}

    template <class... Args>
    constexpr Point(Args&&... args) : _values(std::forward<Args>(args)...) {}

    template <class U> requires std::convertible_to<U, T>
    Point(const Point<U, N>& other) : _values(other._values) {}

    template <class U> requires std::convertible_to<U, T>
    Point(Point<U, N>&& other) : _values(std::move(other._values)) {}

    Point& operator+=(const Vector<T, N>& vector)
    {
        for (size_t i = 0; i < N; i++) {
            _values[i] += vector._values[i];
        }
        return *this;
    }

    Point& operator-=(const Vector<T, N>& vector)
    {
        for (size_t i = 0; i < N; i++) {
            _values[i] -= vector._values[i];
        }
        return *this;
    }

    const T& operator[](size_t index) const
    {
        return _values[index];
    }

    T& operator[](size_t index)
    {
        return _values[index];
    }

private:
    std::array<T, N> _values {};
};

template <class T, size_t N>
Point<T, N> operator+(Point<T, N> point, const Vector<T, N>& vector)
{
    point += vector;
    return point;
}

template <class T, size_t N>
Point<T, N> operator-(Point<T, N> point, const Vector<T, N>& vector)
{
    point -= vector;
    return point;
}

template <class T, size_t N>
Vector<T, N> operator-(const Point<T, N>& lhs, const Point<T, N>& rhs)
{
    auto r = Vector<T, N>{};
    for (size_t i = 0; i < N; i++) {
        r[i] = lhs[i] - rhs[i];
    }
}

template <class T, size_t N>
T distance(const Point<T, N>& lhs, const Point<T, N>& rhs)
{
    return (lhs - rhs).length();
}
