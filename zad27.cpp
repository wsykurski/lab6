//
// Created by wojtek on 11.12.16.
//
#include "zad27.h"
using namespace std;

void zad27() {
    cout << "Zadanie 27" << endl;
    List *p_list = list();
    Node *p_node = node(10);
    Node *p_node2 = node(5);
    Node *p_node3 = node(-1);
    Node *p_node4 = node(4);
    Node *p_node5 = node(3);
    cout << "Wartość node: " << p_node->value << endl;
    cout << "Pushe:" << endl;
    p_list = push(p_list, p_node);
    p_list = push(p_list, p_node2);
    p_list = push(p_list, p_node);
    cout << "Wartość pierwszego wezla listy: " << p_list->first->value << endl;
    cout << "Wartość ostatniego wezla listy: " << p_list->last->value << endl;
    cout << endl << "Drukowanie listy" << endl;
    PrintList(p_list);
    cout << endl << "Inject na końcu:" << endl;
    p_list = inject(p_list, p_node3);
    cout << "Drukowanie listy" << endl;
    PrintList(p_list);
    cout << endl << "Wstawianie po p_node_2:" << endl;
    p_list = insertAfter(p_list, p_node2, p_node4);
    cout << "Drukowanie listy" << endl;
    PrintList(p_list);
    cout << endl << "Wstawianie przed p_node:" << endl;
    p_list = insertBefore(p_list, p_node, p_node5);
    cout << "Drukowanie listy" << endl;
    PrintList(p_list);
}

void PrintList(List *list) {
    Node *temp = list->first;
    while(temp)
    {
        cout << temp->value << ", ";
        temp = temp->next;
    }
}

bool checkList(List *list, Node *n) {
    Node *temp = list->first;
    while(temp)
    {
        if (n == temp || n->value == temp->value) return false;
        temp = temp->next;
    }
    return true;
}

List *list() {
    return new List();
}

Node *node(int v) {
    return new Node{v, nullptr};
}

List *push(List *s, Node *n) {
    if (checkList(s, n))
    {
        Node * temp = s->first;
        s->first = n;
        n->next = temp;
        if(!temp) s->last = n;
    }
    return s;
}

List *inject(List *s, Node *n) {
    if (checkList(s, n))
    {
        s->last->next = n;
        s->last = s->last->next;
    }
    return s;
}

List *insertAfter(List *s, Node *curr, Node *n) {
    if (checkList(s, n))
    {
        Node *temp = curr->next;
        curr->next = n;
        n->next = temp;
        if (curr == s->last) s->last == n;
    }
    return s;
}

List *insertBefore(List *s, Node *curr, Node *n) {
    if (checkList(s, n))
    {
        Node *temp = s->first;
        if (temp == curr)
        {
            n->next = temp;
            s->first = n;
        }
        else {
            while (temp->next && temp->next != curr) temp = temp->next;
            temp->next = n;
            n->next = curr;
        }
    }
    return s;
}


