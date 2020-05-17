#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

string sequenceCreator(string ex);



string sequenceCreator(string howmanytimes){
    vector<string> sequence = {"0"};
    int size = sequence.size();
    int digits[5] = {0 , 1 , 2 , 3 };
    string numbers[5] = {"0", "1", "2", "3"};
    cout << sequence.size() << endl;
    string seqString = ""; 
    for(int i = 0; i < ; i++){
        int count = 1;
        seqString = seqString + sequence[i];
        if(seqString[i] == seqString[i+1]){
            count ++;
            if(seqString[i+1]==seqString[i+2]){
                count++;
            }
        }
        for (int j = 0; j < 5; j++)
        {
            if (count == digits[j])
            {
                string numstr = numbers[j];
                sequence.push_back(numstr);
            }
        }
        seqString = seqString + sequence[i + 1];
        if(seqSting[i] == seqString[i + 1]){
            i++;
            if(seqString[i + 1] == seqString[i + 2]){
                i++;
            }
        }
    }
    return newstring;
}



int kthDigit(int k){
    vector<string> sequence = {"0"};

    if(k < 2){
        sequence = sequenceCreator(sequence);
        return sequence[k];
    }
    else{
        for (int i = 0; i < 3; i++)
        {
            if(sizeofPrev < 2){
                sequence = sequenceCreator(sequence);
                cout << sequence << endl;
            }
            
            string newsequence = "";
            for (int j = sizeofPrev+1; j < sequence.length(); j ++){
                string placeholder = sequence[j];
                newsequence = newsequence + sequenceCreator(placeholder);
                cout << newsequence << endl;
            }

            sequence = sequence + sequenceCreator(newsequence);
            sizeofPrev = sequence.length();
        }
    }

    return sequence[k]; 

}



int main(){
    //int k = 6;
    //int result = kthDigit(k);
    cout << sequence.size() << endl;

    //cout << result << endl;
}