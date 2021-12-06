//Nedim Basic
//5th of December, 2021
//Week 6 programming assignment

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//declare constants
const int max_bowlers = 10;
const int max_scores = 5;

bool GetBowlingData(const char* fileName, string bowlerNames[], int bowlerScores[][max_scores]) {
	ifstream myFile;
	myFile.open(fileName); //open the file
	if (!myFile) return false; //returns false if the file fails to open

	for (int i = 0; i < max_bowlers; i++) {
		myFile >> bowlerNames[i]; //read the name from the file and store it into the bowler name array
		for (int j = 0; j < max_scores; j++) {
			myFile >> bowlerScores[i][j]; //read the score from the file and store it into the bowler score array
		}
	}

	return true;
}

void GetAverageScore(int bowlerScores[][max_scores], int averageScores[]) {
	int total = 0;
	for (int i = 0; i < max_bowlers; i++) {
		for (int j = 0; j < max_scores; j++) {
			total += bowlerScores[i][j]; //add all the scores up into the total
		}
		averageScores[i] = total / max_scores; //divide the total by the max number of scores to get the average
		total = 0;
	}
}

void PrettyPrintResults(string names[], int scores[][max_scores], int avgScores[]) {
	for (int i = 0; i < max_bowlers; i++) {
		cout << "BOWLER NAME: " << names[i] << endl; //display the bowler name
		cout << "SCORES: "; //display the scores by the bowler
		for (int j = 0; j < max_scores; j++) {
			cout << scores[i][j] << " "; //cout statement
		}
		cout << endl;
		cout << "AVERAGE: " << avgScores[i] << endl << endl; //display the average count of scores
	}
};

int main() {
	//declare variables
	string bowlerNames[max_bowlers];
	int bowlerScores[max_bowlers][max_scores];
	int averageScores[max_bowlers];

	//Try to open the file, if the file does not open, end the program and display that the file failed to open
	if (!GetBowlingData("BowlingScores.txt", bowlerNames, bowlerScores)) {
		cout << "The file failed to open" << endl;
		return 1;
	}

	GetAverageScore(bowlerScores, averageScores); //call the GetAverageScore function

	PrettyPrintResults(bowlerNames, bowlerScores, averageScores); //call the PrettyPrintResults function
}