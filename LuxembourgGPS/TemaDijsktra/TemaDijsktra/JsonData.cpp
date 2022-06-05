#include "JsonData.h"
#include <fstream>
#include <chrono>
JsonData::JsonData()
{
    std::ifstream f("Coordinates.json");
    try
    {
        m_jsonData = nlohmann::json::parse(f);
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start= std::chrono::system_clock::now();
        for (const auto& iterator : m_jsonData.at("map_description").at("nodes").at("node"))
        {
            m_luxembourgRealLifeCoordinates.insert(std::make_pair(std::stoi(std::string(iterator.at("-id"))), std::make_pair(std::stoi(std::string(iterator.at("-longitude"))), std::stoi(std::string(iterator.at("-latitude"))))));
            if (std::stoi(std::string(iterator.at("-longitude"))) < longMin)
                longMin = std::stoi(std::string(iterator.at("-longitude")));
            if (std::stoi(std::string(iterator.at("-longitude"))) > longMax)
                longMax = std::stoi(std::string(iterator.at("-longitude")));
            if (std::stoi(std::string(iterator.at("-latitude"))) < latMin)
                latMin = std::stoi(std::string(iterator.at("-latitude")));
            if (std::stoi(std::string(iterator.at("-latitude"))) > latMax)
                latMax = std::stoi(std::string(iterator.at("-latitude")));
        }
        for (const auto& iterator : m_jsonData.at("map_description").at("arcs").at("arc"))
        {
            m_distanceBetweenRealLifeCoordinates.insert(std::make_pair(std::make_pair(std::stoi(std::string(iterator.at("-from"))), std::stoi(std::string(iterator.at("-to")))), std::stoi(std::string(iterator.at("-length")))));
        }
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout<< "Time it took to parse the data: " << elapsed_seconds.count() << " seconds\n";
    }
    catch (nlohmann::json::exception& e)
    {
        std::cout << e.what() << "\n";
        exit(0);
    }
    f.close();
}

void JsonData::NormalizeRealLifeCoordinates()
{
    for (const auto& it : m_luxembourgRealLifeCoordinates)
    {
        m_roadIntersections.insert(it.first);
        m_luxembourgRealLifeCoordinates[it.first] = std::make_pair(1600.0f / (longMax - longMin) * (it.second.first - longMin), 900.0f / (latMax - latMin) * (it.second.second - latMin));
    }
}

void JsonData::createAdjacencyList()
{
    m_adjacencyList.resize(m_luxembourgRealLifeCoordinates.size());
    for (const auto& it : m_distanceBetweenRealLifeCoordinates)
    {
        m_adjacencyList.at(it.first.first).push_back(it.first.second);
        m_adjacencyList.at(it.first.second).push_back(it.first.first);
    }
}

const std::unordered_map<int, std::pair<float, float>>& JsonData::getNormalizedCoordinates()
{
    return m_luxembourgRealLifeCoordinates;
}

std::unordered_map<std::pair<int, int>, int, UtilComparators::KeyHasher>& JsonData::getdistanceBetweenRealLifeCoordinates()
{
    return m_distanceBetweenRealLifeCoordinates;
}

std::vector<std::list<int>>& JsonData::getAdjacencyList()
{
    return m_adjacencyList;
}

std::unordered_set<int>& JsonData::getRoadIntersections()
{
    return m_roadIntersections;
}
