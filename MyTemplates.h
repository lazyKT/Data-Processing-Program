/*
  Here lies function templates
*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Point2D.h"
#include "Point3D.h"


// display data
template <typename T>
void view_data(std::vector<T> vec)
{
  for (T t : vec)
    std::cout << t;
}
