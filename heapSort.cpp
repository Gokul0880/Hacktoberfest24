#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    // Check if left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child exists and is greater than largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Change root, if necessary
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Main function to implement heap sort
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to the end
        swap(arr[0], arr[i]);

        // Heapify the root of the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted array: \n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: \n";
    printArray(arr, n);

    return 0;
}
