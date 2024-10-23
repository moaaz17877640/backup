#include "stack_ds.h"

void create_stack(stack_t *stack){
    //stack =(stack_t *)malloc(sizeof(stack_t)) ;
    //stack->stack_capacity = size; 
    stack->stack_top = -1 ;
   // stack->stack_data = (uint8 *)malloc(stack->stack_capacity * sizeof(uint8));
    return ;
}

// Stack is full when top is equal to the last index
uint8 isFull(const stack_t* stack){
    if(stack->stack_top ==stack->stack_capacity -1 ){
        return  1 ; 
    }
    else {
        return 0; 
    }
}
// Stack is empty when top is equal to -1
uint8 isEmpty(const stack_t* stack){
 if(stack->stack_top == -1 ){
        return 1 ;
    }
    else {
        return 0;
    }
}
// Function to add an item to stack.  It increases top by 1
void push(stack_t* stack, uint8 item){
    if (isFull(stack)){
        return;
    }else{
stack->stack_data[++(stack->stack_top)]= item ;
    }
}

// Function to remove an item from stack.  It decreases top by 1
uint8 pop(stack_t* stack){
    if (isEmpty(stack)){
        return -1;
    }
    else{
return stack->stack_data[stack->stack_top --];
    }
}

// Function to return the top from stack without removing it
uint8 peek(const stack_t* stack){
if (isEmpty(stack)){
        return -1;
}else{
return stack->stack_data[stack->stack_top];
}
}
void fully_poped(stack_t* stack){
    uint8 stack_size = stack->stack_top ;
    while(stack_size--){
    pop(stack);
    
    }
    return;
}
uint8 stack_size(stack_t* stack){
    return (stack->stack_top)+1 ; 
}