/**
* Line3D class difinitions
**/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

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

double Line3D::getScalarValue()
{
  this->setLength();
  return this->length;
}



// setters
void Line3D::setPt1(P3 pt1) { this->pt1 = pt1; }
void Line3D::setPt2(P3 pt2) { this->pt2 = pt2; }

void Line3D::setLength()
{
  this->length = sqrt( pow( ((this->getPt1()).getX() - (this->getPt2()).getX()), 2.00) 
    + pow( ((this->getPt1()).getY() - (this->getPt2()).getY()), 2.00) 
    + pow( ((this->getPt1()).getZ() - (this->getPt2()).getZ()), 2.00) );
}


// '<<' operator overloading
std::ostream& operator<< (std::ostream& out, Line3D* l3)
{
  out << "[" << std::setw(4) << (l3->getPt1()).getX() << ", " << std::setw(4) << (l3->getPt1()).getY()
    << ", " << std::setw(4) << (l3->getPt1()).getZ() << "]" << std::setw(4)  << "[" << std::setw(4) 
    << (l3->getPt2()).getX() << ", " << std::setw(4) << (l3->getPt2()).getY() << ", " << std::setw(4)
    << (l3->getPt2()).getZ() << "]\t" << std::setw(5) << l3->getScalarValue() << std::endl;

  return out;
}

// overload function for file stream '<<' operator
std::ofstream& operator<< (std::ofstream& opt, Line3D* l3)
{
  opt << "[" << std::setw(4) << (l3->getPt1()).getX() << ", " << std::setw(4) << (l3->getPt1()).getY()
    << ", " << std::setw(4) << (l3->getPt1()).getZ() << "]" << std::setw(4)  << "[" << std::setw(4) 
    << (l3->getPt2()).getX() << ", " << std::setw(4) << (l3->getPt2()).getY() << ", " << std::setw(4)
    << (l3->getPt2()).getZ() << "]\t" << std::setw(5) << l3->getScalarValue() << std::endl;

  return opt;
}
