//
// Created by wojtek on 11.12.16.
//

#ifndef LAB6_ZAD27_H
#define LAB6_ZAD27_H
#include <iostream>

struct Node
{
    int value;
    struct Node *next;
    Node() : value(0), next(nullptr) {}
    Node(int val, Node *nx) :  value(val), next(nx) {}
};


struct List
{
    struct Node *first, *last;
};

// pomocnicze:
bool checkList(List * list, Node * n);

// punkt a:
List * list();
Node * node(int v);

// punkt b:
List*  push(List* s, Node* n);

// punkt c:
List*  inject(List* s, Node* n);

// punkt d:
List* insertAfter(List* s, Node* curr, Node* n);

// punkt e:
List* insertBefore(List* s, Node* curr, Node* n);

// punkt f:
List*  del(List* s, int v);

// punkt g:
void  printNode(Node* n);

// punkt h:
void printLR(List *list);

// punlt i:
void  printRL(List* s);

void zad27();

#endif //LAB6_ZAD27_H
