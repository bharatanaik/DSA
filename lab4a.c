//4. a) Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^
//A suffix expression, also known as a postfix expression, is a way of writing mathematical expressions where the operators come after the operands.
//To evaluate a suffix expression with single digit operands and the operators +, -, *, /, %, and ^, you can use a stack data structure.
//
//- Start from the leftmost character in the expression
//- If the character is a digit, push it to the stack
//- If the character is an operator, pop the top two elements from the stack, apply the operator to them, and push the result back to the stack
//- Repeat steps 2 and 3 until the end of the expression is reached
//- The final value left in the stack is the result of the expression
// For example, the expression "23*5+" would be evaluated as follows:
//
//- Push 2 to the stack
//- Push 3 to the stack
//- Pop 3 and 2, multiply them, push the result (6) back to the stack
//- Push 5 to the stack
//- Pop 5 and 6, add them, push the result (11) back to the stack
//- The final value in the stack is 11, which is the result of the expression.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 30

int stack[MAX], top=-1;

void push(int elem){
	stack[++top]=elem;
}

int pop(){
	return stack[top--];
}

int compute(char op, int a, int b){
	switch(op){
		case '+':return a + b;
		case '-':return a - b;
		case '*':return a * b;
		case '/':return a / b;
		case '^':return pow(a, b);
		default:return 0;
	}
}


int main()
{
	int i=0, num, op1, op2, res;
	char exp[20], sym;
	printf("Enter a suffix expression: ");
	gets(exp);
	
	// integer 0-9 lies between ascii values of 48 & 57 '0' = 48 and '9' = 57
	while(exp[i]!='\0'){
		sym = exp[i];
		if(isdigit(sym)){
			num = exp[i]-'0';
			push(num);
			continue;
		}
		op2 = pop();
		op1 = pop();
		res = compute(sym, op1, op2);
		push(res);
		i++;
	}
	printf("Result: %d", res);
 	return 0;
}


