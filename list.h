#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct list_node
{
    int value;
    struct list_node* next;
    struct list_node* prev;
}list_node;

typedef struct list
{
    list_node* header;
    int size;
}list_header;

list_header* new_list();
list_node* new_list_node(int n);
int list_is_null(list_header *list);
int list_add(list_header *list, int n);
int list_remove(list_header* list, int n);
int list_find(list_header* list, int n);

#endif // LIST_H_INCLUDED