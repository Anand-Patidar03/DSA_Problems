class Solution {
public:
int sum;
vector<int> pref;
    Solution(vector<int>& w) {
        sum = 0;
        for (int x : w) 
        {
            sum += x;
            pref.push_back(sum); 
        }

    }
    
    int pickIndex() {
       
        int r = rand() % sum + 1;
        int low = 0, high = pref.size()-1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (pref[mid] < r)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */