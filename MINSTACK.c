#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void pop()
{
    if (head == NULL)
    {
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}
void push(int x)
{
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->data = x;
    ptr->next = head;
    head = ptr;
}
int MIN()
{
    if(head == NULL){
        return INT_MAX;
    }
    struct Node *temp = head;
    int min = head->data;
    while (temp != NULL)
    {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }
    return min;
}
int peek()
{
    if (head == NULL)
        return -1;
    return head->data;
}
int isEmpty(){
    if(head == NULL) return 1;
    return 0;
}
int main()
{
    int q;
    scanf("%d", &q);
    char op[6];
    int min = INT_MAX;
    while (q--)
    {
        scanf("%s", op);
        if (strcmp(op, "PUSH") == 0)
        {
            int val;
            scanf("%d", &val);
            if (val < min)
                min = val;
            push(val);
        }
        else if (strcmp(op,"POP") == 0)
        {
            if(isEmpty()){
                min = INT_MAX;
                printf("EMPTY\n");

            }
            else{
                int top = peek();
                if(top == min){
                    pop();
                    min = MIN();
                }
                else
                {
                    pop();
                }
                
            }
        }
        else
        {
            if(isEmpty()) printf("EMPTY\n");
            else printf("%d\n", min);
        }
    }
}