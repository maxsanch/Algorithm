#include <stdio.h>
#include <stdlib.h>

struct cell {
    int data;
    struct cell* tail;
};

typedef struct cell* list;

list add(int value, list li) {
    list l1 = malloc(sizeof(list));

    l1->data = value;
    l1->tail = li;

    return l1;
}

void main() {
    list l = add(50, NULL);

    l = add(542, l);

    l = add(376, l);

    while (l != NULL) {
        printf("%i \n", l->data);
        l = l->tail;
    }
}