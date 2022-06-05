#pragma once
#include <unordered_map>
#include <unordered_set>
#include "UtilComparators.h"
#include <nlohmann/json.hpp>
class JsonData
{
private:
    std::unordered_map<int, std::pair<float, float>> m_luxembourgRealLifeCoordinates;
    std::unordered_map<std::pair<int, int>, int, UtilComparators::KeyHasher>m_distanceBetweenRealLifeCoordinates;
    std::vector<std::list<int>>m_adjacencyList;
    std::unordered_set<int> m_roadIntersections;
    nlohmann::json m_jsonData;
    int longMin = INT_MAX, longMax = INT_MIN, latMin = INT_MAX, latMax = INT_MIN;
public:
    JsonData();
    void NormalizeRealLifeCoordinates();
    void createAdjacencyList();
    const std::unordered_map<int, std::pair<float, float>>& getNormalizedCoordinates();
    std::unordered_map<std::pair<int, int>, int, UtilComparators::KeyHasher>& getdistanceBetweenRealLifeCoordinates();
    std::vector<std::list<int>>& getAdjacencyList();
    std::unordered_set<int>& getRoadIntersections();
};

