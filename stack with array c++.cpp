#include<iostream>
using namespace std;

class Stack{
	private:
		int size;
		int top;
		int *arr;
		
	public: 
		Stack(int size){
			this -> size = size;
			this -> top = -1;
			this -> arr = new int[size];
		}	
		
		void push (int num){
			if (top < size - 1){
				arr[top++] = num;
			}
		}
		
		void display(){
			for(int i = 0; i <= top; i++ ){
				cout << arr[i] << " ";
			}
		}
		
		int pop(){
			if(top >= 0){
				int value = arr[top];
				top--;
				return value;
			}
		}
		
		bool isFull(){
			return top == size - 1;
		}
		
		bool isEmpty(){
			return top == -1;
		}
};

int main(){
	
	Stack *stack = new Stack(5);
	stack->push(100);
	stack->push(200);
	stack->push(300);
	stack->push(400); 
	stack->pop();
//	if (stack->isFull){
//			cout <<  "yes full ";
//	}
	cout << stack -> isFull() << "";
	stack -> display();     
	
}