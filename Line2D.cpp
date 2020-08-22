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


/**
 *  operator overloading 
 * */

// overloading iostram '<<' operator
std::ostream& operator<< (std::ostream& stream, Line2D* l2)
{
  stream << "[" << std::setw(4) << (l2->getPt1()).getX() << ", " << std::setw(4)
    << (l2->getPt1()).getY() << "]\t[" << std::setw(4) << (l2->getPt2()).getX() << ", "
    << std::setw(4) << (l2->getPt2()).getY() << "]\t" << l2->getScalarValue() << std::endl;  

  return stream;
}

// overloading file stream '<<' operator
std::ofstream& operator<< (std::ofstream& opt, Line2D* l2)
{
  opt << "[" << std::setw(4) << (l2->getPt1()).getX() << ", " << std::setw(4)
    << (l2->getPt1()).getY() << "]\t[" << std::setw(4) << (l2->getPt2()).getX() << ", "
    << std::setw(4) << (l2->getPt2()).getY() << "]\t" << l2->getScalarValue() << std::endl;  

  return opt;
}

bool Line2D::operator== (const Line2D& l1)
{ 
  return pt1 == l1.pt1 && pt2 == l1.pt2;
}


// static functions for sorting

// compare by Pt-1 in ascending order
bool Line2D::comparebyPt1_Asc (Line2D* l1, Line2D* l2)
{
  if ( (l1->getPt1()).getX() == (l2->getPt1()).getX() )
    return (l1->getPt1()).getY() < (l2->getPt1()).getY();
  
  return (l1->getPt1()).getX() < (l2->getPt1()).getX();
}

// compare by pt-1 in descending order
bool Line2D::comparebyPt1_Desc (Line2D* l1, Line2D* l2)
{
  return !(comparebyPt1_Asc(l1, l2));
}


// compare by Pt-2 in ascending order
bool Line2D::comparebyPt2_Asc (Line2D* l1, Line2D* l2)
{
  if ( (l1->getPt2()).getX() == (l2->getPt2()).getX() )
    return (l1->getPt2()).getY() < (l2->getPt2()).getY();
  
  return (l1->getPt2()).getX() < (l2->getPt2()).getX();
}

// compare by pt-2 in descending order
bool Line2D::comparebyPt2_Desc (Line2D* l1, Line2D* l2)
{
  return !(comparebyPt2_Asc(l1, l2));
}


// compare by Length value in ascending order
bool Line2D::comparebyLength_Asc (Line2D* l1, Line2D* l2)
{
  return l1->getScalarValue() < l2->getScalarValue();
}

// compare by Length value in descending order
bool Line2D::comparebyLength_Desc (Line2D* l1, Line2D* l2)
{
  return l1->getScalarValue() > l2->getScalarValue();
}