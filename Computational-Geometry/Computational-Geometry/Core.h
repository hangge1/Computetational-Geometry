#pragma once

#include <cmath>

namespace zzh {

constexpr float fTolerance = 1e-6f;
constexpr double dTolerance = 1e-12f;

bool isEqual(float a, float b) {
    return std::fabs(a - b) <= fTolerance;
}

bool isEqual(double a, double b) {
    return std::fabs(a - b) <= dTolerance;
}

}