/**
* Utility functions definitions
* Utility functions handle the static disaply of the data
**/
#include "Utils.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <limits>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"


// main menu
void main_menu(std::string &filter, std::string &sort_c, std::string &sort_o)
{
  std::cout << "\n1)\tRead in data\n";
  std::cout << "2)\tSpecify filtering criteria (current: " << filter << ")\n";
  std::cout << "3)\tSpecify sorting criteria (current: " << sort_c <<")\n";
  std::cout << "4)\tSpecify sorting order (current: " << sort_o <<")\n";
  std::cout << "5)\tView data\n";
  std::cout << "6)\tStore data\n";
  std::cout << "7)\tQuit\n\n"; 
}


// pause after displaying each option
void enter_to_continue()
{

  std::cout << "\n< ... Press enter to continue ... >\n";
  std::cin.get();

  if (std::cin.peek() == '\n')
  {
    std::cin.get();
    return;
  }
  
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::cin.get();
}


// Process data
void extract_data(std::string &str, int* arr)
{
  int deli_pos = 0;
  int i = 0;

  while ( i < 3)
  {
    // find delimeter to split data
    deli_pos = str.find(", ");
    // std::cerr << "deli position - " << deli_pos << std::endl;
    // std::cerr << "str = " << str << std::endl;
    std::string res = str.substr(0, deli_pos);

    int n = stoi(res);
    arr[i] = n;

    str.erase(0, deli_pos+1);

    if ( str.find(", ") == std::string::npos)
    {
      // last data segment
      i ++;
      n = stoi(str);
      arr[i] = n;
      break;
    }
    i++;
  }
}


// sorting in Point2D
void do_sorting(std::string &s_c, std::string &s_o, std::vector<Point2D*> &vec)
{
  if (s_c == "x-ordinate")
  {
    if (s_o == "ASC")
      std::sort(vec.begin(), vec.end(), Point2D::comparebyX_Asc);
    else
      std::sort(vec.begin(), vec.end(), Point2D::comparebyX_Desc);
  }
  else if (s_c == "y-ordinate")
  {
    if (s_o == "ASC")
      std::sort(vec.begin(), vec.end(), Point2D::comparebyY_Asc);
    else
      std::sort(vec.begin(), vec.end(), Point2D::comparebyY_Desc);
  }
  else
  {
    if (s_o == "ASC")
      std::sort(vec.begin(), vec.end(), Point2D::comparebyScalar_Asc);
    else
      std::sort(vec.begin(), vec.end(), Point2D::comparebyScalar_Desc);
  }
}

// sorting in Point3D
void do_sorting(std::string &s_c, std::string &s_o, std::vector<Point3D*> &vec)
{
  //do sorting for Point3D
  if (s_c == "x-ordinate")
  {
    if (s_o == "ASC")
      std::sort(vec.begin(), vec.end(), Point3D::comparebyX_Asc);
    else
      std::sort(vec.begin(), vec.end(), Point3D::comparebyX_Desc);
  }
  else if (s_c == "y-ordinate")
  {
    if (s_o == "ASC")
      std::sort(vec.begin(), vec.end(), Point3D::comparebyY_Asc);
    else
      std::sort(vec.begin(), vec.end(), Point3D::comparebyY_Desc);
  }
  else if (s_c == "z-ordinate")
  {
    if (s_o == "ASC")
      std::sort(vec.begin(), vec.end(), Point3D::comparebyZ_Asc);
    else
      std::sort(vec.begin(), vec.end(), Point3D::comparebyZ_Desc);
  }
  else
  {
    if (s_o == "ASC")
      std::sort(vec.begin(), vec.end(), Point3D::comparebyScalar_Asc);
    else
      std::sort(vec.begin(), vec.end(), Point3D::comparebyScalar_Desc);
  }
}


// do sorting for Line2D
void do_sorting (std::string &s_c, std::string &s_o, std::vector<Line2D*> &vec)
{
  if (s_c == "Pt. 2")
  {
    if (s_o == "DESC")
      std::sort(vec.begin(), vec.end(), Line2D::comparebyPt2_Desc);
    else
      std::sort(vec.begin(), vec.end(), Line2D::comparebyPt2_Asc);
  }
  else if (s_c == "Length")
  {
    if (s_o == "DESC")
      std::sort(vec.begin(), vec.end(), Line2D::comparebyLength_Desc);
    else
      std::sort(vec.begin(), vec.end(), Line2D::comparebyLength_Asc);
  }
  else
  {
    if (s_o == "DESC")
      std::sort(vec.begin(), vec.end(), Line2D::comparebyPt1_Desc);
    else
      std::sort(vec.begin(), vec.end(), Line2D::comparebyPt1_Asc);
  }
  
}


// do sorting for Line3D
void do_sorting (std::string &s_c, std::string &s_o, std::vector<Line3D*> &vec)
{
  if (s_c == "Pt. 2")
  {
    if (s_o == "DESC")
      std::sort(vec.begin(), vec.end(), Line3D::comparebyPt2_Desc);
    else
      std::sort(vec.begin(), vec.end(), Line2D::comparebyPt2_Asc);
  }
  else if (s_c == "Length")
  {
    if (s_o == "DESC")
      std::sort(vec.begin(), vec.end(), Line3D::comparebyLength_Desc);
    else
      std::sort(vec.begin(), vec.end(), Line3D::comparebyLength_Asc);
  }
  else
  {
    if (s_o == "DESC")
      std::sort(vec.begin(), vec.end(), Line3D::comparebyPt1_Desc);
    else
      std::sort(vec.begin(), vec.end(), Line3D::comparebyPt1_Asc);
  }
  
}