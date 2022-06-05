#pragma once
#include <SFML/Graphics.hpp>
#include "JsonData.h"
#include "UtilAlgoritms.h"
class SfmlData
{
private:
    sf::RenderWindow m_window;
    sf::VertexArray m_lines;
    sf::Vertex m_line;
    sf::CircleShape m_circle;
    std::vector<std::pair<int, sf::CircleShape>> m_circles;
public:
    SfmlData();
    void HighlightRedCircle(const sf::Vector2f& mousePos, JsonData& data);
    bool BoundsCheck(const sf::Vector2f &mousePos);
    void HighlightRedPath(const int& index_curent, JsonData& data, std::vector<int>& shortestPath, std::unordered_set<int>& visited);
    void HighlightWhitePath(JsonData&data);
    //void Rescale(const sf::Event &event,const sf::Vector2f &oldWindow);
    void Run();
};

