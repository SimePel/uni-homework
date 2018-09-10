#include "stdlib.h"

#include "list.h"
#include "weekdayload.h"

static Node* new_node(weekday_load wl);

// new_list returns new list with allocated head
List* new_list() {
    List* l = malloc(sizeof(List));
    l->head = new_node((weekday_load) { Saturday, 0u });
    return l;
}

// new_filled_list returns new list, that contains all weekdays.
List* new_filled_list() {
    List* l = new_list();
    Node* n = l->head;
    for (enum Weekdays i = Sunday; i <= Friday; i++) {
        n->next = new_node((weekday_load) { i, 0u });
        n = n->next;
    }
    return l;
}

// update updates data in weekday struct.
void update(List* l, enum Weekdays w) {
    Node *n = l->head;
    while(n) {
        if (n->wl.weekday == w) {
            n->wl.count++;
            return;
        }
        n = n->next;
    } 
}

// print_week_load print global load about weekdays.
void print_week_load(List* l) {
    Node* n = l->head;
    while(n) {
        print_weekday_load(n->wl);
        n = n->next;
    }
}

// free_list deletes List and appropriate frees memory.
void free_list(List* l) {
    Node* n = l->head;    
    Node* t = n;
    while(n) {
        t = n->next;
        free(n);
        n = t;
    }
    free(t);
    free(l);
}

// new_node return new 'clean' node.
static Node* new_node(weekday_load wl) {
    Node* n = malloc(sizeof(Node));
    n->wl = wl;
    n->next = NULL;

    return n;
}