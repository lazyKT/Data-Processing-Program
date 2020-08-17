/**
* Main File
**/
#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "Utils.h"
#include "Helper.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"

using namespace std;

int CHOICE = 0;
string filter = "Point2D";
string sort_order = "ASC";
string sort_criteria = "x-ordinate";

/** start of main **/
int main() 
{
    bool data_ready = false;
    set<string> dataset;
    vector<string> data_vec;

    Point2D* p2 = new Point2D(3,4);
    Point2D* p3 = new Point2D(3,4);
    Line2D* l2 = new Line2D(*p2,*p3);

    while (true)
    {
        main_menu(filter, sort_criteria, sort_order);

        cout << "Please enter your choice: ";
        cin >> CHOICE;

        /* -- Option 1 -- */
        if (CHOICE == 1)
        {
            data_ready = read_data(dataset);
            //Print<set<string>> (dataset);

            if (data_ready)
            {
                process_data(dataset);
            
                cout << endl <<  dataset.size() << " records read in successfully!\n";
            }
            
            cout << "\nGoing back to main menu ... \n";
        }
        /* -- Option 2 -- */
        else if (CHOICE == 2)
        {
            filter = filter_criteria(filter);
        }
        /* -- Option 5 : view data -- */
        else if (CHOICE == 5)
        {
            // only if the data is read in successfully, display data
            if (data_ready)
            {
                display(filter, sort_criteria, sort_order);
            }
            else
            {
                cout << "\nNo data to be viewed ...\n";
                cout << "hint: Try to load the data file by choosing Option-1\n";
            }
            enter_to_continue();
            cout << "\nGoing back to main menu ... \n\n";
        }
        /* -- Option 7 -- */
        else if (CHOICE == 7)
        {
            break;
        }
        // invalid choice
        else
            std::cout << "\nInvalid Choice.\n\nGoing back to main menu ... \n\n";
            //enter_to_continue();
    }

    return 0;
}

