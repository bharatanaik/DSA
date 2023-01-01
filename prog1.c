//Design, Develop and Implement a menu driven Program in C for the following Array Operations
//
//Creating an Array of N Integer Elements
//Display of Array Elements with Suitable Headings
//Exit.

#include<stdio.h>
#include<stdlib.h>

int *array, flag = 0;

int create_array(){
	int n, i;
	printf("\n\n---- Create Array ----\n");
	printf("enter the size of the array: ");
	scanf("%d", &n);
	array = (int *)malloc(n*sizeof(int));
	printf("\nEnter array elements: ");
	for(i=0; i<n; i++)
		scanf("%d", &array[i]);
	flag++;
	return n;
}

void display_array(int n){
	int i;
	if(flag==0){
		printf("\nArray is empty!");
		return;
	}
	printf("\n\n---- Display Array ----\n");
	printf("elements are: ");
	for(i=0; i<n; i++){
		printf("%d  ", array[i]);
	}
}

int main(){
	int n, op;
	while(1){
		printf("\nOptions: ");
		printf("\n1. Create Array");
		printf("\n2. Display Array");
		printf("\n3. Exit");
		printf("\nChoose option: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				n = create_array();
				break;
				
			case 2:
				display_array(n);
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
