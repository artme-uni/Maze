#ifndef RUNNER_SEARCH_H
#define RUNNER_SEARCH_H

#include <map>
#include "Surface.h"
#include <iostream>

#include <memory>

template<class P>
std::vector<P> search(std::shared_ptr<Surface<P>> &s)
{
    std::vector<int> previous_wave;
    std::vector<int> new_wave;

    int start = s->get_index(s->start);
    int finish = s->get_index(s->finish);

    if (start == -1)
    {
        std::cout << "The start cannot be found\n";
        exit(-1);
    }
    if (finish == -1)
    {
        std::cout << "The finish cannot be found\n";
        exit(-1);
    }

    s->elements[start].wave = 0;
    previous_wave.emplace_back(start);

    int number = 1;

    while (s->elements[finish].wave == -1)
    {
        for (auto &pw : previous_wave)
        {
            std::vector<int> neighbours = s->get_neighbours(s->elements[pw], s->elements);

            for (auto &nb : neighbours)
            {
                if (s->elements[nb].wave == -1)
                {
                    s->elements[nb].wave = number;
                    new_wave.emplace_back(nb);
                }
            }
        }

        if (previous_wave.empty())
        {
            std::cout << "The path cannot be found\n";
            exit(-1);
        }

        previous_wave = new_wave;
        new_wave.clear();
        number++;
    }

    int cur_indx = finish;
    int cur_wave = s->elements[cur_indx].wave;

    std::vector<P> way;
    way.emplace_back(s->elements[finish]);

    while (cur_wave != 0)
    {
        std::vector<int> neighbours = s->get_neighbours(s->elements[cur_indx], s->elements);

        for (auto nb : neighbours)
        {
            if (s->elements[nb].wave == cur_wave - 1)
            {
                cur_indx = nb;
                cur_wave--;
                way.emplace_back(s->elements[cur_indx]);
                s->elements[cur_indx].wave = -5;

                break;
            }
        }
    }

    return way;
}

#endif //RUNNER_SEARCH_H
