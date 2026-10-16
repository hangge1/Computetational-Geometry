#pragma once

#include <ostream>

namespace zzh {

    template<typename elem_type, size_t dim = DIM3>
    class Plane {
        Point<elem_type, dim> point;
        Vector<elem_type, dim> normal;

    public:
        Plane(const Point<elem_type, dim>& point, const Vector<elem_type, dim>& normal)
            : point(point), normal(normal) {
        }

        auto getPoint() const { return point; }

        auto getNormal() const { return normal; }
    };

    template<typename elem_type, size_t dim = DIM3>
    std::ostream& operator<<(std::ostream& os, const Plane<elem_type, dim>& plane) {
        os << "Plane(Origin: " << plane.getPoint() << ", Normal: " << plane.getNormal() << ")";
        return os;
    }

    typedef Plane<float, DIM2> Plane2f;
    typedef Plane<float, DIM3> Plane3f;

    typedef Plane<double, DIM2> Plane2d;
    typedef Plane<double, DIM3> Plane3d;
}