/*
  Here lies function templates
*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Point2D.h"


// display data
template <typename T>
void view_data(std::vector<T> vec)
{
  for (T t : vec)
  {
    std::cout << t;
  }
}


// do sorting of the data
template <typename T>
void do_sorting(std::string &filter, std::string &s_c, std::string &s_o, std::vector<T> &vec)
{
  if (filter == "Point2D")
  {
    // do sorting for Point2D
    if (s_c == "x-ordinate")
    {
      if (s_o == "ASC")
        std::sort(vec.begin(), vec.end(), Point2D::comparebyX_Asc);
      else
        std::sort(vec.begin(), vec.end(), Point2D::comparebyX_Desc);
    }
    else if (filter == "y-ordinate")
    {
      if (s_o == "ASC")
        std::sort(vec.begin(), vec.end(), Point2D::comparebyY_Asc);
      else
        std::sort(vec.begin(), vec.end(), Point2D::comparebyY_Desc);
    }
  }
  else if (filter == "Point3D")
  {
    // do sorting for Point3D
  }
  else
  {
    // do sorting of Line2D and Line3D
  }
}

