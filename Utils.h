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


#endif