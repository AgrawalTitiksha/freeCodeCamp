#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node*);
struct node *display(struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);
struct node *insert_sorted(struct node *start);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *delete_node(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_sorted(struct node *start);
struct node *delete_list(struct node *start);
void main(){
    int choice;
    do{
        printf("\n\n****MAIN MENU****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at beginning");
        printf("\n 4: Add a node at end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Add a node in sorted linked list");
        printf("\n 8: Delete a node from the beginning");
        printf("\n 9: Delete a node from the end");
        printf("\n 10: Delete a given node");
        printf("\n 11: Delete a node before a given node");
        printf("\n 12: Delete a node from sorted linked list");
        printf("\n 13: Delete the entire linked list");
        printf("\n 14: Exit");
        printf("\n ***********************");
        printf("\n\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            start=create_ll(start);
            printf("\nLinked List Created");
            break;
            case 2:
            start=display(start);
            break;
            case 3:
            start=insert_beg(start);
            break;
            case 4:
            start=insert_end(start);
            break;
            case 5:
            start=insert_before(start);
            break;
            case 6:
            start=insert_after(start);
            break;
            case 7:
            start=insert_sorted(start);
            break;
            case 8:
            start=delete_beg(start);
            break;
            case 9:
            start=delete_end(start);
            break;
            case 10:
            start=delete_node(start);
            break;
            case 11:
            start=delete_after(start);
            break;
            case 12:
            start=delete_sorted(start);
            break;
            case 13:
            start=delete_list(start);
            break;
        }
    }while(choice!=14);
}
struct node *create_ll(struct node *start){
    struct node *new_node,*ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data:");
    scanf("%d",&num);
    while(num!=-1){
        new_node=(struct node*)malloc(sizeof(struct node*));
        new_node->data=num;
        if(start==NULL){
            new_node->next=new_node;
            start=new_node;
        }
        else{
            ptr=start;
            while(ptr->next!=start){
                ptr=ptr->next;
                new_node->next=start;
                ptr->next=new_node;
            }
        }
        printf("\nEnter the data:");
        scanf("%d",&num);
    }return start;
}
struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    printf("\n");
    while(ptr->next!=start){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d",ptr->data);
    return start;
}
struct node *insert_beg(struct node *start){
    struct node *new_node,*ptr;
    int num;
    printf("\n Enter the data:");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node *));
    new_node->data=num;
    ptr=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=start;
    start=new_node;
    return start;
}
struct node *insert_end(struct node *start){
    struct node *ptr,*new_node;
    int num;
    printf("\nEnter the data:");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node *));
    new_node->data=num;
    ptr=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=start;
    return start;
}
struct node *insert_before(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("\nEnter the data:");
    scanf("%d",&num);
    printf("\nEnter the value before which the data has to be inserted:");
    scanf("%d",&val);
    new_node=(struct node*)malloc(sizeof(struct node *));
    ptr=start;
    if(ptr->data==val){
        printf("\nEnter the data:");
        scanf("%d",&num);
        start=insert_beg(start);
    }
    else{
        new_node->data=num;
        while(ptr->data!=val){
            preptr=ptr;
            ptr=ptr->next;
        }
        new_node->next=ptr;
        preptr->next=new_node;
    }
    return start;
}
struct node *insert_after(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("\nEnter the data:");
    scanf("%d",&num);
    printf("\nEnter the value after which the data has to be inserted:");
    scanf("%d",&val);
    new_node=(struct node*)malloc(sizeof(struct node *));
    new_node->data=num;
    ptr=start;
    while(preptr->data!=val){
        preptr=ptr;
        ptr=ptr->next;
    }
    new_node->next=ptr;
    preptr->next=new_node;
    return start;
}
struct node *insert_sorted(struct node *start){
    struct node *new_node,*ptr,*preptr;
    int num;
    printf("\nEnter the data:");
    scanf("%d",&num);
    new_node=(struct node*)malloc(sizeof(struct node *));
    new_node->data=num;
    ptr=start;
    while(ptr->data<num){
        preptr=ptr;
        ptr=ptr->next;
        if(ptr==start)
        break;
    }
    if(ptr==start){
        preptr->next=new_node;
        new_node->next=start;
        start=new_node;
    }
    else{
        new_node->next=ptr;
        preptr->next=new_node;
    }
    return start;
}
struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=start->next;
    free(start);
    start=start->next;
    return start;
}
struct node *delete_end(struct node *start){
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=start){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
struct node *delete_node(struct node *start){
    struct node *ptr,*preptr;
    int val;
    printf("\nEnter the value of the node which is to be deleted:");
    scanf("%d",&val);
    ptr=start;
    if(ptr->data==val){
        start=delete_beg(start);
        return start;
    }
    else{
        while(ptr->data!=val){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        return start;
    }
}
struct node *delete_after(struct node *start){
    struct node *ptr,*preptr;
    int val;
    printf("\nEnter the value after which the node has to be deleted:");
    scanf("%d",&val);
    ptr=start;
    while(preptr->data!=val){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    if(ptr==start){
        start=preptr->next;
    }
    free(ptr);
    return start;
}
struct node *delete_sorted(struct node *start){
    struct node *ptr,*preptr;
    int val;
    printf("\nEnter the value of node which has to be deleted:");
    scanf("%d",&val);
    ptr=start;
    if(ptr->data==val){
        start=delete_beg(start);
    }
    else{
        while(ptr->data!=val){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return start;
}
struct node *delete_list(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        start=delete_end(start);
    }
    free(start);
    return start;
}
