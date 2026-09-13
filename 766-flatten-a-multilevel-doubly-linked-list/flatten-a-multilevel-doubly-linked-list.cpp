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
        if(head==nullptr){
            return nullptr;
        }
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->child!=nullptr){
                Node* childTail=temp->child;
                while(childTail->next!=nullptr){
                    childTail=childTail->next;
                }
                if(temp->next!=nullptr){
                    childTail->next=temp->next;
                    temp->next->prev=childTail;
                }
                temp->next=temp->child;
                temp->child->prev=temp;
                temp->child=nullptr;
            }
            temp=temp->next;
    }
    return head;
        }
};