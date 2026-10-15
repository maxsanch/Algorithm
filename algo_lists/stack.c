#include <stdio.h>
#include <stdlib.h>

struct cell {
    int data;
    struct cell* tail;
};

typedef struct cell* list;

list push(int value, list li) {
    list l1 = malloc(sizeof(struct cell));

    l1->data = value;
    l1->tail = li;

    return l1;
}

list pop(list li) {
    list l1 = malloc(sizeof(struct cell));

    l1->data = li->tail->data;
    l1->tail = li->tail->tail;

    return l1;
}

list peek(list li) {
    printf("%i \n", li->data);
}

void main() {
    list l = push(50, NULL);

    l = push(542, l);

    l = push(376, l);

    peek(l);

    l = pop(l);

    l = pop(l);

    while (l != NULL) {
        printf("%i \n", l->data);
        l = l->tail;
    }
}