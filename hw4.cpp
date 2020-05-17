//Nafis Abeer
//U98285639


#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include "cmath"
#include "hw4.h"

using namespace std;

// (a)
int unsorted_mode(std::vector<int> v) {
    //int s = *max_element(v.begin(),v.end()); // going to create a new array containing all the elements of v
    //int b = *min_element(v.begin(),v.end()); // for the negative boys
    //cout << b << endl;
    //cout << s << endl;
    //b = abs(b - 1); // need to include min element's absolute value as an index
    //s = s + 1; // need to include max element as an index
    //vector<int> newarray(s); 
    //vector<int> newnegarray(b); // seperate array to hold index of negative integers

    //for(int i = 0; i < s + 1; i++){ // set the count of every element up to the max element to 0
    //    newarray[i] = 0;
    //}

    //cout << newarray.size() << endl;
    
    //for(int i = 0; i < b + 1; i++){ // set the count of every element up to the max element to 0
    //    newnegarray[i] = 0;
    //cout << newnegarray.size() << endl;

    // achieve above using an unoredered map so the made vector does not get too big for large numbers

    unordered_map<int, int> combinedhash;

    /*for(int j = 0; j < v.size(); j++){ // loop through v and increase the count of elements of new array 
        if(v[j] < 0){
            int index = abs(v[j]);
            newnegarray[index] = newnegarray[index] + 1;
        }

        else{
            int index = v[j];
            newarray[index] = newarray[index] + 1; // newarray[i] now contains the number of elements in v equal to i
        }
        
    }*/

    //simplify to

    for( int j = 0; j < v.size(); j++){
        combinedhash[v[j]]++;
    }

    /*
    int mode1 = distance(newarray.begin(), max_element(newarray.begin(), newarray.end()));
    //cout << mode1 << endl;
    //cout << newarray[mode1] << endl;
    unsigned int mode2 = distance(newnegarray.begin(), max_element(newnegarray.begin(), newnegarray.end()));
    //cout << mode2 << endl;
    //cout << newnegarray[mode2] << endl;


    if(newarray[mode1] > newnegarray[mode2])
    {
        return mode1;
    }
    else 
    {
        return -mode2;
    }
    */

    // simplify above to for loop that searches through hash and changes value of mode as it encounters different elemets that repeat multiple times

    int mode;
    int howmanytimes = 0;
    for(auto index: combinedhash){
        if(howmanytimes < index.second){
            mode = index.first;
            howmanytimes = index.second;
        }
    }

    return mode;

    // vector method works for small values
}

// (b)
int sorted_mode(std::vector<int> v) {
   int count = 1;
   int mode;
   int countofcurrentmode = 1;

   for(int i = 0; i < v.size() - 1; i++){
       if(v[i] == v[i + 1]){
           count++;
           /*if(v[i + 1] = v[i + 2]){
               i++; // skip ahead in the vector since elements have repeated more than once 
               count++;
               if(v[i + 2] = v[i + 3]){
                   i++;
                   count++;
               }
               // im assuming elements won't appear more than 4 times 
           }*/
           if(count > countofcurrentmode){
               mode = v[i];
               countofcurrentmode = count;
           }
       }
       else{
           count = 1;
       }
   }

    return mode; 
}

// (c)
std::pair<int,int> unsorted_closest_integers(std::vector<int> v) {
    /*unordered_map<int, int> combinedhash;
    for( int j = 0; j < v.size(); j++){
        combinedhash[v[j]]++;
    }
    int start = 0;
    int howmanytimes;
    for(auto index: combinedhash){
        howmanytimes = index.second;
        for(int i = start; i < start + howmanytimes; i++){
            v[i] = index.first;
            start = start + howmanytimes;
        }
    }*/ // attempted to use counting sort using unordered maps

    sort(v.begin(), v.end());
    int num1;
    int num2;
    int smalldifference = v[1] - v[0];
    unsigned int difference;
    for(int i = 0; i < v.size() - 1; i++){

        if(v[i + 1] < 0 && v[i] < 0){
            difference = abs(v[i]) - abs(v[i+1]);
        }
        else if(v[i + 1] > 0 && v[i] < 0){
            difference = abs(v[i]) + v[i+1];
        }
        else if(v[i + 1] > 0 && v[i] > 0){
            difference = v[i + 1] - v[i];
        }

        if(difference <= smalldifference){
            num1 = v[i];
            num2 = v[i+1];
            smalldifference = difference;
        }
    }

    return std::make_pair(num1, num2); // you will need to change this
}

// (d)
std::pair<std::pair<int,int>,std::pair<int,int> >
unsorted_closest_coordinates(std::vector<std::pair<int,int> > v) {
    pair<int,int> one, two;
    pair<int,int> result1, result2;

    int s = v.size();

    one = v[0];
    result1 = v[0];
    two = v[1];
    result2 = v[1];

    int Euclidean = sqrt(pow(two.first - one.first, 2) + pow(two.second - one.second, 2));
    int closest = Euclidean;

    for(int i = 0; i < s - 1; i++){
        one = v[i];
        for(int j = i+1; j < s; j++){
            two = v[j];
            Euclidean = sqrt(pow(two.first - one.first, 2) + pow(two.second - one.second, 2));
            if(Euclidean <= closest){
                closest = Euclidean;
                result1 = one;
                result2 = two;
            }
        }
    }
    return std::make_pair(std::make_pair(result1.first, result1.second), std::make_pair(result2.first, result2.second)); // you will need to change this
}

// (e)
void flip_sort(std::vector<int> &v) {
    int i;   // variable for index of largest element
    int j;
    for(j = v.size() - 1; j > 0; j--) // index j down as largest element is flipped to v[j]
    {
        i = distance(v.begin(), max_element(v.begin(), v.begin() + j + 1));
        flip(v, i, j);
    } 
}

// (f)
void peak_valley_sort(std::vector<int> &v) {
    /*unordered_map<int, int> combinedhash;
    for( int j = 0; j < v.size(); j++){
        combinedhash[v[j]]++;
    }
    int start = 0;
    int howmanytimes;
    for(auto index: combinedhash){
        howmanytimes = index.second;
        for(int i = start; i < start + howmanytimes; i++){
            v[i] = index.first;
            start = start + howmanytimes;
        }
    }*/ // attempted to use counting sort using unordered maps


    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i = i + 2){
        if(i + 1 == v.size()){
            break;
        }
        int temp = v[i+1];
        v[i + 1] = v[i];
        v[i] = temp;
    
    }
}

// (g)
void length_alpha_sort(std::vector<std::string> &v) {
    
    for(int i = 1; i < v.size(); i++){ // loop needed to make sure all the elements are compared multiple times
        for(int j = 0; j< v.size() - i; j++){ //for loop to set them in length order
            
            if(v[j].length() > v[j + 1].length()){
                
                swap(v[j], v[j+1]);
            }
        }
    }

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j< v.size(); j++){ //for loop to set them in character order
            
            if(v[j].length() == v[j + 1].length()){
                int loopvarient = v[j].length();
                int stringindex = 0;
                string string1 = v[j];
                string string2 = v[j+1];

            while(string1[stringindex] == string2[stringindex]){
                stringindex++;
            }
            
        
                if(string1[stringindex] > string2[stringindex]){
                    //cout << "reached: " << stringindex << " for " << string1 << " and " << string2 << "located at string index: " << stringindex << endl;
                    swap(v[j], v[j+1]);
                    stringindex = 0;
                }
            }
        }
    }
  
}
/*

int main(){
    vector<int> vect;
    vect.push_back(1);
    vect.push_back(10);
    vect.push_back(50);
    vect.push_back(-18);
    vect.push_back(2);
    vect.push_back(-21);
    vect.push_back(-15);
    vect.push_back(22);
   

    
    //flip_sort(vect);
    //peak_valley_sort(vect);
    //length_alpha_sort(vect);

    pair<int,int> unsortedpair;
    unsortedpair = unsorted_closest_integers(vect);

    cout << "the pair is: (" << unsortedpair.first << "," << unsortedpair.second << ")" << endl;

}

*/