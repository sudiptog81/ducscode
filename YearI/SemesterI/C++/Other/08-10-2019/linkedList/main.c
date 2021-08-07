#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

// void addNode(node *, int);

int main(void)
{
    // List of size 0
    node *list = NULL;

    // Add node to list
    node *n = malloc(sizeof(node));
    if (!n)
    {
        return 1;
    }

    n->info = 1;
    n->next = NULL;

    list = n;

    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->info);
    }

    // Free list
    for (node *tmp = list->next; list != NULL; list = tmp)
    {
        free(list);
    }
}