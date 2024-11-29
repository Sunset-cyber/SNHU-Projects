//Developer: Rob Szabo
//Date: 11/17/24
//CS-210 Project One 
//12 and 24-hour clock


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void displayClocks(int hours12, int mins12, int secs12, int hours24, int mins24, int secs24) { //function to display visual of clocks
	cout << "**************************\t\t" << "**************************" << endl;
	cout << "*      12-Hour Clock     *\t\t" << "*      24-Hour Clock     *" << endl;

	//convert ints to strings and set width to 2 so we can set fill to 0 so single digit numbers begin with 0
	std::string hours12Str = std::to_string(hours12);
	std::string mins12Str = std::to_string(mins12);
	std::string secs12Str = std::to_string(secs12);
	std::string hours24Str = std::to_string(hours24);
	std::string mins24Str = std::to_string(mins24);
	std::string secs24Str = std::to_string(secs24);

	/*decision branching to ensure clock displays time properly by converting each int variable to a string,
	setting the width to 2 and setting the fill to 0 so all numbers display as two digits even if it is a single digit number*/
	if (hours24 < 12) {
		std::cout << "*\t " << std::setw(2) << std::setfill('0') << hours12Str << ":" << std::setw(2) << std::setfill('0') << mins12Str << ":" << std::setw(2) << std::setfill('0') << secs12Str << "AM" << "\t *"
			<< "\t\t*" << "\t" << std::setw(2) << std::setfill('0') << hours24Str << ":" << std::setw(2) << std::setfill('0') << mins24Str << ":" << std::setw(2) << std::setfill('0') << secs24Str << "\t *" << std::endl;
	}

	else if (hours24 == 24) {
		hours24Str = "0";
		std::cout << "*\t " << std::setw(2) << std::setfill('0') << hours12Str << ":" << std::setw(2) << std::setfill('0') << mins12Str << ":" << std::setw(2) << std::setfill('0') << secs12Str << "AM" << "\t *"
			<< "\t\t*" << "\t" << std::setw(2) << std::setfill('0') << hours24Str << ":" << std::setw(2) << std::setfill('0') << mins24Str << ":" << std::setw(2) << std::setfill('0') << secs24Str << "\t *" << std::endl;
	}

	else if (mins24 >= 60) {
		mins24Str = "0";
		mins12Str = "0";
		if (hours24 <= 12) {
			std::cout << "*\t " << std::setw(2) << std::setfill('0') << hours12Str << ":" << std::setw(2) << std::setfill('0') << mins12Str << ":" << std::setw(2) << std::setfill('0') << secs12Str << "AM" << "\t *"
			<< "\t\t*" << "\t" << std::setw(2) << std::setfill('0') << hours24Str << ":" << std::setw(2) << std::setfill('0') << mins24Str << ":" << std::setw(2) << std::setfill('0') << secs24Str << "\t *" << std::endl;
		}
		else {
			std::cout << "*\t " << std::setw(2) << std::setfill('0') << hours12Str << ":" << std::setw(2) << std::setfill('0') << mins12Str << ":" << std::setw(2) << std::setfill('0') << secs12Str << "PM" << "\t *"
				<< "\t\t*" << "\t" << std::setw(2) << std::setfill('0') << hours24Str << ":" << std::setw(2) << std::setfill('0') << mins24Str << ":" << std::setw(2) << std::setfill('0') << secs24Str << "\t *" << std::endl;
		}
	}

	else if (secs24 >= 60) {
		secs24Str = "0";
		secs12Str = "0";
		mins24Str = "0";
		mins12Str = "0";

		if (hours24 <= 12) {
			std::cout << "*\t " << std::setw(2) << std::setfill('0') << hours12Str << ":" << std::setw(2) << std::setfill('0') << mins12Str << ":" << std::setw(2) << std::setfill('0') << secs12Str << "AM" << "\t *"
				<< "\t\t*" << "\t" << std::setw(2) << std::setfill('0') << hours24Str << ":" << std::setw(2) << std::setfill('0') << mins24Str << ":" << std::setw(2) << std::setfill('0') << secs24Str << "\t *" << std::endl;
		}

		else {
			std::cout << "*\t " << std::setw(2) << std::setfill('0') << hours12Str << ":" << std::setw(2) << std::setfill('0') << mins12Str << ":" << std::setw(2) << std::setfill('0') << secs12Str << "PM" << "\t *"
				<< "\t\t*" << "\t" << std::setw(2) << std::setfill('0') << hours24Str << ":" << std::setw(2) << std::setfill('0') << mins24Str << ":" << std::setw(2) << std::setfill('0') << secs24Str << "\t *" << std::endl;
		}
	}

	else {
		std::cout << "*\t " << std::setw(2) << std::setfill('0') << hours12Str << ":" << std::setw(2) << std::setfill('0') << mins12Str << ":" << std::setw(2) << std::setfill('0') << secs12Str << "PM" << "\t *"
			<< "\t\t*" << "\t" << std::setw(2) << std::setfill('0') << hours24Str << ":" << std::setw(2) << std::setfill('0') << mins24Str << ":" << std::setw(2) << std::setfill('0') << secs24Str << "\t *" << std::endl;
	}

	cout << "**************************\t\t" << "**************************" << endl;
}

void displayMenu() { //function to display the selection menu
	cout << "\n***************************" << endl;
	cout << "* 1-Add One Hour\t" << "  *" << endl;
	cout << "* 2-Add One Minute\t" << "  *" << endl;
	cout << "* 3-Add One Second\t" << "  *" << endl;
	cout << "* 4-Exit Program\t" << "  *" << endl;
	cout << "***************************" << endl;
}

//core of the program
int main() {

	int hour12 = 0;
	int minute12 = 0;
	int second12 = 0;
	int hour24 = 0;
	int minute24 = 0;
	int second24 = 0;

	int userInput = 0;

	displayClocks(hour12, minute12, second12, hour24, minute24, second24); //display the clocks before inputs

	std::cout << "Enter Hours: "; //prompt user for inputs
	cin >> hour24;

	std::cout << "Enter Minutes: ";
	cin >> minute24;

	std::cout << "Enter Seconds: ";
	cin >> second24;

	//setting the 12 hour clock to be 12 hours less than 24 hours
	hour12 = hour24 - 12;
	minute12 = minute24;
	second12 = second24;

	//correcting the 12 hour clock so if it is negative it adds 12 and shows an AM hour
	if (hour12 <= 0) {
		hour12 = hour12 + 12;
	}

	if (hour24 >= 24) {
		hour24 = 0;
		hour12 = 12;
	}

	if (minute24 >= 60) {
		minute24 = 0;
		minute12 = 0;
	}

	if (second24 >= 60) {
		second24 = 0;
		second12 = 0;
	}

	displayClocks(hour12, minute12, second12, hour24, minute24, second24);

	displayMenu();

	cin >> userInput;

	while (userInput > 0 && userInput < 5) {

		displayMenu();

		if (userInput == 4) {
			std::cout << "Exiting Program.";
			break;              //exit loop if user chooses to quit
		}

		switch (userInput) {

		case 1:
			hour12 = hour12 + 1;
			hour24 = hour24 + 1;
			break;

		case 2:
			minute12 = minute12 + 1;
			minute24 = minute24 + 1;
			break;

		case 3:
			second12 = second12 + 1;
			second24 = second24 + 1;
			break;
		}

		displayClocks(hour12, minute12, second12, hour24, minute24, second24);

		cin >> userInput;







	}

	return 0;

}