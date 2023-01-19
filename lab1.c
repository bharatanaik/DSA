//1. Design, Develop and Implement a menu driven Program in C for the following Array Operations
//    - Creating an Array of N Integer Elements
//    -  Display of Array Elements with Suitable Headings
//    -  Exit.
//
//    Support the program with functions for each of the above operations.

#include<stdio.h>
#include<stdlib.h>

int create_array(int array[]){
	int i, n;
	printf("\n\n---- Create Array ----\n");
	printf("enter the size of the array: ");
	scanf("%d", &n);
	printf("\nEnter array elements: ");
	for(i=0; i<n; i++)
		scanf("%d", &array[i]);
	return n;
}

void display_array(int array[], int n){
	int i;
	printf("\n\n---- Display Array ----\n");
	printf("elements are: ");
	for(i=0; i<n; i++){
		printf("%d  ", array[i]);
	}
}

int main()
{
	int array[10], n,op, flag=0;
	
	while(1){
		printf("\n\nOptions: ");
		printf("\n1. Create Array");
		printf("\n2. Display Array");
		printf("\n3. Exit");
		printf("\nChoose option: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				n = create_array(array);
				flag++;
				break;
			case 2:
				if(flag!=0)
					display_array(array, n);
				else
					printf("Array not created yet!");
				break;
			case 3:
				printf("\nClosing the program....");
				exit(0);
				
			default:
				printf("Invalid option!");
				
		}
	}

 return 0;
}


