#include<bits/stdc++.h>
using namespace std;

class BST{
    public:
    int data;
    BST* left;
    BST* right;

    BST(int value){
        data = value;
        left = NULL;
        right = NULL;
    }

};

//Insert

BST* insert(BST* root, int value){
    if (root == NULL){
       return new BST(value);
    }

    if(value < root -> data ){
        left -> data = insert(root->left, value);
    }

    else if(value > root -> data){
        right -> data = insert (root -> right, value);
    }
}