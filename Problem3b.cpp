#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> vec);


vector<int> mergeSort(vector<int> vec)
{
    if (vec.size() > 1)
    {
        int mid = vec.size() / 2;
        vector<int> lefthalf(vec.begin(), vec.begin() + mid);
        vector<int> righthalf(vec.begin() + mid, vec.begin() + vec.size());

        lefthalf = mergeSort(lefthalf);
        righthalf = mergeSort(righthalf);

        unsigned i = 0;
        unsigned j = 0;
        unsigned k = 0;
        while (i < lefthalf.size() && j < righthalf.size())
        {
            if (lefthalf[i] < righthalf[j])
            {
                vec[k] = lefthalf[i];
                i++;
            }
            else
            {
                vec[k] = righthalf[j];
                j++;
            }
            k++;
        }

        while (i < lefthalf.size())
        {
            vec[k] = lefthalf[i];
            i++;
            k++;
        }

        while (j < righthalf.size())
        {
            vec[k] = righthalf[j];
            j++;
            k++;
        }
    }

    return vec;
}


int findKthSmallest(vector<int> A, vector<int> B, int k)
{
    vector<int> result;
    result.reserve(A.size() + B.size());
    result.insert(result.end(), A.begin(), A.end());
    result.insert(result.end(), B.begin(), B.end());

    result = mergeSort(result);

    //int size = result.size();

    //sort(result.begin(),result.end());

    return result.at(k-1);

    /*for(int i = 0; i < result.size(); i++){
        cout << result.at(i) ;
    } 

    cout << "\n" << endl;*/
}




