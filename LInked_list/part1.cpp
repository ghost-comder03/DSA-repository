#include<bits/stdc++.h>
#include <string>
#include <math.h>
#define ll long long
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

//delete xth node
Node* deleteNode(Node *head,int x)
{
   if(x==1){
       Node *temp=head;
       head=head->next;
       temp->next=NULL;
       delete temp;
   }
   else{
       Node *prev=NULL;
       Node *curr=head;
       int cnt=1;
       while(cnt<x){
           prev=curr;
           curr=curr->next;
           cnt++;
       }
       prev->next=curr->next;
       curr->next=NULL;
       delete curr;
   }
   return head;
}

// find middle element of given linked list
int getMiddle(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}

//reverse a linked list
struct Node* reverseList(struct Node *head)
{
        
    Node *prev=NULL;
    Node *curr=head;
    Node *age=NULL;
    while(curr!=NULL){
        age=curr->next;
        curr->next=prev;
        prev=curr;
        curr=age;
    }
    return prev;
}

// reverse nodes in k groups
Node* reverseKGroup(Node* head, int k) {
        if(head==NULL||head->next==NULL||k==1)return head;
        Node *s=head,*e=head;
        int inc =k-1;
        while(inc--){
            e=e->next;
            if(e==NULL) return head;
        }
        Node* nexthead=reverseKGroup(e->next,k);
        reverse(s,e);
        s->next=nexthead;
        return e;
        
}
void reverse(Node *s,Node *e){
    Node *p=NULL,*c=s,*n=s->next;
    while(p!=e){
        c->next=p;
        p=c;
        c=n;
        if(n!=NULL)n=n->next;
    }
}

// detect cycle in a linked list
bool detectLoop(Node* head)
{
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
        
}

//intersection of two linkedlist
Node *getIntersectionNode(Node *headA, Node *headB) {
        Node *a=headA,*b=headB;
        while(a!=b){
            if(a==NULL){
                a=headB;
            }
            else a=a->next;
            if(b==NULL) b=headA;
            else b=b->next;
        }
        return a;

        
}

// check if a linkedlist is palindrome or not
bool isPalindrome(Node* head) {
    if(head==NULL||head->next==NULL) return true;
        
    Node* slow = head;
    Node* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverseList(slow->next);
    slow = slow->next;
    Node* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->data != slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}

//rotate a linkedlist k times
int length(Node* head){
        Node* temp=head;
        int i =0;
        while(temp){
            temp=temp->next;
            i++;
        }
        return i;
    }
    Node* rotateRight(Node* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        k=k%(length(head));
        while(k--){
            Node *end=head;
            Node *bend=head;
            while(end->next!=NULL){
                end=end->next;
            }
            while(bend->next->next!=NULL){
                bend=bend->next;
            }

            end->next=head;
            bend->next=NULL;
            head=end;

        }
        return head;

    }


int main(){
    return 0;

}