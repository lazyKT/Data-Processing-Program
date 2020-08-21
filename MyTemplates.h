/*
  Here lies function templates
*/
#include <string>
#include <iostream>
#include <fstream>
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


// write data to file
template <typename T>
void write_data_tmpl (std::ofstream &opt, std::vector<T> vec)
{
  for (T t : vec)
    opt << t;
}
