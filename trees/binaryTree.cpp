#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BTNode{
    public:
    T data;
    BTNode* left;
    BTNode* right;

    BTNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BTNode(){
        delete left;
        delete right;
    }

    int main(){
       BTNode<int>* root = new BTNode<int>(1); 
       BTNode<int>* node1 = new BTNode<int>(2);
       BTNode<int>* node2 = new BTNode<int>(3);

       root -> left = node1;
       root -> right = node2;
    }
}