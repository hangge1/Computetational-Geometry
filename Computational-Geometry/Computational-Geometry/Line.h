#pragma once

#include "Point.h"

namespace zzh {
    template<typename elem_type, size_t dim = DIM3>
    class Line {
        static_assert(dim >= DIM2, "Line dimension must greater equal than 2");
        static_assert(std::is_arithmetic<elem_type>::value, "Line element type must be arithmetic type");
    public:
        Line(const Point<elem_type, dim>& point, const Vector<elem_type, dim>& direction)
            : point(point), direction(direction) {}

        Line(const Point<elem_type, dim>& point1, const Point<elem_type, dim>& point2)
            : point(point1), direction(point2-point1) {
        }

        Point<elem_type, dim> getPoint() const { return point; }
        Vector<elem_type, dim> getDirection() const { return direction; }
    private:
        Point<elem_type, dim> point;
        Vector<elem_type, dim> direction;
    };

    template<typename elem_type, size_t dim>
    std::ostream & operator<<(std::ostream & os, const Line<elem_type, dim> & line) {
        os << "Line(Origin: " << line.getPoint() << ", Dir: " << line.getDirection() << ")";
        return os;
    }

    typedef Line<float, DIM2> Line2f;
    typedef Line<float, DIM3> Line3f;


}