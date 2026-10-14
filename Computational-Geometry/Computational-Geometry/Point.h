#pragma once

#include "Vector.h"

namespace zzh {

    template<typename elem_type, size_t dim = DIM3>
    class Point : public Vector<elem_type, dim> 
    {
    public:
        using Vector<elem_type, dim>::Vector;
    };

    typedef Point<float, DIM2> Point2f;
    typedef Point<float, DIM3> Point3f;

    typedef Point<double, DIM2> Point2d;
    typedef Point<double, DIM3> Point3d;
}