#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void push_left (Node** head, int value) {
    Node* first = (Node*) malloc (sizeof(Node));
    first -> value = value;
    first -> next = *head;
    *head = first;
}

void clear_list (Node** head) {
    free(*head);
    *head = NULL;
}

int pop (Node** head, int index) {
    int del;
    if (index == 0) {
        Node* copy_head;
        copy_head = *head;
        del = copy_head -> value;
        *head = copy_head -> next;
        copy_head -> next = NULL;
        free(copy_head);
    } else {
        Node* extr;
        extr = *head;
        Node* copy_del;
        for (int i=0; i<index; ++i) {
            if (i < index-1) extr = extr -> next;
        }
        copy_del = extr -> next;
        del = copy_del -> value;
        extr -> next = extr -> next -> next;
        copy_del -> next = NULL;
        free(copy_del);
    }
    return del;
}

void remove (Node** head, int value) {
    int x;
    Node* extr;
    Node* prev;
    extr = *head;
    prev = NULL;
    x = extr -> value;
    while (x != value) {
        prev = extr;
        extr = extr -> next;
        if (extr == NULL) return;
        x = extr -> value;
    }
    if (prev == NULL) {
        Node* copy_head;
        copy_head = *head;
        *head = copy_head -> next;
        copy_head -> next = NULL;
        free(copy_head);
    } else {
        prev -> next = prev -> next -> next;
        extr -> next = NULL;
        free(extr);
    }
}

void remove_all (Node** head, int value) {
    Node* extr;
    Node* prev;
    extr = *head;
    while (true) {
        prev = extr;
        extr = extr -> next;
        if (extr == NULL) break;
        if (extr -> value == value) {
            prev -> next = prev -> next -> next;
            extr -> next = NULL;
            free(extr);
            extr = prev;
        }    
    }
    if ((*head) -> value == value) {
        Node* copy_head;
        copy_head = *head;
        *head = copy_head -> next;
        copy_head -> next = NULL;
        free(copy_head);
    }
}

void replace_all (Node* head, int old_value, int new_value){
    Node* extr;
    extr = head;
    while (true) {
        extr = extr -> next;
        if (extr == NULL) break;
        if (extr -> value == old_value) {
            extr -> value = new_value;
        }    
    }
    if (head -> value == old_value) {
        head -> value = new_value;
    }
}

int unique (Node** head) {
    int count;
    count = 0;
    Node** extr;
    extr = head;
    while (true) {
        cout << (*extr) << endl; 
        if ((*extr) != NULL) {
            count = count + 1;
            remove_all(extr, (*extr) -> value);
        } else break;
    }
    return count;
}

void reverse (Node** head) {
    Node* copy_head;
    copy_head = *head;
    Node* tail = (Node*) malloc (sizeof(Node));
    tail -> next = NULL;
    tail -> value = (*head) -> value;
    *head = (*head) -> next;
    copy_head -> next = NULL;
    free(copy_head);
    while ((*head) != NULL) {
        push_left(&tail, (*head) -> value);
        copy_head = *head;
        *head = (*head) -> next;
        copy_head -> next = NULL;
        free(copy_head);
    }
    *head = tail;
}

/*void sort_1 (Node** head) {
    int min;
    min = (*head) -> value;
    Node* pointer_to_min;
    pointer_to_min = *head;
    Node* prev;
    prev = NULL;
    Node* prev_to_min;
    prev_to_min = NULL;
    //Node* first = (Node*) malloc (sizeof(Node));
    for (Node* extr = *head; extr != NULL; extr = extr -> next) {
        if (extr -> value < min) {
            min = extr -> value;
            pointer_to_min = extr;
            prev_to_min = prev;
        }
        prev = extr;
    }
    if (prev_to_min != NULL) {
        pointer_to_min -> next = *head;
        *head = pointer_to_min;
        pointer_to_min -> next = pointer_to_min -> next -> next;
    }
    
    prev = (*head) -> next
    for (Node* extr = (*head) -> next -> next; extr != NULL; extr = extr -> next) {
        if ((extr -> value) < (prev -> value)) {
            extr -> next = prev;
            prev -> next = prev -> next -> next;
            prev
        }
    }
    
}*/


int main() {
    srand(time(NULL));
    
    Node* first = (Node*) malloc (sizeof(Node));
    first -> next = NULL;
    first -> value = 0;
    Node* extr;
    extr = first;
    for (int i=0; i<10; i++) {
        extr -> next = (Node*) malloc (sizeof(Node));
        extr = extr -> next;
        extr -> next = NULL;
        extr -> value = i+1;
    }

    for (Node* a = first; a != NULL; a = a -> next) {
        cout << a << ' ' << a -> value << ' ' << a -> next << endl;
    }
    
    cout << "##############################" << endl;
    
    reverse(&first);
    remove(&first, 5);
    remove(&first, 0);
        
    for (Node* a = first; a != NULL; a = a -> next) {
        cout << a << ' ' << a -> value << ' ' << a -> next << endl;
    }
    return 0;
}
