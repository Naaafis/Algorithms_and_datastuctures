// Nafis Abeer
// U98285639
#include "sumProductDigit.h"
#include <iostream>
#include "sstream"

using namespace std; 

int sumProductDigit(int a, int b){
    int prod = a*b;
    string letters = to_string(prod);
    // cout << letters << endl; 
    int size = letters.size();
    // cout << size << endl;
    int sum;
    int array[100];
    int iter = 0;
    while(size > 1)
    {
        sum = 0;
        for(int i = 0; i < size; i++)
        {
            stringstream integer;
            integer << letters[i];
            int number;
            integer >> number;
            //cout << number << endl;
            array[i] = number;
            sum += array[i];
        }

        //cout << sum << endl;
 
        letters = to_string(sum);
        int s = letters.length();
        //cout << s << endl;
        //for(int i = 0; i < s; i ++)
        //{
        //    cout << letters[i] << endl;
        //}
        size = s; 
    } 

    return sum;
}

