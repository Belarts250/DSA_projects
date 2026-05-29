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

BST* delete(BST* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root->data){
        root -> left = delete(root -> left, key);
    }

    else if (key > root -> data){
        root -> right = delete(root -> right, key);
    }
     else {

        // CASE 1: No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // CASE 2: One child
        else if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // CASE 3: Two children
        else {

            // Find inorder successor
            Node* temp = findMin(root->right);

            // Replace value
            root->data = temp->data;

            // Delete duplicate
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inorder(Node* root) {

    if(root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}


int main() {

    Node* root = NULL;

  //insert
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "BST Inorder Traversal: ";
    inorder(root);

    cout << endl;



    // SEARCH
    int key = 40;

    if(search(root, key)) {
        cout << key << " Found" << endl;
    }
    else {
        cout << key << " Not Found" << endl;
    }



    // DELETE
    root = deleteNode(root, 70);

    cout << "BST After Deletion: ";
    inorder(root);

    cout << endl;

    return 0;
}