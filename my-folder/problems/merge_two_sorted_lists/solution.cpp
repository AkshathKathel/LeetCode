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
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
     ListNode* pointer_one;
     ListNode* pointer_two;
     if(first && second){
    if(first->val<second->val){
        pointer_one = first;
        pointer_two = second;
    }
    else{
        pointer_one = second;
        pointer_two = first;
    }
    ListNode* preserve = pointer_two;
    ListNode* prev = pointer_two;
    ListNode* create = new ListNode();
    int check = 0;
    while(pointer_one!=NULL && pointer_two!=NULL){
        if(pointer_one->val<=pointer_two->val){
            create = new ListNode();
            create->val = pointer_one->val;
            create->next = pointer_two;
            if(prev == pointer_two){
                preserve = create;
            }
            else{
                prev->next = create;
            }
            prev = create;
            pointer_one = pointer_one->next;

        }

        else{
            pointer_two = pointer_two->next;
            prev = prev->next;
        }
    }
    if(pointer_two==NULL){

        prev->next = pointer_one;

    }
     
    return preserve;
     }
     else if(first){
         return first;
     }
     else {
         return second;
     }
    }

};