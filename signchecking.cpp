#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;


    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    cout << "Enter " << n << " integers: " << endl;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num > 0)
            positiveCount++;
        else if (num < 0)
            negativeCount++;
        else
            zeroCount++;
    }

    cout << "\nResults:" << endl;
    cout << "Positive numbers: " << positiveCount << endl;
    cout << "Negative numbers: " << negativeCount << endl;
    cout << "Zeros: " << zeroCount << endl;

    return 0;
}
