#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct Node {
    int coeff;
    int power;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* insertTerm(Node* head, int coeff, int power) {
    Node* temp = createNode(coeff, power);
    if (head == NULL) {
        head = temp;
        head->next = head;
        head->prev = head;
    } else {
        Node* last = head->prev;
        temp->next = head;
        temp->prev = last;
        last->next = temp;
        head->prev = temp;
    }
    return head;
}

void displayPolynomial(Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%dx^%d ", temp->coeff, temp->power);
        temp = temp->next;
        if (temp != head) {
            printf("+ ");
        }
    } while (temp != head);
    printf("\n");
}

Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    if (poly1 == NULL || poly2 == NULL) {
        printf("One of the polynomials is empty\n");
        return NULL;
    }

    Node* result = NULL;
    Node* temp1 = poly1;

    do {
        Node* temp2 = poly2;
        do {
            int coeff = temp1->coeff * temp2->coeff;
            int power = temp1->power + temp2->power;
            result = insertTerm(result, coeff, power);
            temp2 = temp2->next;
        } while (temp2 != poly2);
        temp1 = temp1->next;
    } while (temp1 != poly1);

    Node* current = result;
    do {
        Node* next = current->next;
        while (next != result) {
            if (current->power == next->power) {
                current->coeff += next->coeff;
                Node* temp = next;
                next->prev->next = next->next;
                next->next->prev = next->prev;
                next = next->next;
                free(temp);
            } else {
                next = next->next;
            }
        }
        current = current->next;
    } while (current != result);

    return result;
}


int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    // Example: Polynomial 1: 5x^2 + 2x + 10, Polynomial 2: 2x^1 + 4
    poly1 = insertTerm(poly1, 5, 2);
    poly1 = insertTerm(poly1, 2, 1);
    poly1 = insertTerm(poly1, 10, 0);

    poly2 = insertTerm(poly2, 2, 1);
    poly2 = insertTerm(poly2, 4, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = multiplyPolynomials(poly1, poly2);

    printf("Result of Multiplication: ");
    displayPolynomial(result);

    return 0;
}
