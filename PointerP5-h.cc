#include <iostream>
#include <string>
using namespace std;

//Summary: Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

int main() {

    string input = "A man, a plan, a canal: Panama";

    //set all lower for compare & remove non alphas
    for(int i = 0; i < input.length(); i++){
        if(!isalpha(input[i])){
        	input.erase(i,1);
        	i--;
        }
        input[i] = tolower(input[i]);
    }

    bool isPalendrome = true;
    int start = 0;
    int end = input.length()-1;
    for(int i = 0; i < input.length()/2; i++){
    	if(input[start] != input[end]){
    		isPalendrome = false;
    		break;
    	}
    	start++;
    	end--;
    }

	if(isPalendrome){
		cout << "It's a palendrome!";
	}else{
		cout << "Not a palendrome!!";
	}


}

