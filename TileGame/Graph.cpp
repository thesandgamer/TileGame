#include "Graph.h"

Graph::Graph(int width, int height) : graphWidth(width), graphHeight(height) {
    for (int xx = 0; xx < width; xx++)//Lignes
    {
        for (int yy = 0; yy < height; yy++)//Colognes
        {
            graphNodes.push_back(Node(Vector2AStar(xx, yy)));
        }
    }
}

Graph::Graph()
{
}

Graph::~Graph()
{
}

double Graph::GetCostOfNode(Node current, Node next)
{
    auto it = find(graphNodes.begin(), graphNodes.end(), current);
    if (it != graphNodes.end())
    {
        int index = distance(graphNodes.begin(), it);
        return graphNodes.at(index).cost;

    }

    return -1;
}

Node& Graph::GetNode(Vector2AStar node)
{
    auto it = find(graphNodes.begin(), graphNodes.end(), node);
    if (it != graphNodes.end())
    {
        int index = distance(graphNodes.begin(), it);
        return graphNodes.at(index);

    }
}

Node& Graph::GetNode(Node& node)
{
    auto it = find(graphNodes.begin(), graphNodes.end(), node);
    if (it != graphNodes.end())
    {
        int index = distance(graphNodes.begin(), it);
        return graphNodes.at(index);

    }
    return node;
}

std::vector<Node> Graph::GetAroundNodes(Node current)
{
    std::vector<Node> nodes{};
    int i = 0;
    //On va parcourir les 9 tiles
    for (int xx = -1; xx < 2; xx++)
    {
        for (int yy = -1; yy < 2; yy++)
        {
            if (xx == 0 && yy == 0) continue;
            if (current.x + xx >= 0 && current.x + xx < graphWidth && current.y + yy >= 0 && current.y + yy < graphHeight) //Check si on est dans la grille
            {
                Node newNode = GetNode(Vector2AStar(current.x + xx, current.y + yy));// Node(Vector2(current.x + xx, current.y + yy));
                nodes.push_back(newNode);
                i++;
            }

        }
    }

    return nodes;
}

void Graph::AddObstacles(std::vector<Vector2AStar> positions)
{
    for (Vector2AStar pos : positions)
    {
        AddObstacle(pos);
    }
}

void Graph::AddObstacle(Vector2AStar position)
{
    auto it = find(graphNodes.begin(), graphNodes.end(), position);
    if (it != graphNodes.end())
    {
        int index = distance(graphNodes.begin(), it);
        graphNodes.at(index).traversable = false;

    }
}

void Graph::RemoveObstacle(Vector2AStar position)
{
    auto it = find(graphNodes.begin(), graphNodes.end(), position);
    if (it != graphNodes.end())
    {
        int index = distance(graphNodes.begin(), it);
        graphNodes.at(index).traversable = true;

    }
}
