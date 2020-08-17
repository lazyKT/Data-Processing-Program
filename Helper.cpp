/**
* Helper functions definition
* Helper Functions handle the dynamic data processing and display
**/
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <iomanip>

#include "Utils.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"


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
      if (str.find("], ["))
        std::cout << "separator found!!" << std::endl;
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

        //std::cerr << "str_1 = " << str_1 << ", str_2 = " << str_2 << std::endl;
    }
  }
}


int sub_choices(char &criteria)
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
  std::cout << "\n\tFilter Criteria successfully set to " << crit[sub_choices(criteria)] << std::endl;
  std::cout << "\nGoing back to main menu\n\n";

  return crit[sub_choices(criteria)];
}



////////////////////////////////////////////////////
// overload function of '<<' operator for Point2D //
////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& stream, Point2D* p)
{
  stream << "[" << std::setw(4) << p->getX() << ", " << std::setw(4) << p->getY() << "]\t" << p->getScalarValue();

  return stream;
}


// set headers for view data
void setHeaders(std::string &filter)
{
  if ( filter == "Point2D")
    std::cout << std::setw(5) << "X" << std::setw(6) << "Y" << "\tDist. Fr Origin\n";
  
  else if ( filter == "Point3D")
    std::cout << std::setw(5) << "X" << std::setw(6) << "Y" << std::setw(5) << "Z" << "\tDist. Fr Origin\n";
  else if ( filter == "Line2D") 
  {
    std::cout << std::setw(5) << "P1-X" << std::setw(7) << "P1-Y\t" << std::setw(6) << "P2-X" << std::setw(7) << "P2-Y\t"
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


void display(std::string &filter, std::string &sort_c, std::string &sort_o)
{

  // show display criteria
  show_criteria(filter, sort_c, sort_o);

  // display headers
  setHeaders(filter);

  if (filter == "Point2D")
  {
    for(Point2D* p2: p2_vec)
    {
      std::cout << p2 ;
      std::cout << std::endl;
    }
  }
  else if (filter == "Point3D")
  {
    for (Point3D* p3 : p3_vec)
    {
      std::cout << p3;
    }
  }
  else if (filter == "Line2D")
  {
    for (Line2D* l : l2_vec)
      std::cout << l;
  }
}