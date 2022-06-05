#include "UtilComparators.h"

std::size_t UtilComparators::KeyHasher::operator()(const std::pair<int, int>& k) const
{
    return ((std::hash<int>()(k.first)
        ^ (std::hash<int>()(k.second))));
}

bool UtilComparators::MyComparison::operator()(std::pair<int, int>& pair1, std::pair<int, int>& pair2) const
{
        return pair1.second > pair2.second;
}
