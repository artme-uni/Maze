#ifndef RUNNER_POINT_H
#define RUNNER_POINT_H

#include "../Surface.h"

enum class stat
{
    wall, blank
};

stat char_to_status(char ch);

char status_to_char(stat st);

class Point : public Element
{
public:
    int x = 0;
    int y = 0;

    stat status = stat::blank;

    Point() = default;

    Point(int x, int y) : x(x), y(y)
    {}

    bool operator==(const Point &e) const
    {
        return this->x == e.x && this->y == e.y;
    }
};



#endif //RUNNER_POINT_H