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
    ListNode *copy(ListNode *source)
    {
        if (source == NULL)
            return NULL;

        ListNode *destination = (ListNode*) malloc(sizeof(ListNode));

        destination->val = source->val;
        destination->next = copy(source->next);

        return destination;
    }

    ListNode *reverse(ListNode *source)
    {
        if (source == NULL || source->next == NULL)
            return source;
 
        ListNode *reversed = reverse(source->next);
        source->next->next = source;
        source->next = NULL;
 
        return reversed;
    }

    bool isPalindrome(ListNode *head)
    {
        int sizeLinkedList = size(head);
        ListNode *tmp = copy(head);
        ListNode *tmpReversed = reverse(tmp);

        int length = 0;

        while (head->next != NULL) {
            if (head->val == tmpReversed->val)
                length++;

            head = head->next;
            tmpReversed = tmpReversed->next;
        }

        if (length == sizeLinkedList)
            return true;

        return false;
    }

    int size(ListNode *head)
    {
        int length = 0;
        while (head->next != NULL)
        {
            head = head->next;
            length++;
        }

        return length;
    }
};