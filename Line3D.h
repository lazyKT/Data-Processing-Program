/**
* Line3D class declartation
**/

#ifndef LINE3D_H
#define LINE3D_H

#include <iostream>
#include <fstream>

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
    friend std::ofstream& operator<< (std:: ofstream&, Line3D*);
    bool operator== (const Line3D&);

    // static functions for sorting
    static bool comparebyPt1_Asc (Line3D*, Line3D*);
    static bool comparebyPt1_Desc (Line3D*, Line3D*);
    static bool comparebyPt2_Asc (Line3D*, Line3D*);
    static bool comparebyPt2_Desc (Line3D*, Line3D*);
    static bool comparebyLength_Asc (Line3D*, Line3D*);
    static bool comparebyLength_Desc (Line3D*, Line3D*);
};


#endif