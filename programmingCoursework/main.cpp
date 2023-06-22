

#include <iostream>
#include "fileOperation.h"
#include "Movie.h"
#include "MovieDatabase.h"
#include <string>
using namespace std;

const string dataFileName = "films.txt";

int main(int argc, char *argv[])
{
    string fileName = "films.txt";
    if (2 == argc) {
        fileName = argv[1];
    }
    else
    {
        fileName = dataFileName;
    }

    int choice;
    Movie movieResult;
    MovieDatabase MovieDB(fileName);
    MovieDB.AddMoviesToDB();
    cout << "Welcome to Movie World." << endl;
    do {
        cout << "Please select your choice.	\
			\n0 - To quit	\
			\n1 - Display all movies in DB. \
			\n2 - Display 3rd longest Film-Noir.	\
			\n3 - Display 8th most recent UNRATED movie. \
			\n4 - Display movie with longest title. \
			\nPlease select from 1 to 4. ";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Thanks for using this app.";
                break;
            case 1:
                MovieDB.DisplayAllMovies();
                cout << "\n*********************************\n";
                break;
            case 2:
                movieResult = MovieDB.ThirdLongestFilmNoir();
                movieResult.printMovieDetails();
                cout << "\n*********************************\n";
                break;

            case 3:
                movieResult = MovieDB.EighthMostRecentUnratedFilm();
                movieResult.printMovieDetails();
                cout << "\n*********************************\n";
                break;

            case 4:
                movieResult = MovieDB.FindLongestTitle();
                movieResult.printMovieDetails();
                cout << "\n*********************************\n";
                break;

            default:
                cout << "Please select correct option." << endl;
                break;

        }
    } while ((0 != choice));
}

