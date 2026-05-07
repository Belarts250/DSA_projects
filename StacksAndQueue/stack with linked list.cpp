#include<iostream>
using namespace std;

class Node{
	public:
		
		int data;
		Node *next;
		
		Node(int num){
			data = num;
			next = NULL;
		}
};

class myStack {
	Node* top;
	
	public:
		myStack(){
			top = NULL;
		}
		
	void push(int num){
		Node* temp = new Node(num);
		temp->next = top;
		top = temp; 
	}	
	int pop(){
		if(top == NULL){
			cout << "Stack overflow" << endl;
			return -1;
		}
		
		Node * temp = top;
		top -> top->next;
		int val = temp->data;
		
		delete temp;
		return val;
	}
	
	int peek(){
		if(top == NULL){
			cout << "Stack is empty" << endl;
			return -1
		}
		top -> data;
	}
	
	bool isEmpty(){
		return top == NULL;
	}
};
int main(){
	
	myStack st;
	st.push(1000);
	st.push(2000);
}