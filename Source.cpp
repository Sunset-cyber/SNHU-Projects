//CS-210 Project 3
//Robert Szabo
//12/15/24

#include <iostream>
#include <string>
#include <fstream>
#include "CornerGrocer.h"
using namespace std;

int main() {

    CornerGrocer cg; //establish a variable for calling functions from .cpp

    //initialize variables that will take user input
    int userInput = 0;
    string userString = "";

    cg.computeFrequency("CS210_Project_Three_Input_File.txt");

    cg.writeToFile(); //write everything from text file in list format from map to frequency.dat

    //menu loop with input validation for entered integers
    while (userInput != 4) {
        cg.initialDisplay();
        cin >> userInput;

        if (userInput < 1 || userInput > 4) {
            cout << "Invalid input. Please enter a number 1-4." << endl;
            continue;
        }

        else if (userInput == 1) {
            cin >> userString;
            cout << cg.getFrequency(userString) << endl;
        }

        else if (userInput == 2) {
            cg.displayAllFrequencies();
        }

        else if (userInput == 3) {
            cg.displayAllFreqsHistogram();
        }



    }


    return 0;
}




        