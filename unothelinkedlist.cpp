// unothelinkedlist.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define BP (cout<<endl)

#define DOCK() do{                       \
                                  int dock;     \
                                  cin>>dock;    \
}while(0)

// Definition for singly-linked list node.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for singly-linked list.
class LinkedList
{
public:
    ListNode* createLinkedListFromArray(vector<int>& nodes)
    {
        
    }

    void printNodesArray(vector<int>& nodes)
    {
        
    }

    void printLinkedList(ListNode* head)
    {   
        
    }

    void buildCycle(ListNode* head, int& cycleEntry)
    {
        return;
    }

    ListNode* intersectLinkedList(vector<int>& nodes, ListNode* head, int intersectNode)
    {
        return nullptr;
    }
};

class Solution
{
public:
    
};

int main()
{
    LinkedList singleLinkedList;
    Solution solu;
    ListNode* head = nullptr;

    vector<int> nodes = { 7, 6, 5, 4, 3, 2, 1 };
    singleLinkedList.printNodesArray(nodes);
    head = singleLinkedList.createLinkedListFromArray(nodes);
    singleLinkedList.printLinkedList(head);

    // 19. Remove Nth Node From End of List
    // int n;
    // while(nullptr != head)
    // {
    //     cout << "Which node do you want to remove from the end of list: ";
    //     cin >> n;
    //     cout << endl;
    //     head = solu.removeNthFromEnd(head, n);
    //     cout << "Removed the " << n << "th node from end of list, " << endl;
    //     singleLinkedList.printLinkedList(head);
    // }

    vector<int> nodes2 = { 2, 0, 2, 1, 7, 8, 9, 1};
    singleLinkedList.printNodesArray(nodes2);
    ListNode* head2 = singleLinkedList.createLinkedListFromArray(nodes2);
    singleLinkedList.printLinkedList(head2);

    // 2. Add Two Numbers
    // head = solu.addTwoNumbers(head, head2);
    // cout << "Added two numbers, ";
    // singleLinkedList.printLinkedList(head);

    // 24. Swap Nodes in Pairs
    // head = solu.swapPairs(head);
    // cout << "Swapped pairs, ";
    // singleLinkedList.printLinkedList(head);

    // 61. Rotate List
    // int k;
    // while(1)
    // {
    //     cout << "How many places do you want to rotate the list to right by: ";
    //     cin >> k;
    //     head = solu.rotateRight(head, k);
    //     cout << "Rotated the list to right by " << k << " places, ";
    //     singleLinkedList.printLinkedList(head);
    // }
    
    // 83. Remove Duplicates from Sorted List
    // nodes = { 1, 1, 1, 3, 3, 7, 9, 9, 12, 17 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // head = solu.deleteDuplicates(head);
    // cout << "Deleted duplicates, ";
    // singleLinkedList.printLinkedList(head);

    // 82. Remove Duplicates from Sorted List II
    // nodes = { 1, 1, 1, 3, 3, 7, 9, 9, 12, 17, 17 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // head = solu.deleteDuplicatesII(head);
    // cout << "Deleted duplicates2, ";
    // singleLinkedList.printLinkedList(head);

    // 86. Partition List
    // int x;
    // while(1)
    // {
    //     cout << "Input partition number: ";
    //     cin >> x;
    //     head = solu.partition(head, x);
    //     cout << "Partition the list with number " << x << ", ";
    //     singleLinkedList.printLinkedList(head);
    // }

    // 206. Reverse Linked List
    // head = solu.reverseList(head);
    // cout << "Reversed ";
    // singleLinkedList.printLinkedList(head);

    // 234. Palindrome Linked List
    // nodes = { 1, 2, 3, 4, 3, 2, 1 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // cout << "Is parlindrome: " << (solu.isPalindrome(head)?"true":"false") << endl;

    // 203. Remove Linked List Elements
    // int val;
    // while(1)
    // {
    //     nodes = { 1, 2, 3, 4, 3, 2, 1 };
    //     singleLinkedList.printNodesArray(nodes);
    //     head = singleLinkedList.createLinkedListFromArray(nodes);
    //     singleLinkedList.printLinkedList(head);
    //     cout << "Remove integer: ";
    //     cin >> val;
    //     head = solu.removeElements(head, val);
    //     cout << "Removed integer, ";
    //     singleLinkedList.printLinkedList(head);
    // }

    // 160. Intersection of Two Linked Lists
    // int val;
    // while(1)
    // {
    //     singleLinkedList.printNodesArray(nodes);
    //     head = singleLinkedList.createLinkedListFromArray(nodes);
    //     singleLinkedList.printLinkedList(head);
    //     singleLinkedList.printNodesArray(nodes2);
    //     cout << "Input intersection node: ";
    //     cin >> val;
    //     ListNode* head2 = singleLinkedList.intersectLinkedList(nodes2, head, val);
    //     singleLinkedList.printLinkedList(head2);
    //     ListNode* pIntersection = solu.getIntersectionNode(head, head2);
    //     cout << "Intersection Node: " << ((nullptr == pIntersection)?"null":to_string(pIntersection->val)) << endl << endl;
    // }

    // 876. Middle of the Linked List
    // ListNode *pMiddle = solu.middleNode(head);
    // cout << "Middle node: " << ((nullptr == pMiddle)?"null":to_string(pMiddle->val)) << endl;

    // 92. Reverse Linked List II
    // int m, n;
    // while(1)
    // {
    //     cout << "Reverse from: ";
    //     cin >> m;
    //     cout << "to: ";
    //     cin >> n;
    //     head = solu.reverseBetween(head, m, n);
    //     cout << "Reversed between " << m << " and " << n <<", ";
    //     singleLinkedList.printLinkedList(head);
    // }

    // 109. Convert Sorted List to Binary Search Tree
    // nodes = { 1, 2, 3, 4, 5, 6, 7 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // TreeNode *root = solu.sortedListToBST(head);

    // 148. Sort List
    // nodes = { 19, 2, 35, 54, 77, 7, 63 };
    // nodes = { 4,19,14,5,5,-3,1,8,5,11,15 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // head = solu.sortList(head);
    // cout << "Sorted ";
    // singleLinkedList.printLinkedList(head);

    // 143. Reorder List
    // solu.reorderList(head);
    // cout << "Reordered ";
    // singleLinkedList.printLinkedList(head);

    // 147. Insertion Sort List
    // nodes = { 19, 2, 35, 54, 77, 7, 63 };
    // nodes = { 4,19,14,5,5,-3,1,8,5,11,15 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // head = solu.insertionSortList(head);
    // cout << "Insertion sorted ";
    // singleLinkedList.printLinkedList(head);

    // 141. Linked List Cycle
    // int cycleEntry;
    // while(1)
    // {
    //     singleLinkedList.printNodesArray(nodes);
    //     head = singleLinkedList.createLinkedListFromArray(nodes);
    //     singleLinkedList.printLinkedList(head);
    //     cout << "Input the position where tail connects to: ";
    //     cin >> cycleEntry;
    //     singleLinkedList.buildCycle(head, cycleEntry);
    //     cout << "Has cycle: " << (solu.hasCycle(head)?"true":"false") << endl << endl;
    // }

    // int cycleEntry;
    // while(1)
    // {
    //     singleLinkedList.printNodesArray(nodes);
    //     head = singleLinkedList.createLinkedListFromArray(nodes);
    //     singleLinkedList.printLinkedList(head);
    //     cout << "Input the position where tail connects to: ";
    //     cin >> cycleEntry;
    //     singleLinkedList.buildCycle(head, cycleEntry);
    //     ListNode *pCycleEntry = solu.detectCycle(head);
    //     cout << "Cycle entry node: " << ((nullptr == pCycleEntry)?"null":to_string(pCycleEntry->val)) << endl << endl;
    // }

    // 21. Merge Two Sorted Lists
    // nodes = { 1, 3, 5, 6, 7, 12 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // nodes = { 2, 4, 7, 7, 9, 10, 11, 12, 14, 17, 19};
    // singleLinkedList.printNodesArray(nodes);
    // ListNode* head2 = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head2);
    // head = solu.mergeTwoLists(head, head2);
    // cout << "Merged two lists, ";
    // singleLinkedList.printLinkedList(head);

    // 23. Merge k Sorted Lists
    // vector<ListNode*> lists;
    // nodes = { 1, 3, 5, 6, 7, 12 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // lists.emplace_back(head);
    // nodes = { 2, 4, 7, 7, 9, 10, 11, 12, 14, 17, 19};
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // lists.emplace_back(head);
    // nodes = { 3, 4, 8, 13, 13, 15, 16, 18, 18, 18 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // lists.emplace_back(head);
    // head = solu.mergeKLists(lists);
    // cout << "Merged K lists, ";
    // singleLinkedList.printLinkedList(head);

    // 138. Copy List with Random Pointer
    // Accepted in once submission, so no debug function implemented.
    // solu.copyRandomList();

    // 25. Reverse Nodes in k-Group
    // int k;
    // while(1)
    // {
    //     cout << "How many nodes should be reversed per group: ";
    //     cin >> k;
    //     head = solu.reverseKGroup(head, k);
    //     cout << "Reversed in groups of " << k << ", ";
    //     singleLinkedList.printLinkedList(head);
    // }

    // 445. Add Two Numbers II
    head = solu.addTwoNumbersII(head, head2);
    cout << "Added two numbers II, ";
    singleLinkedList.printLinkedList(head);

    DOCK();

    return 0;
}

