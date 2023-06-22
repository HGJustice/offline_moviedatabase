#pragma once
#include <iostream>
#include <fstream>
#include "string"
#include "Movie.h"

using namespace std;

class fileOperation
{
public:
    fileOperation() {}
    fileOperation(string dataFileName);
    ~fileOperation();
    bool getMovieDetail(Movie& movie);
    void closeFile() {
        if (file.is_open()) {
            file.close();
        }
    }

private:
    ifstream file;
};

