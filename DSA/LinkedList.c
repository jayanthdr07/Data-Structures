#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at front.\n", value);
}
void deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (pos == 1) {
        head = head->next;
        printf("Deleted %d from position 1.\n", temp->data);
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    printf("Deleted %d from position %d.\n", deleteNode->data, pos);
    free(deleteNode);
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, value, pos;
    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Insert at front\n");
        printf("2. Delete at position\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 2:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePosition(pos);
            break;
        case 3:
            display();
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
