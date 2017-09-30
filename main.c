#include <stdio.h>
#include "ListNode.h"

int main() {
    SLNode *pHead ;
    SLNode *Head ;
    int s = 0 ;
    double d = 0.0 ;

    ListInitiate(&pHead) ;
    for (int i = 0, j = 10; i < 10; i++, j --) {
        Head = ListInsert( pHead, i, j, (double)j ) ;//Head 接收头节点的地址
    }

    for (int j = 1; j <= ListLength(pHead); j++) {//1-10
        ListGet(pHead, j, &s, &d) ;
        printf("%4d %.2lf\n", s, d) ;
    }

    Destroy(&pHead) ;


    printf("The World is over!\n");
    return 0;
}