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
int peek()
{
    if (head == NULL)
        return -1;
    return head->data;
}
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
int isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}
int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            return 0;
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int k = 1, flag = 1;
        ;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == k)
            {
                k++;
            }
            else
            {
                if(peek() == k){
                    k++;
                    pop();
                    i--;
                    continue;
                }
                else push(arr[i]);
            }
        }
        while (!isEmpty())
        {
            if (peek() == k)
            {
                k++;
                pop();
            }
            else
            {
                while (!isEmpty())
                {
                    pop();
                    flag = 0;
                }
                break;
            }
        }
        if (flag)
            printf("yes\n");
        else
            printf("no\n");
    }
}