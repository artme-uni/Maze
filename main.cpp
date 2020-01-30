#include <iostream>
#include <fstream>
#include "Search.h"
#include "Run/Surface_Points.h"
#include "Read/Surface_Words.h"

int main(int argc, char **argv)
{
    if (argc == 1 || argc > 4 || (argc == 2 && (std::string(argv[1]) == "help")))
    {
        std::cout << "Expected input:\n"
                     "runner"
                     "\t ./prog.exe input.txt --option\n"
                     "reader"
                     "\t ./prog.exe input.txt first last\n"
                     "Available options for runner:\n"
                     "\t --planar (by default)\n"
                     "\t --cylinder\n"
                     "\t --tor\n";
        return 0;
    } else
    {
        std::vector<std::string> line;
        for (int i = 1; i < argc; i++)
            line.emplace_back(std::string(argv[i]));

        std::string mode = "planar";

        for (int i = 0; i < line.size(); i++)
        {
            if (line[i][0] == '-' && line[i][1] == '-')
            {
                line[i].erase(0, 2);
                if (line[i] == "planar" || line[i] == "cylinder" || line[i] == "tor")
                {
                    mode = line[i];
                    line.erase(line.begin() + i);
                } else
                {
                    std::cerr << "Available options for runner:\n"
                                 "\t --planar (by default)\n"
                                 "\t --cylinder\n"
                                 "\t --tor\n";
                    return -1;
                }
            }
        }

        std::ifstream file;
        file.open(line[0]);

        if (!(file.is_open())){
            std::cerr << "File cannot be opened\n";
            return -1;
        }

        if (line.size() == 1)
        {
            std::shared_ptr<Surface<Point>> s = make_surface(mode);

            s->set_points(file);
            std::vector<Point> p = search(s);

            for (auto &tm : p)
            {
                std::cout << tm.x << ", " << tm.y << "\n";
            }

        } else
        {
            std::shared_ptr<Surface<Word>> s = make_surface_word();

            s->set_points(file);
            s->start = Word(line[1]);
            s->finish = Word(line[2]);

            std::vector<Word> p = search(s);

            for (auto &tm : p)
            {
                std::cout << tm.string << "\n";
            }
        }
    }

    return 0;
}