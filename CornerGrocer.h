//CS-210 Project 3
//Robert Szabo
//12/15/24

#pragma once
#ifndef CORNERGROCER_H
#define CORNERGROCER_H

#include <string>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class CornerGrocer
{
public:
	CornerGrocer();
	CornerGrocer(std::string name);
	CornerGrocer(std::string name, int quantity);
	
	void setName(std::string name);
	void setQuantity(int quantity);

	string getName() const;
	int getQuantity() const;

	void addItem();
	void removeItem();

	void computeFrequency(string fileName);

	void writeToFile();

	int getFrequency(string name);

	void displayAllFrequencies();

	void displayAllFreqsHistogram();

	void initialDisplay();

	int getUserInput(int userInput);
private:
	std::string name;
	int quantity;
	map<string, int>grocerMap;
};

#endif