/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        flatten(head->next);
        if(head->child)
        {
            Node *nodeNext=head->next;
            Node *node=flatten(head->child);
            head->next=node;
            node->prev=head;
            Node *t=node;
            while(t->next) t=t->next;
            t->next=nodeNext;
            if(nodeNext)nodeNext->prev=t;
            head->child=NULL;
        }
        
        
        return head;
    }
};