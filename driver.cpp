#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>

#include "linked.h"
#include "node.h"

using namespace std;

int user_input_handle(string input);
int user_input_handle2(string input);

//Main, contains the loops that prompt for the user inputs and calls functions based on their actions.
int main()
{
    Linked link;
    int not_quit2 = 1;
    while(not_quit2)
    {
        int not_quit = 1;
        while(not_quit)
        {
            int new_num = 0;
            cout << "\nPlease enter a number: ";
            cin >> new_num;

            //cout << endl << link.push_back(new_num) << endl << endl;
            cout << endl << link.push_front(new_num) << endl << endl;

            cout << "\nDo you want another num?\nEnter ---> y <--- for 'yes'\nEnter ---> n <--- for 'no'\nInput: ";
            string input1;
            cin >> input1;
            not_quit = user_input_handle(input1);

            if (!not_quit)
            {
                //link.insert(420,1);
                cout << "\nSort ascending or descending?\nEnter ---> a <--- for 'ascending'\nEnter ---> d <--- for 'descending'\nInput: ";
                string input3;
                cin >> input3;
                if (user_input_handle2(input3) == 1)
                {
                    link.sort_ascending();
                }
                else if (user_input_handle2(input3) == 2)
                {
                  link.sort_descending();
                }

                link.print();
                link.print_num_of_primes();
                link.clear();
            }
        }
        cout << "\nDo you want to do this again?\nEnter ---> y <--- for 'yes'\nEnter ---> n <--- for 'no'\nInput: ";
        string input2;
        cin >> input2;
        not_quit2 = user_input_handle(input2);
    }
}

//Handels inputs for y or n
int user_input_handle(string input)
{
    int error = 1;
    int result;
    while (error)
    {
        if (input == "y")
        {
            error = 0;
            result = 1;
        }
        else if (input == "n")
        {
            error = 0;
            result = 0;
        }
        else
        {
            cout << "\nYour input was incorrect. \nEnter ---> y <--- for 'yes'\nEnter ---> n <--- for 'no'\nInput: ";
            cin  >> input;
        }
    }
    return result;
}


//Handels inputs for a or d
int user_input_handle2(string input)
{
    int error = 1;
    int result;
    while (error)
    {
        if (input == "a")
        {
            error = 0;
            result = 1;
        }
        else if (input == "d")
        {
            error = 0;
            result = 2;
        }
        else
        {
            cout << "\nYour input was incorrect. \nEnter ---> a <--- for 'ascending'\nEnter ---> d <--- for 'descending'\nInput: ";
            cin  >> input;
        }
    }
    return result;
}
