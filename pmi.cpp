#include<iostream>
using namespace std;

// Recursive function to calculate sum of first n natural numbers
int recursive(int n){
    if(n == 1){           // Base case: when n reaches 1, stop recursion
        return 1;
    } else {
        // Recursive case: add current number n to the sum of (n-1) numbers
        int recursiveAnswer = n + recursive(n-1);
        return recursiveAnswer;
    }
}

int main(){
    int num = 10;
    int n = 10;           // n is declared but never used (redundant)
    int pmi;              // variable to store result from formula

    // Loop to print sum of first i numbers using the mathematical formula
    for(int i = 0; i <= num; i++){
        pmi = i * (i + 1) / 2;                    // Formula for sum of first i natural numbers
        cout << "The sum of first " << i 
             << " numbers is " << pmi << endl;
    }
    
    cout << "The formula of PMI gives " << pmi << endl;
    
    // Call the recursive function to compute sum of first 10 numbers
    int Answer = recursive(10);
    cout << "The formula of recursive gives " << Answer << endl;    
    
    // Compare both results to "prove" the formula
    if(pmi == Answer){
        cout << "So, the formula is proven because they are equal";
    }
    else{
        cout << "The formula is incorrect";
    }

    return 0;   // Good practice to add this
}