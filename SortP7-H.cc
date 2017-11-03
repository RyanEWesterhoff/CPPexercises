#include <iostream>
using namespace std;

//Summary: Search for a given element in a rotated sorted array. Return null if not found.

int main(){
	int ary[] = {10,11,12,1,2,3,4,5,6};
	int n = 1;
	bool found = false;

	for(int i = 0; i < sizeof(ary)/sizeof(ary[0]); i++){
		if(ary[i] == n){
			found = true;
			break;
		}
	}

	if(found == true){
		cout << "Element found!";
	}else{
		cout << "No such element.";
	}

}