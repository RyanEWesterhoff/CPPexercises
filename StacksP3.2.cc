#include <iostream>
#include <stack>
using namespace std;

//Summary: Write a stack

struct MyStack
{
    stack<int> s;
    int minVal;

    // Prints minimum element of MyStack
    int min()
    {
       if(s.empty()) return NULL;
       else return minVal;
    }

    void push(int x){
    	if(s.empty()){
    		minVal = x;
    		s.push(x);
    	}else{
    		if(x < minVal){
    			minVal = x;
    			s.push(x);
    		}else{
    			s.push(x);
    		}
    	}
    }

    void pop(){
    	if(s.top() == minVal){
    		s.pop();
    		minVal = s.top();
    		stack<int> tempStack;
    		while(!s.empty()){
    			if(s.top() < minVal) minVal = s.top();
    			tempStack.push(s.top());
    			s.pop();
    		}
    		s = tempStack;
    	}else{
    		s.pop();
    	}

    }

    int peek(){
    	return s.top();
    }

};

int main() {
    MyStack m;

    m.push(3);
    m.push(4);
    m.push(5);
    m.push(2);
    m.push(6);

    //test min
    cout << "Min val in stack is: " << m.min() << endl;

    //test pop
    m.pop();
    m.pop();
    cout << "NEW Min val in stack is: " << m.min() << endl;

}


