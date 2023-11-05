#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index to divide the search range.

        if (arr[mid] == target) {
            return mid; // Found the target element, return its index.
        } else if (arr[mid] < target) {
            left = mid + 1; // Adjust the search range to the right half.
        } else {
            right = mid - 1; // Adjust the search range to the left half.
        }
    }

    return -1; // Target element not found in the array.
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 6;
    int result = binarySearch(arr, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
