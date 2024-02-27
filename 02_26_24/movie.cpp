#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "movieData.h"

/* Create a program that uses a structure named MovieData to store the following information about a movie:

Title
Genre
Director
Year Released
Running time (in minutes) */

void printMovie(MovieData theMovie);
void printMovie(std::ostream &, MovieData theMovie);
MovieData inputMovie();
void resetStream();

int main()
{
    std::string title;
    std::string genre;
    std::string director;
    int year;
    int runningTime;

    std::string title2;
    std::string genre2;
    std::string director2;
    int year2;
    int runningTime2;

    std::string titles[10];
    std::string genres[10];
    std::string directors[10];
    std::ofstream myMovies;
    myMovies.open("movies.txt");
    MovieData movies[10];
    MovieData myFavoriteMovie;
    MovieData robinHood;
    myFavoriteMovie.title = "The Shawshank Redemption";
    myFavoriteMovie.genre = "Drama";
    myFavoriteMovie.director = "Frank Darabont";
    myFavoriteMovie.year = 1994;
    myFavoriteMovie.runningTime = 142;
    printMovie(myFavoriteMovie);
    movies[0] = myFavoriteMovie;

    robinHood.title = "Robin Hood";
    robinHood.genre = "Animated";
    robinHood.director = "Wolfgang Reitherman";
    robinHood.year = 1973;
    robinHood.runningTime = 83;
    movies[1] = robinHood;
    printMovie(myMovies, robinHood);
    printMovie(std::cout, robinHood);

    myFavoriteMovie = robinHood;
    title = title2;
    if (myFavoriteMovie.title == robinHood.title && myFavoriteMovie.year == robinHood.year && myFavoriteMovie.director == robinHood.director)
    {
    }

    for (int i = 2; i < 3; i++)
    {
        movies[i] = inputMovie();
    }
    for (int i = 0; i < 3; i++)
    {
        printMovie(myMovies, movies[i]);
    }
    myMovies.close();
    return 0;
}

void printMovie(MovieData theMovie)
{
    printMovie(std::cout, theMovie);
}

void printMovie(std::ostream &out, MovieData theMovie)
{
    out << "Title: " << theMovie.title << std::endl;
    out << "Genre: " << theMovie.genre << std::endl;
    out << "Director: " << theMovie.genre << std::endl;
    out << "Year Released: " << theMovie.year << std::endl;
    out << "Running Time (in minutes): " << theMovie.runningTime << std::endl;
}

MovieData inputMovie()
{
    MovieData theMovie;
    std::cout << "Enter the title of the movie: ";
    std::cin >> std::ws;
    getline(std::cin, theMovie.title);
    std::cout << "Enter the genre of the movie: ";
    std::cin >> std::ws;
    getline(std::cin, theMovie.genre);
    std::cout << "Enter the director's name: ";
    std::cin >> std::ws;
    getline(std::cin, theMovie.director);
    std::cout << "Enter the year the movie was released: ";
    std::cin >> theMovie.year;
    while (!std::cin || theMovie.year < 1887 || theMovie.year > 2034)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "The year should be after 1887 and before 2034." << std::endl;
        std::cout << "Enter the year the movie was released: ";
        std::cin >> theMovie.year;
    }
    std::cout << "Enter the runtime in minutes: ";
    std::cin >> theMovie.runningTime;
    while (!std::cin || theMovie.runningTime < 1)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "The runtime should be greater than 0" << std::endl;
        std::cout << "Enter the runtime in minutes: ";
        std::cin >> theMovie.runningTime;
    }
    return theMovie;
}

void resetStream()
{
    std::cout << "You entered something that is not a number!" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
