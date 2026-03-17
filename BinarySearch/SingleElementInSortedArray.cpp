#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    if (n == 1 || nums[0] != nums[1]) {
        return nums[0];
    }

    if (nums[n - 2] != nums[n - 1]) {
        return nums[n - 1];
    }

    int st = 1, end = n - 2;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Check if mid is the single element
        if ((nums[mid - 1] != nums[mid]) && (nums[mid + 1] != nums[mid])) {
            return nums[mid];
        }

        // Decide direction using index parity
        if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) ||
            (mid % 2 == 0 && nums[mid + 1] == nums[mid])) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (sorted array with one single element): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = singleNonDuplicate(nums);

    cout << "Single non-duplicate element is: " << result << endl;

    return 0;
}