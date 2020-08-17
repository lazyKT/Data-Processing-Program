/**
* Utility functions definitions
* Utility functions handle the static disaply of the data
**/
#include "Utils.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <limits>


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
  int start = 0;
  int i = 0;

  while ( i < 3)
  {
    deli_pos = str.find(", ");
    // std::cout << "deli position - " << deli_pos << std::endl;
    // std::cout << "str = " << str << std::endl;
    std::string res = str.substr(start, deli_pos);
    //std::cerr << "res = " << res << std::endl;

    int n = stoi(res);
    arr[i] = n;

    str.erase(0, deli_pos+1);

    if ( str.find(", ") == std::string::npos)
    {
      // last segment
      //std::cout << "last seg = " << str << std::endl;
      i ++;
      n = stoi(str);
      arr[i] = n;
      break;
    }
    i++;
    start = deli_pos-2;
  }
}
