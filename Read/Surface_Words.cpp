#include "Surface_Words.h"

void Surface_Words::set_points(std::istream &in)
{
    std::string str;

    while (getline(in, str))
    {
        elements.emplace_back(Word(str));
    }
}

bool Surface_Words::is_neighbours(const Word &a, const Word &b) const
{
    return Levenshtein(a.string, b.string) == 1;
}

int Surface_Words::Levenshtein(std::string first, std::string second) const
{
    if (first.size() > second.size())
    {
        return Levenshtein(second, first);
    }

    int min_size = first.size(), max_size = second.size();
    std::vector<int> lev_dist(min_size + 1);

    for (int i = 0; i <= min_size; ++i)
    {
        lev_dist[i] = i;
    }

    for (int j = 1; j <= max_size; ++j)
    {
        int temp = lev_dist[0];
        int prev;
        ++lev_dist[0];

        for (int i = 1; i <= min_size; ++i)
        {
            prev = lev_dist[i];
            if (first[i - 1] == second[j - 1])
            {
                lev_dist[i] = temp;
            } else
            {
                lev_dist[i] = std::min(std::min(lev_dist[i - 1], lev_dist[i]), temp) + 1;
            }
            temp = prev;
        }
    }

    return lev_dist[min_size];
}

std::shared_ptr<Surface<Word>> make_surface_word()
{
    return std::make_shared<Surface_Words>();
}