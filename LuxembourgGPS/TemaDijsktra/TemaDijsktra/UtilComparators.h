#pragma once
#include <iostream>
class UtilComparators
{
public:
    struct KeyHasher
    {
        std::size_t operator()(const std::pair<int, int>& k) const;
    };
    struct MyComparison
    {
        bool operator() (std::pair<int, int>& pair1, std::pair<int, int>& pair2)const;
    };
};

