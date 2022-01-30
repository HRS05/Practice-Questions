// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node * reverse(Node *node)
    {
        if(node==NULL || node->next==NULL) return node;
        Node *res=reverse(node->next);
        node->next->next=node;
        node->next=NULL;
        return res;
    }

    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int num1,num2;
        int carry=0;
        Node *n1,*n2;
        if(first==NULL && second==NULL) return NULL;
        if(first==NULL) return second;
        if(second==NULL) return first;
        n1=reverse(first); n2=reverse(second);

        struct Node *ans=NULL;
        struct Node *t;
        while(n1!=NULL || n2!=NULL || carry)
        {
            if(n1!=NULL) num1=n1->data; else num1=0;
            if(n2!=NULL) num2=n2->data; else num2=0;
            int total=num1+num2+carry;
            if(ans!=NULL)
            {
                ans->next=new Node(total%10);
                ans=ans->next;
            }
            else
            {
                ans=new Node(total%10);
                t=ans;
            }
            carry=total/10;
            if(n1)n1=n1->next;
            if(n2)n2=n2->next;
        }
        return reverse(t);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends