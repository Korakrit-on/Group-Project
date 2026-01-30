#include<stdio.h>
#include <stdlib.h>

int main() {
    float a, b, result ;
    char op ;
    printf("Enter numbers and an operator (+, -, *, /, %%): ") ;
    scanf("%f %c %f", &a, &op, &b) ;
    
    switch (op) {
        case '+' :
            result = a + b ;
            break ;
        case '-' :
            result = a - b ;
            break ;
        case '*' :
            result = a * b ;
            break ; 
        case '/' :
            result = a / b;
            break ;
        case '%':
            result = a%b ;
            break ;
        default :
            printf("Error! Invalid operator.\n");
            return 1 ;
    }

    printf("Result = %f\n", result) ;
    return 0 ;
}