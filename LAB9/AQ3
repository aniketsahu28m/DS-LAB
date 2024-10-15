#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cnode *cnptr;
typedef struct cnode
{
    int data;
    char name[100];
    cnptr next;
    cnptr prev;
} cnode;

cnptr last = NULL;

cnptr createCnode(int val)
{
    cnptr temp = (cnptr)malloc(sizeof(cnode));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insertBegin(int val, char nam[])
{
    cnptr temp = createCnode(val);
    strcpy(temp->name, nam);
    if (last == NULL)
    {
        last = temp;
        last->next = last;
        last->prev = last;
    }
    else
    {
        temp->next = last->next; // head
        last->next->prev = temp;
        temp->prev = last;
        last->next = temp;
    }
}

void deleteend()
{
    if (last == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Next person is %s for %d mins\n", last->name, last->data);
        cnptr previous = last->prev;
        previous->next = last->next;
        last->next->prev = previous;
        free(last);
        last = previous;

        if (last->next == last) // If the list becomes empty
            last = NULL;
    }
}

void traverse()
{
    if (last == NULL) {
        printf("Queue is empty\n");
        return;
    }

    cnptr current = last->next;
    do {
        printf("%s (%d mins) ", current->name, current->data); // Print name AND time
        current = current->next;
    } while (current != last->next);

    printf("\n");
}

int main()
{
    char contin = 'y';
    int choice;
    while (contin == 'y')
    {
        printf("What do you want to do? \n 1. Add person to queue \n 2. Pass the chance to next person \n 3. View the Queue\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            {
                int val;
                printf("Enter the name:\n");
                fflush(stdin);
                char name[100];
                gets(name);
                printf("Enter the time in minutes: \n");
                scanf("%d", &val);
                insertBegin(val, name);
                break;
            }
        case 2:
            {
                deleteend();
                break;
            }
        case 3:
            {
                printf("People in the Queue are\n");
                traverse();
                break;
            }
        }
        printf("continue? (y/n)\n");
        fflush(stdin);
        scanf(" %c", &contin);
    }

    return 0;
}
