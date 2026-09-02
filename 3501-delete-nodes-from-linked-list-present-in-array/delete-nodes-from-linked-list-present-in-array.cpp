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
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hitlist(nums.begin(),nums.end());
        while(head!=nullptr && hitlist.count(head->val)){
            ListNode* n=head;
            head=head->next;
        }
        ListNode* temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(hitlist.count(temp->next->val)){
                ListNode* n=temp->next;
                temp->next=temp->next->next;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};