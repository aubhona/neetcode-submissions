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
        if (!head) {
            return nullptr;
        }
        
        std::unordered_map<Node*, Node*> pointer_map;

        auto new_head = new Node(head->val);
        auto new_node = new_head;
        auto old_head = head;

        pointer_map[head] = new_node;

        while (head) {
            if (head->next)
            {
                new_node->next = new Node(head->next->val);
                pointer_map[head->next] = new_node->next;
            } else {
                new_node->next = nullptr;
            }

            head = head->next;
            new_node = new_node->next;
        }

        head = old_head;
        new_node = new_head;

        while (head) {
            new_node->random = pointer_map[head->random];
            head = head->next;
            new_node = new_node->next;
        }

        return new_head;
    }
};
