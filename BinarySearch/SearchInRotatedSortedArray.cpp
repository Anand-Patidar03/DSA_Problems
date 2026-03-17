#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == nums[mid]) {
                return mid;
            }
            else if (nums[st] <= nums[mid] && (nums[st] <= target && target <= nums[mid])) {
                end = mid - 1;
            }
            else if (nums[st] <= nums[mid] && !(nums[st] <= target && target <= nums[mid])) {
                st = mid + 1;
            }
            else if (nums[mid] <= nums[end] && (nums[mid] <= target && target <= nums[end])) {
                st = mid + 1;
            }
            else if (nums[mid] <= nums[end] && !(nums[mid] <= target && target <= nums[end])) {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (rotated sorted array): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    int result = obj.search(nums, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}