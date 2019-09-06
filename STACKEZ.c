#include <stdio.h>
#include <stdlib.h>

struct Node {
    long long int data;
    struct Node * next;
};
struct Node * head = NULL;
void pop(){
    if(head == NULL){ 
        return;
    }
    struct Node * temp = head;
    head = head->next;
    free(temp);
}
void push(long long int x){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = x;
    ptr->next = head;
    head = ptr;
}
int isEmpty(){
    if(head == NULL) return 1;
    return 0;
}
long long int peek(){
    if(head == NULL) return -1;
    return head->data;
}

int main()
{
    int t;
    scanf("%d",&t);
    int op;
    while(t--){
        scanf("%d",&op);
        if(op == 1){
            long long int x;
            scanf("%lld",&x);
            push(x);
        }
        else if(op == 2){
            pop();
        }
        else{
            if(isEmpty()){
                printf("Empty!\n");
            }
            else{
                printf("%lld\n",peek());
            }
        }
    }
}
