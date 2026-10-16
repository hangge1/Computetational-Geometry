#pragma once

#include "Point.h"

namespace zzh {
    template<typename elem_type, size_t dim = DIM3>
    class Line {
        static_assert(dim >= DIM2, "Line dimension must greater equal than 2");
        static_assert(std::is_arithmetic<elem_type>::value, "Line element type must be arithmetic type");

        typedef Point<elem_type, dim> PointType;
        typedef Vector<elem_type, dim> VectorType;
    public:
        Line(const PointType& point, const VectorType& direction)
            : point(point), direction(direction) {}

        Line(const PointType& point1, const PointType& point2)
            : point(point1), direction(point2 - point1) {
        }

        PointType getPoint() const { return point; }
        VectorType getDirection() const { return direction; }
    private:
        PointType point;
        VectorType direction;
    };

    template<typename elem_type, size_t dim>
    std::ostream & operator<<(std::ostream & os, const Line<elem_type, dim> & line) {
        os << "Line(Origin: " << line.getPoint() << ", Dir: " << line.getDirection() << ")";
        return os;
    }

    typedef Line<float, DIM2> Line2f;
    typedef Line<float, DIM3> Line3f;

    typedef Line<double, DIM2> Line2d;
    typedef Line<double, DIM3> Line3d;
}