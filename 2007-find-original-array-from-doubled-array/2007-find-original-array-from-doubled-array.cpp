class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0)
            return {};
        multiset<int> s;
        for (int i : changed)
            s.insert(i);
        vector<int> ans;
        while (!s.empty())
        {
            int x = *s.begin();
            s.erase(s.begin());
            if (s.find(x * 2) == s.end())
                return {};
            s.erase(s.find(x * 2));
            ans.push_back(x);
        }
        return ans;
    }
};