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
        int len = 0;
    ListNode* temp = head;

    while(temp) {
        len++;
        temp = temp->next;
    }

    int pos = len - n + 1;

    if(pos == 1) {
        ListNode* del = head;
        head = head->next;
        delete del;
        return head;
    }

    ListNode* prev = NULL;
    temp = head;

    while(pos > 1) {
        prev = temp;
        temp = temp->next;
        pos--;
    }

    prev->next = temp->next;
    delete temp;

    return head; 
    }
};