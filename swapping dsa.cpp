#include <iostream>
using namespace std;

// Function to swap two numbers using pass by reference
void swap(int &x, int &y){
    // Create a temporary variable to store the value of x
    int temp = x;

    // Assign the value of y to x
    x = y;

    // Assign the stored value (original x) to y
    y = temp; 
}

int main(){
    
    // Declare and initialize two variables
    int x = 2, y = 3;
    
    // Display values before swapping
    cout << "Before swapping: x = " << x << " and y = " << y << endl;

    // Call swap function (values will be swapped because of reference)
    swap(x, y);

    // Display values after swapping
    cout << "After swapping: x = " << x << " and y = " << y;

    return 0;
}