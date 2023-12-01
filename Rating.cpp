#include "Rating.h"
#include <iostream>
#include <fstream>
using namespace std;
int Rating::RatingID = 1;

Rating::Rating() : User()
{
    MenuItemID = 0;
    CustomerID = userID;
    Score = 0;
    Comment = " ";
    // Default constructor implementation
}

Rating::~Rating()
{
    // Destructor implementation
}

void Rating::Rate()
{
    // Taking input for each attribute
    cout << "RatingID: " << RatingID << endl;

    cout << "Enter MenuItemID: " << MenuItemID << endl;

    cout << "Enter CustomerID: " << CustomerID << endl;
    // this portion will give the rating of the entire program.
    cout << "Enter Score (1-5): ";
    cin >> Score;
    if (Score == 1)
    {
        rating = "*";
        cout << rating << endl;
    }
    else if (Score == 2)
    {
        rating = "**";
        cout << rating << endl;
    }
    else if (Score == 3)
    {
        rating = "***";
        cout << rating << endl;
    }
    else if (Score == 4)
    {
        rating = "****";
        cout << rating << endl;
    }
    else if (Score == 5)
    {
        rating = "*****";
        cout << rating << endl;
    }


    cout << "Enter Comment: ";
    /////////////////////////////////
    cin.ignore(); // Clear the input buffer
    getline(cin, Comment);
    ++RatingID;
}
void Rating::SaveToFile()
{
    ofstream outputFile("rating.txt", ios::app);

    if (!outputFile.is_open())
    {
        cerr << "Error opening the file." << endl;
        return;
    }

    outputFile << "RatingID: " << RatingID << endl;
    outputFile << "MenuItemID: " << MenuItemID << endl;
    outputFile << "CustomerID: " << CustomerID << endl;
    outputFile << "Score: " << Score << endl;
    outputFile << "Comment: " << Comment << endl;

    outputFile.close();
}
