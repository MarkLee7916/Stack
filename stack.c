#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isEmpty(const Stack* s)
{
    return size(s) == 0;
}

// Dynamically creates a new Stack. Returns NULL if malloc() call fails
Stack* new_stack(void)
{
	Stack* stack = (Stack*) malloc(sizeof(Stack));

	if (stack == NULL) {
        	fprintf(stderr, "\nError: Call to malloc() failed");
        	return NULL;
	}

	stack->index = -1;
	stack->max_size = 8;
        stack->array = (int*) malloc(stack->max_size * sizeof(int));

        if (stack->array == NULL) {
        	fprintf(stderr, "\nError: Call to malloc() failed");
        	return NULL;
        }

        return stack;
}

// Resets the stack back to an empty stack
void clear(Stack* stack)
{
    stack->index = -1;
}

// Frees allocated memory and nulls out the heap pointers
void destroy_stack(Stack* stack)
{
    free(stack->array);
    free(stack);
    stack = NULL;
}

// Pushes element on top of Stack. If it doesn't fit in the array, allocates a new array and moves contents into it
int push(Stack* stack, int elem)
{
    int* buffer;

    if (stack->index == stack->max_size - 1) {
        stack->max_size *= 2;
        buffer = realloc(stack->array, stack->max_size * sizeof(int));

        if (buffer == NULL) {
            fprintf(stderr, "\nError: Call to realloc() failed. Element not pushed");
            return 0;
        }
        else {
            stack->array = buffer;
        }
    }

    	stack->index++;
	stack->array[stack->index] = elem;
	return 1;
}

// Returns the number of elements stored in the Stack
int size(const Stack* stack)
{
    return stack->index + 1;
}

// Retrieves and removes most recent element added to Stack. Variable success set to 1 if operation succeeds, 0 if it fails
int pop(Stack* stack, int* success)
{
    if (stack->index == -1) {
        *success = 0;
        fprintf(stderr, "\nError: tried to pop from empty stack");
        return NULL;
    }

    int return_val = stack->array[stack->index];
    stack->index--;

    *success = 1;
    return return_val;
}

// Retrieves most recent element added to Stack, but doesn't remove it. Variable success set to 1 if operation succeeds, 0 if it fails
int peek(const Stack* stack, int* success)
{
    if (stack->index == -1) {
        *success = 0;
        fprintf(stderr, "\nError: tried to peek at empty stack");
        return NULL;
    }

    *success = 1;
    return stack->array[stack->index];
}
