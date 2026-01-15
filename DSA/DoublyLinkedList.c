#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtPosition(int value, int pos) {
    struct Node* newNode = createNode(value);
    if (pos == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        printf("%d inserted at position %d.\n", value, pos);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", value, pos);
}
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (temp->next == NULL) { // Only one node
        printf("%d deleted from end.\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("%d deleted from end.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, value, pos;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at specific position\n");
        printf("2. Delete from end\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
	switch (choice) {
        case 1:
            printf("Enter value and position: ");
            scanf("%d %d", &value, &pos);
            insertAtPosition(value, pos);
            break;
	case 2:
            deleteFromEnd();
            break;
	case 3:
            displayList();
            break;
	case 4:
            printf("Exiting...\n");
            exit(0);
	default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
