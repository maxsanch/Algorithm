#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct cell {
    int key;
    int value;
    struct cell* next;
};

typedef struct cell* list;

struct hash_table {
    list table[TABLE_SIZE];
};

typedef struct hash_table* hash_table;

// Fonction de hash
int hash(int key) {
    return key % TABLE_SIZE;
}

hash_table create_hash_table() {

    hash_table h = malloc(sizeof(struct hash_table));

    for (int i = 0; i < TABLE_SIZE; i++) {
        h->table[i] = NULL;
    }

    return h;
}

void insert(hash_table h, int key, int value) {

    int index = hash(key);

    list new_cell = malloc(sizeof(struct cell));

    new_cell->key = key;
    new_cell->value = value;

    new_cell->next = h->table[index];

    h->table[index] = new_cell;
}

int search(hash_table h, int key) {

    int index = hash(key);

    list current = h->table[index];

    while (current != NULL) {

        if (current->key == key) {
            return current->value;
        }

        current = current->next;
    }

    return -1;
}

void print_hash_table(hash_table h) {

    for (int i = 0; i < TABLE_SIZE; i++) {

        printf("[%d] : ", i);

        list current = h->table[i];

        while (current != NULL) {

            printf("(%d -> %d) ", current->key, current->value);

            current = current->next;
        }

        printf("\n");
    }
}

void free_hash_table(hash_table h) {

    for (int i = 0; i < TABLE_SIZE; i++) {

        list current = h->table[i];

        while (current != NULL) {

            list temp = current;

            current = current->next;

            free(temp);
        }
    }

    free(h);
}


int main() {

    hash_table h = create_hash_table();

    insert(h, 10, 100);
    insert(h, 25, 200);
    insert(h, 35, 300);
    insert(h, 42, 400);

    print_hash_table(h);

    printf("\n");

    printf("Valeur de 25 : %d\n", search(h, 25));
    printf("Valeur de 42 : %d\n", search(h, 42));
    printf("Valeur de 99 : %d\n", search(h, 99));

    free_hash_table(h);

    return 0;
}