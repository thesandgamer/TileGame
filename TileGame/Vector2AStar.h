#pragma once
class Vector2AStar
{
public:
        double x;
        double y;

        Vector2AStar()
        {
            x = -1;
            y = -1;
        }
        Vector2AStar(double xP, double yP) : x(xP), y(yP)
        {

        }
        ~Vector2AStar() {};



        bool operator ==(const Vector2AStar other)
        {
            if (this->x == other.x && this->y == other.y) return true;
            return false;

        }
        bool operator !=(const Vector2AStar other)
        {
            if (this->x == other.x && this->y == other.y) return false;
            return true;

        }
        bool operator>(const Vector2AStar& other)
        {
            if (this->x > other.x && this->y > other.y) return true;
            return false;
        }
        bool operator<(const Vector2AStar& other)
        {
            if (this->x < other.x && this->y < other.y) return true;
            return false;
        }

};

