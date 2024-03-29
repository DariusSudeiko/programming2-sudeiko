#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// map number to name
const char *map[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// data structure
typedef struct Data {
    int number;
    char name[8];
} data_t;

// define the item (node) of a linked list
typedef struct Node {
    data_t data;
    struct Node *next;
    struct Node *prev;
} node_t;

// declare of functions
// add(node_t **, node_t) - it is function signature
node_t *add(node_t **, node_t);
void print_node(const node_t *);
void display(const node_t *);
void display_reverse(const node_t *);
void freeList(node_t **);

int main(int argc, char const *argv[]) {
    node_t *list = NULL; // the head of a linked list

    for (size_t i = 0; i < sizeof(map) / sizeof(map[0]); ++i) {
        node_t node = { .data.number = i };
        strcpy(node.data.name, map[i]);
        add(&list, node);
    }

    puts("The linked list is: ");
    display(list);
    puts("The linked list in reverse is: ");
    display_reverse(list);
    freeList(&list);
    return 0;
}

node_t *add(node_t **head, node_t node) {
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    if (tmp) {
        tmp->data = node.data;
        tmp->next = *head;
        tmp->prev = NULL;
        if (*head) {
            (*head)->prev = tmp;
        }
        *head = tmp;
    }
    return tmp;
}

void print_node(const node_t *node) {
    printf("node: %d, %s, len of name %zu; prev: %p, next: %p\n",
           node->data.number, node->data.name, strlen(node->data.name),
           (void *)node->prev, (void *)node->next);
}

void display(const node_t *head) {
    for (const node_t *ptr = head; ptr != NULL; ptr = ptr->next) {
        print_node(ptr);
    }
}

void display_reverse(const node_t *head) {
    const node_t *ptr = head;
    if (ptr) {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        while (ptr != NULL) {
            print_node(ptr);
            ptr = ptr->prev;
        }
    }
}

void freeList(node_t **head) {
    while (*head != NULL) {
        node_t *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}