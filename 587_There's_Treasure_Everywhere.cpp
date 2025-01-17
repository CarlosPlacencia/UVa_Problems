/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : There's Treasure Everywhere : 587 : Galactic_Banana

Data structure required :

Tricks of the trade : 

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

double X = 1 / sqrt(2);
pair< double,  double> Movements(int Moves, string Dir, pair< double,  double> Point);

int main()
{
	double Moves = 0;
	int index = 0;
	int number = 1;
	string Direction = "";
	string Dir = "";

	while (getline(cin, Direction) && Direction != "END") {
		pair< double,  double> Point(0.0, 0.0); // Starting Point
		cout << "Map #" << number << "\n";
		while (Direction[index] != '.') {
			while(Direction[index] != ','){
				// Determine if the character is a Number or a Letter
				if (Direction[index] < 65) { // Means the character is a Number
					Moves = Moves * 10 + Direction[index] - '0'; // Horner's Rule
					index++;
				}
				else if (Direction[index] > 65) {
					Dir += Direction[index]; // Storing the Direction (N, E, S W, NE...)
					index++;
				}
				if (Direction[index] == '.') break;
			}
			// Call the function
			Point = Movements(Moves, Dir, Point);
			Moves = 0;
			Dir = "";
			if (Direction[index] == '.') break;
			else index++;
		}
		printf("The treasure is located at (%.3lf,%.3lf).\n", Point.first, Point.second);
		printf("The distance to the treasure is %.3lf.\n\n",
				sqrt(Point.first*Point.first + Point.second * Point.second));
		number++;
		index = 0;
	}

	return 0;
}

pair < double, double> Movements(int Moves, string Dir, pair< double,  double> Point) {

	if (Dir == "N")
	{
		Point.second += Moves; // Move up +
	}
	else if (Dir == "E")
	{
		Point.first += Moves; // Move to the right +
	}
	else if (Dir == "S") 
	{
		Point.second -= Moves;// Move Down -
	}
	else if (Dir == "W")
	{
		Point.first -= Moves; // Move to the left -
	}
	else if (Dir == "NE")
	{
		Point.first += Moves * X;
		Point.second += Moves * X;
	}
	else if (Dir == "SE")
	{
		Point.first += Moves * X;
		Point.second -= Moves * X;
	}
	else if (Dir == "SW")
	{
		Point.first -= Moves * X;
		Point.second -= Moves * X;
	}
	else// Will be NW
	{
		Point.first -= Moves * X;
		Point.second += Moves * X;
	}
	return Point;
}