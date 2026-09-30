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
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[NULL] = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* copy = new Node(curr->val);
            nodeMap[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while (curr != NULL) {
            Node* copy = nodeMap[curr];
            copy->next = nodeMap[curr->next];
            copy->random = nodeMap[curr->random];
            curr = curr->next;
        }
        return nodeMap[head];
    }
};
