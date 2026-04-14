class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        stack<int> s;
        
        vector<string> res;
        s.push(0);

        for(int i=0;i<m;i++)
        {
            if(target[i] - s.top() == 1)
            {
                res.push_back("Push");
                s.push(target[i]);
            }
            else
            {
                int diff = target[i] - s.top();
                for(int j=0;j<diff-1;j++)
                {
                    res.push_back("Push");
                    res.push_back("Pop");
                }
                res.push_back("Push");
                s.push(target[i]);
            }
        }
        return res;
    }
};