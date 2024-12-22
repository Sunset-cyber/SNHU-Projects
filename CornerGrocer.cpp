//CS-210 Project 3
//Robert Szabo
//12/15/24

#include <iostream>
#include <string>
#include <fstream>
#include "CornerGrocer.h"
using namespace std;

CornerGrocer::CornerGrocer() {
}

CornerGrocer::CornerGrocer(string name) {
	this->name = name;
}

CornerGrocer::CornerGrocer(string name, int quantity) {
	this->name = name;
	this->quantity = quantity;
}

void CornerGrocer::setName(string productName) {
	name = productName;
}

void CornerGrocer::setQuantity(int productQty) {
	quantity = productQty;
}
string CornerGrocer::getName() const{
	return name;
}

int CornerGrocer::getQuantity() const {
	return quantity;
}

int CornerGrocer::getUserInput(int userInput) {
	return userInput;
}

//open the file and count frequencies of each item
void CornerGrocer::computeFrequency(string fileName) {
	ifstream inFS;
	inFS.open(fileName);
	string itemName;
	while (!inFS.eof()) {
		inFS >> itemName;
		grocerMap[itemName]++;
	}
}

//write data to file after computing the frequency
void CornerGrocer::writeToFile() {
	ofstream outFS;

	outFS.open("frequency.dat");

	map<string, int>::iterator grocerMapIterator;

	grocerMapIterator = grocerMap.begin();

	while (grocerMapIterator != grocerMap.end()) {
		outFS << grocerMapIterator->first << " " << grocerMapIterator->second << endl;
		++grocerMapIterator;
	}
}

//output the numeric value for the frequency of a specific word (Menu option 1)
int CornerGrocer::getFrequency(string name) {
	return grocerMap[name];
	}

//output all items and their numeric values in list format (Menu option 2)
void CornerGrocer::displayAllFrequencies() {
	for (const auto& pair : grocerMap) {
		cout << pair.first << " " << pair.second << endl;
	}
}

//output all items and their frequencies in histogram format (Menu option 3)
void CornerGrocer::displayAllFreqsHistogram() {
	for (const auto& pair : grocerMap) {
		cout << pair.first << " ";
		for (int i = 0; i < pair.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
}

//prompt the user to enter their choice of options
void CornerGrocer::initialDisplay() {
	cout << "Type in the number of your choice from the following options..." << endl;
	cout << "1. Search for the frequency of a specific item." << endl;
	cout << "2. Print a list with numbers representing the frequency of all items purchased." << endl;
	cout << "3. Print a histogram representing the frequency of all items purchased." << endl;
	cout << "4. Exit." << endl;
}



	

