/**
* Line3D class difinitions
**/

#include <iostream>
#include <iomanip>

#include "Point3D.h"
#include "Line3D.h"


typedef Point3D P3;


// default constructor
Line3D::Line3D() {}

// constructor
Line3D::Line3D( P3 pt1, P3 pt2)
  :pt1(pt1), pt2(pt2)
  {
  }

// destructor
Line3D::~Line3D(){ std::cout << "Point3D destroyed\n"; }


// getters
P3 Line3D::getPt1()
{
  return this->pt1;
}

P3 Line3D::getPt2()
{
  return this->pt2;
}


// setters
void Line3D::setPt1(P3 pt1) { this->pt1 = pt1; }
void Line3D::setPt2(P3 pt2) { this->pt2 = pt2; }

void Line3D::setLength()
{
  
}


// '<<' operator overloading
std::ostream& operator<< (std::ostream& out, Line3D* l3)
{
  out << "[" << std::setw(4) << (l3->getPt1()).getX() << ", " << std::setw(4) << (l3->getPt1()).getY()
    << ", " << std::setw(4) << (l3->getPt1()).getZ() << "]" << std::setw(4) << "[" << std::setw(4) 
    << (l3->getPt2()).getX() << ", " << std::setw(4) << (l3->getPt2()).getY() << ", " << std::setw(4)
    << (l3->getPt2()).getZ() << "]" << std::setw(10) << "LENGTH" << std::endl;

  return out;
}
