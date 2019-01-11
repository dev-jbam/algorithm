/*

https://leetcode.com/problems/reverse-nodes-in-k-group/


25. Reverse Nodes in k-Group
Hard

894

197

Favorite

Share
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/


#if 0


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size= getSizeOfNode(head);    
        if( size < k ) return head;
        
        ListNode *prev= nullptr;
        ListNode *cur= head;
        ListNode *next= head->next;

        int count = size/k;
        
        vector< pair <ListNode*, ListNode* > > v_p_node;
        
        ListNode* org_first=head;
        for(int g_idx = 0 ; g_idx < count; g_idx++){
            org_first = cur;
            for(int i =0; i < k; ++i){
                next = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = next;
            }
            org_first -> next = cur;
            v_p_node.push_back(make_pair(prev, org_first));
        }
                
        for(int i =0; i < v_p_node.size() -1 ; ++i){
            v_p_node[i].second ->next = v_p_node[i + 1].first; 
        }
        
        return v_p_node[0].first;
    }
    
    inline int getSizeOfNode(ListNode* head){
        ListNode *ptr =head;
        int count = 0;
        while(ptr){
            ptr=ptr->next;
            count++;
        }
        return count;
    }
};

#endif