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

        ListNode* temp = head;
        int cnt = 0;

        while(temp != NULL){
            cnt++;
            temp = temp -> next;
        }

        if(cnt == n){
            ListNode* newHead = head -> next;
            delete head;
            return newHead;
        }

        int sz = cnt - n;
        temp = head;
        ListNode* prev = NULL;

        while(sz > 0){
            prev = temp;
            temp = temp -> next;
            sz--;
        }

        prev -> next = temp -> next;
        delete temp;
        return head;
    }
};