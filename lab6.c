#include <stdio.h>
#include <stdlib.h>

struct node
{
	int id;
	char name[20], branch[10], specialization[20];
	struct node *rlink, *llink;
};

typedef struct node *NODE;

NODE push(NODE first)
{
	NODE temp = (NODE)malloc(sizeof(struct node));
	printf("\nEnter profesor's data\n");
	printf("id: ");
	scanf("%d", &temp->id);
	printf("name: ");
	scanf("%s", temp->name);
	printf("branch: ");
	scanf("%s", temp->branch);
	printf("area of specialization: ");
	scanf("%s", temp->specialization);
	if (first == NULL)
	{
		temp->llink = NULL;
		temp->rlink = NULL;
		return temp;
	}
	first->llink = temp;
	temp->rlink = first;
	return temp;
}

NODE pop(NODE first)
{
	NODE temp;
	if (first == NULL)
	{
		printf("\nList is empty. Cannot Delete");
		return first;
	}
	temp = first;
	temp = temp->rlink;
	printf("\nItem deleted = %d", first->id);
	free(first);
	return temp;
}

void display(NODE first)
{
	NODE cur;
	cur = first;
	if (first == NULL)
	{
		printf("\nList is empty");
		return NULL;
	}
	printf("\nPROFESSOR'S LIST");
	printf("\nid\tname\tbranch\tspecialization\n");
	while (cur != NULL)
	{
		printf("%d\t%s\t%s\t%s\n", cur->id, cur->name, cur->branch, cur->specialization);
		cur = cur->rlink;
	}
}

void count(NODE first)
{
	int count = 0;
	NODE temp;
	temp = first;
	while (temp != NULL)
	{
		count++;
		temp = temp->rlink;
	}
	printf("number of node is %d", count);
}

NODE insert(NODE front)
{
	NODE temp, cur;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter profesor's data\n");
	printf("id: ");
	scanf("%d", &temp->id);
	printf("name: ");
	scanf("%s", temp->name);
	printf("branch: ");
	scanf("%s", temp->branch);
	printf("area of specialization: ");
	scanf("%s", temp->specialization);
	if (front == NULL)
	{
		temp->llink = NULL;
		temp->rlink = NULL;
		return temp;
	}
	cur = front;
	while (cur->rlink != NULL)
	{
		cur = cur->rlink;
	}
	cur->rlink = temp;
	temp->rlink = NULL;
	return front;
}

NODE delete(NODE front)
{
	NODE temp;
	if (front == NULL)
	{
		printf("\nList is empty. Cannot Delete");
		return front;
	}
	temp = front;
	temp = temp->rlink;
	printf("\nItem deleted = %d", front->id);
	free(front);
	return temp;
}


int main(int argc, char const *argv[])
{
	int op;
	NODE first = (NODE)malloc(sizeof(struct node));
	NODE front = (NODE)malloc(sizeof(struct node));
	first = front = NULL;
	while (1)
	{
		printf("\n\nOptions");
		printf("\n# STACK OF PROFESSOR'S DATA");
		printf("\n1. push");
		printf("\n2. pop");
		printf("\n3. display stack");
		printf("\n4. count stack");

		printf("\n\n# QUEUE OF PROFESSOR'S DATA");
		printf("\n5. insert");
		printf("\n6. delete");
		printf("\n7. display queue");
		printf("\n8. count queue");

		printf("\n9. Exit");
		printf("\nEnter choice: ");
		scanf("%d", &op);

		switch (op)
		{
		case 1: first = push(first);
			break;
		case 2: first = pop(first);
			break;
		case 3: display(first);
			break;
		case 4: count(first);
			break;
		case 5: front = insert(front);
			break;
		case 6: front = delete(front);
			break;
		case 7: display(front);
			break;
		case 8: count(front);
			break;
		case 9: exit(0);
			break;
		default: printf("\nInvalid option");
			break;
		}
	}
	return 0;
}
