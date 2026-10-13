#pragma once

#include <cmath>

namespace zzh {

constexpr float Tolerance = 1e-6f;

bool isEqual(float a, float b) {
    return std::fabs(a - b) <= Tolerance;
}

}