#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* head1=head->next;
        ListNode *res= new ListNode(head->val);
        // ListNode *res=head;
        ListNode *curr=res;
        while(head && head->next && head->next->next) {
            curr->next=head->next->next;
            // curr=curr->next;
            head=head->next->next;
        }
        curr->next=head1;
        // curr=curr->next;
        while(head1 && head1->next && head1->next->next) {
            curr->next=head1->next->next;
            // curr=curr->next;
            head1=head1->next->next;
        }
        curr->next=NULL;
        return res;
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a linked list with values [1, 2, 3, 4, 5]
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    // Create a solution object
    Solution solution;

    // Call the oddEvenList function
    ListNode* result = solution.oddEvenList(head);

    // Print the resulting linked list
    printList(result);

    // Free the memory allocated for the linked lists
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
