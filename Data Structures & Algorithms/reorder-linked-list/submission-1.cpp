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
    void reorderList(ListNode* head) {
        if(!head || !head->next)    
            return;
        ListNode* n=head;
        ListNode* nn=head;
        while(nn->next && nn->next->next){
            n = n->next;
            nn = nn->next->next;
        }

        // reverse second half of the list
        ListNode* p=nullptr;
        // n = n->next;
        while(n){
            ListNode* nn = n->next;
            n->next = p;
            p = n;
            n = nn;
        }

        // merge p and head
        n = head;
        while(n && p){
            ListNode* nn = n->next;
            ListNode* pp = p->next;
            n->next = p;
            p->next = nn;
            n = nn;
            p = pp;
        }
    }
};
