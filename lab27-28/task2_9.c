#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct st {
    char symbol;
    struct st *next;
} QUEUE;
QUEUE *add(QUEUE *tail, char item);
char shift(QUEUE **head);
int main() {
    char str[100];
    QUEUE *head = NULL, *tail = NULL;
    int is_palindrome = 1;
    printf("Введіть рядок: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    for (int i = 0; str[i] != '\0'; i+=1) {
        if (isalpha(str[i])) {
            tail = add(tail, tolower(str[i]));
            if (!head) head = tail;
        }
    }
    QUEUE *temp_head = head;
    QUEUE *temp_tail = tail;
    while (temp_head && temp_tail) {
        if (shift(&temp_head) != shift(&temp_tail)) {
            is_palindrome = 0;
            break;
        }
    }
    printf(is_palindrome ? "Це паліндром\n" : "Це не паліндром\n");
    while (head) shift(&head);
    return 0;
}
QUEUE *add(QUEUE *tail, char item) {
    QUEUE *new_item = (QUEUE*)malloc(sizeof(QUEUE));
    new_item->symbol = item;
    new_item->next = NULL;
    if (tail) tail->next = new_item;
    return new_item;
}
char shift(QUEUE **head) {
    QUEUE *temp = *head;
    char value = temp->symbol;
    *head = temp->next;
    free(temp);
    return value;
}