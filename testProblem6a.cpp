/**
 ** Created by Wenchao Li
 **/

#include "findSingle.h"
#include <iostream>
using namespace std;

int main()
{
  int arr[] = {2, 3, 4, 7, 4, 4, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "The integer that occurs only once is " << findSingle(arr, n) << ".\n";
  return 0;
}