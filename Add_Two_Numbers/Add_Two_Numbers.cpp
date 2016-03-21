#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
        ListNode *prev = result;

        bool init = true;

        int digit, carry_over;
        digit = carry_over = 0;

        while(l1 && l2) {
            digit = ((l1->val + l2->val)+carry_over) % 10;
            carry_over = ((l1->val + l2->val)+carry_over) / 10;

            ListNode *node = new ListNode(digit);

            if(init) {
                result = node;
                prev = result;
                init = false;
            }
            else {
                prev->next = node;
                prev = node;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *tmp = NULL;

        // join the remaining nodes of the input to result chain
        if(l1) {
            prev->next = l1;
            tmp = l1;
        }
        else {
            prev->next = l2;
            tmp = l2;
        }

        // continue computation with joined chain
        while(tmp && carry_over) {
            if(tmp->val == 9 && carry_over) {
                tmp->val = 0;
                carry_over = 1;
            }
            else {
                tmp->val += carry_over;
                carry_over = 0;
            }

            prev = tmp;
            tmp = tmp->next;
        }

        if(carry_over) {
            ListNode *node = new ListNode(carry_over);
            prev->next = node;
            prev = node;
        }

        return result;
    }
};

int main() {

    ListNode *tmp = NULL;

    // construct input list 1
    ListNode *l1 = new ListNode(9);
    tmp = new ListNode(8);
    l1->next = tmp;
    // tmp->next = new ListNode(1);

    // construct input list 2
    ListNode *l2 = new ListNode(1);
    // tmp = new ListNode(9);
    // l2->next = tmp;
    // tmp->next = new ListNode(4);

    Solution soln;
    ListNode *result = soln.addTwoNumbers(l1, l2);

    // test the output
    while(result) {
        int value = result->val;
        result = result->next;
        cout << value << " ";
    }

    cout << endl;

    return 0;
}