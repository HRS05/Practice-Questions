// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node *node)
    {
        if(node==NULL || node->next==NULL) return node;
        Node *res=reverse(node->next);
        node->next->next=node;
        node->next=NULL;
        return res;
    }
    
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        Node *ans=NULL;
        Node *res;
        int carry=1;
        while(head!=NULL || carry)
        {
            int sum=carry;
            if(head)
            {
                sum+=head->data;
                head=head->next;
            }
            if(ans==NULL)
            {
                ans=new Node((sum)%10);
                res=ans;
            }
            else
            {
                ans->next=new Node((sum)%10);
                ans=ans->next;
            }
            carry=(sum)/10;
        }
        return reverse(res);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends