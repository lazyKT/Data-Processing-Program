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
        /* -- Option 2: Define Filtering Data  -- */
        else if (CHOICE == 2)
        {
            filter = filter_criteria(filter);
        }
        /* -- Option 3: Define Sorting Criteria -- */
        else if (CHOICE == 3)
        {
            sort_criteria = def_sort_criteria(filter, sort_criteria);
        }
        /* -- Option 4: Define Sorting Order -- */
        else if (CHOICE == 4)
        {
            sort_order = def_sort_order(sort_order);
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
        /* -- Option 6: store data in text file -- */
        else if (CHOICE == 6)
        {
            store_data(filter);

            cout << "\nGoing Back to Main Menu ... \n";
        }
        /* -- Option 7 -- */
        else if (CHOICE == 7)
        {
            cout << "\nExiting Program ... \n";
            
            break;
        }
        // invalid choice
        else
            std::cout << "\nInvalid Choice.\n\nGoing back to main menu ... \n\n";
            //enter_to_continue();
    }

    return 0;
}

