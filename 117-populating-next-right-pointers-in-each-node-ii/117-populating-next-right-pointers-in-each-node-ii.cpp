/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         Node *n,*p;
        int size,i;
        queue<Node*> q;
        if(root==NULL) return NULL;
        q.push(root);
        
        while(!q.empty())
        {
            p=NULL;
            size=q.size();
            for(i=0;i<size;i++)
            {
                n=q.front(); q.pop();
                if(p!=NULL)
                {
                    p->next=n;
                }
                p=n;
                
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            p->next=NULL;
        }
        return root;
    }
};