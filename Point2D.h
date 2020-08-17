/**
  Point2D Class declartation
*/

#ifndef POINT2D_H
#define POINT2D_H

#include <string>


class Point2D
{
  protected:
    int x, y;
    double disFrOrigin;
    virtual void setDisFrOrigin();
  public:
    // default constructor
    Point2D();
    // constructor
    Point2D( int x, int y);
    // destructor
    virtual ~Point2D();

    int getX();
    int getY();
    double getScalarValue();

    void setX(int x);
    void setY(int y);

};


#endif