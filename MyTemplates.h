/*
  Here lies function templates
*/
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "Point2D.h"
#include "Point3D.h"


// display data
template <typename T>
void view_data(std::vector<T> vec)
{
  for (T t : vec)
    std::cout << t;
}


// write data to file
template <typename T>
void write_data_tmpl (std::ofstream &opt, std::vector<T> vec)
{
  int record = 0;

  for (T t : vec)
  {
    opt << t;
    record++;
  }
  std::cout << std::endl << record << " records outputed successfully\n\n";
}


// scalar difference
template <typename T>
double scalar_difference (T t1, T t2)
{
  return abs( t1->getScalarValue() - t2->getScalarValue() );
}


// equals
template <typename T>
bool equals (T t1, T t2)
{
    return t1 == t2;
}