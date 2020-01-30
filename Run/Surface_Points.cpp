#include "Surface_Points.h"
#include "Surfaces/Planar.h"
#include "Surfaces/Tor.h"
#include "Surfaces/Cylinder.h"


void Surface_Points::set_points(std::istream &in)
{
    std::string str;

    int cur_x = 0;
    int cur_y = 0;

    while (getline(in, str))
    {
        int temp = str.size();

        if (temp >= x_length)
            x_length = str.size();
        else
        {
            while (temp != x_length)
            {
                str += ".";
                temp++;
            }
        }

        for (cur_x = 0; cur_x < x_length; ++cur_x)
        {
            if (str[cur_x] == 'S')
            {
                start.x = cur_x;
                start.y = cur_y;
            }
            if (str[cur_x] == 'F')
            {
                finish.x = cur_x;
                finish.y = cur_y;
            }

            Point current(cur_x, cur_y);
            current.status = char_to_status(str[cur_x]);

            elements.emplace_back(current);
        }

        cur_y++;
        y_length = cur_y;
    }
}

char wave_to_char(int cur)
{
    if (cur == -1)
        return '+';
    else if (cur == 0)
        return '@';
    else if(cur == - 5)
        return 'o';
    else if(cur > 0)
        return ' ';
}

void Surface_Points::print(std::ostream &out)
{
    std::array<std::array<Point, 100>, 100> a;

    usleep(100000);
    system("clear");

    for (auto &temp : elements)
    {
        int x = temp.x;
        int y = temp.y;

        a[x][y] = temp;
    }

    for (int j = 0; j < y_length; ++j)
    {
        for (int i = 0; i < x_length; ++i)
        {
            std::cout << std::setw(2) << wave_to_char(a[i][j].wave) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

std::shared_ptr<Surface<Point>> make_surface(std::string &mode)
{
    if (mode == "planar")
        return std::make_shared<Planar>();
    else if (mode == "cylinder")
        return std::make_shared<Cylinder>();
    else if (mode == "tor")
        return std::make_shared<Tor>();
}