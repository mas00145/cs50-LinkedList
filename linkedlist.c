#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "node.h"



// function prototypes
node * addNodeToStart(node *head, int data);

node * addNodeAtEnd(node *head, int data);

void printNode(node *head);

void destroyList(node *head);
void destroyRecursive(node *head); // recursive version

bool isElementInList(node *head, int data);

void deleteElement(node **head, int data); // send in a pointer to the pointer to head of list, so we can change it in the function



int main(int argc, char *argv[])
{
    node *numbers = NULL;


    // create test linkedlist
    numbers = addNodeAtEnd(numbers, 2);
    numbers = addNodeAtEnd(numbers, 4);
    numbers = addNodeAtEnd(numbers, 6);
    numbers = addNodeAtEnd(numbers, 8);

    numbers = addNodeToStart(numbers, 22);



    deleteElement(&numbers, 4);


    printNode(numbers);
    //destroyList(numbers);
    destroyRecursive(numbers);


}


// Add a node to the start of the list
node * addNodeToStart(node *head, int data)
{
    node *n = malloc(sizeof(node));
    if(!n)
    {
        printf("Not enough memory\n");
        exit(1);
    }
    n->number = data;
    n->next = head;

    return n;
}


// add a node to the end of a list
node * addNodeAtEnd(node *head, int data)
{

    node *n = malloc(sizeof(node));
    if(!n)
    {
        printf("Not enough memory!\n");
        exit(1);
    }

    n->number = data;
    n->next = NULL;

    if (head)
    {
        for (node *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if (!ptr->next)
            {
                ptr->next = n;
                return head;
            }
        }
    }
    else
    {
        head = n;

    }
    return head;

}


// print all list data elements
void printNode(node *head)
{
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
}


// find a single element in the list
bool isElementInList(node *head, int data)
{
    if (head)
    {
        for (node *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->number == data)
            {
                return true;
            }
        }

    }

    return false;
}

// delete list element
void deleteElement(node **head, int data)
{
    node *currP;
    node *prevP;

    // for the first node there is no previous
    prevP = NULL;

  if(*head)
  {
      for (currP = *head; currP != NULL; prevP = currP, currP = currP->next)
      {
            if (currP->number == data) // found the value
            {
                if (prevP == NULL)
                {
                    *head = currP->next;
                }
                else
                {
                    prevP->next = currP->next;
                }
                free(currP);
                return; // done so return to calling function

            }
      }
  }

}


// free each node in the list
void destroyList(node *head)
{
    node *current = head;
    node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

}

void destroyRecursive(node *head)
{
    if (!head)
    {
       return;

    }

    destroyRecursive(head->next);
    free(head);
}
