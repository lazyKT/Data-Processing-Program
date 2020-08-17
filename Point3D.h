/**
* Declartation of Class Point3D
**/

#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>

#include "Point2D.h"

class Point3D : public Point2D
{
  protected:
    int z;
    void setDisFrOrigin() override;
  public:
    // default constructor
    Point3D();
    // constructor
    Point3D(int x, int y, int z);
    // destructor
    ~Point3D();


    // getters
    int getZ();

    // setters
    void setZ(int z);

    // operator overloading
    friend std::ostream& operator<<(std::ostream& stream, Point3D* p);
};


#endif