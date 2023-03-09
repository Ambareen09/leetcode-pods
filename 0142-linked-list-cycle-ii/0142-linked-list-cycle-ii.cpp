/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return NULL;
        ListNode *slow=head, *fast=head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow) break;
        }
        if(!fast or !fast->next) return NULL;
        
        ListNode *p1= head, *p2=slow;
        while(p1 != p2){
            p1 = p1->next;
            p2=p2->next;
        }
        
        return p1;
    }
};