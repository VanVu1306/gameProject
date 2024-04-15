#include <bits/stdc++.h>
using namespace std;

int binarySearch(int* array, int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;
    if (array[mid] == target) {
        return mid;
    }
    else if (array[mid] > target) {
        return binarySearch(array, left, mid - 1, target);
    }
    else {
        return binarySearch(array, mid + 1, right, target);
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(nums) / sizeof(nums[0]);

    int target = 6;
    int index = binarySearch(nums, 0, size - 1, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
