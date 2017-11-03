#include <iostream>
using namespace std;

//Summary: Given a list of names (first name and last name), sort the list by their last names.

//Returns the string that comes first alphabetically by last name
string compLast(string first, string second){
    int firstPtr = first.length()-1;
    int secondPtr = second.length()-1;

    while(!isspace(first[firstPtr])) firstPtr--;
    firstPtr++;

    while(!isspace(second[secondPtr])) secondPtr--;
    secondPtr++;

    while(first[firstPtr] == second[secondPtr]){
    	firstPtr++;
    	secondPtr++;
    }

    if(first[firstPtr] < second[secondPtr]){
    	return first;
    }else{
    	return second;
    }
}

void insertionSort(string ary[], int n)
{
   int j;
   string key;
   for (int i = 1; i < n; i++)
   {
       key = ary[i];
       j = i-1;

       while ((j >= 0) && (compLast(ary[j], key) == key))
       {
           ary[j+1] = ary[j];
           j = j-1;
       }
       ary[j+1] = key;
   }
}

int main(){
    string input[] = {"Daenerys Targaryen", "Jon Snow", " Tyrion Lannister", " Joffrey Baratheon"};
    int n = sizeof(input)/sizeof(input[0]);

    insertionSort(input, n);

    for(int i = 0; i < n - 1; i++){
    	cout << input[i] << ", ";
    }
    cout << input[n - 1];


}