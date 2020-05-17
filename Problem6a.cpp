//Nafis Abeer
//U98285639
#include "findSingle.h"
#include <iostream>

using namespace std;

int findSingle(int arr[], int arr_size)
{
    int single = 0;

    for(int i = 0; i < arr_size; i++)
    {
        int number = arr[i];
        int secondnumber;
        bool match = 1;
        for(int j = 0; j < arr_size; j++)    
        {
            if(i == j)
            {
                j++; // skip over terms where i = j so the same numbers aren't equal
                if(j == arr_size)
                {
                    break; // break out of loop if last number is reached
                }
            }
            secondnumber = arr[j];
            if(number == secondnumber)
            {
                match = 0;
                break; // break out to previous for loop
            }

            else if(match && j == (arr_size - 1))
            {
                single = number;
                return single; 
            }
        }
    }
}
