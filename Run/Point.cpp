#include "Point.h"

stat char_to_status(char ch)
{
    switch (ch)
    {
        case '.':
            return (stat::blank);
        case '#':
            return (stat::wall);
        case 'F':
            return (stat::blank);
        case 'S':
            return (stat::blank);
    }
}

char status_to_char(stat st)
{
    switch (st)
    {
        case stat::blank:
            return '.';
        case stat::wall:
            return '#';
    }
}

