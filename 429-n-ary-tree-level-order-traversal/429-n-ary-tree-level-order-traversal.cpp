/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v(size);
            for(int i=0;i<size;i++)
            {
                Node * node = q.front(); q.pop();
                v[i]=node->val;
                for(int j=0;j<node->children.size();j++)
                {
                    q.push(node->children[j]);
                }
            }
            ans.push_back(v);
        }
        
        
        return ans;
     }
};