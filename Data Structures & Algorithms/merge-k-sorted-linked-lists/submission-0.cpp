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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype([](auto* a, auto* b){return a->val>b->val;})> pq;
        for(auto& l: lists){
            pq.push(l);
        }
        if(pq.empty())
            return nullptr;
        ListNode* head = pq.top();
        pq.pop();
        if(head->next)
            pq.push(head->next);
        ListNode* node = head;
        while(!pq.empty()){
            node->next = pq.top();
            pq.pop();
            node = node->next;
            if(node->next)
                pq.push(node->next);
        }
        return head;
    }
};
