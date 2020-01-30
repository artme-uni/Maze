#ifndef RUNNER_CYLINDER_H
#define RUNNER_CYLINDER_H

#include "../Surface_Points.h"

class Cylinder : public Surface_Points
{
public:
    bool is_neighbours(const Point &a, const Point &b) const override
    {
        return (a.status == stat::blank && b.status == stat::blank) &&
               ((abs(a.x - b.x) == 1 && a.y == b.y) ||
                (abs(a.y - b.y) == 1 && a.x == b.x) ||
                (abs(a.x - b.x) == x_length - 1 && a.y == b.y));
    }
};


#endif //RUNNER_CYLINDER_H
