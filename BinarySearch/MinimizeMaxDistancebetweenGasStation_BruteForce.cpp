#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,5};
    int k = 4,n = nums.size();

    vector<int> station(n-1,0);
    vector<double> res;

    for(int i=0;i<k;i++)
    {
        double maxVal = -1,maxIdx=-1;
        for(int i=0;i<n-1;i++)
        {
            double diff = (double)(nums[i+1]-nums[i]);
            if(station[i] != 0)
            {
                diff /= (station[i]+1);
            }
            if(maxVal < diff)
            {
                maxVal = diff;
                maxIdx = i;
            }
        }
        station[maxIdx]++;
    }

    for(int i=0;i<n-1;i++)
    {
        double diff = nums[i+1] - nums[i];
        res.push_back(nums[i]);
        if(station[i] != 0)
        {
            diff /= (station[i]+1);
        }
        for(int j=0;j<station[i];j++)
        {
            res.push_back(nums[i] + (j+1)*diff);
        }
    }

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<nums[n-1]<<endl;


    return 0;
}