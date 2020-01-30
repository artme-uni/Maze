#ifndef RUNNER_SURFACE_WORDS_H
#define RUNNER_SURFACE_WORDS_H

#include <iostream>
#include <string>
#include <memory>

#include "../Surface.h"

class Word : public Element
{
public:
    std::string string;

    Word() = default;

    Word(std::string &str)
    {
        string = str;
    }

    bool operator==(const Word &e) const
    {
        return this->string == e.string;
    }
};

class Surface_Words : public Surface<Word>
{
private:
    bool is_neighbours(const Word &a, const Word &b) const override;

    int Levenshtein(std::string first, std::string second) const;

public:
    Surface_Words() = default;

    void set_points(std::istream &in) override;
};

std::shared_ptr<Surface<Word>> make_surface_word();

#endif //RUNNER_SURFACE_WORDS_H
