/*
This is the Vector3 source file for the 3dbasics program, which provides simple tools 
to represent and compute a 3D environment.

Author: Benji Smith, 2013
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#include "Vector3.h"
#include <cmath>

using namespace std;

//Default constructor
Vector3::Vector3(){
	x = 0;
	y = 0;
	z = 0;
}

//Constructor for given x, y, and z values
Vector3::Vector3(float xIn, float yIn, float zIn){
	x = xIn;
	y = yIn;
	z = zIn;
}

//Constructor given another vector reference
Vector3::Vector3(const Vector3& vector){
	x = vector.x;
	y = vector.y;
	z = vector.z;
}

//The following operators all apply to vector math, namely adding two vectors
//and scalar multiplication.
Vector3 Vector3::operator+(const Vector3& addVec) const{
	return Vector3(x + addVec.x, y + addVec.y, z + addVec.z);
}

Vector3 Vector3::operator-(const Vector3& subVec) const{
	return Vector3(x - subVec.x, y - subVec.y, z - subVec.z);
}

Vector3 Vector3::operator*(float scale) const{
	return Vector3(x * scale, y * scale, z * scale);
}

Vector3 Vector3::operator/(float scale) const{
	return Vector3(x / scale, y / scale, z / scale);
}

//Comparison operator just checks to see if all corresponding components are equal
bool Vector3::operator==(const Vector3& compareVec) const{
	return (x == compareVec.x && y == compareVec.y && z == compareVec.z);
}

//The length of the vector
float Vector3::Magnitude() const{
	return sqrt(x*x + y*y + z*z);
}

//The square of the length of the vector (optimization, doesn't require a sqrt())
float Vector3::MagnitudeSquared() const{
	return (x*x + y*y + z*z);
}

//Return the vector's normalized form 
//NOTE: This does not modify the original vector.  To do that, use Normlize() instead
Vector3 Vector3::Normalized() const{
	float magnitude = Magnitude();
	return *this / magnitude;
}

//Set the vector to its normalizd form, so that its magnitude (length) is one
void Vector3::Normalize(){
	float magnitude = Magnitude();
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}

//Print all values of the vector in a readable form (used mostly for debugging)
void Vector3::Print() const{
	cout << "\nThe X value is: " << x << endl;
	cout << "\nThe Y value is: " << y << endl;
	cout << "\nThe Z value is: " << z << endl;
}

//Returns the amount of overlap bewtween two vectors
float DotProduct(const Vector3& a, const Vector3& b){
	return a.x *b.x + a.y * b.y + a.z * b.z;
}

//Returns a Vector orthogonal (perpendicular) to the two input vectors
//The math seems complicated, but it's not important to understand what the cross product
Vector3 CrossProduct(const Vector3& a, const Vector3& b){
	return Vector3( (a.y*b.z - a.z*b.y), 
					(a.z*b.x - a.x*b.z), 
					(a.x*b.y - a.y*b.x));
}

Vector3 VectorProject(const Vector3& toProject, const Vector3& projectOnto){
	return projectOnto * (DotProduct(toProject, projectOnto) / projectOnto.MagnitudeSquared());
}



