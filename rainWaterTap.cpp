#include <iostream>
#include <vector>
using namespace std;

// Function to calculate trapped water
int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int waterTrapped = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                waterTrapped += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                waterTrapped += rightMax - height[right];
            }
            right--;
        }
    }
    
    return waterTrapped;
}

// Function to print the water trapped
void printWaterTrapped(vector<int>& height) {
    int result = trap(height);
    cout << "Amount of water trapped: " << result << " units." << endl;
}

// Driver code
int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Elevation map: ";
    for (int h : height) cout << h << " ";
    cout << endl;

    printWaterTrapped(height);

    return 0;
}
