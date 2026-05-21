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

    return root;
}

bool search(BST* root, int key){
    if(root == NULL) return false;

    if (root -> data == key ){
        return true;
    }

    if (key < root -> data){
        return search (root -> left , key);
    }


    if (key > root -> data){
        return search (root -> right , key);
    }
    return false;
}

BST* findMin (BST* root){
    while(root -> left ! = NULL){
        root = root -> left;
    }
    return root;
}