/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertCopy(Node* head) {
        Node* temp = head;

        // First step: create copy nodes in between original nodes
        while (temp != NULL) {
            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = temp->next->next;
        }
    }

    void connectRandom(Node* head) {

        // Second step: connect random pointers
        Node* temp = head;

        while (temp != NULL) {
            Node* copyNode = temp->next;

            if (temp->random != NULL) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = NULL;
            }

            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {

        Node* temp = head;

        Node* dummy = new Node(-1);
        Node* res = dummy;

        while (temp != NULL) {

            res->next = temp->next;

            temp->next = temp->next->next;

            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }

public:
    Node* copyRandomList(Node* head) {

        insertCopy(head);
        connectRandom(head);

        return getDeepCopyList(head);
    }
};