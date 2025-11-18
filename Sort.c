#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createList() {
    int n, value;
    struct Node *head = NULL;
    struct Node *temp;
    struct Node *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void sortList(struct Node* head) {
    if (head == NULL)
        return;


    struct Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {

        for (j = i->next; j != NULL; j = j->next) {

            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}


struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL;
    struct Node *next = NULL;
    struct Node *curr = head;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create Linked List 1\n");
        printf("2. Create Linked List 2\n");
        printf("3. Display Lists\n");
        printf("4. Sort List 1\n");
        printf("5. Reverse List 1\n");
        printf("6. Concatenate List1 + List2\n");
        printf("7. Exit\n");
        printf("8. Sort List 2\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            list1 = createList();
            break;
        case 2:
            list2 = createList();
            break;
        case 3:
            printf("List 1: ");
            display(list1);
            printf("List 2: ");
            display(list2);
            break;
        case 4:
            sortList(list1);
            break;
        case 5:
            list1 = reverseList(list1);
            printf("List 1 reversed.\n");
            break;
        case 6:
            list1 = concatenate(list1, list2);
            printf("Concatenated List: ");
            display(list1);
            break;
        case 7:
            exit(0);
        case 8:
            sortList(list2);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
}
