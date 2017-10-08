#include <stdio.h>
#include "ListNode.h"

int main() {
    SLNode *pHead1, *pHead2 ;
    int n = 0 ;

    double p = 0.0 ;

    ListInitiate(&pHead1) ;
    ListInitiate(&pHead2) ;

    for (int i = 0, j = 1; i < 10; i++, j ++) {
        pHead1 = ListInsert( pHead1, i, j, (double)j ) ;//Head 接收头节点的地址
        pHead2 = ListInsert( pHead2, i, j, (double)j ) ;
    }

    printf("输如方式:系数 指数\n") ;
    printf("多项式一:\n") ;
    Input(pHead1) ;
    for (int j = 1; j <= ListLength(pHead1) - 1; j++) {//1-10
        ListGet(pHead1, j, &n, &p) ;
        printf("%.2lf*X^%d + ", p, n) ;
    }
    ListGet(pHead1, ListLength(pHead1), &n, &p) ;
    printf("%.2lf*X^%d", p, n) ;

    printf("\n") ;
    printf("多项式二:\n") ;
    Input(pHead2) ;
    for (int j = 1; j <= ListLength(pHead2) - 1; j++) {//1-10
        ListGet(pHead2, j, &n, &p) ;
        printf("%.2lf*X^%d + ", p, n) ;
    }
    ListGet(pHead1, ListLength(pHead2), &n, &p) ;
    printf("%.2lf*X^%d\n", p, n) ;

    Destroy(&pHead1) ;
    Destroy(&pHead2) ;

    printf("The World is over!\n");
    return 0;
}