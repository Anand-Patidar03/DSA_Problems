#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1 || nums[0] > nums[1])
    {
        return 0;
    }

    if (nums[n - 1] > nums[n - 2])
    {
        return n - 1;
    }

    int st = 1, end = n - 2;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        // Peak condition
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        // Increasing slope → go right
        else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
        {
            st = mid + 1;
        }
        // Decreasing slope → go left
        else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1])
        {
            end = mid - 1;
        }

        else
        {
            if (nums[mid] > nums[st])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int peakIndex = findPeakElement(nums);

    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << nums[peakIndex] << endl;

    return 0;
}