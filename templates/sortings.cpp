#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    vector<int> arr(n);
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> a1 = arr, a2 = arr, a3 = arr;
    bubbleSort(a1);
    selectionSort(a2);
    insertionSort(a3);

    cout << "Bubble Sort: ";
    for (int x : a1) cout << x << " ";
    cout << "\nSelection Sort: ";
    for (int x : a2) cout << x << " ";
    cout << "\nInsertion Sort: ";
    for (int x : a3) cout << x << " ";
    cout << "\n";
    return 0;
}