#ifndef RUNNER_SURFACE_POINTS_H
#define RUNNER_SURFACE_POINTS_H

#include <iostream>
#include <array>
#include <iomanip>
#include <unistd.h>
#include <memory>

#include "Point.h"

class Surface_Points : public Surface<Point>
{
public:
    int x_length = 0;
    int y_length = 0;

    void set_points(std::istream &in) override;

    void print(std::ostream &out);
};

std::shared_ptr<Surface<Point>> make_surface(std::string &mode);

#endif //RUNNER_SURFACE_POINTS_H
