/*
This is the main source file for the 3dbasics program, which provides simple tools
to represent and compute a 3D environment.

Author: Benji Smith, 2013
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#include <iostream>
#include "3dbasics.h"

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
	cout << "\nDot Product of the two: \n";
	cout << DotProduct(testVec,normalVector) << endl;

	//Print magnitude of the test vector
	cout << "\nMagnitude: \n";
	cout << testVec.Magnitude() << endl;

	//Project test vector onto the x-axis
	cout << "\nTest Vector projected onto the x-axis.\n";
	VectorProject(testVec,X_AXIS).Print();

	//A Quaternion that represents a rotation of 1.1 radians about testVec
	Quaternion testQuat(testVec, 1.1);

	//A Quaternion that represents a rotation of 0.7 radians about testVec
	Quaternion secondQuat(testVec, 0.7);

	//Print the three quaternions
	cout << "\ntestQuat:\n";
	testQuat.Print();
	cout << "\nsecondQuat:\n";
	secondQuat.Print();
	//Print the first two quaternions multiplied together
	cout << "\ntestQuat * secondQuat:\n";
	(testQuat*secondQuat).Print();

	cout << "\nsecondQuat * testQuat:\n";
	(secondQuat*testQuat).Print();

	//Non-commutativity of Quaternions
	cout << "\nQuaternion(1,2,-2,4) * Quaternion(3,-.4,-.6,2):\n";
	(Quaternion(1,2,-2,4) * Quaternion(3,-.4,-.6,2)).Print();

	//This will output differently than the above command
	cout << "\nQuaternion(3,-.4,-.6,2) * Quaternion(1,2,-2,4):\n";
	(Quaternion(3,-.4,-.6,2) * Quaternion(1,2,-2,4)).Print();

	//Will be +Z-axis
	cout << "\nX-Axis rotated about y-axis by 90 degrees\n";
	(Rotate(X_AXIS, Quaternion(Y_AXIS, 90.0f*DEG2RAD))).Print();

	//Will be -X axis
	cout << "\nX-Axis rotated about y-axis by 90 degrees, then y-axis by 90 degrees again\n";
	(Rotate(X_AXIS, Quaternion(Y_AXIS, 90.0f*DEG2RAD) * Quaternion(Y_AXIS, 90.0f*DEG2RAD))).Print();

    //Create a Basis that is the Cartesian coordinte system, exactly flipped about the origin
	Basis3D flip(X_AXIS * -1, Y_AXIS * -1, Z_AXIS * -1);

	//Flip the testVec into local coordinates for the flip cooridnate system
	Vector3 flippedVec = flip.ConvertGlobalToLocal(testVec);

    //Print the testVec flipped about the origin
	cout << "\nTestVec flipped about the origin.\n";
	flippedVec.Print();

    //This matrix represents a linear transformation that keeps X unchanged, inverts Y, and doubles Z
	Matrix3x3 testMatrix( Vector3(1, 0,  0),
                          Vector3(0, -1, 0),
                          Vector3(0, 0,  2));

    //This transforms the test vector according to the matrix
    Vector3 transformedVec = testMatrix * testVec;

    //Print the transformed vector
    cout << "\nTransformed Vector: \n";
    transformedVec.Print();

	return 0;
}
