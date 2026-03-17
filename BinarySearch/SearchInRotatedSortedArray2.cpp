#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int st = 0, end = nums.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (target == nums[mid]) {
            return true;
        }

        // Handle duplicates
        if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
            st++;
            end--;
        }
        else if (nums[st] <= nums[mid]) {
            if (nums[st] <= target && target < nums[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        else if (nums[mid] <= nums[end]) {
            if (nums[mid] < target && target <= nums[end]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (rotated sorted array with duplicates): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (search(nums, target))
        cout << "Target found" << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}