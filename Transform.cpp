/*
This is the Transform source file for the 3dbasics program, which provides simple tools
to represent and compute a 3D environment.

Author: Benji Smith, 2014
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#include "Transform.h"
#include "Vector3.h"

struct Vector3;


Transform::Transform()
{
    position = Vector3();
    rotation = Quaternion();
    scale    = Vector3(1,1,1);
}

Transform::Transform(const Vector3& _position, const Quaternion& _rotation, const Vector3& _scale){
    position = _position;
    rotation = _rotation;
    scale    = _scale;
}

//NOTE: does not take into account transform.position, since that's an affine transformation.
Basis3D Transform::GetBasis() const{
    return (Basis3D( Rotate(X_AXIS * scale.x, rotation),
                     Rotate(Y_AXIS * scale.y, rotation),
                     Rotate(Z_AXIS * scale.z, rotation)));
}

Vector3 Transform::TransformVector(const Vector3& original) const;


