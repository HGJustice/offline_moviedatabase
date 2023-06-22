#include "Movie.h"


Movie::Movie()
{
    movieTitle = "";
    yearOfRelease = -1;
    certificate = "";
    genres = "";
    duration = -1;
    avgRating = -1;
}

Movie::Movie(string title, int year, string cert, string gen, int lengthInMin, int rating)
{
    movieTitle = title;
    yearOfRelease = year;
    certificate = cert;
    genres = gen;
    duration = lengthInMin;
    avgRating = rating;
}


Movie::~Movie()
{
}

void Movie::printMovieDetails() {
    cout << movieTitle << "\t\t" << yearOfRelease << "\t\t" << certificate << "\t\t" << genres << "\t\t" << duration << "\t\t" << avgRating << endl;
}
