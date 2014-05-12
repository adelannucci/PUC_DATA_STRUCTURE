#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct stack_node
{
    int value;
    struct stack_node* next;
}stack_node;


typedef struct stack_header
{
    unsigned long size;
    stack_node* top;
}stack_header;

stack_header* new_stack();
stack_node* new_stack_node(int n);
int stack_is_null(stack_header *stack);
int push(stack_header* stack, int n);
int pop(stack_header* stack);
int peek(stack_header* stack);

#endif // STACK_H_INCLUDED
