#include "SfmlData.h"
SfmlData::SfmlData()
{
	m_window.create(sf::VideoMode(1600.0f, 900.0f), "Luxembourg Shortest Path GPS", sf::Style::Close|sf::Style::Resize);
	m_lines.setPrimitiveType(sf::Lines);
    sf::CircleShape circle;
    m_circle.setFillColor(sf::Color::Red);
    m_circle.setRadius(5.0f);
    m_circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
}

bool SfmlData::BoundsCheck(const sf::Vector2f &mousePos)
{
    if (mousePos.x >= 0.0f && mousePos.x <= m_window.getSize().x && mousePos.y >= 0.0f && mousePos.y <= m_window.getSize().y)
        return true;
    return false;
}

void SfmlData::HighlightRedPath(const int&index_curent, JsonData& data,std::vector<int> &shortestPath, std::unordered_set<int>& visited)
{
    if (visited.find(m_circles[index_curent].first) == visited.end() && visited.find(m_circles[index_curent - 1].first) == visited.end())
    {
        m_line.color = sf::Color::Red;
        shortestPath = UtilAlgoritms::Dijkstra(data.getRoadIntersections(), data.getdistanceBetweenRealLifeCoordinates(), data.getAdjacencyList(), m_circles[index_curent - 1].first, m_circles[index_curent].first);
        int j = m_circles[index_curent].first;
        if (shortestPath[j] == -1)
        {
            return;
        }
        while (shortestPath[j] != m_circles[index_curent - 1].first)
        {
            m_line.position.x = data.getNormalizedCoordinates().at(j).first;
            m_line.position.y = data.getNormalizedCoordinates().at(j).second;
            m_lines.append(m_line);
            m_line.position.x = data.getNormalizedCoordinates().at(shortestPath[j]).first;
            m_line.position.y = data.getNormalizedCoordinates().at(shortestPath[j]).second;
            m_lines.append(m_line);
            j = shortestPath[j];
        }
        visited.insert(m_circles[index_curent - 1].first);
        visited.insert(m_circles[index_curent].first);
    }
}

void SfmlData::HighlightWhitePath(JsonData& data)
{
    for (const auto& it : data.getdistanceBetweenRealLifeCoordinates())
    {
        m_line.position.x =  data.getNormalizedCoordinates().at(it.first.first).first;
        m_line.position.y =  data.getNormalizedCoordinates().at(it.first.first).second;
        m_lines.append(m_line);
        m_line.position.x =  data.getNormalizedCoordinates().at(it.first.second).first;
        m_line.position.y =  data.getNormalizedCoordinates().at(it.first.second).second;
        m_lines.append(m_line);
    }
}

//void SfmlData::Rescale(const sf::Event& event,const sf::Vector2f&oldWindow)
//{
//    float diagonal, newDiagonal,ratio;
//    diagonal = sqrt(oldWindow.x * oldWindow.x + oldWindow.y * oldWindow.y);
//    std::cout << "diagonal " << diagonal<<"\n";
//    newDiagonal = sqrt(event.size.width * event.size.width + event.size.height * event.size.height);
//    std::cout << "newDiagonal " << newDiagonal << "\n";
//    ratio = (diagonal < newDiagonal) ? (diagonal*100/newDiagonal) : (newDiagonal * 100 / diagonal);
//    for (auto& circle : m_circles)
//    {
//        std::cout << ratio << " ratio\n";
//        circle.second.setRadius((diagonal<newDiagonal)?(circle.second.getRadius() + ratio / 100 * circle.second.getRadius()): (circle.second.getRadius() - ratio / 100 * circle.second.getRadius()));
//        std::cout << circle.second.getRadius() << "\n";
//    }
//}

void SfmlData::HighlightRedCircle(const sf::Vector2f& mousePos, JsonData& data)
{
    int id = UtilAlgoritms::closestRoadIntersectionToClick(mousePos, data.getNormalizedCoordinates());
    m_circle.setPosition(data.getNormalizedCoordinates().at(id).first, data.getNormalizedCoordinates().at(id).second);
    if (m_circles.size() != 0)
    {
        if (m_circles[m_circles.size() - 1].first != id)
            m_circles.push_back(std::make_pair(id, m_circle));
    }
    else
        m_circles.push_back(std::make_pair(id, m_circle));
}

void SfmlData::Run()
{
    JsonData data;
    std::vector<int> shortestPath;
    std::unordered_set<int> visited;
    data.NormalizeRealLifeCoordinates();
    data.createAdjacencyList();
    sf::Vector2f oldWindow = sf::Vector2f(m_window.getSize().x, m_window.getSize().y);
    HighlightWhitePath(data);
    std::cout << "Click on the screen to see the shortest path between 2 points.\n";
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::Resized:
                //Rescale(event,oldWindow);
                break;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));
            if (BoundsCheck(mousePos) != false)
            {
                HighlightRedCircle(mousePos, data);
            }
        }
        m_window.clear();
        for (int index_curent = 0; index_curent < m_circles.size(); index_curent++)
        {
            m_window.draw(m_circles[index_curent].second);
            if (index_curent % 2 == 1)
            {
                HighlightRedPath(index_curent, data, shortestPath, visited);
            }
        }
        m_window.draw(m_lines);
        m_window.display();
    }
}
