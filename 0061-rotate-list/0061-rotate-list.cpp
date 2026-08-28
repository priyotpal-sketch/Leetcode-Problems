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
//  The time complexity of this approach will be O(n) bcoz we traversing the list one by one 
// we do here K=K%n to make sure that even if K=7 in example  1, that we will be get same result even after rotating 7 times and rotating 2 times ,that's why .
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        
        int n = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }

        
        k = k % n;

        if (k == 0)
            return head;

        
        tail->next = head;

        
        int steps = n - k;

        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

    
        ListNode* newHead = newTail->next;

        
        newTail->next = nullptr;

        return newHead;
    }
};