//
// Created by antonio on 17-9-30.
//

#ifndef PROJECT_1_LISTNODE_H
#define PROJECT_1_LISTNODE_H

#include <malloc.h>

typedef int DataType ;//指数
typedef double Real ;//系数

typedef struct Node{
    struct Node *next ;
    DataType data ;//指数
    Real real ;//系数
}SLNode;


void ListInitiate(SLNode **head){
    *head = (SLNode *)malloc(sizeof(SLNode)) ;
    (*head)->next = NULL ;
}

int ListLength(SLNode *head){
    SLNode *p = head ;
    int size = 0 ;
    while (p->next != NULL){
        p = p->next ;
        size ++ ;
    }
    return size ;
}

//此处应有一个函数
//Insert one data and copy s to the new node
SLNode* ListInsert(SLNode *head, int i, DataType s, Real d){
    SLNode *p, *q ;
    int j = -1 ;
    p = head ;

    while(p->next != NULL && j < i - 1){
        p = p->next ;
        j ++ ;
    }

    q = (SLNode *)malloc(sizeof(SLNode)) ;
    q->next = p->next ;
    p->next = q ;
    q->data = s ;//傳入數據,鏈接節點
    q->real = d ;

    return head ;
}

int Input(SLNode *head, DataType s, Real d){
    int i;
    double j ;
    SLNode *p = head, *q;
    char a = ' ', b = ' ' ;
    scanf("%d %lf%c%c", &i, &j, &a, &b) ;
    while ( (a != '#') && (b != '#') ) {
        if(j == 0){
            continue ;
        } else if(/*判断有无相同指数的项*/1){
          q->real += j ;//no space
        } else{
            //space
            q = (SLNode *)malloc(sizeof(SLNode)) ;
            //Inser(q) ;//分三种情况插入,不过插入前要比较.
        }

        scanf("%d %lf%c%c", &i, &j, &a, &b) ;
    }
}

int ListDelete(SLNode *head, int i, DataType *s, Real *d){
    SLNode *p, *q ;
    int j = -1 ;

    p = head ;
    while(p != NULL && j < i - 1){
        p = p->next ;
        j ++ ;
    }

    if(j != i - 1){

        printf("参数错误\n") ;
        return 0 ;
    }

    q = p->next ;
    *s = p->data ;
    *d = p->real ;
    p->next = p->next->next ;
    free(q) ;

    return 1 ;
}

int ListGet(SLNode *head, int i, DataType *s, Real *d){
    SLNode *p ;
    int j = -1;

    p = head ;
    while(p != NULL && j < i - 1){
        p = p ->next ;
        j ++ ;
    }

    if(j != i - 1){

        printf("参数错误\n") ;
        return 0 ;
    }

    *s = p->data ;
    *d = p->real ;

    return 1 ;

}

void Destroy(SLNode **head){
    SLNode *p,*q ;
    p = (*head) ;
    while(p != NULL){
        q = p ;
        p = p->next ;
        free(q) ;
    }

    *head = NULL  ;//头指针 = 空
    return ;
}

void ListSort(SLNode **head){
    //传入头指针,指数从小到大排序

}

#endif //PROJECT_1_LISTNODE_H
