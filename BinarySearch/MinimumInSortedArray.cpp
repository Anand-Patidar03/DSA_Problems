#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int>& nums) {
    int minm = INT_MAX;
    int st = 0, end = nums.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (nums[st] <= nums[mid]) {
            minm = min(minm, nums[st]);
            st = mid + 1;
        }
        else if (nums[mid] <= nums[end]) {
            minm = min(minm, nums[mid]);
            end = mid - 1;
        }
    }

    return minm;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (rotated sorted array): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = findMin(nums);

    cout << "Minimum element is: " << result << endl;

    return 0;
}