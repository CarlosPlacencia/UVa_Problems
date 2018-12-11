// One_Little_two_Little_Three_Little_Endians.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int N, M;
	while (cin >> N)
	{
		// Create a bitset
		bitset<32> NumBig(N);
		bitset<32> NumLittle;
		for (int i = 0; i < 8; i++)
		{
			NumLittle[24 + i] = NumBig[i];
			NumLittle[16 + i] = NumBig[i + 8];
			//
			//
		}
		M = NumLittle.to_ullong();
		cout << N << "   " << M << endl;
	}

    return 0;
}

