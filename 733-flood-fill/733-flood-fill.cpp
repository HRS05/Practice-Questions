class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor=image[sr][sc];
        if (oldColor != newColor)fillIt(image,sr,sc,oldColor,newColor);
        return image;
    }
    void fillIt(vector<vector<int>>& image, int sr, int sc,int oldColor ,int newColor)
    {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return;
        if(image[sr][sc]!=oldColor) return;
        image[sr][sc]=newColor;
        fillIt(image,sr+1,sc+0,oldColor,newColor);
        fillIt(image,sr-1,sc-0,oldColor,newColor);
        fillIt(image,sr+0,sc+1,oldColor,newColor);
        fillIt(image,sr-0,sc-1,oldColor,newColor);
    }    
};