/*/////////////////////////////////////////////////////////////////////

Carlos Placencia : Is This Integration? : 10209 : Galactic_Banana

Data structure required :

Tricks of the trade : Geometry!!!

*/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <cmath>

# define Pi 3.141592653589793238462643383279502884L

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //Speed!!
	cin.tie(nullptr);

	double L = 0.0; // length of one side of the square

	while (cin >> L) {
		double Cosine = cos(75 * Pi / 180.0); // Converting to degrees
		double X = 30.0 / 360.0;

		/* Calculating the are of the Big Square */
		double AreaofSquare = (L * L);

		/* Calculating the Area of the  striped region */
		double a = ((2.0 * L) * Cosine); // Gives me the base of the isosceles triangle
		double s = ((a + L + L) / 2); // Harem's Rule
		double A = sqrt((s * (s - a) * (s - L) * (s - L)));
		double B = ((Pi * (L * L)) * X);
		double C = ((B - A) * 4.0);
		double D = (a * a);
		double E = (D + C); // Area of the striped region
		printf("%.3lf ", E);

		/* Calculating the Are of the Dotted region */
		double G = ((((a * a) * sqrt(3.0)) / 4.0) + (B - A)) * 4;
		printf("%.3lf ", G);

		/* Calculating the rest of the region */
		double H = AreaofSquare - (E + G);
		printf("%.3lf\n", H);
	}
    return 0;
}