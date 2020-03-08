typedef struct stack {
	int index;
	int max_size;
	int* array;
} Stack;

Stack* new_stack();
int push(Stack* stack, int elem);
int pop(Stack* stack, int* success);
void destroy_stack(Stack* stack);
int size(const Stack* stack);
int peek(const Stack* stack, int* success);
void clear(Stack* stack);
int isEmpty(const Stack* stack);

