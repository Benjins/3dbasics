/*
This is the main source file for the 3dbasics program, which provides simple tools 
to represent and compute a 3D environment.

Author: Benji Smith, 2013
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#include <iostream>
#include "Vector3.h"

using namespace std;

int main(){
	
	//Create a Vector with given components
	Vector3 testVec(2.3, 4.5, 6.1);
	
	//Get the normalization of the Test Vector
	Vector3 normalVector = testVec.Normalized();
	
	//Print the values of the Test Vector
	cout << "\nTest Vector: ";
	testVec.Print();
	
	//Print the values of the normalized vector
	cout << "\nNormal Vector: ";
	normalVector.Print();
	
	//Find the dot product of the test vector and its normalized form
	cout << "\nDot Product fo the two: \n";
	cout << DotProduct(testVec,normalVector) << endl;
	
	
	//Print magnitude of the test vector
	cout << "\nMagnitude: \n";
	cout << testVec.Magnitude() << endl;
	
	return 0;
}
