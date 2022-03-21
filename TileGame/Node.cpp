#include "Node.h"

Node::Node()
{   
    positon = Vector2AStar(-1, -1);
    x = -1;
    y = -1;
    cameFrom = nullptr;
    cost = -1;
    traversable = true;
    
}

Node::Node(Vector2AStar positionP) : positon(positionP)
{ 
    x = positon.x;
    y = positon.y;
    cameFrom = nullptr;
    cost = -1;
    traversable = true;   
}

Node::~Node()
{
    
}
