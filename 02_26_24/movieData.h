#ifndef MOVIEDATA_H
#define MOVIEDATA_H
#include <string>

struct MovieData
{
    std::string title;
    std::string genre;
    std::string director;
    int year;
    int runningTime;
};

#endif