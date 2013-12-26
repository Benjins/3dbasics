/*
This is the Matrix source file for the 3dbasics program, which provides simple tools
to represent and compute a 3D environment.

Author: Benji Smith, 2013
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#include "Matrix.h"
#include "Vector3.h"
#include "Vector2.h"

struct Vector2;
struct Vector3;

//This is the identity matrix
Matrix3x3::Matrix3x3(){
    row1 = X_AXIS; //(1,0,0)
    row2 = Y_AXIS; //(0,1,0)
    row3 = Z_AXIS; //(0,0,1)
}

Matrix3x3::Matrix3x3(Vector3 _row1, Vector3 _row2, Vector3 _row3){
    row1 = _row1;
    row2 = _row2;
    row3 = _row3;
}

Vector3 Matrix3x3::Column1() const{
    return Vector3(row1.x, row2.x, row3.x);
}

Vector3 Matrix3x3::Column2() const{
    return Vector3(row1.y, row2.y, row3.y);
}

Vector3 Matrix3x3::Column3() const{
    return Vector3(row1.z, row2.z, row3.z);
}

//The transpoe is basically taking rows, and making them columns (reflecting it across the diagonal)
Matrix3x3 Matrix3x3::Transpose() const{
    return Matrix3x3(Column1(), Column2(), Column3());
}

 //Adding matrices adds each corresponding value
Matrix3x3 Matrix3x3::operator+(const Matrix3x3& multMatrix) const{
    return Matrix3x3( row1+ multMatrix.row1,
                      row2+ multMatrix.row2,
                      row3+ multMatrix.row3);
}

 //Multiplying matrices is a bit mathy, but effectively combines their transformations, much like multiplying Quaternions
Matrix3x3 Matrix3x3::operator*(const Matrix3x3& param) const{
    return Matrix3x3( Vector3( DotProduct(row1, param.Column1()),
                               DotProduct(row1, param.Column2()),
                               DotProduct(row1, param.Column3())),

                      Vector3( DotProduct(row2, param.Column1()),
                               DotProduct(row2, param.Column2()),
                               DotProduct(row2, param.Column3())),

                      Vector3( DotProduct(row3, param.Column1()),
                               DotProduct(row3, param.Column2()),
                               DotProduct(row3, param.Column3())));
}

//Multiplying a matrix by a vector transforms that vector (again, details are a bit mathy)
Vector3 Matrix3x3::operator*(const Vector3& multVector) const{
    return Vector3( DotProduct(row1, multVector),
                    DotProduct(row2, multVector),
                    DotProduct(row3, multVector));
}

/*
//Not needed now, and they didn't work to begin with
Vector3 ArrayToVector3(float arr[]){
    return Vector3(arr[0],
                   arr[1],
                   arr[2]);
}

Vector2 ArrayToVector2(float arr[]){
    return Vector3(arr[0],
                   arr[1]);
}*/





