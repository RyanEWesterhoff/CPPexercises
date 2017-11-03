#include <iostream>
#include <vector>
using namespace std;

//Summary: Given two arrays, write a function to computes their intersection.

int main() {
    int ary1[5]={5,4,3,2,1};
    int ary2[5]={3,4,5,6,7};
    vector<int> output;
    
    for(int i = 0; i < sizeof(ary1)/sizeof(ary1[0]); i++){
        for(int j = 0; j < sizeof(ary2)/sizeof(ary2[0]); j++){
            if(ary1[i] == ary2[j]){
                output.push_back(ary2[j]);
            }
        }
    }
    
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }

}
