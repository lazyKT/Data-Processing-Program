/**
* Point2D Class Definitions
**/
#include <iostream>
#include <cmath>
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