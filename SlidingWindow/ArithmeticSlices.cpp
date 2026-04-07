class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=1;
        int count = 0;
        int diff = -1,len=0;
        if(n<3)
        {
            return 0;
        }
        int prevDiff = nums[1]-nums[0];
        while(j<n)
        {
           int diff = nums[j] - nums[j-1];
           if(diff == prevDiff)
           {
              len = j-i+1;
              j++;
           }
           else
           {
               
               if(len >= 3)
               {
                  count += len-2;
               }
               i++;
               j=i+1;
               prevDiff = nums[j] - nums[j-1];
           }

           if(j == n)
           {
               count += len-2;
               i++;
               j = i+1;
           }
           if(i >= n-2)
           {
               break;
           }
        }
        return count;
    }
};