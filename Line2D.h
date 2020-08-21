/**
* Line2D class declartion
**/

#ifndef LINE2D_H
#define LINE2D_H

#include <iostream>

#include "Point2D.h"

class Line2D
{
  private:
    Point2D pt1, pt2;
  protected:
    double length;
    virtual void setLength();
  public:
    // default constructor
    Line2D();
    // constructor
    Line2D( Point2D pt1, Point2D pt2);
    // destructor
    virtual ~Line2D();

    //getters
    Point2D getPt1();
    Point2D getPt2();
    virtual double getScalarValue();

    // setters
    void setPt1( Point2D pt1 );
    void setPt2( Point2D pt2 );

    // operator overlaoding
    // similar to toString() in java
    friend std::ostream& operator<< (std::ostream& stream, Line2D* l2);

    // static function for sorting
    static bool comparebyPt1_Asc (Line2D*, Line2D*);
    static bool comparebyPt1_Desc (Line2D*, Line2D*);
    static bool comparebyPt2_Asc (Line2D*, Line2D*);
    static bool comparebyPt2_Desc (Line2D*, Line2D*);
    static bool comparebyLength_Asc( Line2D*, Line2D*);
    static bool comparebyLength_Desc (Line2D*, Line2D*);
};


#endif