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
#include <unordered_map>

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
        ListNode *node = nullptr;
        ListNode *next = nullptr;

        for (int i = nodes.size()-1; i >= 0; --i)
        {
            node = new ListNode(nodes[i]);
            node->next = next;
            next = node;
        }

        return node;
    }

    void printNodesArray(vector<int>& nodes)
    {
        int n = nodes.size();
        if (0 == n)
            return;

        cout << "nodes: [";

        for (int i = 0; i < n; ++i)
        {
            cout << " " << nodes[i];
            if (i < n - 1)
                cout << ",";
        }

        cout << " ]" << endl;
    }

    void printLinkedList(ListNode* head)
    {
        if (!head)
            return;

        cout << "Single Linked List: ";

        while (head)
        {
            cout << head->val;
            head = head->next;
            if (head)
                cout << "->";
        }

        cout << endl;
    }

    void buildCycle(ListNode* head, int& cycleEntry)
    {
        return;
    }

    ListNode* intersectLinkedList(vector<int>& nodes, ListNode* head, int val)
    {
        ListNode *node = nullptr;
        ListNode *head2 = nullptr;

        while (head)
        {
            if (head->val == val)
                break;

            head = head->next;
        }

        node = head2 = createLinkedListFromArray(nodes);

        while (node->next)
            node = node->next;

        node->next = head;

        return head2;
    }
};

class Solution
{
public:
    // 19. Remove Nth Node From End of List
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head)
            return head;

        ListNode *former = head;
        ListNode *latter = head; 
        ListNode *prev = nullptr;

        while (n--)
            former = former->next;
        
        if (!former)
            return head->next;

        while (former)
        {
            former = former->next;
            prev = latter;
            latter = latter->next;
        }

        prev->next = latter->next;

        return head;
    }

    // 2. Add Two Numbers
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *prev = nullptr;
        int carry = 0;

        while (cur1 && cur2)
        {
            cur1->val += cur2->val + carry;
            carry = cur1->val / 10;
            cur1->val %= 10;
            prev = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        if (!cur1)
            cur1 = prev->next = cur2;

        while (carry && cur1)
        {
            cur1->val += carry;
            carry = cur1->val / 10;
            cur1->val %= 10;
            prev = cur1;
            cur1 = cur1->next;
        }

        if (carry)
            prev->next = new ListNode(1);

        return l1;
    }

    // 24. Swap Nodes in Pairs
    ListNode* swapPairs(ListNode* head)
    { 
        ListNode *node = head;
        ListNode *prev = nullptr, *next = nullptr, *pprev = nullptr;
        int step = 1;

        while (node)
        {
            if (0 == (step++) % 2)
            {
                prev->next = node->next;
                node->next = prev;
                if (3 == step)
                    head = node;
                else
                    pprev->next = node;
                node = prev->next;
                pprev = prev;
            }
            else
            {
                prev = node;
                node = node->next;
            }
        }

        return head;
    }

    // 61. Rotate List
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head || 0 == k)
            return head;

        vector<ListNode*> nodes;
        int n = 0;

        while (head)
        {
            nodes.push_back(head);
            head = head->next;
            ++n;
        }

        if (1 == n || 0 == k % n)
            return nodes[0];

        k %= n;
        k = n - k;

        head = nodes[k];
        nodes[k-1]->next = nullptr;
        nodes[n-1]->next = nodes[0];

        return head;
    }

    // 83. Remove Duplicates from Sorted List
    ListNode* deleteDuplicates(ListNode* head)
    {
        unordered_map<int, int> nodes;

        ListNode *node = head;
        ListNode *prev = nullptr;

        while (node)
        {
            auto it = nodes.find(node->val);
            if (nodes.end() == it)
            {
                nodes.insert({node->val, 1});
                prev = node;
            }
            else
                prev->next = node->next;

            node = node->next;
        }

        return head;
    }

    // 82. Remove Duplicates from Sorted List II
    ListNode* deleteDuplicatesII(ListNode* head)
    {
        ListNode *prev = nullptr;
        ListNode *node = head;

        while (node && node->next)
        {
            if (node->val != node->next->val)
            {
                prev = node;
                node = node->next;
                continue;
            }

            node = node->next;
            
            while (1)
            {
                if (!node->next)
                {
                    node = nullptr;
                    break;
                }

                if (node->val != node->next->val)
                {
                    node = node->next;
                    break;
                }

                node = node->next;
            }

            if (!prev)
                head = node;
            else
                prev->next = node;
        }

        return head;
    }

    // 86. Partition List
    // ListNode* partition(ListNode* head, int x)
    // {
    //     ListNode *node = head;
    //     ListNode *ltail = nullptr;
    //     ListNode *xnode = nullptr;
    //     ListNode *rhead = nullptr;
    //     ListNode *rtail = nullptr;

    //     while (node)
    //     {
    //         if (node->val == x)
    //             break;
    //         node = node->next;
    //     }

    //     if (!node)
    //         return head;

    //     xnode = node;
    //     node = head;
    //     head = nullptr;

    //     while (node)
    //     {
    //         if (node == xnode)
    //         {
    //             node = node->next;
    //             continue;
    //         }

    //         if (node->val < x)
    //         {
    //             if (!ltail)
    //                 head = ltail = node;
    //             else
    //             {
    //                 ltail->next = node;
    //                 ltail = node;
    //             }
    //         }
    //         else if (node->val > x)
    //         {
    //             if (!rhead)
    //                 rhead = rtail = node;
    //             else
    //             {
    //                 rtail->next = node;
    //                 rtail = node;
    //             }
    //         }

    //         node = node->next;
    //     }

    //     xnode->next = rhead;
    //     if (rtail)
    //         rtail->next = nullptr;

    //     if (!head)
    //         head = xnode;
    //     else
    //         ltail->next = xnode;

    //     return head; 
    // }

    ListNode* partition(ListNode* head, int x)
    {
        ListNode *node =head;
        ListNode *ltail = nullptr;
        ListNode *rhead = nullptr;
        ListNode *rtail = nullptr;

        while (node)
        {
            if (node->val < x)
            {
                if (!ltail)
                    head = ltail = node;
                else
                {
                    ltail->next = node;
                    ltail = node;
                }
            }
            else
            {
                if (!rhead)
                    rhead = rtail = node;
                else
                {
                    rtail->next = node;
                    rtail = node;
                }
            }

            node = node->next;
        }

        if (rhead)
        {
            if (ltail)
                ltail->next = rhead;

            rtail->next = nullptr;
        }

        return head;
    }

    // 206. Reverse Linked List
    ListNode* r_reverseList(ListNode *prev, ListNode* node)
    {
        if (!node)
            return node;

        ListNode *next = node->next;
        node->next = prev;

        if (!next)
            return node;

        return r_reverseList(node, next);
    }

    ListNode* i_reverseList(ListNode* head)
    {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;

        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;   
        }

        return prev;
    }

    ListNode* reverseList(ListNode* head)
    {
        // return r_reverseList(NULL, head);
        return i_reverseList(head);     
    }

    // 234. Palindrome Linked List
    bool isPalindrome(ListNode* head)
    {
        if (!head || !head->next)
            return true;
        
        if (!head->next->next)
            return (head->val == head->next->val);

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;

        while (1)
        {
            if (!fast->next)
            {
                fast = slow->next;
                slow = prev;
                break;
            }
            else if (!fast->next->next)
            {
                fast = slow->next;
                slow->next = prev;
                break;
            }

            fast = fast->next->next;

            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        while (fast)
        {
            if (slow->val != fast->val)
                return false;
            
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }

    // 203. Remove Linked List Elements
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode *node = head;
        ListNode *prev = nullptr;

        while (node)
        {
            if (node->val == val)
            {
                if (node == head)
                    head = node->next;
                else
                    prev->next = node->next;
            }
            else
                prev = node;

            node = node->next;
        }

        return head;
    }

    // 160. Intersection of Two Linked Lists
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;
        
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        int done = 0;

        while (done < 3)
        {
            if (nodeA == nodeB)
                return nodeA;

            nodeA = nodeA->next;
            nodeB = nodeB->next; 
            
            if (!nodeA)
            {
                nodeA = headB;
                ++done;
            }

            if (!nodeB)
            {
                nodeB = headA;
                ++done;
            } 
        }

        return nullptr;
    }
};

int main()
{
    LinkedList singleLinkedList;
    Solution solu;
    ListNode* head = nullptr;
    ListNode* head2 = nullptr;

// #define COMMON_INIT

    vector<int> nodes = { 7, 6, 5, 4, 3, 2, 1 };
#ifdef COMMON_INIT
    singleLinkedList.printNodesArray(nodes);
    head = singleLinkedList.createLinkedListFromArray(nodes);
    singleLinkedList.printLinkedList(head);
#endif

    vector<int> nodes2 = { 2, 0, 2, 1, 7, 8, 9, 1};
#ifdef COMMON_INIT
    singleLinkedList.printNodesArray(nodes2);
    head2 = singleLinkedList.createLinkedListFromArray(nodes2);
    singleLinkedList.printLinkedList(head2);
#endif

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
    // while (1)
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
    // nodes = { 1, 2, 3, 3, 2, 1 };
    // // nodes = { 1, 2, 3, 4, 3, 2, 1 };
    // singleLinkedList.printNodesArray(nodes);
    // head = singleLinkedList.createLinkedListFromArray(nodes);
    // singleLinkedList.printLinkedList(head);
    // cout << "Is parlindrome: " << (solu.isPalindrome(head)?"true":"false") << endl;

    // 203. Remove Linked List Elements
    // int val;
    // while (1)
    // {
    //     cout << "Remove integer: ";
    //     cin >> val;
    //     head = solu.removeElements(head, val);
    //     cout << "Removed integer, ";
    //     singleLinkedList.printLinkedList(head);
    // }

    // 160. Intersection of Two Linked Lists
    int val;
    while (1)
    {
        singleLinkedList.printNodesArray(nodes);
        head = singleLinkedList.createLinkedListFromArray(nodes);
        singleLinkedList.printLinkedList(head);
        cout << "Input intersection node: ";
        cin >> val;

        singleLinkedList.printNodesArray(nodes2);
        head2 = singleLinkedList.intersectLinkedList(nodes2, head, val);
        singleLinkedList.printLinkedList(head2);
        ListNode* pIntersection = solu.getIntersectionNode(head, head2);
        cout << "Intersection Node: " << ((nullptr == pIntersection)?"null":to_string(pIntersection->val)) << endl << endl;
    }

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
    // head = solu.addTwoNumbersII(head, head2);
    // cout << "Added two numbers II, ";
    // singleLinkedList.printLinkedList(head);

    DOCK();

    return 0;
}

