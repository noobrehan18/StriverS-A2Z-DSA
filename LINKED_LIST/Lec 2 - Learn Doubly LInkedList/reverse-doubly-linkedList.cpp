#include<bits/stdc++.h>

using namespace std;

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* head)
{   
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* last = NULL;
    Node* current = head;

    while(current!=NULL){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }

    return last->prev;
}

//sheet qs=====-->>

/*.          Reverse a Doubly Linked List

You are given the head of a doubly linked list.

Reverse the list in-place and return the new head of the reversed list.
Examples:
Input: head = [10, 20, 30]
Output:﻿ [30, 20, 10]
Input: head = [1, 3, 5, 7, 9]
Output: [9, 7, 5, 3, 1]*/

//soltion-->>

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* current = head;
        ListNode* temp = NULL;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != NULL) {
            head = temp->prev;
        }

        return head;
    }
};