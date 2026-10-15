#include <stdio.h>
#include <stdlib.h>

struct cell {
    int data;
    struct cell* tail;
};

typedef struct cell* list;

list append(int value, list li) {
    list l1 = malloc(sizeof(struct cell));

    l1->data = value;
    l1->tail = li;

    return l1;
}

list dequeue(list li) {
    list l1 = NULL;
    list temp = li;

    while(temp->tail != NULL) {
        l1 = append(temp->data, l1);
        temp = temp->tail;
    }

    return l1;
}

list peek(list li) {
    list temp = li;
    while(temp->tail != NULL) {
        temp = temp->tail;
    }
    printf("%i \n", temp->data);
}

void main() {
    list l = append(50, NULL);

    l = append(542, l);

    l = append(376, l);

    l = dequeue(l);

    while (l != NULL) {
        printf("%i \n", l->data);
        l = l->tail;
    }
}