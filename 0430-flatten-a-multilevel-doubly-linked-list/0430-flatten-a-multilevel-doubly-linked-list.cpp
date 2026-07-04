/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;
        
        solve(head);
        return head;
    }

    Node* solve(Node* head) {
        Node* curr = head;
        Node* last = NULL;

        while(curr) {
            Node* nextNode = curr->next;

            if(curr->child) {
                Node* childHead = curr->child;
                Node* childTail = solve(childHead);

                curr->next = childHead;
                childHead->prev = curr;

                curr->child = NULL;

                if(nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                last = childTail;
            }
            else {
                last = curr;
            }

            curr = nextNode;
        }

        return last;
    }
};