// Computational-Geometry.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "Vector.h"

int main()
{
    zzh::Vector3f a{ 1.0f, 0.0f, 0.0f };
    zzh::Vector3f b{ 0.0f, 1.0f, 0.0f };
    std::cout << zzh::dot(a, b) << std::endl;
    std::cout << zzh::cross3d(a, b) << std::endl;

    return 0;
}
