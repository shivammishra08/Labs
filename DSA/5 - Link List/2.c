#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
}*head, *tail;
int count=0;

void display(){
    struct node *curr = head;
    if(!head){
        printf("Empty list\n");
        return;
    }
    while(curr){
        printf("%d ",curr->data);
        curr = curr->link;
    }
}
void create(){
    printf("Input (-1 to exit) : ");
    while(1){
        int in; scanf("%d",&in);
        if(in == -1) break; count++;
        struct node *new=malloc(sizeof(struct node));    
        new->data = in; new->link = NULL;
        if(head == NULL)
            head = new;
        else
           tail->link = new;
        tail = new;
    }
    printf("I/P : ");
    display();
}

struct node *reverse(struct node *temp, int k){
    int n = 0; if(k == 1) return temp;
    struct node *curr, *next, *prev;
    curr = temp, next = prev = NULL;
    while (curr!=NULL && n<k){
        next = curr->link;
        curr->link = prev;
        prev = curr; curr = next;
        n++;
    }
    if(next) temp->link = reverse(next,k);
    return prev;
}
int main(){
    create();
    if(!head) printf("Empty List\n");
    else
        for(int i=0; i<3; i++){
            printf("\n\nTest Case %d :",i+1);
            printf("\nEnter k : ");
            int k; scanf("%d",&k);
            if(k<0 || k>count)
                printf("Index out of bound");
            else{
                head = reverse(head,k);
                printf("O/P : ");
                display();
            }
        }
    return 0;
}