/*
 * File: application.c
 * Author: MOAAZ
 *
 * Created on December 1, 2023, 10:21 PM
 */
#include "application.h"
volatile uint8 tmr1_counter = 0;
void app_initialize(void);
void key_value();
uint8 f_operation_resul_for_mult_div(void);
extern keypad_t keypad_1;
extern chr_lcd_4bit_t lcd_2;
Std_ReturnType ret = E_NOT_OK;
stack_t stack_numbers;
stack_t stack_operation;
uint8 value = 0;
uint8 tp;
uint8 lcd_counter = 1;
uint8 result = 10;
int main() {
    app_initialize();
    while (1) {
        //for get value and push in stack
        while (!value) {
            keypad_get_value(&keypad_1, &value);
            
        }
        push(&stack_numbers, value);
       
        value = 0;
        tp = peek(&stack_numbers);
        ret |= lcd_4bit_send_data_char_posit(&lcd_2, 1, lcd_counter, tp);
         __delay_ms(150);
        lcd_counter++;
        if (tp == 'c') {
            fully_poped(&stack_numbers);
            lcd_4bit_send_command(&lcd_2, LCD_CLEAR_DISPLAY);
            lcd_counter = 1;
        }else {
        
        }
        //for display result 
        if (tp == '=' ) {
            result = f_operation_resul_for_mult_div();
            ret |= lcd_4bit_send_data_char_posit(&lcd_2, 1, lcd_counter,result );
            //nothing  
        }else {
        
        }
    }

    return (EXIT_SUCCESS);
}

void app_initialize(void) {
    Std_ReturnType ret = E_NOT_OK;
    ret = keypad_initialize(&keypad_1);
    ret |= lcd_4bit_initialize(&lcd_2);

}

uint8 f_operation_resul_for_mult_div(void) {

    uint32 result = 0;
    
    uint8 loop_counter = stack_size(&stack_numbers);
   // uint8 num_value[loop_counter];
    uint8 operation = 0;
 pop(&stack_numbers);
    while (loop_counter--) {
        
        operation = pop(&stack_numbers);
        switch (operation) {
            case '*':
             //   result += (uint32) (stack_numbers.stack_data[operation - 1] * stack_numbers.stack_data[operation + 1]);
                stack_numbers.stack_data[operation - 1] = 0;
                stack_numbers.stack_data[operation] = '+';
                stack_numbers.stack_data[operation + 1] = (uint32) (stack_numbers.stack_data[operation - 1] * stack_numbers.stack_data[operation + 1]);
                break;
            case '/':
               // result += (uint32) (stack_numbers.stack_data[operation - 1] / stack_numbers.stack_data[operation + 1]);
                stack_numbers.stack_data[operation - 1] = 0;
                stack_numbers.stack_data[operation] = '+';
                stack_numbers.stack_data[operation + 1] = (uint32) (stack_numbers.stack_data[operation - 1] / stack_numbers.stack_data[operation + 1]);

                break;
            default :   //nothing
                break;



        }


    }
     loop_counter = stack_size(&stack_numbers);
     operation = 0;
    
    while (loop_counter--) {
        operation = stack_numbers.stack_data[stack_size(&stack_numbers) - loop_counter ];
        switch (operation) {
            case '+':
                result += (uint32) (stack_numbers.stack_data[operation - 1] + stack_numbers.stack_data[operation + 1]);
                break;
            case '-':
                result += (uint32) (stack_numbers.stack_data[operation - 1] - stack_numbers.stack_data[operation + 1]);
                
                break;
            default :   //nothing
                break;



        }


    }

     return result;

}
