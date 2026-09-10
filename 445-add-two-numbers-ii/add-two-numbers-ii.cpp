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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1, s2;
        
        // Pushing logic is perfect
        while(l1 != nullptr){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* head = nullptr; // 1. Declare the front door OUTSIDE the loop
        
        while(!s1.empty() || !s2.empty()){
            int sum = carry;
            
            // Math logic is perfect
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            
            carry = sum / 10;
            
            // 2. Build the car and attach it to the front
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;     // Hook new car to the existing train
            head = newNode;           // Shift the front door to the new car
        }
        
        // 3. Catch the leftover carry and slap it on the very front
        if(carry > 0){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        
        return head; // Return the final front door
    }
};