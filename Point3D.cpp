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
Point3D::~Point3D() {}

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
    << std::setw(4) << p->getZ() << "]\t"  << p->getScalarValue() << std::endl;

  return stream;
}

// operator overloading for std::ofstream '<<' operator
std::ofstream& operator<< (std::ofstream& opt, Point3D* p)
{
  opt << "[" << std::setw(4) << p->getX() << ", " << std::setw(4) << p->getY() << ", " 
    << std::setw(4) << p->getZ() << "]\t" << p->getScalarValue() << std::endl;

  return opt;
}

bool Point3D::operator== (const Point3D& p)
{
  return x == p.x && y == p.y && z == p.z;
}



/* 
  static sorting functions
*/


// sort by x-ordinate in ascending order
bool Point3D::comparebyX_Asc(Point3D* p1, Point3D* p2)
{
  if (p1->getX() == p2->getX())
    return p1->getY() < p2->getY();

  return p1->getX() < p2->getX();
}

// sort by x-ordinate in descending order
bool Point3D::comparebyX_Desc(Point3D* p1, Point3D* p2)
{
  // return the opposite of ascending order
  return !(Point3D::comparebyX_Asc(p1, p2));
}


// sort by y-ordinate in ascending order
bool Point3D::comparebyY_Asc( Point3D* p1, Point3D* p2 )
{
  if (p1->getY() == p2->getY())
    return p1->getX() < p2->getX();

  return p1->getY() < p2->getY();
}

// sort by y-ordinate in descending order
bool Point3D::comparebyY_Desc( Point3D* p1, Point3D* p2)
{
  return !(Point3D::comparebyY_Asc(p1, p2));
}


// sort by z-ordinate in ascending order
bool Point3D::comparebyZ_Asc( Point3D* p1, Point3D* p2)
{
  if (p1->getZ() == p2->getZ())
    return p1->getX() < p2->getX();
  
  return p1->getZ() < p2->getZ();
}

// sort by z-ordinate in descending order
bool Point3D::comparebyZ_Desc( Point3D* p1, Point3D* p2)
{
  return !(Point3D::comparebyZ_Asc(p1, p2));
}


// compare by scalar value in ascending order
bool Point3D::comparebyScalar_Asc( Point3D* p1, Point3D* p2)
{
  return p1->getScalarValue() < p2->getScalarValue();
}

// compare by scalar value in descending order
bool Point3D::comaprebyScalar_Desc( Point3D* p1, Point3D* p2)
{
  return p1->getScalarValue() > p2->getScalarValue();
}
