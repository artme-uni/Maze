#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

#include "Search.h"
#include "Run/Surfaces/Planar.h"
#include "Run/Surfaces/Cylinder.h"
#include "Run/Surfaces/Tor.h"
#include "Read/Surface_Words.h"

TEST_CASE("Test_0", "Exemple")
{
    REQUIRE (true);
}

TEST_CASE("Test_1", "Surface_Points")
{
    std::ifstream file;
    file.open("../examples/maze.txt");

    Planar s;

    s.set_points(file);

    REQUIRE (s.elements.size() == 544);
}

TEST_CASE("Test_2", "Planar")
{
    std::ifstream file;
    file.open("../examples/maze.txt");

    Planar s;

    s.set_points(file);

    REQUIRE (s.get_neighbours(s.elements[0], s.elements).size() == 2);
}

TEST_CASE("Test_3", "Cylinder")
{
    std::ifstream file;
    file.open("../examples/maze.txt");

    Cylinder s;

    s.set_points(file);

    REQUIRE (s.get_neighbours(s.elements[0], s.elements).size() == 3);
}

TEST_CASE("Test_4", "Tor")
{
    std::ifstream file;
    file.open("../examples/maze.txt");

    Tor s;

    s.set_points(file);

    REQUIRE (s.get_neighbours(s.elements[0], s.elements).size() == 4);
}

TEST_CASE("Test_5", "Planar")
{
    std::ifstream file;
    file.open("../examples/maze.txt");

    Planar s;

    s.set_points(file);

    REQUIRE (s.is_neighbours(s.elements[0], s.elements[1]));
}

TEST_CASE("Test_6", "Cylinder")
{
    std::ifstream file;
    file.open("../examples/maze.txt");

    Cylinder s;

    s.set_points(file);

    REQUIRE (s.is_neighbours(s.elements[0], s.elements[31]));
}

TEST_CASE("Test_7", "Tor")
{
    std::ifstream file;
    file.open("../examples/maze.txt");

    Tor s;

    s.set_points(file);

    REQUIRE (!s.is_neighbours(s.elements[0], s.elements[55]));
}

TEST_CASE("Test_8", "Surface_Words")
{
    std::ifstream file;
    file.open("../examples/part.txt");

    Surface_Words s;

    s.set_points(file);

    REQUIRE (s.elements.size() == 6892);
}

TEST_CASE("Test_9", "Surface_Words")
{
    std::ifstream file;
    file.open("../examples/part.txt");

    Surface_Words s;
    s.set_points(file);

    std::string str = std::string("very");

    REQUIRE (s.get_neighbours(str, s.elements).size() == 4);
}


TEST_CASE("Test_96", "Search")
{
    std::ifstream file;
    std::stringstream out;

    file.open("../examples/maze.txt");

    std::string str1 = std::string("tor");

    std::shared_ptr<Surface<Point>> s = make_surface(str1);

    s->set_points(file);
    std::vector<Point> p = search(s);

    for (auto &tm : p)
    {
        out << tm.x << ", " << tm.y << "\n";
    }

    REQUIRE (out.str() ==
             "20, 11\n21, 11\n21, 10\n22, 10\n23, 10\n24, 10\n24, 11\n24, 12\n23, 12\n23, 13\n22, 13\n21, 13\n20, 13\n20, "
             "14\n19, 14\n18, 14\n17, 14\n16, 14\n15, 14\n15, 15\n15, 16\n15, 0\n15, 1\n15, 2\n15, 3\n16, 3\n16, 4\n16, "
             "5\n16, 6\n16, 7\n17, 7\n17, 8\n18, 8\n19, 8\n20, 8\n21, 8\n");
}

TEST_CASE("Test_97", "Search")
{
    std::ifstream file;
    std::stringstream out;

    file.open("../examples/maze.txt");

    std::string str1 = std::string("cylinder");

    std::shared_ptr<Surface<Point>> s = make_surface(str1);

    s->set_points(file);
    std::vector<Point> p = search(s);

    for (auto &tm : p)
    {
        out << tm.x << ", " << tm.y << "\n";
    }

    REQUIRE (out.str() ==
             "20, 11\n21, 11\n21, 10\n22, 10\n23, 10\n24, 10\n24, 11\n24, 12\n23, 12\n23, 13\n22, 13\n21, 13\n20, 13\n20, "
             "14\n19, 14\n18, 14\n17, 14\n16, 14\n15, 14\n15, 13\n15, 12\n14, 12\n13, 12\n12, 12\n11, 12\n10, 12\n9, 12\n8, "
             "12\n7, 12\n7, 11\n7, 10\n6, 10\n5, 10\n5, 9\n5, 8\n4, 8\n3, 8\n2, 8\n1, 8\n0, 8\n31, 8\n30, 8\n29, 8\n28, 8\n27, "
             "8\n27, 7\n26, 7\n25, 7\n24, 7\n23, 7\n22, 7\n21, 7\n21, 8\n");
}

TEST_CASE("Test_98", "Search")
{
    std::ifstream file;
    std::stringstream out;

    file.open("../examples/maze.txt");

    std::string str1 = std::string("planar");

    std::shared_ptr<Surface<Point>> s = make_surface(str1);

    s->set_points(file);
    std::vector<Point> p = search(s);

    for (auto &tm : p)
    {
        out << tm.x << ", " << tm.y << "\n";
    }

    REQUIRE (out.str() ==
             "20, 11\n21, 11\n21, 10\n22, 10\n23, 10\n24, 10\n24, 11\n24, 12\n23, 12\n23, 13\n22, 13\n21, 13\n20, 13\n20, "
             "14\n19, 14\n18, 14\n17, 14\n16, 14\n15, 14\n15, 13\n15, 12\n14, 12\n13, 12\n12, 12\n11, 12\n10, 12\n9, 12\n8, "
             "12\n7, 12\n7, 11\n7, 10\n6, 10\n5, 10\n5, 9\n5, 8\n4, 8\n3, 8\n3, 7\n3, 6\n3, 5\n3, 4\n4, 4\n5, 4\n6, 4\n7, 4\n8, "
             "4\n8, 3\n9, 3\n10, 3\n11, 3\n12, 3\n13, 3\n14, 3\n15, 3\n16, 3\n16, 4\n16, 5\n16, 6\n16, 7\n17, 7\n17, 8\n18, "
             "8\n19, 8\n20, 8\n21, 8\n");
}

TEST_CASE("Test_99", "Search")
{
    std::ifstream file;
    std::stringstream out;

    file.open("../examples/part.txt");

    std::shared_ptr<Surface<Word>> s = make_surface_word();

    std::string str1 = std::string("very");
    std::string str2 = std::string("worry");

    s->set_points(file);
    s->start = Word(str1);
    s->finish = Word(str2);

    std::vector<Word> p = search(s);

    for (auto &tm : p)
    {
        out << tm.string << "\n";
    }

    REQUIRE (out.str() == "worry\nwordy\nword\nward\nwary\nvary\nvery\n");
}