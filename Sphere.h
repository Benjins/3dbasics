/*
This is the Sphere header file for the 3dbasics program, which provides simple tools
to represent and compute a 3D environment.

Author: Benji Smith, 2013
Licensed under the GNU GPL v3
Full License Text found in LICENSE file
*/

#ifndef SPHERE_H
#define SPHERE_H

struct Vector3;

struct Sphere{
    Vector3 origin;
    float radius;

    Sphere();
    Sphere(Vector3 origin);
    Sphere(Vector3 origin, float radius);

    bool Contains(const Vector3& tesPt) const;
};

#endif
