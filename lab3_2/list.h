#ifndef LIST_H
#define LIST_H
#include "weekdayload.h"

typedef struct Node Node;
struct Node {
    weekday_load wl;
    Node* next;
};

typedef struct List List;
struct List {
    Node* head;
};

List* new_list();
List* new_filled_list();
void update(List*, enum Weekdays);
void print_week_load(List*);
void free_list(List*);

#endif