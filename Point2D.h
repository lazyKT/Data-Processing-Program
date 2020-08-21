/**
  Point2D Class declartation
*/

#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


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

    // '<<' Operator Overloading
    friend std::ostream& operator<< (std::ostream&, Point2D*);
    friend std::ofstream& operator<<(std::ofstream& ofs, Point2D*);
    
    // static functions for Sorting 
    static bool comparebyX_Asc(Point2D*, Point2D*);
    static bool comparebyX_Desc(Point2D*, Point2D*);
    static bool comparebyY_Asc(Point2D*, Point2D*);
    static bool comparebyY_Desc(Point2D*, Point2D*);
    static bool comparebyScalar_Asc(Point2D*, Point2D*);
    static bool comparebyScalar_Desc(Point2D*, Point2D*);
};


#endif