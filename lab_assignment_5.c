#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int length = 0;
	node* tmp = head;
	while(tmp != NULL){
		length++;  		// adds to length
		tmp = tmp->next; // sets tmp = to next one to continue count
	}
	return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	// calculate and return a string
	int size = length(head);	
	char* string = (char*)malloc(sizeof(char) * (size + 1));  // size + 1 to fit end of string
	if(string == NULL){
		return NULL;    // worst case
	}

	node* current = head;
	int i = 0;  // count for every letter
	while(current != NULL){
		string[i++] = current->letter;
		current = current->next;
	}
	string[i] = '\0';// add \0 to last index of the string
	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c){

	node* newNode = malloc(sizeof(node));
	newNode->letter = c;
	newNode->next = NULL;

// produces is forwards
	if(*pHead == NULL){ 
		// whenever list is empty, the new node is the head
		*pHead = newNode;
	} else {
		// finds the last node and appends the new node
		node* lastNode = *pHead;
		while(lastNode->next != NULL){
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
/* 
	string prints backwards!? 
	newNode->next = *pHead ;
	*pHead = newNode;
	*/
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* current = *pHead;
	node* next;
	if(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	*pHead = NULL;
	
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}