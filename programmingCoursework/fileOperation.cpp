
#include "fileOperation.h"
#include <vector>

using namespace std;


std::vector<std::string> split(std::string stringToBeSplitted, std::string delimeter)
{
    std::vector<std::string> splittedString;
    int startIndex = 0;
    int  endIndex = 0;
    int tempIndex = 0;
    bool flag = false;

    while ((endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size() )
    {
        if (stringToBeSplitted[endIndex + 1] == ' ') {
            tempIndex = startIndex;
            startIndex = endIndex + 1;
            flag = true;
            continue;
        }

        if (flag) {
            startIndex = tempIndex;
            flag = false;
        }
        std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
        splittedString.push_back(val);
        startIndex = endIndex + delimeter.size();

    }
    if (startIndex < stringToBeSplitted.size())
    {
        std::string val = stringToBeSplitted.substr(startIndex);
        splittedString.push_back(val);
    }
    return splittedString;

}



fileOperation::fileOperation(string dataFileName)
{
    file.open(dataFileName, ios::in); //opening file
    if (!file.is_open())
        cout << "Failed to open " << dataFileName.c_str() << endl;
}


fileOperation::~fileOperation()
{
    closeFile();
}
//
bool fileOperation::getMovieDetail(Movie& movie) {
    vector<string> tempVector;
    string temp;
    if (file.is_open()) {
        getline(file, temp);
        if (!temp.empty()) {
            tempVector = split(temp, ",");

            movie.setMovieTitle(tempVector[0]);
            movie.setYearOfRelease(stoi(tempVector[1]));
            movie.setCertificate(tempVector[2]);
            movie.setGenres(tempVector[3]);
            movie.setDuration(stoi(tempVector[4]));
            movie.setAvgRating(stoi(tempVector[5]));
            return true;
        }
    }
    else
        cout << "File is closed" << endl;
    return false;
}
