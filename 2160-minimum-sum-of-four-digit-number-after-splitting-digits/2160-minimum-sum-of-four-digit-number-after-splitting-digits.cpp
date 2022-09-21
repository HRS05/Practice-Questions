class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        int x=10;
        while(num)
        {
            v.push_back(num%x);
            cout<<num%x<<endl;
            num=num/x;
        }
        sort(v.begin(),v.end());
        return (v[0]+v[1]) * 10 + (v[2]+v[3]);
    }
    
    
    // int minimumSum(int num) {
    //     string s=to_string(num);
    //     sort(s.begin(),s.end());
    //     string s1="",s2="";
    //     int x1,x2;
    //     s1+=s[0];
    //     s1+=s[2];
    //     s2+=s[1];
    //     s2+=s[3];
    //     cout<<s1<<"  "<<s2<<endl;
    //      x1 = stoi(s1);
    //      x2 = stoi(s2);
    //     return x1+x2;
    // }
};