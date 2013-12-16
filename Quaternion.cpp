/*
This is the Quaternion source file for the 3dbasics program, which provides simple tools 
to represent and compute a 3D environment.

Author: Benji Smith, 2013
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#include "Quaternion.h"
#include "Vector3.h"
#include <cmath>
#include <iostream>

using namespace std;

//Default constructor
Quaternion::Quaternion(){
	w = 1;
	x = 0;
	y = 0;
	z = 0;
}

Quaternion::Quaternion(float wIn, float xIn, float yIn, float zIn){
	w = wIn;
	x = xIn;
	y = yIn;
	z = zIn;
}

//Constructs a Quaternion that represents the given axis-angle rotation
Quaternion::Quaternion(const Vector3& axis, float angle){
	float halfAngle = angle/2;
	w = sin(halfAngle);
	
	Vector3 normalizedAxis = axis.Normalized();
	float cosHalfAngle = sqrt(1 - w*w); //because cos(x)^2 + sin(x)^2 = 1
	
	x = normalizedAxis.x * cosHalfAngle;
	y = normalizedAxis.y * cosHalfAngle;
	z = normalizedAxis.z * cosHalfAngle;
}

Quaternion::Quaternion(const Quaternion& quat){
	w = quat.w;
	x = quat.x;
	y = quat.y;
	z = quat.z;
}

void Quaternion::Print() const{
	cout << "\nThe W value is: " << w << endl;
	cout << "\nThe X value is: " << x << endl;
	cout << "\nThe Y value is: " << y << endl;
	cout << "\nThe Z value is: " << z << endl;
}




