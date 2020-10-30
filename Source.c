#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M (256)

struct _person;
typedef struct _person* Position;

typedef struct _person {
	char firstName[M];
	char lastName[M];
	int year;
	Position next;
}Person;

Position createStudent(char* , char* , int);
void insertStart(Position,Position);
void printList(Position);
void insertEnd(Position ,Position);
Position Find(char*, Position);
void Delete(Position, Position);
Position findPrev(char*, Position);

int main(void)
{
	char c;
	Person head;
	Position p = NULL;
	char firstName[M] = { NULL };
	char lastName[M] = { NULL };
	int year = NULL;
	head.next = NULL;
	int i, n;
	
	printf("\nHow many students do you want to enter:\t");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nPlease insert person:\n");

		printf("First name:\t");
		scanf(" %s", firstName);

		printf("Last name:\t");
		scanf(" %s", lastName);

		printf("Birth year:\t");
		scanf(" %d", &year);

		p = createStudent(firstName, lastName, year);
		insertStart(&head, p);
		puts("\n");
		printList(&head);
	}

	while (1) {

		printf("\n\nMENU:\nChoose one option:\n\tB->insert new person at the beginning of the list\n");
		printf("\tA->insert new person at the end of the list\n\tF->find a person(by last name)\n\tD->delete a person\n");
		printf("\tE->if you are done with the selection\n\tOption:\t");
		scanf(" %c", &c);

		switch (c)
		{
		case 'b':
		case 'B':
			printf("\nPlease insert person:\n");

			printf("First name:\t");
			scanf(" %s", firstName);

			printf("Last name:\t");
			scanf(" %s", lastName);

			printf("Birth year:\t");
			scanf(" %d", &year);

			p = createStudent(firstName, lastName, year);
			insertStart(&head, p);
			puts("\n");
			printList(&head);
			break;
		case 'a':
		case 'A':
			printf("\nPlease insert person:\n");

			printf("First name:\t");
			scanf(" %s", firstName);

			printf("Last name:\t");
			scanf(" %s", lastName);

			printf("Birth year:\t");
			scanf(" %d", &year);

			p = createStudent(firstName, lastName, year);
			insertEnd(&head, p);
			puts("\n");
			printList(&head);
			break;
		case 'f':
		case 'F':
			printf("\nPlease insert person last name:");
			scanf(" %s", lastName);
			puts("\n");
			p = Find(lastName, &head);
			if (p != NULL)
				printf("\t\nFound: %s %s %d\n", p->firstName, p->lastName, p->year);
			else
				printf("Last name not found in linked list!");
			printList(&head);
			break;
		case 'd':
		case 'D':
			printf("\nPlease insert person last name:");
			scanf(" %s", lastName);
			puts("\n");
			Delete(lastName, &head);
			printList(&head);
			break;
		case 'E':
		case 'e':
			printList(&head);
			return EXIT_SUCCESS;
			break;
		default:
			puts("Input error!!");
		}
	}
	return 0;
}

	

Position createStudent(char* firstName, char* lastName, int year) {
	Position p = NULL;

	p = (Position)malloc(sizeof(Person));

	if (!p) {
		printf("Memory allocation failed!\r\n");
		return NULL;
	}

	strcpy(p->firstName, firstName);
	strcpy(p->lastName, lastName);
	p->year = year;
	p->next = NULL;

	return p;

}

void insertEnd(Position head,Position p) {
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = p;
	p->next = NULL;
}


void insertStart(Position head, Position p) {
	p->next = head->next;
	head->next = p;
}

Position Find(char* lastName, Position head) {
	Position p=NULL;
	p = head->next;
	int L=0;

	while(p != NULL){
		if (strcmp(p->lastName, lastName) == 0) {
			L = 1;
			break;
		}
		else
			L = 0;
		p = p->next;
	}
	if (L == 1)
		return p;
	else
		return NULL;
}


Position findPrev(char *lastName, Position P) {
	Position prev = P;
	P = P->next;

	while (P != NULL && strcmp(P->lastName,lastName)!=0) {
		prev = P;
		P = P->next;
	}
	if (P == NULL)
		return NULL;
	else
		return prev;
}



void Delete(char* lastName, Position P) {
	Position prev;
	prev = findPrev(lastName, P);

	if (prev != NULL)
	{
		P = prev->next;
		prev->next = P->next;
		free(P);
	}
	else
		printf("Last name not found in linked list!");
}

void printList(Position head) {
	Position p = NULL;
	printf("\nlist content:\n");
	if (head->next == NULL)
		printf("Linked list is empty!");
	for (p = head->next; p != NULL; p = p->next)
		printf("\t%s %s %d\n", p->firstName, p->lastName, p->year);
	
	printf("\n");

}