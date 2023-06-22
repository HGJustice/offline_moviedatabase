#pragma once
#include <iostream>
#include <string>

using namespace std;


class Movie
{
public:
    Movie();
    Movie(string title, int year, string cert, string gen, int lengthInMin, int rating);
    ~Movie();

    string getMovieTitle() { return movieTitle; }
    int getYearOfRelease() { return yearOfRelease; }
    string getCertificate() { return certificate; }
    string getGenres() { return genres; }
    int getDuration() { return duration; }
    int getAvgRating() { return avgRating; }


    void setMovieTitle(string title) { movieTitle = title; return; }
    void setYearOfRelease(int year) { yearOfRelease = year; return; }
    void setCertificate(string cert) { certificate = cert; return; }
    void setGenres(string gen) { genres = gen; return; }
    void setDuration(int length) { duration = length; return; }
    void setAvgRating(int rating) { avgRating = rating; }

    void printMovieDetails();

private:
    string movieTitle;
    int yearOfRelease;
    string certificate;
    string genres;
    int duration;
    int avgRating;
};

