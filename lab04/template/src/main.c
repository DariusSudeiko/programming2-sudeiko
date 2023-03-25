#include <stdio.h>
#include <math.h>
//
// mini-project - Calculator
//
// Please complete the code development and fix the issues if face with them
//
// Using callback create calculator
// operations
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

typedef int (*op)(int, int);
// get symbol from standard input
char input_opcode();
// input 2 integer numbers
void input_numbers(int *, int *); // we have to change something here
// print result
void print(int); // change this
void menu(op *);

int main(int argc, char const *argv[])
{
    // 1. Define operations array
    op operations[4] = {add, sub, mul, div};
	// 2. Call menu function with operations array
    menu(operations); // new change
    return 0;
}

void menu(op *operations)
{

    int result = 0;
    int a;
    int b;
    while (1)
    {
        char opcode = input_opcode();
        input_numbers(&a, &b); 
        switch (opcode) 
        {
        case '+':
            result = operations[0](a,b);
            break;
        case '-':
            result = operations[1](a,b);
            break;
        case '*':
            result = operations[2](a,b);
            break;
        case '/':
            result = operations[3](a,b);
            break;
        default:
            printf("Error! operator is not correct \n");
            return;
        }
        print(result);
        return;
    }
}

void print(int a){

    printf("the result is %d \n", a);
}
char input_opcode()
{
    char c;
    printf("Enter opcode: ");
    scanf(" %c", &c);
    return c;
}
void input_numbers(int *a, int *b){
	printf("enter first number  ");
	scanf("%d", a); // we use x instead of &x because we need the adress of the number not the value
	printf("enter second number ");
	scanf("%d", b); // we use y instead of &y because we need the adress of the number not the value
};

int add(int a, int b){
    return a + b;
};
int sub(int a, int b){
    return a - b;
};
int mul(int a, int b){
    return a * b;
};
int div(int a, int b){
    return a / b;
};