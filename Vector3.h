/*
This is the Vector3 header file for the 3dbasics program, which provides simple tools 
to represent and compute a 3D environment

Author: Benji Smith, 2013
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/


#ifndef VECTOR3_H
#define	VECTOR3_H

#include <cmath>
#include <iostream>

using namespace std;

/*
The Vector3 structure, which holds information about a three-dimensional vector

Most of the functions here involve vector math, so if anything doesn't look familiar,
just Google it.  It should be easy to get the intuition behind it.
*/

struct Vector3 {
	float x;
	float y;
	float z;
	
	Vector3(){
		x = 0;
		y = 0;
		z = 0;
	}
	
	Vector3(float xIn, float yIn, float zIn){
		x = xIn;
		y = yIn;
		z = zIn;
	}
	
	Vector3 operator+(const Vector3& addVec) const{
		return Vector3(x + addVec.x, y + addVec.y, z + addVec.z);
	}
	
	Vector3 operator-(const Vector3& subVec) const{
		return Vector3(x - subVec.x, y - subVec.y, z - subVec.z);
	}
	
	Vector3 operator*(float scale) const{
		return Vector3(x * scale, y * scale, z * scale);
	}
	
	Vector3 operator/(float scale) const{
		return Vector3(x / scale, y / scale, z / scale);
	}
	
	//The length of the vector
	float Magnitude() const{
		return sqrt(x*x + y*y + z*z);
	}
	
	//Return the vector's normalized form 
	//NOTE: This does not modify the original vector.  To do that, use Normlize() instead
	Vector3 Normalized() const{
		float magnitude = Magnitude();
		return *this / magnitude;
	}
	
	//Set the vector to its normalizd form, so that its magnitude (length) is one
	void Normalize(){
		float magnitude = Magnitude();
		x = x / magnitude;
		y = y / magnitude;
		z = z / magnitude;
	}
	
	//Print all values of the vector in a readable form (used mostly for debugging)
	void Print() const{
		cout << "\nThe X value is: " << x << endl;
		cout << "\nThe Y value is: " << y << endl;
		cout << "\nThe Z value is: " << z << endl;
	}
	
};

//The Dot Product, or overlap of two vectors
float DotProduct(const Vector3& a, const Vector3& b);

#endif





