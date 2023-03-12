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
class cmp{
    public:
        bool operator() (ListNode *a , ListNode *b){
            if(a->val > b->val) return true;
            return false;
        }
    };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        
        for(auto i : lists){
            if(i){
                q.push(i);
            }
        }
        while(q.size()){
            ListNode* temp = q.top();
            tail->next = temp;
            tail = temp;
            q.pop();
            
            if(temp->next) q.push(temp->next);
        }
        return dummy->next;
    }
};