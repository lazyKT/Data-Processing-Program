/**
* Line2D class definition
**/

#include <iostream>
#include <iomanip>
#include <cmath>

#include "Point2D.h"
#include "Line2D.h"

typedef Point2D P2;


// default constructor
Line2D::Line2D() {}

// constructor
Line2D::Line2D( P2 pt1, P2 pt2 )
  : pt1(pt1), pt2(pt2) 
{}

// destructor
Line2D::~Line2D() { std::cout << "Line2D destroyed\n"; }


// setters
void Line2D::setLength()
{
  this->length = sqrt(pow((this->getPt1()).getScalarValue(), 2.00) + pow((this->getPt2()).getScalarValue(), 2.00));
}

void Line2D::setPt1(P2 pt1)
{
  this->pt1 = pt1;
}


void Line2D::setPt2(P2 pt2)
{
  this->pt2 = pt2;
}

// getters
P2 Line2D::getPt1() { return this->pt1; }

P2 Line2D::getPt2() { return this->pt2; }

double Line2D::getScalarValue()
{
  this->setLength();
  return this->length;
}


// operator overloading
std::ostream& operator<< (std::ostream& stream, Line2D* l2)
{
  stream << "[" << std::setw(4) << (l2->getPt1()).getX() << ", " << std::setw(4)
    << (l2->getPt1()).getY() << "]\t[" << std::setw(4) << (l2->getPt2()).getX() << ", "
    << std::setw(4) << (l2->getPt2()).getY() << "]\t" << l2->getScalarValue() << std::endl;  

  return stream;
}