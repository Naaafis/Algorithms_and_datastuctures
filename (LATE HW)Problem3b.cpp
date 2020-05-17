#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

string sequenceCreator(string ex);



vector<string> sequenceCreator(int howmanytimes){
    vector<string> sequence = {"0"};
    int size;
    int digits[5] = {0 , 1 , 2 , 3 };
    string numbers[5] = {"0", "1", "2", "3"};
    cout << sequence.size() << endl;
    string seqString = ""; 
for(int time = 0; time < howmanytimes; i++){
    size = sequence.size();
    for(int i = size; i < size + 3; i++){
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
        for (int j = 0; j < 5; j++)
        {
            if (sequence[i] == numbers[j])
            {
                string numstr = numbers[j];
                sequence.push_back(numstr);
            }
        }

        seqString = seqString + sequence[i + 1];
        seqString = seqString + sequence[i + 2];

        if(size==1){
            i=i+2;
        }

        if(seqSting[i] == seqString[i + 1]){
            i++;
            if(seqString[i + 1] == seqString[i + 2]){
                i++;
            }
        }
    }
    return newstring;
}
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