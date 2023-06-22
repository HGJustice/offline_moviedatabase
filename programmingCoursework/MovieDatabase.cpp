
#include "MovieDatabase.h"
#include "Movie.h"
#include "fileOperation.h"
#include <algorithm>

using namespace std;


bool compareBasedOnYear(Movie& obj1, Movie& obj2) {
    return obj1.getYearOfRelease() < obj2.getYearOfRelease();
}

bool compareBasedOnLength(Movie& obj1, Movie& obj2) {
    return obj1.getDuration() < obj2.getDuration();
}


MovieDatabase::MovieDatabase(string fileName)
{
    dataFile = new(fileOperation)(fileName);
}

MovieDatabase::~MovieDatabase()
{
    dataFile->closeFile();
    if (nullptr != dataFile) {
        delete dataFile;
        dataFile = nullptr;
    }
}

void MovieDatabase::AddMoviesToDB()
{
    Movie temp;
    while (dataFile->getMovieDetail(temp)) {
        movieList.push_back(temp);
    }
    dataFile->closeFile();
}

void MovieDatabase::sortMovieList(vector<Movie>& tempList) {
    std::sort(tempList.begin(), tempList.end(), compareBasedOnYear);
}

void MovieDatabase::DisplayAllMovies() {
    vector<Movie> sortedList(movieList);
    sortMovieList(sortedList);
    for (vector<Movie>::iterator itr = sortedList.begin(); itr != sortedList.end(); itr++) {
        itr->printMovieDetails();
    }
}

Movie MovieDatabase::ThirdLongestFilmNoir() {
    vector<Movie> filmNoir;
    FindMovieBasedOnGenres("Film-Noir", filmNoir);
    std::sort(filmNoir.begin(), filmNoir.end(), compareBasedOnLength);

    //for (int i = 0; i < filmNoir.size();i++) {
    //	cout << filmNoir[i].getMovieTitle() << " - " << filmNoir[i].getDuration() << endl;
    //}

    return filmNoir[filmNoir.size()-3];
}

Movie MovieDatabase::EighthMostRecentUnratedFilm() {
    vector<Movie> Unratedfilm;
    FindMovieBasedOnCertificate("UNRATED", Unratedfilm);
    std::sort(Unratedfilm.begin(), Unratedfilm.end(), compareBasedOnYear);

    //for (int i = 0; i < Unratedfilm.size(); i++) {
    //	cout << Unratedfilm[i].getMovieTitle() << " - " << Unratedfilm[i].getYearOfRelease() << endl;
    //}

    return Unratedfilm[Unratedfilm.size() - 8];
}

void MovieDatabase::FindMovieBasedOnCertificate(string Certificate, vector<Movie>& list) {
    for (int i = 0; i < movieList.size(); i++) {
        if (string::npos != movieList[i].getCertificate().find(Certificate)) {
            list.push_back(movieList[i]);
        }
    }
}

void MovieDatabase::FindMovieBasedOnGenres(string genres, vector<Movie>& list) {
    for (int i=0; i < movieList.size(); i++) {

        if (string::npos != movieList[i].getGenres().find(genres)) {
            list.push_back(movieList[i]);
        }
    }
}

Movie MovieDatabase::FindLongestTitle() {
    int longestSize = -1;
    int longestMovieIndex = -1;

    for (int i = 0; i < movieList.size(); i++) {
        int size = movieList[i].getMovieTitle().size();
        if (longestSize < size) {
            longestSize = size;
            longestMovieIndex = i;
        }
    }

    return movieList[longestMovieIndex];
}
