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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = nullptr;
        ListNode* nod = head;
        ListNode* nod_n = head;
        n--;
        while(nod_n && n){
            nod_n=nod_n->next;
            n--;
        }
        while(nod_n->next){
            p = nod;
            nod = nod->next;
            nod_n=nod_n->next;
        }
        // remove nod
        if(p)
            p->next = nod->next;
        else
            head = nod->next;
        return head;
    }
};
