#include <stdio.h>
#include "ListNode.h"

int main(void) {
    SLNode *pHead1, *pHead2, *q ;
    int n = 0 ;
    double p = 0.0 ;

    ListInitiate(&pHead1) ;//初始化头节点
    ListInitiate(&pHead2) ;

    for (int i = 0, j = 10; i < 10; i++, j --) {//初始化链表数据
        pHead1 = ListInsert( pHead1, i, j, (double)j ) ;//Head 接收头节点的地址
        pHead2 = ListInsert( pHead2, i, j, (double)j ) ;
    }

    printf("输如方式:系数 指数\n") ;
    printf("多项式一:\n") ;
    Input(pHead1) ;//输入函数

    //排序:从小到大
    pHead1 = ListSort(pHead1) ;//排序函数
    ListDislay(pHead1) ;//输出函数

    printf("多项式二:\n") ;
    //Input(pHead2) ;

    //排序:从小到大
    pHead2 = ListSort(pHead2) ;
    ListDislay(pHead2) ;//输出函数

    printf("两项相加:\n") ;
    q = ListAdd(pHead1, pHead2) ;

    ListSort(q) ;
    ListDislay(q) ;

    Destroy(&pHead1) ;//释放内存
    Destroy(&pHead2) ;

    printf("\nThe World is over!\n");
    return 0;
}