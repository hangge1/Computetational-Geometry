#pragma once

#include <array>

#include "Core.h"
#include <ostream>

namespace zzh {

    constexpr size_t DIM2 = 2;
    constexpr size_t DIM3 = 3;

    template<typename elem_type, size_t dim = DIM3>
    class Vector {
        static_assert(dim >= DIM2, "Vector dimension must greater equal than 2");
        static_assert(std::is_arithmetic<elem_type>::value, "Vector element type must be arithmetic type");

    public:
        Vector(std::array<elem_type, dim> rhs) : data(rhs) {}
        Vector(elem_type x, elem_type y) : data({ x, y }) {}
        Vector(elem_type x, elem_type y, elem_type z) : data({ x, y, z }) {}

        Vector operator+(const Vector& rhs) const {
            std::array<elem_type, dim> result;
            for (size_t i = 0; i < dim; ++i) {
                result[i] = data[i] + rhs.data[i];
            }
            return Vector(result);
        }

        Vector operator-(const Vector& rhs) const {
            std::array<elem_type, dim> result;
            for (size_t i = 0; i < dim; ++i) {
                result[i] = data[i] - rhs.data[i];
            }
            return Vector(result);
        }

        Vector operator*(elem_type scalar) const {
            std::array<elem_type, dim> result;
            for (size_t i = 0; i < dim; ++i) {
                result[i] = data[i] * scalar;
            }
            return Vector(result);
        }

        elem_type operator[] (size_t index) const {
            if (index >= dim) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        void assign(size_t index, elem_type value) {
            if (index >= dim) {
                throw std::out_of_range("Index out of range");
            }
            data[index] = value;
        }

        bool operator==(const Vector& rhs) const {
            for (size_t i = 0; i < dim; ++i) {
                if (!zzh::isEqual(data[i], rhs[i])) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const Vector& rhs) const {
            return !(*this == rhs);
        }

        bool operator<(const Vector& rhs) const {
            for (size_t i = 0; i < dim; ++i) {
                if (data[i] < rhs[i]) {
                    return true;
                }
                else if (data[i] > rhs[i]) {
                    return false;
                }
            }
            return false;
        }

        bool operator>(const Vector& rhs) const {
            for (size_t i = 0; i < dim; ++i) {
                if (data[i] > rhs[i]) {
                    return true;
                }
                else if (data[i] < rhs[i]) {
                    return false;
                }
            }
            return false;
        }

        float magnitude() const {
            float sum = 0;
            for (size_t i = 0; i < dim; ++i) {
                sum += data[i] * data[i];
            }
            return std::sqrt(sum);
        }

        void normalize() {
            float mag = magnitude();
            if (zzh::isEqual(mag, 0.0f)) {
                throw std::runtime_error("Cannot normalize a zero vector");
            }
            for (size_t i = 0; i < dim; ++i) {
                data[i] /= mag;
            }
        }

    private:
        std::array<elem_type, dim> data;
    };

    typedef Vector<float, DIM2> Vector2f;
    typedef Vector<float, DIM3> Vector3f;
    typedef Vector<double, DIM2> Vector2d;
    typedef Vector<double, DIM3> Vector3d;

    template<typename elem_type, size_t dim = DIM3>
    std::ostream& operator<<(std::ostream& os, const Vector<elem_type, dim>& vec) {
        os << "(";
        for (int i = 0; i < dim; ++i) {
            os << vec[i];
            if (i < dim - 1) {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }

    template<typename elem_type, size_t dim = DIM3>
    float dot(const Vector<elem_type, dim>& a, const Vector<elem_type, dim>& b) {
        float result = 0;
        for (size_t i = 0; i < dim; ++i) {
            result += a[i] * b[i];
        }
        return result;
    }

    template<typename elem_type>
    float cross2d(const Vector<elem_type, DIM2>& a, const Vector<elem_type, DIM2>& b) {
        return a[0] * b[1] - a[1] * b[0];
    }

    template<typename elem_type>
    Vector<elem_type, DIM3> cross3d(const Vector<elem_type, DIM3>& a, const Vector<elem_type, DIM3>& b) {
        return Vector<elem_type, DIM3>(
            a[1] * b[2] - a[2] * b[1],
            a[2] * b[0] - a[0] * b[2],
            a[0] * b[1] - a[1] * b[0]
        );
    }
}