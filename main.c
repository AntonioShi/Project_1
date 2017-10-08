#include <stdio.h>
#include "ListNode.h"

int main() {
    SLNode *pHead ;
    int n = 0 ;

    double p = 0.0 ;


    int i;
    double j ;
    char a = ' ', b = ' ' ;

//    scanf("%c %c", &a, &b) ;

    ListInitiate(&pHead) ;
    for (int i = 0, j = 10; i < 10; i++, j --) {
        pHead = ListInsert( pHead, i, j, (double)j ) ;//Head 接收头节点的地址
    }
//
    Input(pHead) ;
    for (int j = 1; j <= ListLength(pHead); j++) {//1-10
        ListGet(pHead, j, &n, &p) ;
        printf("%4d %.2lf\n", n, p) ;
    }

    Destroy(&pHead) ;


    printf("The World is over!\n");
    return 0;
}