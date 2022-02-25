#include <stdio.h>
#include <stdlib.h>
struct SNode{
    int data;
    struct SNode* link;
};

void push(struct SNode **stack, int data){
    struct SNode *new = malloc(sizeof(struct SNode));
    new->data = data;  new->link = *stack;
    *stack = new;
}
int pop(struct SNode **stack){
    if (*stack){
        struct SNode *temp = *stack;
        int res = temp->data;
        *stack = temp->link;
        free(temp); return res;
    }
    printf("Stack Underflow\n");
}

void display(struct SNode *stack){
    if(stack){
        struct SNode *temp = stack;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else  printf("Empty Stack\n");
}

void insbot(struct SNode **stack, int item){
    if(!*stack)
        push(stack,item);
    else{
        int temp=pop(stack);
        insbot(stack, item);
        push(stack, temp);
    }
}
void reverse(struct SNode **stack){
    if(*stack){
        int item=pop(stack);
        reverse(stack);
        insbot(stack, item);
    }
}

int main(){
    struct SNode *stack = NULL;
    int ch,in;
    printf("1. Push\n2. Pop\n3. Display\n4. Reverse\n0. Exit\n");
    while(1){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the value : ");
            scanf("%d",&in);
            push(&stack, in);
        }
        else if(ch==2){
            if(stack){
                int del=pop(&stack);
                printf("%d popped\n",del);
            }
            else printf("Stack Underflow\n");
        }
        else if(ch==3) display(stack);
        else if(ch==4) {
            if(stack) reverse(&stack);
            else printf("Stack is empty\n");
        }
        else if(ch==0) break;
        else printf("Please Enter valid choice\n");
    }
    return 0;
}