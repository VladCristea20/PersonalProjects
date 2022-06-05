#include "UtilAlgoritms.h"

float UtilAlgoritms::distanceBetweenTwoPoints(const std::pair<float, float>& A, const sf::Vector2f& B)
{
	return sqrt((A.first - B.x) * (A.first - B.x) + (A.second - B.y) * (A.second - B.y));
}

int UtilAlgoritms::closestRoadIntersectionToClick(const sf::Vector2f& point, const std::unordered_map<int, std::pair<float, float>>& luxembourgRealLifeCoordinates)
{
    float MINdistance = 2203.0f;
    int id;
    for (const auto& it : luxembourgRealLifeCoordinates)
    {
        float distanta = distanceBetweenTwoPoints(it.second, point);
        if (distanta < MINdistance)
        {
            id = it.first;
            MINdistance = distanceBetweenTwoPoints(it.second, point);
        }
    }
    return id;
}

std::vector<int> UtilAlgoritms::Dijkstra(std::unordered_set<int> nodes, const std::unordered_map<std::pair<int, int>, int, UtilComparators::KeyHasher> &distanceBetweenCoordinates, const std::vector<std::list<int>> &adjacencyList, const int& start, const int& finish)
{
    std::vector<int>shortestPath, distanceFromSourceToEachNode;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, UtilComparators::MyComparison> priorityQueue;
    for (const auto& node : nodes)
    {
        distanceFromSourceToEachNode.push_back(INT_MAX);
        shortestPath.push_back(-1);
    }
    priorityQueue.push(std::make_pair(start, distanceFromSourceToEachNode[start]));
    int x;
    while (nodes.empty() != true)
    {
        if (priorityQueue.empty() == true)
            return shortestPath;
        x = priorityQueue.top().first;
        priorityQueue.pop();
        if (x == finish)
            break;
        if (nodes.find(x) != nodes.end())
        {
            nodes.erase(x);
            for (const auto& y : adjacencyList[x])
            {
                if (nodes.find(y) != nodes.end())
                {
                    if (distanceBetweenCoordinates.find(std::make_pair(x, y)) != distanceBetweenCoordinates.end())
                    {
                        if (distanceFromSourceToEachNode[y] > distanceFromSourceToEachNode[x] + distanceBetweenCoordinates.at(std::make_pair(x, y)))
                        {
                            distanceFromSourceToEachNode[y] = distanceFromSourceToEachNode[x] + distanceBetweenCoordinates.at(std::make_pair(x, y));
                            shortestPath[y] = x;
                            priorityQueue.push(std::make_pair(y, distanceFromSourceToEachNode[y]));
                        }
                    }
                }
            }
        }
    }
    return shortestPath;
}
