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

// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Definition for a Node.
class Node
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// Definition for singly-linked list.
class LinkedList
{
public:
    ListNode* createLinkedListFromArray(vector<int>& nodes)
    {
        ListNode* pNode = nullptr;
        ListNode* pNext = nullptr;

        for(int i = nodes.size()-1; i >= 0; i--)
        {
            pNode = new ListNode(nodes[i]);
            pNode->next = pNext;
            pNext = pNode;
        }
        
        return pNode;
    }

    void printNodesArray(vector<int>& nodes)
    {
        cout << "nodes array: [";
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i];

            if (nodes.size() != i + 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    void printLinkedList(ListNode* head)
    {   
        cout << "Single Linked List: ";

        while(nullptr != head)
        {
            cout << head->val;
            head = head->next;

            if(nullptr != head)
                cout << "->";
        }

        cout << endl;
    }

    void buildCycle(ListNode* head, int& cycleEntry)
    {
        if(nullptr == head || 0 > cycleEntry)
            return;

        int count = -1;
        ListNode *pCursor = head, *pTail = nullptr;

        while(nullptr != pCursor)
        {
            count++;
            pTail = pCursor;
            pCursor = pCursor->next;
        }

        if(cycleEntry > count)
            return;
        
        pCursor = head;

        while(0 <= cycleEntry)
        {
            if(0 == cycleEntry)
                pTail->next = pCursor;
            
            cycleEntry--;
            pCursor = pCursor->next;
        }
    }

    ListNode* intersectLinkedList(vector<int>& nodes, ListNode* head, int intersectNode)
    {
        ListNode *pNode = nullptr;
        ListNode *pNext = nullptr;
        ListNode *pIntersection = head;
        
        while(nullptr != pIntersection)
        {
            if(pIntersection->val == intersectNode)
                break;
            pIntersection = pIntersection->next;
        }

        pNext = pIntersection;

        for(int i = nodes.size()-1; i >=0; i--)
        {
            pNode = new ListNode(nodes[i]);
            pNode->next = pNext;
            pNext = pNode;
        }

        return pNode;
    }
};

class Solution
{
public:
    // 19. Remove Nth Node From End of List
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(nullptr == head || 0 >= n)
            return head;

        ListNode* pNode = head;
        ListNode* pPrev = head;

        while(0 < n && nullptr != pNode)
        {
            pNode = pNode->next;
            n--;
        }

        if(nullptr == pNode)
        {
            if(0 == n)
            {
                pNode = head;
                head = head->next;
                delete pNode;
            }
            return head;
        }

        while(nullptr != pNode->next)
        {
            pNode = pNode->next;
            pPrev = pPrev->next;
        }

        pNode = pPrev->next;
        pPrev->next = pNode->next;
        delete pNode;

        return head;
    }

    // 2. Add Two Numbers
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(nullptr == l1)
            return l2;
        if(nullptr == l2)
            return l1;
        
        int carry = 0;

        ListNode* pHead = l1;
        ListNode* pPrev = nullptr;

        while(nullptr != l1 && nullptr != l2)
        {
            l1->val += l2->val + carry;
            carry = l1->val/10;
            l1->val %= 10;
            pPrev = l2;
            l2 = l2->next;
            delete pPrev;
            pPrev = l1;
            l1 = l1->next;
        }

        if(nullptr != l2)
        {
            pPrev->next = l2;
            l1 = l2;
        }

        while(nullptr != l1)
        {
            if(0 == carry)
                break;
            
            l1->val += carry;
            carry = l1->val/10;
            l1->val %= 10;
            pPrev = l1;
            l1 = l1->next;
        }
        
        if(carry)
        {
            ListNode* pNode = new ListNode(carry);
            pPrev->next = pNode;
        }

        return pHead;
    }

    // 24. Swap Nodes in Pairs
    ListNode* swapPairs(ListNode* head)
    {
        if(nullptr == head || nullptr == head->next)
            return head;

        ListNode* pCursor1 = head;
        ListNode* pCursor2 = head->next;
        ListNode* pPrev = nullptr;
        head = pCursor2;

        while(1)
        {
            if(nullptr != pPrev)
                pPrev->next = pCursor2;
            
            pCursor1->next = pCursor2->next;
            pCursor2->next = pCursor1;
            pPrev = pCursor1;

            pCursor1 = pCursor1->next;
            if(nullptr == pCursor1)
                break;
            
            pCursor2 = pCursor1->next;
            if(nullptr == pCursor2)
                break;
        }

        return head;
    }

    // 61. Rotate List
    // This solution is one pass when k < len
    // ListNode* rotateRight(ListNode* head, int k)
    // {
    //     if(nullptr == head || nullptr == head->next || 0 >= k)
    //         return head;

    //     ListNode *pTail = head;
    //     ListNode *pPrev = nullptr;

    //     int len = 0;

    //     while(len < k)
    //     {
    //         len++;
    //         pPrev = pTail;
    //         pTail = pTail->next;
    //         if(nullptr == pTail)
    //             break;
    //     }

    //     if(nullptr == pTail)
    //     {
    //         if(len == k)
    //             return head;

    //         pTail = pPrev;
    //         pPrev = head;

    //         k %= len;
    //         k = len - k - 1;
    //         while(0 < k--)
    //             pPrev = pPrev->next;
    //     }
    //     else
    //     {
    //         pPrev = head;
    //         while(nullptr != pTail->next)
    //         {
    //             pTail = pTail->next;
    //             pPrev = pPrev->next;
    //         }
    //     }

    //     pTail->next = head;
    //     head = pPrev->next;
    //     pPrev->next = nullptr;

    //     return head;
    // }

    // This solution is easy to understand
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(nullptr == head || nullptr == head->next || 0 >= k)
            return head;

        ListNode *pTail = head;
        ListNode *pTruncate = head;
        int len = 1;

        while(nullptr != pTail->next)
        {
            pTail = pTail->next;
            len++;
        }

        if(len == k)
            return head;
        else if(len < k)
            k %= len;
        
        k = len - k - 1;
        while(0 < k--)
            pTruncate = pTruncate->next;
        
        pTail->next = head;
        head = pTruncate->next;
        pTruncate->next = nullptr;

        return head;
    }

    // 83. Remove Duplicates from Sorted List
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(nullptr == head)
            return head;

        ListNode *pCursor1 = head;
        ListNode *pCursor2 = head->next;
        ListNode *pNext = nullptr;

        while (nullptr != pCursor2)
        {
            if(pCursor1->val == pCursor2->val)
            {
                pNext = pCursor2->next;
                delete pCursor2;
                pCursor2 = pNext;
            }
            else
            {
                pCursor1->next = pCursor2;
                pCursor1 = pCursor1->next;
                pCursor2 = pCursor2->next;
            }
        }

        pCursor1->next = nullptr;

        return head;
    }

    // 82. Remove Duplicates from Sorted List II
    ListNode* deleteDuplicatesII(ListNode* head)
    {
        if(nullptr == head || nullptr == head->next)
            return head;

        ListNode* pSlider1 = nullptr;
        ListNode* pSlider2 = head;
        ListNode* pDistinct = nullptr;
        head = nullptr;

        while(nullptr != pSlider2)
        {
            if(nullptr == pSlider1)
            {
                if(pSlider2->val != pSlider2->next->val)
                    head = pDistinct = pSlider2;
                pSlider1 = pSlider2;
                pSlider2 = pSlider2->next;
                continue;
            }
            else if(pSlider2->val != pSlider1->val)
            {
                if(nullptr == pSlider2->next)
                {
                    if(nullptr == head)
                        head = pDistinct = pSlider2;
                    else
                    {
                        pDistinct->next = pSlider2;
                        pDistinct = pSlider2;
                    }
                }
                else
                {
                    if(pSlider2->val != pSlider2->next->val)
                    {
                        if(nullptr == head)
                            head = pDistinct = pSlider2;
                        else
                        {
                            pDistinct->next = pSlider2;
                            pDistinct = pSlider2;
                        }
                    }
                }
            }
            pSlider1 = pSlider1->next;
            pSlider2 = pSlider2->next;
        }

        if(nullptr != pDistinct)
            pDistinct->next = nullptr;

        return head;
    }

    // 86. Partition List
    ListNode* partition(ListNode* head, int x)
    {
        if(nullptr == head)
            return head;

        ListNode *pCursor = head;
        ListNode *pSmaller = nullptr;
        ListNode *pGreater = nullptr;
        ListNode *pGreaterHead = nullptr;

        while(nullptr != pCursor)
        {
            if(pCursor->val < x)
            {
                if(nullptr == pSmaller)
                    head = pSmaller = pCursor;
                else
                {
                    pSmaller->next = pCursor;
                    pSmaller = pCursor;
                }
            }
            else
            {
                if(nullptr == pGreater)
                    pGreater = pGreaterHead = pCursor;
                else
                {
                    pGreater->next = pCursor;
                    pGreater = pCursor;
                }    
            }

            pCursor = pCursor->next;
        }

        if(nullptr != pGreater)
        {
            if(nullptr != pSmaller)
                pSmaller->next = pGreaterHead;

            pGreater->next = nullptr;
        }

        return head;
    }

    // 206. Reverse Linked List
    ListNode* reverseList(ListNode* head)
    {
        if(nullptr == head || nullptr == head->next)
            return head;

        ListNode *pPrev = head;
        ListNode *pCursor = head->next;
        ListNode *pNext = nullptr;
        head->next = nullptr;

        while(nullptr != pCursor)
        {
            pNext = pCursor->next;
            pCursor->next = pPrev;
            pPrev = pCursor;
            pCursor = pNext;
        }

        head = pPrev;

        return head;
    }

    // 234. Palindrome Linked List
    bool isPalindrome(ListNode* head)
    {
        if(nullptr == head || nullptr == head->next)
            return true;

        if(nullptr == head->next->next)
            return (head->val == head->next->val);
        
        ListNode *pSlower = head->next, *pFaster = head->next->next;
        ListNode *pPrev = head, *pNext = nullptr;
        head->next = nullptr;

        while(1)
        {
            pNext = pSlower->next;
            pSlower->next = pPrev;
            pPrev = pSlower;

            if(nullptr == pFaster->next)
            {
                pSlower = pSlower->next;
                pFaster = pNext;
                break;
            }
            else if(nullptr == pFaster->next->next)
            {
                pFaster = pNext;
                break;
            }
            pSlower = pNext;
            pFaster = pFaster->next->next;
        }

        while(nullptr != pSlower && nullptr != pFaster)
        {
            if(pSlower->val != pFaster->val)
                return false;

            pSlower = pSlower->next;
            pFaster = pFaster->next;
        }

        if(nullptr != pSlower || nullptr != pFaster)
            return false;

        return true;
    }

    // 237. Delete Node in a Linked List
    void deleteNode(ListNode* node)
    {
        ListNode *pNext = node->next;
        node->val = pNext->val;
        node->next = pNext->next;
        delete pNext;
    }

    // 203. Remove Linked List Elements
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode *pCursor = head;
        ListNode *pPrev = nullptr;
        head = nullptr;

        while(nullptr != pCursor)
        {
            if(pCursor->val != val)
            {
                if(nullptr == pPrev)
                    head = pPrev = pCursor;
                else
                {
                    pPrev->next = pCursor;
                    pPrev = pCursor;
                }
            }
            
            pCursor = pCursor->next;
        }

        if(nullptr != pPrev)
            pPrev->next = nullptr;

        return head;
    }

    // 160. Intersection of Two Linked Lists
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(nullptr == headA || nullptr == headB)
            return nullptr;

        if(headA == headB)
            return headA;

        int lenA = 0, lenB = 0;
        ListNode *pCursorA = headA, *pCursorB = headB;

        while(nullptr != headA)
        {
            lenA++;
            headA = headA->next;
        }

        while(nullptr != headB)
        {
            lenB++;
            headB = headB->next;
        }

        int diff = abs(lenA - lenB);
        while(0 < diff)
        {
            diff--;
            if(lenA > lenB)
                pCursorA = pCursorA->next;
            else
                pCursorB = pCursorB->next;
        }

        while(nullptr != pCursorA)
        {
            if(pCursorA == pCursorB)
                return pCursorA;
            pCursorA = pCursorA->next;
            pCursorB = pCursorB->next;
        }

        return nullptr;
    }

    // 876. Middle of the Linked List
    ListNode* middleNode(ListNode* head)
    {
        if(nullptr == head)
            return head;

        ListNode *pSlower = head;
        ListNode *pFaster = head;

        while(1)
        {
            if(nullptr == pFaster->next)
            {
                return pSlower;
            }
            else if(nullptr == pFaster->next->next)
            {
                return pSlower->next;
            }
            pSlower = pSlower->next;
            pFaster = pFaster->next->next;
        }
    }

    // 92. Reverse Linked List II
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        if(nullptr == head)
            return head;

        ListNode *pPrev = nullptr, *pCursor = head, *pNext = nullptr;
        ListNode *pBeforeM = nullptr, *pM = nullptr;
        int pos = 1;

        while(nullptr != pCursor)
        {
            if(pos == m - 1)
                pBeforeM = pCursor;
            if(pos == m)
                pM = pPrev = pCursor;
            else if(pos > m && pos < n)
            {
                pNext = pCursor->next;
                pCursor->next = pPrev;
                pPrev = pCursor;
                pCursor = pNext;
                pos++;
                continue;
            }
            else if(pos == n)
            {
                pM->next = pCursor->next;
                pCursor->next = pPrev;
                if(1 == m)
                    head = pCursor;
                else
                    pBeforeM->next = pCursor;
                break;
            }

            pCursor = pCursor->next;
            pos++;            
        }

        return head;
    }

    // 109. Convert Sorted List to Binary Search Tree
    TreeNode* listToBalancedBST(ListNode *head)
    {
        if(nullptr == head)
            return nullptr;

        ListNode *pPrev = nullptr, *pSlower = head, *pFaster = head;
        ListNode *pMiddle = nullptr;

        while(1)
        {
            if(nullptr == pFaster->next)
            {
                pMiddle = pSlower;
                break;
            }
            else if(nullptr == pFaster->next->next)
            {
                pPrev = pSlower;
                pMiddle = pSlower->next;
                break;
            }
            pPrev = pSlower;
            pSlower = pSlower->next;
            pFaster = pFaster->next->next;
        }

        TreeNode *pNode = new TreeNode(pMiddle->val);
        if(nullptr != pPrev)
        {
            pPrev->next = nullptr;
            pNode->left = listToBalancedBST(head);
            pNode->right = listToBalancedBST(pMiddle->next);
        }
        return pNode;
    }

    TreeNode* sortedListToBST(ListNode* head)
    {
        return listToBalancedBST(head);
    }

    // 148. Sort List
    // This solution is same as Partition(), crude and lack of consideration of duplicates
    // ListNode *findPivot(ListNode*& head, ListNode *tail)
    // {
    //     if(head == tail)
    //         return head;
        
    //     if(nullptr == head || nullptr == head->next || tail == head->next)
    //         return head;

    //     ListNode *pCursor = head->next, *pPivot = head;
    //     ListNode *pSmaller = nullptr, *pGreater = pPivot;

    //     while(pCursor != tail)
    //     {
    //         if(pCursor->val < pPivot->val)
    //         {
    //             if(nullptr == pSmaller)
    //                 head = pSmaller = pCursor;
    //             else
    //             {
    //                 pSmaller->next = pCursor;
    //                 pSmaller = pCursor;
    //             }
    //         }
    //         else
    //         {
    //             pGreater->next = pCursor;
    //             pGreater = pCursor;
    //         }
            
    //         pCursor = pCursor->next;
    //     }

    //     if(nullptr != pSmaller)
    //     {
    //         pSmaller->next = pPivot;
    //     }

    //     pGreater->next = tail;

    //     return pPivot;
    // }

    // Partition promotion, it will be nice if it does consideration of duplicates
    // ListNode *findPivot(ListNode*& head, ListNode *tail)
    // {
    //     if(head == tail)
    //         return head;
        
    //     if(nullptr == head || nullptr == head->next || tail == head->next)
    //         return head;

    //     ListNode *pPivot = head, *pCursor = head->next;
    //     ListNode *pPrePivot = nullptr, *pSegmentEnd = pPivot;

    //     while(pCursor != tail)
    //     {
    //         if(pCursor->val < pPivot->val)
    //         {
    //             if(nullptr == pPrePivot)
    //                 head = pCursor;
    //             pPrePivot = pCursor;
    //         }
    //         else
    //         {
    //             pSegmentEnd->next = pCursor;
    //             pSegmentEnd = pCursor;
    //             if(nullptr != pPrePivot)
    //                 pPrePivot->next = pSegmentEnd->next;
    //         }

    //         pCursor = pCursor->next;
    //     }

    //     if(nullptr != pPrePivot)
    //     {
    //         pSegmentEnd->next = pPrePivot->next;
    //         pPrePivot->next = pPivot;
    //     }
        
    //     return pPivot;
    // }

    // full consideration of duplicates
    ListNode *findPivot(ListNode*& head, ListNode *tail, ListNode*& pRight)
    {
        if(head == tail)
            return head;
        
        if(nullptr == head || nullptr == head->next || tail == head->next)
            return head;

        ListNode *pPrev = head, *pPivot = head, *pCursor = head->next;
        ListNode *pPrePivot = nullptr;

        while(pCursor != tail)
        {
            if(pPivot->val > pCursor->val)
            {
                pPrev->next = pCursor->next;
                if(nullptr != pPrePivot)
                    pPrePivot->next = pCursor;
                
                pCursor->next = pPivot;
                if(head == pPivot)
                    head = pCursor;
                pPrePivot = pCursor;
                pCursor = pPrev->next;
                continue;
            }
            else if(pPivot->val == pCursor->val)
            {
                if(pPrev->val == pCursor->val)
                    pRight = pCursor;
                else
                {
                    pPrev->next = pCursor->next;
                    pCursor->next = pRight->next;
                    pRight->next = pCursor;
                    pRight = pCursor;
                    pCursor = pPrev->next;
                    continue;
                }
            }

            pPrev = pCursor;
            pCursor = pCursor->next;
        }

        return pPivot;
    }

    ListNode* quickSortList(ListNode *head, ListNode *tail)
    {
        if(head != tail)
        {
            ListNode *pRight = head;
            ListNode *pPivot = findPivot(head, tail, pRight);
            pRight->next = quickSortList(pRight->next, tail);
            return quickSortList(head, pPivot);
        }

        return head;
    }

    ListNode* sortList(ListNode* head)
    {
        return quickSortList(head, nullptr);
    }

    // 143. Reorder List
    void reorderList(ListNode* head)
    {
        if(nullptr == head)
            return;

        ListNode *pSlower = head, *pFaster = head;
        ListNode *pPrev = nullptr, *pNext = nullptr;

        while(1)
        {
            if(nullptr == pFaster->next || nullptr == pFaster->next->next)
            {
                pNext = pSlower->next;
                pSlower->next = nullptr;
                pSlower = pNext;
                break;
            }

            pSlower = pSlower->next;
            pFaster = pFaster->next->next;
        }

        while(nullptr != pSlower)
        {
            pNext = pSlower->next;
            pSlower->next = pPrev;
            pPrev = pSlower;
            pSlower = pNext;
        }

        pSlower = pPrev;
        pFaster = head;

        while(nullptr != pSlower)
        {
            pNext = pFaster->next;
            pFaster->next = pSlower;
            pPrev = pSlower->next;
            pSlower->next = pNext;

            pFaster = pNext;
            pSlower = pPrev;
        }
    }

    // 147. Insertion Sort List
    ListNode* insertionSortList(ListNode* head)
    {
        if(nullptr == head || nullptr == head->next)
            return head;

        ListNode *pCursor1 = head->next, *pCursor2 = nullptr;
        ListNode *pSortedHead = head, *pNext = nullptr, *pSortedNext = nullptr;
        pSortedHead->next = nullptr;

        while(nullptr != pCursor1)
        {
            pNext = pCursor1->next;

            if(pCursor1->val <= pSortedHead->val)
            {
                pCursor1->next = pSortedHead;
                pSortedHead = pCursor1;
                pCursor1 = pNext;
                
                continue;
            }
            
            pCursor2 = pSortedHead;

            while(nullptr != pCursor2->next && pCursor1->val > pCursor2->next->val)
                pCursor2 = pCursor2->next;
            
            pSortedNext = pCursor2->next;
            pCursor2->next = pCursor1;
            pCursor1->next = pSortedNext;

            pCursor1 = pNext;
        }

        return pSortedHead;
    }

    // 141. Linked List Cycle
    // bool hasCycle(ListNode *head)
    // {    
    //     if(nullptr == head || nullptr == head->next)
    //         return false;
        
    //     ListNode *pSlower = head, *pFaster = head->next;

    //     while(1)
    //     {
    //         if(nullptr == pFaster->next || nullptr == pFaster->next->next)
    //             return false;

    //         if(pFaster == pSlower)
    //             return true;

    //         pSlower = pSlower->next;
    //         pFaster = pFaster->next->next;
    //     }
    // }
    
    bool hasCycle(ListNode *head)
    {   
        ListNode *pSlower = head, *pFaster = head;

        while(nullptr != pFaster && nullptr != pFaster->next)
        {
            pSlower = pSlower->next;
            pFaster = pFaster->next->next;
            if(pSlower == pFaster)
                break;
        }

        return (nullptr != pFaster && nullptr != pFaster->next);
    }

    // 142. Linked List Cycle II
    /*
                  entry     junction(faster meets slower) 
        |-----a-----|-----t-----|here is also 'a'| 
        N1->N2->N3->N4->N5->N6->N7......->Nn-1->Nn->
                    |______________r(cycle)________|
        |-------------------L--------------------|

        The question is to find out the value of 'a' which represents the number of nodes it passed though from head to the cycle entry.

        The entire linked list totally has 'L' nodes.
        From the head to cycle entry there are 'a' nodes, and the number of nodes of cycle is 'r'.
        Faster and slower met at the node where is 't' nodes from the cycle entry. 
        Assuming slower moved S steps(each step means go through 1 node), so that the number of steps faster has taken is 2S.
        2S = S+nr (s=a+t, nr means the faster has stepped through the cycle in n times)
        S = nr ---> a+t = nr(n>=1). Suppose n = 1, we can get: a+t = r since r = L-a, so: a+t = L-a ---> L=2a+t
        It means the number of nodes to take from the junction back to the cycle entry is also 'a'.  
        So the solution is from head we need to go through as many nodes as from the junction back to the cycle entry, then we will get touch in the cycle entry.
    */
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *pSlower = head, *pFaster = head;

        while(nullptr != pFaster && nullptr != pFaster->next)
        {
            pSlower = pSlower->next;
            pFaster = pFaster->next->next;

            if(pSlower == pFaster)
                break;
        }

        if(nullptr == pFaster || nullptr == pFaster->next)
            return nullptr;
        
        pSlower = head;

        while(pSlower != pFaster)
        {
            pSlower = pSlower->next;
            pFaster = pFaster->next;
        }

        return pSlower;
    }

    // 21. Merge Two Sorted Lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(nullptr == l1 && nullptr == l2)
            return nullptr;
        else if(nullptr == l1)
            return l2;
        else if(nullptr == l2)
            return l1;
        else if(l1 == l2)
            return l1;

        ListNode *pCursor1 = l1, *pCursor2 = l2;
        ListNode *pPrev = nullptr, *pNext = nullptr;

        while(nullptr != pCursor1 && nullptr != pCursor2)
        {
            if(pCursor1->val < pCursor2->val)
            {
                if(nullptr != pPrev)
                    pPrev->next = pCursor1;
                pPrev = pCursor1;
                pCursor1 = pCursor1->next;
            }
            else if(pCursor1->val > pCursor2->val)
            {
                if(nullptr != pPrev)
                    pPrev->next = pCursor2;
                pPrev = pCursor2;
                pCursor2 = pCursor2->next;
            }
            else
            {
                if(nullptr != pPrev)
                    pPrev->next = pCursor1;
                pNext = pCursor1->next;
                pCursor1->next = pCursor2;
                pPrev = pCursor2;
                pCursor2 = pCursor2->next;
                pCursor1 = pNext;
            }
        }

        if(nullptr != pCursor1)
            pPrev->next = pCursor1;
        else if(nullptr != pCursor2)
            pPrev->next = pCursor2;

        return (l1->val <= l2->val)?l1:l2;
    }

    // 23. Merge k Sorted Lists
    void mergeSort(vector<ListNode*>& lists, int left, int right)
    {
        if(left < right)
        {
            int mid = left + (right - left)/2;
            mergeSort(lists, left, mid);
            mergeSort(lists, mid+1, right);
            lists[left] = mergeTwoLists(lists[left], lists[mid+1]);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty())
            return nullptr;

        mergeSort(lists, 0, lists.size()-1);
        return lists[0];
    }

    // 138. Copy List with Random Pointer
    Node* copyRandomList(Node* head)
    {
        if(nullptr == head)
            return head;

        map<Node*, Node*> nodesMap;
        Node *pNode = head;

        while(nullptr != pNode)
        {
            auto itNode = nodesMap.find(pNode);

            Node *copyNode = nullptr;

            if(itNode != nodesMap.end())
                copyNode = itNode->second;
            else
            {
                copyNode = new Node(pNode->val);
                nodesMap.insert({pNode, copyNode});
            }

            if(nullptr != pNode->next)
            {
                itNode = nodesMap.find(pNode->next);
                if(itNode != nodesMap.end())
                    copyNode->next = itNode->second;
                else
                {
                    Node *nextNode = new Node(pNode->next->val);
                    copyNode->next = nextNode;
                    nodesMap.insert({pNode->next, nextNode});
                }
            }

            if(nullptr != pNode->random)
            {
                itNode = nodesMap.find(pNode->random);
                if(itNode != nodesMap.end())
                    copyNode->random = itNode->second;
                else
                {
                    Node *randomNode = new Node(pNode->random->val);
                    copyNode->random = randomNode;
                    nodesMap.insert({pNode->random, randomNode});
                }
            }

            if(pNode == head)
                head = copyNode;

            pNode = pNode->next;
        }

        return head;
    }

    // 25. Reverse Nodes in k-Group
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(nullptr == head || k <= 1)
            return head;

        int len = 0;
        ListNode *pCursor = head;
        ListNode *pHead = nullptr, *pTail = head;
        ListNode *pPrev = nullptr, *pNext = nullptr;

        while(nullptr != pCursor)
        {
            len++;
            pCursor = pCursor->next;
        }

        pCursor = head;
        int groupNum = len/k;
        int moveCount = k;

        while(groupNum)
        {
            while(0 < moveCount--)
            {
                pNext = pCursor->next;
                pCursor->next = pPrev;
                pPrev = pCursor;
                pCursor = pNext;
            }

            if(head == pTail)
                head = pPrev;
            else
            {
                pTail->next = pPrev;
                pTail = pHead;
            }

            groupNum--;
            if(!groupNum)
            {
                pTail->next = pCursor;
                break;
            }

            pHead = pPrev = pCursor;
            pCursor = pCursor->next;
            moveCount = k - 1;
        }

        return head;
    }

    // 445. Add Two Numbers II
    ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2)
    {
        if(nullptr == l1 && nullptr == l2)
            return nullptr;
        else if(nullptr == l1)
            return l2;
        else if(nullptr == l2)
            return l1;
        
        stack<ListNode*> num1, num2;
        ListNode *head1 = l1, *head2 = l2;
        int carry = 0;

        while(nullptr != l1 || nullptr != l2)
        {
            if(nullptr != l1)
            {
                num1.push(l1);
                l1 = l1->next;
            }
            if(nullptr != l2)
            {
                num2.push(l2);
                l2 = l2->next;  
            }
        }

        while(!num1.empty() && !num2.empty())
        {
            l1 = num1.top();
            num1.pop();
            l2 = num2.top();
            num2.pop();

            l1->val += l2->val + carry;
            carry = l1->val/10;
            l1->val %= 10;
            delete l2;
        }

        if(!num2.empty())
        {
            num2.top()->next = l1;
            num1 = std::move(num2);
            head1 = head2;
        }

        if(carry)
        {
            while(!num1.empty())
            {
                l1 = num1.top();
                num1.pop();

                l1->val += carry;
                carry = l1->val/10;
                l1->val %= 10;

                if(!carry)
                    break;
            }

            if(carry)
            {
                l1 = new ListNode(carry);
                l1->next = head1;
                head1 = l1;
            }
        }

        return head1;
    }
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

