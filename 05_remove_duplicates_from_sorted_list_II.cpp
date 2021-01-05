/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/




// Using map
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        unordered_map<int, int> mp;
        ListNode* temp = head;
        while (temp) {
            ++mp[temp->val];
            temp = temp->next;
        }
        temp = head;
        ListNode* newHead = new ListNode(0);
        ListNode* ret = newHead;
        while (temp) {
            if (mp[temp->val] > 1) {
                for (int i=0; temp and i<mp[temp->val]; ++i)
                    temp = temp->next;
            } else {
                newHead->next = temp;
                newHead = newHead->next;
                temp = temp->next;
            }
        }
        newHead->next = nullptr;
        return ret->next;
    }
};




// O(1) space
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* newHead = new ListNode(0);
        ListNode* curr = head, *ret = newHead;
        int cnt = 0;
        while (curr) {
            ++cnt;
            if (curr->next and curr->val != curr->next->val or !curr->next) {
                if (cnt == 1) {
                    newHead->next = curr;
                    newHead = newHead->next;
                }
                cnt = 0;
            }
            curr = curr->next;
        }
        newHead->next = nullptr;
        return ret->next;
    }
};

