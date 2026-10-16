#pragma once
#include "Point.h"

namespace zzh {

enum class PointLineRelation {
    LEFT,
    RIGHT,
    BEYOND,
    BEHIND,
    ORIGIN,
    DESTINATION,
    BETWEEN
};

PointLineRelation intersect(const Point3d& Lp1, const Point3d& Lp2, const Point3d& p)
{
    //TODO:
    return PointLineRelation::LEFT; // Placeholder implementation
}

}