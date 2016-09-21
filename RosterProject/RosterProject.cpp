/*
Author: Adams, Richard
Group members: Alvarado, Ron; Amezcua, David;  Baeza, Oscar;
Assignment: Programming Assignment Two
Course: COMP B12
Instructor: Richard Miles
Date submitted: 2016/09/20
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LinearSearch(vector<int> jerseyNumber, int numbersSize, int key) {
   int i = 0;
   
   for (i = 0; i < numbersSize; ++i) {
      if (jerseyNumber.at(i) == key) {
         return i;
      }
   }
   
   return -1; /* not found */
}

void PrintMenu() {
	cout << "MENU" << endl;
	cout << "a - Add player" << endl;
	cout << "d - Remove player" << endl;
	cout << "u - Update player rating" << endl;
	cout << "r - Output players about a rating" << endl;
	cout << "o - Output roster" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
	cout << "Choose an option: ";
	return;
}
void OutputRoster(const vector<int>& jerseyNumber, const vector<int>& playerRating) {
	cout << "ROSTER";
	for (int i = 1; i <= jerseyNumber.size(); i++) {
		cout << "Player " << i << " -- Jersey number: " << jerseyNumber.at(i - 1)
			<< ", Rating: " << playerRating.at(i - 1) << endl;
	}
}
void AddPlayer(vector<int>& jerseyNumber, vector<int>& playerRating, int jNumber, int pRating) {
	jerseyNumber.push_back(jNumber);
	playerRating.push_back(pRating);
	cout << endl;
}
void RemovePlayer(vector<int>& jerseyNumber, vector<int>& playerRating, int jNumber) {
	int numbersSize = jerseyNumber.size();
	int index;
	index = LinearSearch(jerseyNumber, numbersSize, jNumber);
	jerseyNumber.erase(jerseyNumber.begin()+index);
	playerRating.erase(playerRating.begin()+index);
	cout << endl;
}
void UpdateRating(vector<int>& jerseyNumber, vector<int>& playerRating, int jNumber, int pRating) {
	cout << "FIXME";
	cout << endl;
}
void AboveRating(const vector<int>& jerseyNumber, const vector<int>& playerRating, int pRating) {
	cout << "FIXME";
	cout << endl;
	cout << endl;
}

int main()
{
	vector<int> jerseyNumber;
	vector<int> playerRating;
	int i = 0;
	int j = 0;
	int userInput;
	int jNumber;
	int pRating;

	for (i = 1; i < 6; i++)
	{
		cout << "Enter player " << i << "'s number: ";
		cin >> userInput;
		jerseyNumber.push_back(userInput);
		cout << "Enter player " << i << "'s rating: ";
		cin >> userInput;
		playerRating.push_back(userInput);
		cout << endl;
	}
	for ( i = 1; i < 6; i++){
		cout << "Player " << i << " -- Jersey number: " << jerseyNumber.at(i-1)
			<< ", Rating: " << playerRating.at(i-1) << endl;
	}
	cout << endl;
	char userInput2;
	do
	{
		
		PrintMenu();
		cin >> userInput2;
		
		if (userInput2 == 'o') {
			OutputRoster(jerseyNumber, playerRating);
			cout << endl;
		}
		else if (userInput2 == 'a')
		{
			
			cout << "Enter a new player's jersey number: ";
			cin >> jNumber;
			cout << "Enter a new player's rating: ";
			cin >> pRating;
			AddPlayer(jerseyNumber, playerRating, jNumber, pRating);
			cout << endl;
		}
		else if (userInput2 == 'd') {
			cout << "Enter a jersey number: ";
			cin >> jNumber;
			RemovePlayer(jerseyNumber, playerRating, jNumber);
			cout << endl;
		}
		else if (userInput2 == 'u')
		{
			cout << "Enter a jersey number: ";
			cin >> jNumber;
			cout << "Enter new rating for player: ";
			cin >> pRating;
			cout << endl;
			UpdateRating(jerseyNumber, playerRating, jNumber, pRating);
			cout << endl;
		}
		else if (userInput2 == 'r') {
			cout << "Enter a rating: ";
			cin >> pRating;
			cout << "ABOVE " << pRating << endl;
			AboveRating(jerseyNumber, playerRating, pRating);
		}
	} while (userInput2 != 'q');
	return 0;
}

