//
// Created by antonio on 17-9-30.
//

#ifndef PROJECT_1_LISTNODE_H
#define PROJECT_1_LISTNODE_H

#include <malloc.h>
#include <stdio.h>

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
SLNode* ListInsert(SLNode *head, int i, DataType n, Real d){
    //在i位置处插入一个节点,系数d,指数n
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
    q->data = n ;//傳入數據,鏈接節點
    q->real = d ;

    return head ;

}

///*在链表末尾插入结点*/
//void InsertToLast(SLNode *head,SLNode *x)
//{
//    SLNode *p,*s;
//
//    p= head->next;
//    while(p->next !=head)
//    {
//        p=p->next;
//    }
//
//    if(p->next == head)
//    {
//
//        s= (SLNode *)malloc(sizeof(SLNode));  //生成新节点
//        s->data =x->data;
//
//        s->next = p->next;
//        p->next = s;
//    }
//
//
//}

//从现有的链表中查找看看是否有相同的指数节点
SLNode *FindSameNode(SLNode *head, DataType n){//传入要查找的指数
    SLNode *p = head->next ;

    while (p != NULL) {
        if (p->data != n) {
            ;
        } else {
            return p;
        }
        p = p->next;
    }
    return NULL ;

}

//大致分两类情况,系数d?0,d = 0, d#0.
//d =0,则无需操作 d#0,再分指数有无相同的情况.
int Input(SLNode *head){
    int n = 0;//指数
    double d = 1 ;//系数
    SLNode *p = head;
    SLNode *q = NULL;
    char a ;

    for (int i = 0; (a = getchar()) != '\n'; i++) {
        ungetc(a, stdin) ;
        scanf("%lf %d", &d, &n) ;

        if(d == 0){
            continue ;
        }
        else if(d != 0){
            /*判断有无相同指数的项*/
            //添加一个检索函数
            /**/
            q = FindSameNode(head, n) ;
            if(q != NULL){
                q->real += d ;
            } else{
                //没有找到相同指数的节点
                p = ListInsert(head, ListLength(head), n, d);//尾插入

            }
        }

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


SLNode* ListSort(SLNode *head) {
    //传入头指针,指数从小到大排序
    SLNode *p, *q ;
    int n ;
    double d ;

    p = head->next ;
    while (p) {
        q = p->next ;
        while (q) {
            if(p->data > q->data){
                n = p->data ;
                d = p->real ;
                p->data = q->data ;
                p->real = q->real ;
                q->data = n ;
                q->real = d ;

            }
            q = q->next ;
        }
        p = p->next ;
    }

    return head ;
}

void ListDislay(SLNode *head){
    int n ;
    double d ;
    SLNode *p = head ;
    for (int j = 1; j <= ListLength(p) - 1; j++) {//1-10
        ListGet(p, j, &n, &d) ;
        printf("%.2lf*X^%d + ", d, n) ;
    }
    ListGet(p, ListLength(p), &n, &d) ;
    printf("%.2lf*X^%d\n", d, n) ;

    printf("\n") ;

}

SLNode* ListAdd(SLNode *pHead1, SLNode *pHead2){
    SLNode *p, *q, *tail ;

    for(q = pHead2->next; q != NULL; q = q->next){
        p = FindSameNode(pHead1, q->data) ;
        if(p != NULL){
            p->real += q->real ;
        } else{
            p = ListInsert(pHead1, ListLength(pHead1), q->data, q->real) ;
        }
    }
    return p ;
}

#endif //PROJECT_1_LISTNODE_H
