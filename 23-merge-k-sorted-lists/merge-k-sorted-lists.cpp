/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    struct compare{
        bool operator()(ListNode*a,ListNode*b){
            return a->val>b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> minHeap;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                minHeap.push(lists[i]);
            }
        }
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        while(!minHeap.empty()){
            ListNode*cur=minHeap.top();
            minHeap.pop();
            temp->next=cur;
            temp=temp->next;
            if(cur->next!=nullptr){
                minHeap.push(cur->next);
            }
        }
        ListNode*head=dummy->next;
         delete dummy;
         return head;
    }
};