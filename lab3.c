//Design, Develop and Implement a menu driven Program in C for the following operations on 
//STACK of Integers (Array Implementation of Stack with maximum size MAX)
//a. Push an Element on to Stack
//b. Pop an Element from Stack
//c. Demonstrate Overflow and Underflow situations on Stack
//d. Display the status of Stack
//e. Exit
#include<stdio.h>
#include<stdlib.h>
#define MAX 10


int stack[MAX], top=-1;

void push()
{
	int i, elem;
	if(top == MAX - 1){
		printf("STACK OVERFLOW!\n");
		return;
	}
	printf("\nEnter an element: ");
	scanf("%d", &elem);
	top++;
	stack[top] = elem;
}

void pop(){
	if(top == -1){
		printf("STACK UNDERFLOW!\n");
		return;
	}
	printf("element deleted is %d\n", stack[top]);
	top--;
}

void demo_over_under_flow(){
	int i, elem;
	printf("\n\n#### OVER FLOW CONDITION ####\n\n");
	printf("Currently stack contains %d elements and max size of stack is %d.\n So, Enter %d more elements to see STACK OVERFLOW error: ",top+1, MAX,MAX-top); 
	for(i = top;i<MAX; i++){
		push(elem);
	}
	
	printf("\n\n#### UNDER FLOW CONDITION ####\n\n");
	printf("stack containes %d elements,\n let's pop %d times to see STACK UNDERFLOW!\n", top+1, top+2);
	for(i=top+1; i>-1; i--){
		pop();
	}
}

void display_stack(){
	int i;
	if(top==-1){
		printf("\nno elements in the stack");
		return;
	}
	printf("\n\n---- Display STACK ----\n\n");
	printf("STACK contains %d elements, \n", top+1);
	printf("elements are: ");
	for(i=0; i<=top; i++){
		printf("%d  ", stack[i]);
	}
}

int main()
{
	 
	int op;
	while(1){
		printf("\n\nOptions: \n");
		printf("1. Push an Element on to Stack\n");
		printf("2. Pop an Element on to Stack\n");
		printf("3. Demonstrate Overflow and Underflow situations on Stack\n");
		printf("4. Display the status of Stack\n");
		printf("5. Exit\n");
		printf("Choose an option: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				
				push();
				break;
			case 2:
				pop();
				break;
				
			case 3:
				demo_over_under_flow();
				break;
			case 4:
				display_stack();
				break;
			case 5:
				printf("\nClosing the program...");
				exit(0);
			default:
				printf("\nInvalid option!\n");
				break;
		}
	}
 return 0;
}





