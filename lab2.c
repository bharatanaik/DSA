//2. Design, Develop and Implement a menu driven Program in C for the following Array operations 
//a. Inserting an Element (ELEM) at a given valid Position (POS)
//b. Deleting an Element at a given valid Position POS)
//c. Display of Array Elements
//d. Exit.
//Support the program with functions for each of the above operations

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

// 0, 1, 2, 4 <= insert(3 at 3rd pos)
// 0, 1, 2, 3, 4 <= index of 4 also changes
// begin a for loop from last (i--) and shift one by one until the condition is i == pos
int insert_elem(int array[], int n, int elem, int pos)
{
	int i;
	if(pos>n)
		n = pos;
	for(i = n; i>pos; i--)
		array[i] = array[i-1]; 
	array[pos] = elem;
	return n;
}

//0, 1, 2, 3, 4 <= delete 2 from list , POS = 2
//0, 1, 3, 4 <= index of 3 & 4 shifts to left
// So we have to develop a for loop which shifts all digits to left till i = n - 1 
int delete_elem(int array[], int n, int pos)
{
	int i, ptr;
	if(pos>n)
		return n;
	for(i=pos; i<n; i++)
		array[i] = array[i+1];
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
	int i, op, n, array[MAX_SIZE], elem, pos;
	printf("---- CREATE ARRAY ----");
	printf("\nEnter number of elements: ");
	scanf("%d", &n);
	printf("\nEnter elements: ");
	for(i=0; i<n; i++)
		scanf("%d", &array[i]);
	while(1)
	{
		printf("\nOptions: ");
		printf("\n1. Insert an element");
		printf("\n2. Delete an element");
		printf("\n3. Display of array element");
		printf("\n4. Exit");		
		printf("\nChoose option: ");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				printf("\nEnter element to insert: ");
				scanf("%d",&elem);
				printf( "\nEnter position to insert: ");
				scanf("%d", &pos);
				n = insert_elem(array, n, elem, pos);
				break;
			case 2:
				printf("\n\nEnter position to delete: ");
				scanf("%d", &pos);
				n = delete_elem(array, n, pos);
				break;
			case 3:
				display_array(array, n);
				break;
			case 4:
				printf("\nClosing the program....");
				exit(0);
			default:
				printf("Invalid option!");
		}
	}
	return 0;
}

