/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  void deleteNode(ListNode* node) {
    // copy the value of next node to the node
    node->val = node->next->val;
    // point the node to next node
    node->next = node->next->next;
  }
};