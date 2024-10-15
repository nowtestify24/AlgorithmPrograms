#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

                                    // Function to find the median of two sorted arrays
double medianTwoArrays(const vector<int>& vec1, const vector<int>& vec2);
int main() {
    vector<int> a{1, 2, 3};
    vector<int> b{4, 5, 6};
    double answer = medianTwoArrays(a, b);
    cout << "The median of the two arrays is: " << answer << endl;
    return 0;
}

double medianTwoArrays(const vector<int>& vec1, const vector<int>& vec2) {
    // Ensure vec1 is the smaller array to minimize the number of partitions
    if (vec1.size() > vec2.size()) {
        return medianTwoArrays(vec2, vec1);
    }
    int x = vec1.size();
    int y = vec2.size();
        // Initialize binary search bounds
    int low = 0;
    int high = x;
    while (low <= high) {
        int partitionX = (low + high) / 2;  // Partition index for vec1
        int partitionY = (x + y + 1) / 2 - partitionX;  // Partition index for vec2

        // Handle edge cases where partitions are at the bounds
        int maxX = (partitionX == 0) ? INT_MIN : vec1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : vec1[partitionX];
        int maxY = (partitionY == 0) ? INT_MIN : vec2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : vec2[partitionY];

        // Check if partition is correct
        if (maxX <= minY && maxY <= minX) {
           // If total number of elements is even
            if ((x + y) % 2 == 0) {
                return (double)(max(maxX, maxY) + min(minX, minY)) / 2;
            } else 
            {
                // If total number of elements is odd
                return (double)(max(maxX, maxY));
            }
        } else if (maxX > minY) {
            high = partitionX - 1;  // Move partitionX to the left
        } else {
            low = partitionX + 1;  // Move partitionX to the right
        }
    }
    return -1;  // Return -1 if median cannot be found (error case)
}
