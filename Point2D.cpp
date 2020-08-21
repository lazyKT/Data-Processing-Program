/**
* Point2D Class Definitions
**/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>

#include "Point2D.h"

// default constructor
Point2D::Point2D() {}


Point2D::Point2D(int x, int y)
  : x(x), y(y){}

Point2D::~Point2D() { }


/** -- setters -- **/
void Point2D::setX(int x) { this->x = x; }
void Point2D::setY(int y) { this->y = y; }

// calculate distance from origin 
void Point2D::setDisFrOrigin()
{
  this->disFrOrigin = sqrt(pow(this->x, 2.00) + pow(this->y, 2.00));
}


/** -- getters -- **/

int Point2D::getX()
{
  return this->x;
}

int Point2D::getY()
{
  return this->y;
}

double Point2D::getScalarValue()
{
  this->setDisFrOrigin();
  return this->disFrOrigin;
}


// '<<' Operator Overloading
std::ostream& operator<<(std::ostream& stream, Point2D* p)
{

  stream << "[" << std::setw(4) << p->getX() << ", " << std::setw(4) << p->getY() 
    << "]\t" << p->getScalarValue() << std::endl;

  return stream;
}

std::ofstream& operator<< (std::ofstream& opt, Point2D* p)
{
  opt << "[" << std::setw(4) << p->getX() << ", " << std::setw(4) << p->getY() 
    << "]\t" << p->getScalarValue() << std::endl;

  return opt;
}



/**
 * Sorting
*/

// Sort by X in ascending order
bool Point2D::comparebyX_Asc(Point2D * p1, Point2D * p2)
{
  if (p1->getX() == p2->getX())
    return p1->getY() < p2->getY();
  return p1->getX() < p2->getX();
}

// sort by x in descending order
bool Point2D::comparebyX_Desc(Point2D * p1, Point2D *p2)
{
  // return opposite of ascending order
  return !(Point2D::comparebyX_Asc(p1, p2));
}


// sort by Y in ascending order
bool Point2D::comparebyY_Asc(Point2D * p1, Point2D * p2)
{
  if (p1->getY() == p2->getY())
    return p1->getX() < p2->getX();
  return p1->getY() < p2->getY();
}


// sort by Y in descending order
bool Point2D::comparebyY_Desc(Point2D *p1, Point2D *p2)
{
  return !(Point2D::comparebyY_Asc(p1, p2));
}


// sort by scalar value in ascending order
bool Point2D::comparebyScalar_Asc(Point2D *p1, Point2D *p2)
{
  return p1->getScalarValue() < p2->getScalarValue();
}

// sort by scalar value in descending order
bool Point2D::comparebyScalar_Desc(Point2D* p1, Point2D* p2)
{
  return p1->getScalarValue() > p2->getScalarValue();
}