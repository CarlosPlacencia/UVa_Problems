/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Rotated squares : 10016 : Galactic_Banana

Data structure required : Vectors

Tricks of the trade : A matrix of NxN has its rings modified based
					  on specific instructions.
					  
*/////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int Number_of_Matrices = 0;
	int Number_of_Rotations = 0;
	int Number_of_Rings = 0;
	int Upper_Left = 0; // Help traverse the rings
	int Lower_Right = 0;
	int Size = 0; // Size of the Matrix
	int Ring_Size = 0;
	bool first = true;

	cin >> Number_of_Matrices;

	while (Number_of_Matrices != 0) //Count down Numb_Matices
	{
		cin >> Size;
		Ring_Size = Size;
		vector<vector<int>> Matrix(Size, vector<int>(Size));

		for (int r = 0; r < Size; r++) // Loading the matrix
		{
			for (int c = 0; c < Size; c++)
			{
				cin >> Matrix[r][c];
				//cout << Matrix[r][c];
			}
			//cout << "\n";
		}

		// Calculate how many rings the matrix will have
		if ((Size % 2) == 0) Number_of_Rings = Size / 2;
		else Number_of_Rings = ((Size / 2) + 1);
		// cout << "Number of rings: " << Number_of_Rings << "\n";
		//cout << "\n";

		//Looping through the rings and loading the rotation instructions
		for (int ring = 0; ring < Number_of_Rings; ring++)
		{
			//cout << "RING: " << ring << "\n";

			cin >> Number_of_Rotations;
			Upper_Left = ring;
			Lower_Right = (Size - ring - 1);

			vector<int> Rotations(Number_of_Rotations); // Keeps track of the rotations

			for (int j = 0; j < Number_of_Rotations; j++)
			{
				

				cin >> Rotations[j];
				// cout << "Ring: " << ring << " Rotation: " << Rotations[j] << " ";

				/********************************************
				 	1. Will be the UPSIDE-DOWN FLIP         
				 	2. Will be the LEFT-RIGHT FLIP          
				 	3. Will be the MAIN INVERSE DIAGONAL    
				 	4. Will be the MAIN DIAGONAL            
				*********************************************/
				//cout << "\n";
				//cout << "Doing the operation on ring: " << ring << "\n";

				switch (Rotations[j])
				{
				case 1:
					
					//cout << "UPSIDE-DOWN FLIP " << "\n";
					//cout << "********************" << "\n";
					// tells you how many rows need a swap
					for (int i = 0; i < (Ring_Size / 2); i++)
					{
						for (int c = Upper_Left; c <= Lower_Right; c++)
						{
							//cout << Matrix[Upper_Left + i][c] << " ";

							// Seperates the numbers in the boundaries from the ones in the middle
							if (Upper_Left + i == ring || c == ring || 
								Upper_Left == Size - (ring + 1) || c == Size - (ring + 1))  // ### May have to change Size to Ring_Size ###
							{
								//cout << Matrix[Upper_Left + i][c] << " ";
								swap(Matrix[Upper_Left + i][c], Matrix[Lower_Right - i][c]);
							}
							//else cout << "* ";
						}
						//cout << "\n";
					}
					break;
				case 2:
					//cout << "LEFT-RIGHT FLIP " << "\n";
					//cout << "********************" << "\n";
					// Tells you how many columns need to be solved
					for (int i = 0; i < (Ring_Size / 2); i++)
					{
						for (int c = Upper_Left; c <= Lower_Right; c++)
						{
							//cout << Matrix[Upper_Left + i][c] << " ";

							// Seperates the numbers in the boundaries from the ones in the middle
							if (Upper_Left + i == ring || c == ring ||
								Upper_Left == Size - (ring + 1) || c == Size - (ring + 1))  // ### May have to change Size to Ring_Size ###
							{
								//cout << Matrix[Upper_Left + i][c] << " ";
								swap(Matrix[c][Upper_Left + i], Matrix[c][Lower_Right - i]);
							}
							//else cout << "* ";
						}
						//cout << "\n";
					}
					break;
				case 3:
					//cout << "MAIN DIAGONAL " << "\n";
					//cout << "********************" << "\n";
					for (int r = Upper_Left + 1; r <= Lower_Right; r++)
					{
						//  Add the Swap instruction
						swap(Matrix[r][Upper_Left], Matrix[Upper_Left][r]);
						//cout << Matrix[r][Upper_Left] << " ";
					}
					for (int c = Upper_Left + 1; c < Lower_Right; c++)
					{
						// Add the swap instruction
						swap(Matrix[Lower_Right][c], Matrix[c][Lower_Right]);
						//cout << Matrix[Lower_Right][c] << " ";
					}
					break;
				case 4:
					//cout << "MAIN INVERSE DIAGONAL " << "\n";
					//cout << "********************" << "\n";
					for (int r = Upper_Left + 1, counter = (Lower_Right - 1);
						r <= Lower_Right; r++, counter--)
					{
						//  Add the Swap instruction
						//cout << Matrix[r][Lower_Right] << " ";
						swap(Matrix[r][Lower_Right], Matrix[Upper_Left][counter]);
					}
					for (int c = Upper_Left + 1, counter = (Lower_Right - 1);
						c < Lower_Right; c++, counter--)
					{
						// Add the swap instruction
						//cout << Matrix[Lower_Right][c] << " ";
						swap(Matrix[Lower_Right][c], Matrix[counter][Upper_Left]);
					}
					break;
				}
				//cout << "\n";
			}
			Ring_Size -= 2; // Decreasing by two to get the ring size;
		}

		// Printing out the New Matrix
		for (int r = 0; r < Size; r++) // Loading the matrix
		{
			for (int c = 0; c < Size; c++)
			{

				printf("%d", Matrix[r][c]);
				if (c < Size - 1)
					printf(" ");
			}
			cout << "\n";
		}
	
		Number_of_Matrices--;
	}

    return 0;
}

