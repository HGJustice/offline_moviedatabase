#pragma once

#include <iostream>
#include <vector>
#include "fileOperation.h"

using namespace std;


class MovieDatabase
{
public:
    MovieDatabase(string fileName);
    ~MovieDatabase();
    void DisplayAllMovies();
    void AddMoviesToDB();
    void sortMovieList(vector<Movie>& tempList);
    Movie ThirdLongestFilmNoir();
    void FindMovieBasedOnGenres(string genres, vector<Movie>& list);
    Movie EighthMostRecentUnratedFilm();
    void FindMovieBasedOnCertificate(string Certificate, vector<Movie>& list);

    Movie FindLongestTitle();

private:
    fileOperation* dataFile;
    vector<Movie> movieList;
};

