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


