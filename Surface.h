#ifndef RUNNER_SPACE_H
#define RUNNER_SPACE_H

#include <vector>
#include <iostream>

template<class P>
class Surface
{
private:
    virtual bool is_neighbours(const P &a, const P &b) const = 0;

public:
    std::vector<P> elements;
    P start;
    P finish;

    std::vector<int> get_neighbours(const P &p, const std::vector<P> &elem) const
    {
        std::vector<int> temp;

        for (int i = 0; i < elem.size(); i++)
        {
            if (is_neighbours(p, elem[i]))
                temp.emplace_back(i);
        }

        return temp;
    }

    virtual void set_points(std::istream &in) = 0;

    int get_index(P p) const
    {
        for (int i = 0; i < elements.size(); ++i)
        {
            if (p == elements[i])
                return i;
        }

        return -1;
    }
};

class Element
{
public:
    int wave = -1;

    virtual bool operator==(const Element &e) const
    {
        return true;
    };
};

#endif //RUNNER_POINT_H
