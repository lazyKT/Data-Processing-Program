/**
* Declartation of Class Point3D
**/

#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include <fstream>

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
    friend std::ofstream& operator<< (std::ofstream& opt, Point3D* p);

    // static member functions for sorting 
    static bool comparebyX_Asc (Point3D*, Point3D*);
    static bool comparebyX_Desc (Point3D*, Point3D*);
    static bool comparebyY_Asc (Point3D*, Point3D*);
    static bool comparebyY_Desc (Point3D*, Point3D*);
    static bool comparebyZ_Asc (Point3D*, Point3D*);
    static bool comparebyZ_Desc (Point3D*, Point3D*);
    static bool comparebyScalar_Asc (Point3D*, Point3D*);
    static bool comaprebyScalar_Desc (Point3D*, Point3D*);
};


#endif