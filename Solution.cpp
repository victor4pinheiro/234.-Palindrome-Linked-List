#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverse(ListNode *source)
    {
        ListNode *previous = NULL;
        ListNode *current = source;
        while (current != NULL) {
            ListNode *nextTemp = current->next;
            current->next = previous;
            previous = current;
            current = nextTemp;
        }
        return previous;
    }

    bool isPalindrome(ListNode *head) {
        if (head == NULL) return true;

        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfStart = reverse(firstHalfEnd->next);

        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != NULL) {
            if (p1->val != p2->val) result = false;
            p1 = p1->next;
            p2 = p2->next;
        }        

        firstHalfEnd->next = reverse(secondHalfStart);
        return result;
    }

    ListNode *endOfFirstHalf(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};