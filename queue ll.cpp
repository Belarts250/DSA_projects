#include<iostream>
using namespace std;
struct Node {
	int data;
	Node * next;	
	
	Node(int val){
		data = val;
		next = nullptr;
	}
};


class LinkedQueue{
	private:
		Node *front;
		Node *rear;
		
	public:
	LinkedQueue(){
		front = rear = nullptr;		
	} 
	
	bool isEmpty(){
		return front == nullptr;
	}	
	void enqueue(int value){
		Node *newNode = new Node(value);
		
		if(isEmpty()){
			front = rear = newNode;
			cout << value << " enqueued" << endl;
			return;
		}
		
		rear -> next = newNode;
		rear = newNode;
		
	}
	
    void dequeue(){
		if(isEmpty()){
			cout << "Stack underflow";
			return;
		}
		Node *temp = front;
		front = front->next;
		
		if(front == nullptr){
			rear = nullptr;
		}
		
		cout << temp->data << " removed " << endl;
		delete temp;
		
	}
	int peek(){
		if(isEmpty()){
			cout << "Queue is empty";
			return -1;
		}
		return front -> data;
		
	}		
	void display();	
};

int main(){
	
	LinkedQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Front element after dequeues: " << q.peek() << endl;

    return 0;
	
}