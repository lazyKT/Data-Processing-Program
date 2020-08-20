/**
  Declaration of Utility Functions
  * Utility functions handle the static disaply of the data
**/
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <set>
#include <iostream>

#include "Point2D.h"
#include "Point3D.h"

// print something like lists
template <typename T>
void Print(T list)
{
  for ( std::string str : list)
  {
    std::cout << str << std::endl;
  }
}


// display main menu
void main_menu(std::string &filter, std::string &s_o, std::string &s_c);

// a pause after every option
// saying that "Press enter to continue"
void enter_to_continue();

// process datasets
void extract_data(std::string &str, int*);
// sorting Point2D
void do_sorting(std::string &s_c, std::string &s_o, std::vector<Point2D*> &vec);
// sorting Point3D
// overloaded function
void do_sorting(std::string &s_c, std::string &s_o, std::vector<Point3D*> &vec);

#endif