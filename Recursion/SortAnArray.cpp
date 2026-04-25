#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void insertEle(vector<int>& nums,int ele)
{
    if(nums.size() == 0 || nums[nums.size()-1] <= ele)
    {
        nums.push_back(ele);
        return;
    }

    int val = nums[nums.size()-1];
    nums.pop_back();
    
    insertEle(nums,ele);

    nums.push_back(val);
}

void arrSort(vector<int>& nums)
{
    if(nums.size() == 1)
    {
        return;
    }
    int ele = nums[nums.size()-1];
    nums.pop_back();
    arrSort(nums);
    insertEle(nums,ele);

}

int main()
{
    vector<int> nums = {4,8,3,5,8,0,2};
    int n = 7;
    arrSort(nums);

    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}