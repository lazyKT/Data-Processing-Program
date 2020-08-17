/**
* Point3D Class Definition
**/

#include "Point2D.h"
#include "Point3D.h"

#include <iostream>
#include <cmath>
#include <iomanip>


// default constructor
Point3D::Point3D(){}

// constructor
Point3D::Point3D( int x, int y, int z )
  : Point2D(x, y), z(z){}


// destructor
Point3D::~Point3D() { std::cout << "Poin3D destroyed" << std::endl; }

// calculate di
void Point3D::setDisFrOrigin()
{
  this->disFrOrigin = sqrt( pow(this->x, 2.00) + pow(this->y, 2.00) + pow(this->z,2.00));
}


// getters
int Point3D::getZ()
{
  return this->z;
}


// setters
 void Point3D::setZ(int z)
{
  this->z = z;
}


// operatoer overloading for '<<' operator
std::ostream& operator<<(std::ostream& stream, Point3D* p)
{

  stream << "[" << std::setw(4) << p->getX() << ", " << std::setw(4) << p->getY() << ", " 
    << std::setw(4) << p->getZ() << "]\t" << p->getScalarValue() << std::endl;

  return stream;
}

