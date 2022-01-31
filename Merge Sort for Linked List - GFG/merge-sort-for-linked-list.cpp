// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node *getMiddle(Node *head)
    {
        if(head==NULL) return head;
        Node *slow=head;
        Node *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* sortedMergeList(Node *a,Node *b)
    {
        Node *newHead;
        Node *temp=new Node(0);
        newHead=temp;
        while(a!=NULL && b!=NULL)
        {
            if(a->data > b->data)
            {
                temp->next=b;
                b=b->next;
            }
            else
            {
                temp->next=a;
                a=a->next;
            }
            temp=temp->next;
        }
        
        if(a!=NULL)
        {
            temp->next=a;
        }
        if(b!=NULL)
        {
            temp->next=b;
        }
        
        return newHead->next;
    }
    
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        Node *mid=getMiddle(head);
        Node *head2=mid->next;
        mid->next=NULL;
        Node *left=mergeSort(head);
        Node *right=mergeSort(head2);
        
        return sortedMergeList(left,right);
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends