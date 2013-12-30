/*
This is the Matrix header file for the 3dbasics program, which provides simple tools
to represent and compute a 3D environment.

Author: Benji Smith, 2013
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#ifndef MATRIX_H
#define MATRIX_H

#include "Vector2.h"
#include "Vector3.h"

#define IDENTITY_3x3

struct Vector2;
struct Vector3;

/* The Matrix structs hold information about arrays, i.e. matrices.
A matrix represents a transformation between vectors, and multiplying
a matrix and a vector transforms that vector by the given amount.
*/

struct Matrix3x3{
    Vector3 row1;
    Vector3 row2;
    Vector3 row3;

    Matrix3x3();
    Matrix3x3(Vector3 _row1, Vector3 _row2, Vector3 _row3);

    //float** realMatrix() const;
    //^I'm not ready to do this yet, don't know enough about arrays

    Vector3 Column1() const;
    Vector3 Column2() const;
    Vector3 Column3() const;

    //The transpose is basically taking rows, and making them columns (reflecting it across the diagonal)
    Matrix3x3 Transpose() const;

    //Adding matrices adds each corresponding value
    Matrix3x3 operator+(const Matrix3x3& multMatrix) const;

    //Multiplying matrices is a bit mathy, but effectively combines their transformations, much like multiplying Quaternions
    Matrix3x3 operator*(const Matrix3x3& multMatrix) const;

    //Multiplying a matrix by a vector transforms that vector (again, details are a bit mathy)
    Vector3 operator*(const Vector3& multVector) const;

    //Print the values of the matrix in a readable format
    void Print() const;
};

//Vector3 ArrayToVector3(float arr[]);
//Vector2 ArrayToVector2(float arr[]);
//^Ignore for now, not being used


Matrix3x3 MakeScaleMatrix(float scale);

#endif // MATRIX_H
