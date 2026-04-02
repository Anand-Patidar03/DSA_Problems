#include <bits/stdc++.h>
using namespace std;

vector<int> NearestGreaterToLeft(vector<int>& nums) {
    stack<int> s;
    vector<int> res;
    int n = nums.size();

    for(int i=0;i<n;i++)
    {
        if(s.size() == 0)
        {
            res.push_back(-1);
        }
        else if(s.size() > 0 && s.top() > nums[i])
        {
            res.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() <= nums[i])
        {
            while(s.size() > 0 && s.top() <= nums[i])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(s.top());
            }
        }
        s.push(nums[i]);
    }
    return res;
}

int main() {
    int n;
    vector<int> nums = {1,3,0,0,1,2,4};

    vector<int> ans = NearestGreaterToLeft(nums);

    for (int x : ans) cout << x << " ";
}