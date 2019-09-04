#include <stdio.h>
#include <stdlib.h>

struct Cell
{
    int data;
    struct Cell *next;
};

typedef struct Cell* List;

struct Cell* Cell_init(int data)
{
    struct Cell* cell = (struct Cell*) malloc(sizeof(struct Cell));
    cell->data = data;
    return cell;
}

void insert_node(struct Cell *head, int data)
{
    struct Cell *t = Cell_init(data);
    t->next = head->next;
    head->next = t;
}

void delete_node(struct Cell *head, int data)
{
    if(head->next != NULL)
    {
        struct Cell *prev = head, *curr = head->next;
        while(curr != NULL)
        {
            if(curr->data == data)
            {
                prev->next = curr->next;
                free(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

void printList(struct Cell *head)
{
    struct Cell *t = head->next;
    while(t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

List List_init()
{
    List list = Cell_init(0);
    list->next = NULL;
    return list;
}

int main()
{
    List list;
    list = List_init();
    int n = 10;
    for(int i = 0; i < n; i++)
    {
        insert_node(list, rand() % n + 1);
    }
    printList(list);
    delete_node(list, rand() % n + 1);
    delete_node(list, rand() % n + 1);
    printList(list);
}
