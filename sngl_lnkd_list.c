#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList (int size) {
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int value;
    
    for (int indx=0; indx<size; indx+=1) {
        current = (struct Node*)malloc(sizeof(struct Node));
        
        if (current == NULL) {
            printf ("\nMemory allocation failed !");
            break;
        } else {
            printf ("\nEnter value for node %i: ", indx+1);
            scanf ("%i", &value);
            
            current -> data = value;
            current -> next = NULL;
            
            if (head == NULL)
                head = current;
            else
                temp -> next = current;
            temp = current;
            
            printf ("New node added !");
        }
    }
    printf ("\nList created !\n\n");
    return head;
}

struct Node* insertNodeAtHead (struct Node *head, int node) {
    struct Node *new_node = NULL;
    
    new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node -> data = node;
    new_node -> next = head;
    head = new_node;
    
    printf ("\nNode %i inserted at HEAD", node);
    printf ("\n");
    return head;
}

struct Node* insertNodeAtEnd (struct Node *head, int node) {
    struct Node *new_node = NULL, *temp = head;
    
    new_node = (struct Node*)malloc(sizeof(struct Node));
    
    while (temp != NULL && temp -> next != NULL) {
        temp = temp -> next;
    }
    new_node -> data = node;
    new_node -> next = NULL;
    temp -> next = new_node;
    temp = new_node;
    
    printf ("\nNode %i inserted at END !", node);
    printf ("\n");
    
    return head;
}

struct Node* insertNodeAtOther (struct Node *head, int node, int position) {
    struct Node *new_node = NULL, *temp = head;
    
    if (position <= 1 || head == NULL) {
        return insertNodeAtHead (head, node);
    } else {
        new_node = (struct Node*)malloc(sizeof(struct Node));
        for (int i=1; i < position-1 && temp->next != NULL; i+=1) {
            temp = temp -> next;
        }
        new_node -> data = node;
        
        new_node -> next = temp -> next;
        temp -> next = new_node;
        printf ("\nNode %i inserted at position %i", node, position);
    }
    printf ("\n");
    return head;
}

struct Node* deleteHeadNode (struct Node *head) {
    
    struct Node *temp = head;
    if (head == NULL) {
        printf ("\nList is empty !");
    } else {
        head = head->next;
        printf ("\nHead node %i deleted !", temp->data);
        free(temp);
    }
    printf ("\n");
    return head;
}

struct Node* deleteNode (struct Node *head, int value) {
    
    struct Node *temp = head, *prev = NULL;
    
    if (head == NULL) {
        printf ("\nList is empty !");
    } else if (head->data == value) {
        printf ("\n");
        return deleteHeadNode (head);
    }
    
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf ("\nNode %i not found !", value);
        printf ("\n");
        return head;
    } else if (temp->data == value) {
        prev->next = temp->next;
        free(temp);
        printf ("\nNode %i deleted !", value);
        printf ("\n");
        return head;
    } else {
        printf ("Invalid input !");
        printf ("\n");
        return head;
    }
}

void printList (struct Node *head) {
    struct Node *temp = head;
    
    if (head == NULL) {
        printf ("\nList is empty !");
    } else {
        printf ("\nList: ");
        while (temp != NULL) {
            printf ("%i->", temp->data);
            if (temp->next == NULL)
                printf ("TAIL");
            temp = temp->next;
        }
        printf ("\n");
    }
}

int main (void) {
    char check;
    int size, node, position;
    struct Node *head = NULL;
    
    printf ("Enter the size of the list: ");
    scanf ("%i", &size);
    
    head = createList (size);
    
    while (1) {
        
        printf (
            "\n1.Print List"
            "\n2.Insert node at head position."
            "\n3.Insert node at some other position."
            "\n4.Insert node at end position."
            "\n5.Delete head node."
            "\n6.Delete some other position node."
            "\n7.Exit"
            );
        printf ("\nEnter the operation number you want to perform: ");
        int opr;
        
        if (scanf ("%i", &opr) >= 1) {
            switch (opr) {
                case 1:
                    printList (head);
                    break;
                case 2:
                    printf ("\nEnter the node to insert: ");
                    scanf ("%i", &node);
                    head = insertNodeAtHead (head, node);
                    break;
                case 3:
                    printf ("\nAt which position you want to enter the node ? ");
                    scanf ("%i", &position);
                    printf ("\nEnter the node to insert: ");
                    scanf ("%i", &node);
                    
                    head = insertNodeAtOther (head, node, position);
                    break;
                case 4:
                    printf ("\nEnter the node to insert: ");
                    scanf ("%i", &node);
                    head = insertNodeAtEnd (head, node);
                    break;
                case 5:
                    printf ("\nDo you want to delete the head node (YES-Y/NO-N) ? ");
                    char optn; scanf (" %c", &optn);
                    if (optn == 'Y' || optn == 'y')
                        head = deleteHeadNode (head);
                        break;
                case 6:
                    printf ("\nEnter the node you want to delete: ");
                    scanf ("%i", &node);
                    head = deleteNode (head, node);
                    break;
                case 7:
                    exit (0);
                    break;
                default:
                    printf ("\nInvalid entry !\n");
                    break;
            }
        } else {
            printf ("\nInvalid entry ! Please enter a number !\n");
            break;
        }
    }
}
