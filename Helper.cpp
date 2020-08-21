/**
* Helper functions definition
* Helper Functions handle the dynamic data processing and display
**/
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
#include <vector>
#include <iomanip>

#include "Utils.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"


// GLOBAL SCOPES
std::vector<Point2D*> p2_vec;
std::vector<Point3D*> p3_vec;
std::vector<Line2D*> l2_vec;
std::vector<Line3D*> l3_vec;
// this is for later clean up dynamic allocations
std::vector<Point2D*> clean_up;


// read data file
bool read_data(std::set<std::string> &dataset)
{
  std::string filename;
  std::cout << "Please enter the data file name : ";
  std::cin >> filename;

  std::ifstream ifs(filename);

  // if file is not valid, return false
  if (!ifs.good())
  {
    std::cout << "\nError reading file: " << filename << ". File not found or permission denied\n";
    return false; 
  }

  std::string line;
  while(getline(ifs,line))
  {
    dataset.insert(line);
  }

  return true;
}


// process the data, read from the data file
void process_data(std::set<std::string> &dataset)
{
  for (std::string str : dataset)
  {
    std::string type = str.substr(0, str.find(", "));
    str.erase(0, (str.find(","))+3);
    
    // Point2D
    if ( type == "Point2D" )
    {
      int P2[2];
      
      extract_data(str, P2);

      Point2D* p2 = new Point2D(P2[0], P2[1]);
      p2_vec.push_back(p2);
    }
    // Point3D
    else if ( type == "Point3D" )
    {
      //std::cout << "saving private point3d... " << str << std::endl;
      int P3[3];

      extract_data(str, P3); // extract data from string

      Point3D* p3 = new Point3D(P3[0], P3[1], P3[2]);
      p3_vec.push_back(p3);
    }
    // In line2D and line3D data, '], [' is the separator between two points
    // Line2D
    else if (type == "Line2D")
    {
      std::string str_1 = str.substr(0, (str.find("], [")));
      std::string str_2 = str.substr((str.find("], ["))+4, str.length()-1);

      // create 1st point for Line2D
      int pts1[2];
      extract_data(str_1, pts1);
      Point2D* point1 = new Point2D(pts1[0], pts1[1]);
      //clean_up.push_back(point1);

      // create 2nd point for Point2D
      int pts2[2];
      extract_data(str_2, pts2);
      Point2D* point2 = new Point2D(pts2[0], pts2[1]);
      //clean_up.push_back(point2);

      // create line2d
      Line2D* l2 = new Line2D(*point1, *point2);
      l2_vec.push_back(l2);

    }
    // Line3D
    else if (type == "Line3D")
    {
      std::string str_1 = str.substr(0, (str.find("], [")));
      std::string str_2 = str.substr((str.find("], ["))+4, str.length()-1);

      // Point-1 for Line3D
      int pts1[3];
      extract_data(str_1, pts1);
      Point3D* point1 = new Point3D(pts1[0], pts1[1], pts1[2]);

      // Point 2 for Line3D
      int pts2[3];
      extract_data(str_2, pts2);
      Point3D* point2 = new Point3D(pts2[0], pts2[1], pts2[2]);

      Line3D* l3 = new Line3D(*point1, *point2);
      l3_vec.push_back(l3);
    }
  }
}


// sub_choices for filtered criteria
int def_sub_choices(char &criteria)
{
  if (criteria == 'a')
    return 0;
  else if (criteria == 'b')
    return 1;
  else if (criteria == 'c')
    return 2;
  else if (criteria == 'd')
    return 3;
  else
    return 0;
}


// define sorting criteria based on filtered data- Option 3
std::string def_sort_criteria(std::string& filter, std::string& current)
{
  char choice;
  std::string sort_c;
  std::cout << "\n[ Specifying sorting criteria (current: " << current << ") ... ]\n";

  if (filter == "Point2D")
  {
    std::string sub_choices[3] = {"x-ordinate", "y-ordinate", "distance"};
    
    std::cout << "\n\ta)\tX ordinate value\n";
    std::cout << "\tb)\tY ordinate value\n";
    std::cout << "\tc)\tDist. Fr Origin value\n";

    std::cout << "\n\tPlease enter your criteria (a-c) : ";
    std::cin >> choice;
    sort_c = sub_choices[def_sub_choices(choice)];
  }
  else if (filter == "Point3D")
  {
    std::string sub_choices[4] = {"x-ordinate", "y-ordinate", "z-ordinate", "distance"};

    std::cout << "\n\ta)\tX ordinate value\n";
    std::cout << "\tb)\tY ordinate value\n";
    std::cout << "\tc)\tZ ordinate value\n";
    std::cout << "\td)\tDist. Fr Origin value\n";

    std::cout << "\n\tPlease enter your criteria (a-d) : ";
    std::cin >> choice;
    sort_c = sub_choices[def_sub_choices(choice)];
  }
  else 
  {
    std::string sub_choices[3] = {"Pt.1", "Pt.2", "Length"};

    std::cout << "\n\ta)\tX and Y ordinate values of Pt.1\n";
    std::cout << "\tb)\tX and Y ordinate values of Pt.2\n";
    std::cout << "\tc)\tLength\n";

    std::cout << "\n\tPlease enter your criteria (a-c) : ";
    std::cin >> choice;
    sort_c = sub_choices[def_sub_choices(choice)];
  }
  std::cout << "\tSorting Criteria successfully set to " << sort_c << std::endl;
  std::cout << "\n\tGoing back to main menu ... \n";

  return sort_c;
}


// define data for later display Option: 2
std::string filter_criteria(std::string &current)
{
  char criteria;
  std::string crit[4] = {"Point2D", "Point3D", "Line2D", "Line3D"};

  std::cout << "\n[ Specifying filtering criteria ( current: " << current << ")]\n";
  std::cout << "\n\ta)\tPoint2D records\n";
  std::cout << "\tb)\tPoint3D records\n";
  std::cout << "\tc)\tLine2D records\n";
  std::cout << "\td)\tLine3D records\n";

  std::cout << "\n\tPlease enter your criteria (a-d) : ";
  std::cin >> criteria;
  std::cout << "\n\tFilter Criteria successfully set to " << crit[def_sub_choices(criteria)] << std::endl;
  std::cout << "\nGoing back to main menu\n\n";

  return crit[def_sub_choices(criteria)];
}


// define sorting order: asc or desc
std::string def_sort_order(std::string &current)
{
  char criteria;
  std::string orders[2] = {"ASC", "DESC"};

  std::cout <<"\n[ Specifying sorting order (current: " << current << ") ]\n";
  std::cout << "\n\ta)\tASC (Ascending Order)\n";
  std::cout << "\tb)\tDESC (Descending Order)\n";

  std::cout << "\n\tPlease enter your criteria (a-b) :";
  std::cin >> criteria;

  std::cout << "\tSorting order successfully set to '" << orders[def_sub_choices(criteria)] << "'\n";

  return orders[def_sub_choices(criteria)];
}


// set headers for view data
void setHeaders(std::string &filter)
{
  if ( filter == "Point2D")
    std::cout << std::setw(5) << "X" << std::setw(6) << "Y" << "\t\tDist. Fr Origin\n";
  
  else if ( filter == "Point3D")
    std::cout << std::setw(5) << "X" << std::setw(6) << "Y" << std::setw(5) << "Z" << "\tDist. Fr Origin\n";
  else if ( filter == "Line2D") 
  {
    std::cout << std::setw(5) << "P1-X" << std::setw(7) << "P1-Y\t\t" << std::setw(6) << "P2-X" << std::setw(7) << "P2-Y\t"
      << "Length\n";
  }

  std::cout << "----------------------------------------\n";
}


// show criteria for view data
void show_criteria(std::string &filter, std::string &sort_c, std::string &sort_o)
{
  std::cout << "\n[ View Data ... ]\n";
  std::cout << "filtering criteria : "  << filter << std::endl;
  std::cout << "sorting criteria : " << sort_c << std::endl;
  std::cout << "sorting order : " << sort_o << std::endl << std::endl;
}


// display data
void display(std::string &filter, std::string &sort_c, std::string &sort_o)
{

  // show display criteria
  show_criteria(filter, sort_c, sort_o);

  // display headers
  setHeaders(filter);

  if (filter == "Point2D")
  {
    do_sorting(sort_c, sort_o, p2_vec);
    view_data(p2_vec); 
  }
  else if (filter == "Point3D")
  {
    do_sorting(sort_c, sort_o, p3_vec);
    view_data(p3_vec);
  }
  else if (filter == "Line2D")
  {
    view_data(l2_vec);
  }
  else if ( filter == "Line3D")
  {
    view_data(l3_vec);
  }
}