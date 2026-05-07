#include <iostream>
using namespace std;

// ?? Generic Bubble Sort Template
template <typename T>
void bubbleSort(T num[], int n) {
    int i, j;
    T temp;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (num[j] > num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}

int main() {
    // ?? Integer array
    int num[] = {9, 3, 5, 7, 2, 1, 0, 4, 6, 8};
    int n = 10;

    cout << "Before sorting (int): ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    bubbleSort(num, n); // automatically uses T = int

    cout << "After sorting (int): ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl << endl;


    // ?? Double array
    double numD[] = {9.2, 3.5, 5.1, 7.9, 2.3, 1.0, 0.4, 4.8, 6.6, 8.1};
    int nD = 10;

    cout << "Before sorting (double): ";
    for (int i = 0; i < nD; i++) {
        cout << numD[i] << " ";
    }
    cout << endl;

    bubbleSort(numD, nD); // automatically uses T = double

    cout << "After sorting (double): ";
    for (int i = 0; i < nD; i++) {
        cout << numD[i] << " ";
    }
    cout << endl;

    return 0;
}
