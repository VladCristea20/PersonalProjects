#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include "UtilComparators.h"
class UtilAlgoritms
{
public:
    static float distanceBetweenTwoPoints(const std::pair<float, float>&, const sf::Vector2f&);
    static std::vector<int> Dijkstra(std::unordered_set<int>,const std::unordered_map<std::pair<int, int>, int, UtilComparators::KeyHasher>&,const std::vector<std::list<int>>&, const int&, const int&);
    static int closestRoadIntersectionToClick(const sf::Vector2f&,const std::unordered_map<int, std::pair<float, float>>&);
};

