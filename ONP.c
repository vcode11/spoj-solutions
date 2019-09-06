#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
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
void push(char x)
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

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
char peek()
{
    if (head == NULL)
        return '\0';
    return head->data;
}
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int isOperator(char ch)
{
    return (ch == '/' || ch == '*' || ch == '+' || ch == '-' || ch == '^');
}
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        char str[401];
        scanf("%s", str);
        char res[401];
        int k = 0;
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            if (isOperand(str[i]))
            {
                res[k++] = str[i];
            }
            else if (isOperator(str[i]))
            {
                while (!isEmpty() && Prec(peek()) > Prec(str[i]) && peek() != '(')
                {
                    res[k++] = peek();
                    pop();
                }
                push(str[i]);
            }
            else
            {
                if (str[i] == '(')
                {
                    push(str[i]);
                }
                else
                {
                    while (!isEmpty() && peek() != '(')
                    {
                        res[k++] = peek();
                        pop();
                    }
                    pop();
                }
            }
        }
        while (!isEmpty())
        {
            res[k++] = peek();
            pop();
        }
        res[k] = '\0';
        printf("%s\n", res);
    }
}