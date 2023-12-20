#include <iostream>
#include <vector>
#include <climits>

// Function to find the maximum subarray sum that crosses the midpoint
int maxCrossingSum(const std::vector<int>& arr, int low, int mid, int high, int& leftIndex, int& rightIndex) {
    int leftSum = INT_MIN;
    int sum = 0;
    int tempLeftIndex = mid;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            tempLeftIndex = i;
        }
    }//sums the left side of the array

    int rightSum = INT_MIN;
    sum = 0; //RESETS THE SUM ; 
    int tempRightIndex = mid + 1;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            tempRightIndex = i;
        }
    }//sums the right side of the array

    leftIndex = tempLeftIndex;
    rightIndex = tempRightIndex;
    return leftSum + rightSum;
}

// Function to find the maximum subarray sum using divide-and-conquer
int maxSubarraySum(const std::vector<int>& arr, int low, int high, int& leftIndex, int& rightIndex) {
    if (low == high) {
        leftIndex = low;
        rightIndex = high;
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftLow, leftHigh, rightLow, rightHigh;
    
    int leftMax = maxSubarraySum(arr, low, mid, leftLow, leftHigh);
    int rightMax = maxSubarraySum(arr, mid + 1, high, rightLow, rightHigh);
    int crossingMax = maxCrossingSum(arr, low, mid, high, leftIndex, rightIndex);

    if (leftMax >= rightMax && leftMax >= crossingMax) {
        leftIndex = leftLow;
        rightIndex = leftHigh;
        return leftMax;
    }
    else if (rightMax >= leftMax && rightMax >= crossingMax) {
        leftIndex = rightLow;
        rightIndex = rightHigh;
        return rightMax;
    }
    else {
        return crossingMax;
    }
}

int main() {
    int k;
    std::cin >> k;
    std::vector<int> list(k);

    for (int i = 0; i < k; i++) {
        std::cin >> list[i]; 
    }

    int leftIndex, rightIndex;
    int maxSum = maxSubarraySum(list, 0, k - 1, leftIndex, rightIndex);

    std::cout << maxSum;
    return 0;
}
