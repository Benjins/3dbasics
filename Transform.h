/*
This is the Transform header file for the 3dbasics program, which provides simple tools
to represent and compute a 3D environment.

Author: Benji Smith, 2014
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#ifndef TRANSFORM_H
#define TRANSFORM_H

/*
The Transform structure holds information about the three main transformations for a 3D rigidbody: position, rotation, and scale.
Note that position is an affine transformation, so this structure is not equivalent to the Basis3D structure, which only holds linear transformations.
Also, the basis vectors that the Transform produces are always orthogonal (perpendicular to one another), since they're just rotated and scaled.
*/

struct Transform
{
    Vector3 position;
    Quaternion rotation;
    Vector3 scale;

    Transform();
    Transform(const Vector3& _position, const Quaternion& _rotation, const Vector3& _scale);

    //NOTE: does not take into account transform.position, since that's an affine transformation.
    Basis3D GetBasis() const;

    Vector3 TransformVector(const Vector3& original) const;
};

#endif // TRANSFORM_H
