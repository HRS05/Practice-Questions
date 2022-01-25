class Solution {
    
    
    void solve(List<List<String> > ans,List<String> path,String s,int index)
    {
        if(index==s.length())
        {
            ans.add(new ArrayList(path));
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            if(isPalindrome(s,index,i))
            {
                path.add(s.substring(index,i+1));
                solve(ans,path,s,i+1);
                path.remove(path.size()-1);
            }
        }
    }
    
    boolean isPalindrome(String s,int start,int end)
    {
        if(start<=end)
        {
            if(s.charAt(start)!=s.charAt(end)) return false;
            return isPalindrome(s,++start,--end);
        }
        return true;
    }
    
    
    public List<List<String>> partition(String s) {
        List<List<String>> ans=new ArrayList<List<String> >();
        List<String> path=new ArrayList<String>();
        solve(ans,path,s,0);
        return ans;
    }
}