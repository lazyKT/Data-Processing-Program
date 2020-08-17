/**
* Helper Functions Declarations
* Helper Functions handle the dynamic data processing and display
**/

#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <iostream>
#include <set>
#include <vector>
#include "Point2D.h"
#include "Point3D.h"


// read the data file
bool read_data(std::set<std::string> &dataset);

// process the data from file, to display
void process_data(std::set<std::string> &dataset);

void display(std::string &filter, std::string &sort_c, std::string &sort_o);
// filter data to be viewed: Option-2
std::string filter_criteria(std::string &current);

#endif