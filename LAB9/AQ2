#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int coefficient, int exponent) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->coefficient =coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(Node **head, int coefficient, int exponent) {
    Node *newNode = createNode(coefficient, exponent);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        Node *last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

Node *addPolynomials(Node *poly1, Node *poly2) {
    if (poly1 == NULL) return poly2;
    if (poly2 == NULL) return poly1;

    Node *result = NULL;
    Node *temp1 = poly1, *temp2 = poly2;

    do {
        if (temp1->exponent > temp2->exponent) {
            insertEnd(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            insertEnd(&result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            int sum = temp1->coefficient + temp2->coefficient;
            if (sum != 0) {
                insertEnd(&result, sum, temp1->exponent);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    } while (temp1 != poly1 || temp2 != poly2);

    return result;
}

void displayPolynomial(Node *head) {
    if (head == NULL) {
        printf("Empty polynomial.\n");
        return;
    }

    Node *temp = head;
    do {
        printf("(%dx^%d) ", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != head) {
            printf("+ ");
        }
    } while (temp != head);
    printf("\n");
}

void insert(Node** poly, int coef, int exp) {
 Node* temp = (Node*) malloc(sizeof(Node));
 temp->coefficient = coef;
 temp->exponent = exp;
 temp->next = NULL;

 if (*poly == NULL) { *poly = temp; return; }

 Node* current = *poly;

 while (current->next != NULL) current = current->next;

 current->next = temp;
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL;

    insertEnd(&poly1, 5, 3);  // 5x^3
    insertEnd(&poly1, 4, 1);  // 4x^1
    insertEnd(&poly1, 3, 0);  // 3x^0

    insertEnd(&poly2, 3, 2);  // 3x^2
    insertEnd(&poly2, 2, 1);  // 2x^1
    insertEnd(&poly2, 1, 0);  // 1x^0

    printf("First polynomial: ");
    displayPolynomial(poly1);

    printf("Second polynomial: ");
    displayPolynomial(poly2);

    Node *sum = addPolynomials(poly1, poly2);

    printf("Sum of the polynomials: ");
    displayPolynomial(sum);



    return 0;
}
