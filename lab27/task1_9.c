#include <stdlib.h>
#include <stdio.h>

typedef struct st {
    char symbol;
    struct st *next;
} STACK;
void push(STACK **s, char item);
char pop(STACK **s);
int main() {
    STACK *head = NULL;
    char ch;
    int count = 0;
    printf("Введіть 15 символів:\n");
    for (int i = 0; i < 15; i+=1) {
        scanf(" %c", &ch);
        push(&head, ch);
    }
    while (head) {
        if (pop(&head) == 'A') count+=1;
    }
    printf("Символ 'A' зустрічається %d разів\n", count);
    return 0;
}
void push(STACK **s, char item) {
    STACK *new_item = (STACK*)malloc(sizeof(STACK));
    new_item->symbol = item;
    new_item->next = *s;
    *s = new_item;
}
char pop(STACK **s) {
    STACK *temp = *s;
    char value = temp->symbol;
    *s = temp->next;
    free(temp);
    return value;
}