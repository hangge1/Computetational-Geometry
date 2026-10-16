// Computational-Geometry.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "Line.h"
#include "Plane.h"
#include "Point.h"
#include "Vector.h"

int main()
{
    zzh::Vector3f a{ 1.0f, 0.0f, 0.0f };
    zzh::Vector3f b{ 0.0f, 1.0f, 0.0f };
    std::cout << zzh::dot(a, b) << std::endl;
    std::cout << zzh::cross3d(a, b) << std::endl;

    zzh::Point3f p1{ 1.0f, 2.0f, 3.0f };
    zzh::Point3f p2{ 2.0f, 3.0f, 4.0f };
    zzh::Line3f line(p1, p2 - p1);

    zzh::Vector3f normal{1.0f,1.0f, 1.0f};
    zzh::Plane3f plane(p1, normal);

    std::cout << "p1:" << p1 << std::endl;
    std::cout << "p2:" << p2 << std::endl;
    std::cout << "line:" << line << std::endl;
    std::cout << "plane:" << plane << std::endl;

    return 0;
}
