#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	struct queue	*next;
	int				value;
}					myQueue;

typedef struct stack {

   	struct queue	*stack1;
    struct queue	*stack2;

}                   MyStack;

// creates an instance of the stack
MyStack* myStackCreate() {
    MyStack *new = malloc(sizeof(MyStack));
	if (!new)
        return NULL;
	new->stack1 = NULL;
	new->stack2 = NULL;
    return new;
}

void	addElement(myQueue **new, myQueue  **old, int x) {
	myQueue *node = malloc(sizeof(myQueue));
	if (!node)
        return ;
	node->value = x;
	node->next = *old;
	*old = NULL;
	*new = node;
}

// pushes element x to the top of the stack
void	myStackPush(MyStack* obj, int x) {
	if (obj->stack1 == NULL)
		addElement(&obj->stack1, &obj->stack2, x);
	else
		addElement(&obj->stack2, &obj->stack1, x);
}

int	removeElement(myQueue **new, myQueue **old) {
	int	result = (*old)->value;
	*new = (*old)->next;
	free(*old);
	*old = NULL;
	return (result);
}

// removes the element at the top of the stack and returns it
int myStackPop(MyStack* obj) {
	if (obj->stack1 == NULL && obj->stack2 == NULL)
		return (0);
	if (obj->stack1 == NULL)
		return (removeElement(&obj->stack1, &obj->stack2));
	else
		return (removeElement(&obj->stack2, &obj->stack1));
}

// // return the element at the top of the stack
int myStackTop(MyStack* obj) {
    if (obj->stack1 == NULL) {
		if (obj->stack2 == NULL)
			return 0;
		return (obj->stack2->value);
	}
	return (obj->stack1->value);
}

// checks if the stack is empty
bool myStackEmpty(MyStack* obj) {
    if (obj == NULL)
		return (true);
	if (obj->stack1 == NULL && obj->stack2 == NULL)
		return (true);
	return (false);
}

void	freeList(myQueue *stack) {
	if (stack == NULL)
		return ;
	freeList(stack->next);
	free(stack);
}

// frees the stack
void myStackFree(MyStack* obj) {
    freeList(obj->stack1);
    freeList(obj->stack2);
	if (obj)
		free(obj);
}

int main() {
	MyStack* obj = myStackCreate();
	myStackPush(obj, 2);
 
	int param_2 = myStackPop(obj);
	int param_3 = myStackTop(obj);
	bool param_4 = myStackEmpty(obj);
	printf("%i, %i, %i\n", param_2, param_3, param_4);
	myStackFree(obj);
	return 0;
}