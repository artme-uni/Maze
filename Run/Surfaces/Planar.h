#ifndef RUNNER_PLANAR_H
#define RUNNER_PLANAR_H

#include "../Surface_Points.h"

class Planar : public Surface_Points
{
public:
    bool is_neighbours(const Point &a, const Point &b) const override
    {
        return (a.status == stat::blank && b.status == stat::blank) &&
               ((abs(a.x - b.x) == 1 && a.y == b.y) ||
                (abs(a.y - b.y) == 1 && a.x == b.x));
    }
};

#endif //RUNNER_PLANAR_H