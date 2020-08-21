/**
* Line3D class declartation
**/

#ifndef LINE3D_H
#define LINE3D_H

#include <iostream>

#include "Line2D.h"
#include "Point3D.h"


class Line3D: public Line2D
{
  private:
    Point3D pt1, pt2;
  protected:
    void setLength() override;
  public:
    // cosntructor
    Line3D();
    // cosntructor
    Line3D(Point3D pt1, Point3D pt2);
    // destructor
    ~Line3D() override;

    // getters
    Point3D getPt1();
    Point3D getPt2();
    double getScalarValue() override;

    // setters
    void setPt1( Point3D pt1 );
    void setPt2( Point3D pt2 );

    // '<<'operator overloading
    friend std::ostream& operator<< (std::ostream&, Line3D*);
};


#endif