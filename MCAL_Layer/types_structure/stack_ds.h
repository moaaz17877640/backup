/* 
 * File:   stack_ds.h
 * Author: MOAAZ
 *
 * Created on May 24, 2024, 6:16 PM
 */

#ifndef STACK_DS_H
#define	STACK_DS_H

#include "../Std_Libraries.h"
#include "../Mcal_Std_Types.h"
typedef struct{
    uint8 stack_top;
    uint8 stack_capacity;
    uint8 *stack_data;
}stack_t;

void create_stack(stack_t *stack );
// Stack is full when top is equal to the last index
uint8 isFull(const stack_t* stack);

// Stack is empty when top is equal to -1
uint8 isEmpty(const stack_t* stack);
// Function to add an item to stack.  It increases top by 1
void push(stack_t* stack, uint8 item);

// Function to remove an item from stack.  It decreases top by 1
uint8 pop(stack_t* stack);

// Function to return the top from stack without removing it
uint8 peek(const stack_t* stack);
// function to fully clear all elements from stack 
void fully_poped(stack_t* stack);
// function to return the size of stack ..
uint8 stack_size(stack_t* stack);
#endif	/* STACK_DS_H */

