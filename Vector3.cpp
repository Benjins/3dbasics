/*
This is the Vector3 source file for the 3dbasics program, which provides simple tools 
to represent and compute a 3D environment

Author: Benji Smith, 2013
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#include "Vector3.h"
#include <cmath>

using namespace std;

//Returns the dot product (the amount of overlap) bewtween two vectors
float DotProduct(const Vector3& a, const Vector3& b){
	return a.x *b.x + a.y * b.y + a.z * b.z;
}



