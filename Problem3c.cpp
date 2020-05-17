#include "ListNode.h"
#include "iostream"

using namespace std;

ListNode* findCycleStart(ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    else if(head -> next == NULL){
        return NULL;
    }

    ListNode* behind = head;
    ListNode* ahead = head;

    behind = behind ->next;
    ahead = ahead ->next;
    ahead = ahead ->next;

    while(ahead && ahead->next){
        if( behind == ahead ){
            break;
        }
        behind = behind -> next;
        ahead = ahead -> next;
        ahead = ahead -> next;
    }

    if(behind != ahead){
        return NULL;
    }
    
    behind = head;
    while (behind != ahead){
        behind = behind ->next;
        ahead = ahead -> next;
    }


	return behind; // you will need to change this
}