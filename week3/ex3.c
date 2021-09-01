#include <stdio.h>
#include <stdlib.h>

#define TYPE int

typedef struct node {
    TYPE val;
    int has_next;
    struct node *next;
} Tnode;

Tnode* get_last_node(Tnode *head){
    while (head->has_next) {
        head = head->next;
    }
    return head;
}

void insert_node(Tnode *after, Tnode node) {  // insert after
    if (after->has_next) {
        Tnode *next_next = after->next;

        after->next = malloc(sizeof(Tnode));

        after->next->val = node.val;
        after->next->has_next = 1;
        after->next->next = next_next;
    } else {
        after->has_next = 1;
        after->next = malloc(sizeof(Tnode));

        after->next->val = node.val;
        after->next->has_next = 0;
    }
}

void print_node(Tnode *head) {  // insert after
    printf("List:\n%d ", head->val);
    while (head->has_next) {
        head = head->next;
        printf("%d ", head->val);
    }
    printf("\n");
}

void delete_node(Tnode *node_before) {
    if (!node_before->has_next) return;
    if (node_before->next->has_next) {
        node_before->next = node_before->next->next;
    } else {
        node_before->has_next = 0;
    }
    free(node_before->next);
}


int main() {
    Tnode head = {0, 0};

    Tnode next;
    next.has_next = 0;

    next.val = 1;
    insert_node(get_last_node(&head), next);

    next.val = 5;
    insert_node(get_last_node(&head), next);

    next.val = 2;
    insert_node(get_last_node(&head), next);

    next.val = 9;
    insert_node(get_last_node(&head), next);

    print_node(&head);

    delete_node(head.next);
    print_node(&head);

    return 0;

}
