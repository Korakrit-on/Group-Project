#include<stdio.h>
#include <stdlib.h>



double AddOperate(double a , double b , char operate) {
    switch (operate)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;   
    }
    return 0; 

}
int main() {
    
}