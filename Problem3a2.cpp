#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int kthDigit(int k){
    int digits[5] = {0 , 1 , 2 , 3 };
    string numbers[5] = {"0", "1", "2", "3"};
    vector<string> sequence = {"0"};
    string seqString = ""; 
    if(k == 0){
        return digits[0];
    }
    if(k == 1){
        return digits[1];
    }
    
    if(k > 1){
        for(int i = 0; i < k; i++){
            size = sequence.size();
            if(size == 1){
                sequence.push_back("10");
            }
            else if(size > 1){
                
            }
        }
    }
}



int main(){
    //int k = 6;
    //int result = kthDigit(k);
    cout << sequence.size() << endl;

    //cout << result << endl;
}