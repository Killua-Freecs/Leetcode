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
    ListNode* doubleIt(ListNode* head) {
        ListNode* res = new ListNode(0);        
        ListNode* curr = res;
        if(head->val >= 5) {
            curr->val = 1;
            curr->next = new ListNode((head->val*2)%10);
            curr = curr->next;
        }
        else {
            curr->val = head->val*2%10;
        }
        head = head->next;
        while(head != nullptr) {
            if(head->val >= 5) {
                curr->val+=1;
            } 
            curr->next = new ListNode((head->val*2)%10);
            curr = curr->next;
            head = head->next;
        }
        return res;        
    }
};


// Alternate In Place Solution

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
    ListNode* doubleIt(ListNode* head) {
        if(head->val >= 5) {
            head = new ListNode(0,head);
        } 
        ListNode* curr = head;
        while(curr!=nullptr) {
            curr->val = ((curr->val)*2)%10;

            if(curr->next != nullptr && curr->next->val >= 5) {
                curr->val += 1;
            }
            curr = curr->next;
        }
        return head;
    }
};