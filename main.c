////循环队列的表示与实现
//#include "stdlib.h"
//#include "stdio.h"
//#include "string.h"
//#define MAX_SIZE 6
//
//typedef struct SqQueue {
//    char* a1;
//    int front;
//    int rear;
//}SqQueue;
//
//void InitSqQueue(SqQueue* s) {
//    s->front = s->rear = 0;
//    s->a1 = (char*) malloc(sizeof(char) * MAX_SIZE);
//}
//
//void EnQueue(SqQueue* s, char e) {
//    if ((s->rear + 1) % MAX_SIZE == s->front) {
//        printf("队列已满，无法插入\n");
//        return;
//    }
//    s->a1[s->rear] = e;
//    s->rear = (s->rear + 1) % MAX_SIZE;
//}
//
//void OutQueue(SqQueue* s, char* e) {
//    if (s->rear == s->front) {
//        printf("队列已空，无法出列\n");
//        return;
//    }
//    *e = s->a1[s->front];
//    s->front = (s->front + 1) % MAX_SIZE;
//}
//
//void GetHeadOfQueue(SqQueue* s, char* e) {
//    if (s->rear == s->front) {
//        printf("队列已空，无法获取\n");
//        return;
//    }
//    *e = s->a1[s->front];
//}
//
////void print(SqQueue* s) {
////    if (s->rear == s->front) {
////        printf("队列已空\n");
////        return;
////    }
////    if (s->rear > s->front) {
////        for (int i = s->front; i < s->rear; ++i) {
////            printf("%c ", s->a1[i]);
////        }
////        printf("\n");
////    }
////    if (s->rear < s->front) {
////        for (int i = s->front; i < MAX_SIZE; ++i) {
////            printf("%c ", s->a1[i]);
////        }
////        for (int i = 0; i < s->rear; ++i) {
////            printf("%c ", s->a1[i]);
////        }
////        printf("\n");
////    }
////}
//void print(SqQueue* s) {
//    if (s->rear == s->front) {
//        printf("队列已空\n");
//        return;
//    }
//    int t1 = s->front, t2 = s->rear;
//    while ((t1) % MAX_SIZE != t2) {
//        printf("%c ", s->a1[t1]);
//        t1 = (t1 + 1) % MAX_SIZE;
//    }
//    printf("\n");
//}
//int main() {
//    SqQueue* s = (SqQueue*) malloc(sizeof(SqQueue));
//    InitSqQueue(s);
//    char e;
//    for (int i = 0; i < 6; ++i) {
//        EnQueue(s, 'a' + i);
//        GetHeadOfQueue(s, &e);
//        printf("队首元素为%c\n", e);
//        print(s);
//    }
//    for (int i = 0; i < 6; ++i) {
//        OutQueue(s, &e);
//        if (s->rear == s->front) {
//            printf("无队首元素\n");
//        } else {
//            GetHeadOfQueue(s, &e);
//            printf("队首元素为%c\n", e);
//        }
//        print(s);
//    }
//}

////链队列的表示与实现
//#include "stdio.h"
//#include "stdlib.h"
//#include "string.h"
//
//typedef struct NodeQueue {
//    char data;
//    struct NodeQueue* next;
//}NodeQueue;
//
//void InitNodeQueue(NodeQueue** front, NodeQueue** rear) {
//    *front = (NodeQueue*) malloc(sizeof(NodeQueue));
//    (*rear) = *front;
//    (*rear)->next = NULL;
//}
//
//void EnNodeQueue(NodeQueue** rear, char e) {
//    NodeQueue* temp = (NodeQueue*) malloc(sizeof(NodeQueue));
//    temp->data = e;
//    temp->next = NULL;
//    (*rear)->next = temp;
//    (*rear) = temp;
//}
//
//void OutNodeQueue(NodeQueue** front) {
//    if ((*front)->next == NULL) {
//        printf("链队已空\n");
//        return;
//    }
//    NodeQueue* temp;
//    temp = (*front)->next;
//    (*front)->next = (*front)->next->next;
//    free(temp);
//}
//
//void GetHead(NodeQueue* front, char* e) {
//    if(front->next == NULL) {
//        printf("链队为空\n");
//        return;
//    }
//    *e = (front)->next->data;
//}
//
//void print(NodeQueue* front) {
//    if(front->next == NULL) {
//        printf("链队为空\n");
//        return;
//    }
//    while (front->next != NULL) {
//        printf("%c ", front->next->data);
//        front = front->next;
//    }
//    printf("\n");
//}
//int main() {
//    NodeQueue* front, *rear;
//    InitNodeQueue(&front, &rear);
//    for (int i = 0; i < 5; ++i) {
//        EnNodeQueue(&rear, 'a' + i);
//        print(front);
//    }
//    char e;
//    GetHead(front, &e);
//    printf("队首为%c\n", e);
//    for (int i = 0; i < 5; ++i) {
//        OutNodeQueue(&front);
//        print(front);
//    }
//
//    return 0;
//}






////3.舞伴配对问题：有m个女生，有n个男生（m不等于n），参加一个舞会。男女生分别编号坐在舞池的两边的椅子上。每曲开始时，依次从男生和女生中各出一人配对跳舞，
/// 本曲没成功配对者坐着等待下一曲找舞伴。请设计一个程序模拟动态地显示出上述过程，输出每曲配对情况。
//#include "stdlib.h"
//#include "stdio.h"
//#include "string.h"
//#define MAX_SIZE 50
//
//typedef struct SqQueue {
//    char* a1;
//    int front;
//    int rear;
//}SqQueue;
//
//void InitSqQueue(SqQueue* s) {
//    s->front = s->rear = 0;
//    s->a1 = (char*) malloc(sizeof(char) * MAX_SIZE);
//}
//
//void EnQueue(SqQueue* s, char e) {
//    if ((s->rear + 1) % MAX_SIZE == s->front) {
//        printf("队列已满，无法插入\n");
//        return;
//    }
//    s->a1[s->rear] = e;
//    s->rear = (s->rear + 1) % MAX_SIZE;
//}
//
//void OutQueue(SqQueue* s, char* e) {
//    if (s->rear == s->front) {
//        printf("队列已空，无法出列\n");
//        return;
//    }
//    *e = s->a1[s->front];
//    s->front = (s->front + 1) % MAX_SIZE;
//}
//
//void GetHeadOfQueue(SqQueue* s, char* e) {
//    if (s->rear == s->front) {
//        printf("队列已空，无法获取\n");
//        return;
//    }
//    *e = s->a1[s->front];
//}
//
//void print(SqQueue* s) {
//    if (s->rear == s->front) {
//        printf("队列已空\n");
//        return;
//    }
//    if (s->rear > s->front) {
//        for (int i = s->front; i < s->rear; ++i) {
//            printf("%c ", s->a1[i]);
//        }
//        printf("\n");
//    }
//    if (s->rear < s->front) {
//        for (int i = s->front; i < MAX_SIZE; ++i) {
//            printf("%c ", s->a1[i]);
//        }
//        for (int i = 0; i < s->rear; ++i) {
//            printf("%c ", s->a1[i]);
//        }
//        printf("\n");
//    }
//}
//void Compare(SqQueue* woman, SqQueue* man) {
//    int m, n;
//    printf("输入女人与男人人数\n");
//    scanf("%d %d", &m, &n);
//    for (int i = 0; i < m; ++i) {
//        EnQueue(woman, 'A' + i);
//    }
//    for (int i = 0; i < n; ++i) {
//        EnQueue(man, 'a' + i);
//    }
//    char e;
//    char wom[m];
//    char mn[n];
//    int m1;
//    printf("请输入舞曲数目\n");
//    scanf("%d", &m1);
//    for (int i = 0; i < m1; ++i) {
//        if (m >= n) {
//            for (int i = 0; i < n; ++i) {
//                OutQueue(woman, &e);
//                wom[i] = e;
//            }
//            for (int i = 0; i < n; ++i) {
//                OutQueue(man, &e);
//                mn[i] = e;
//            }
//            for (int i = 0; i < n; ++i) {
//                printf("%c ", wom[i]);
//            }
//            printf("\n");
//            for (int i = 0; i < n; ++i) {
//                printf("%c ", mn[i]);
//            }
//            printf("\n");
//            for (int i = 0; i < n; ++i) {
//                EnQueue(woman, wom[i]);
//            }
//            for (int i = 0; i < n; ++i) {
//                EnQueue(man, mn[i]);
//            }
//        }
//        if (m < n) {
//            for (int i = 0; i < m; ++i) {
//                OutQueue(woman, &e);
//                wom[i] = e;
//            }
//            for (int i = 0; i < m; ++i) {
//                OutQueue(man, &e);
//                mn[i] = e;
//            }
//            for (int i = 0; i < m; ++i) {
//                printf("%c ", wom[i]);
//            }
//            printf("\n");
//            for (int i = 0; i < m; ++i) {
//                printf("%c ", mn[i]);
//            }
//            printf("\n");
//            for (int i = 0; i < m; ++i) {
//                EnQueue(woman, wom[i]);
//            }
//            for (int i = 0; i < m; ++i) {
//                EnQueue(man, mn[i]);
//            }
//        }
//    }
//}
//int main() {
//    SqQueue* woman = (SqQueue*) malloc(sizeof(SqQueue));
//    SqQueue* man = (SqQueue*) malloc(sizeof(SqQueue));
//    InitSqQueue(woman);
//    InitSqQueue(man);
//    Compare(woman, man);
//    return 0;
//}










//4.划分子集问题：集合A=｛a1,a2,…an｝,集合上的关系R={(ai,aj),ai,aj∈A，i≠j},其中ai,aj表示ai与aj间存在冲突关系。要求将A划分成互不相交的子集A1,A2,Ak,
// 使任何子集中的元素不冲突。划分的子集数尽可能少。
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#define MAX_SIZE 20
typedef struct SqQueue {
    char* a1;
    int front;
    int rear;
}SqQueue;

void InitSqQueue(SqQueue* s) {
    s->front = s->rear = 0;
    s->a1 = (char*) malloc(sizeof(char) * MAX_SIZE);
}

void EnQueue(SqQueue* s, char e) {
    if ((s->rear + 1) % MAX_SIZE == s->front) {
        printf("队列已满，无法插入\n");
        return;
    }
    s->a1[s->rear] = e;
    s->rear = (s->rear + 1) % MAX_SIZE;
}

void OutQueue(SqQueue* s, char* e) {
    if (s->rear == s->front) {
        printf("队列已空，无法出列\n");
        return;
    }
    *e = s->a1[s->front];
    s->front = (s->front + 1) % MAX_SIZE;
}

void GetHeadOfQueue(SqQueue* s, char* e) {
    if (s->rear == s->front) {
        printf("队列已空，无法获取\n");
        return;
    }
    *e = s->a1[s->front];
}

void print(SqQueue* s) {
    if (s->rear == s->front) {
        printf("队列已空\n");
        return;
    }
    int t1 = s->front, t2 = s->rear;
    while ((t1) % MAX_SIZE != t2) {
        printf("%c ", s->a1[t1]);
        t1 = (t1 + 1) % MAX_SIZE;
    }
    printf("\n");
}

int SqLength(SqQueue* s) {
    return (s->rear - s->front + MAX_SIZE) % MAX_SIZE;
}

void compare(SqQueue* s, int a1, int a2, int a3, int a4) {
    if (s->rear == s->front) {
        printf("队列已空\n");
        return;
    }
    char A[a4];
    char e;
    int n = 0;
    OutQueue(s, &A[0]);
    n++;
    int t3 = 1;
    int t4 = SqLength(s);
    for (int i = 0; i < t4; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s->a1[s->front] - A[j] == a1 || s->a1[s->front] - A[j] == a2 || s->a1[s->front] - A[j] == a3 || A[j] - s->a1[s->front] == a1 || A[j] - s->a1[s->front] == a2 || A[j] - s->a1[s->front] == a3) {
                t3 = 0;
                break;
            }
        }
        if (t3) {
            OutQueue(s, &A[n]);
            n++;
        } else {
            OutQueue(s, &e);
            EnQueue(s, e);
        }
        t3 = 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("%c ", A[i]);
    }
    printf("\n");
}
int main() {
    int n =20;
    char A[n];
    printf("大写字母小写字母与数字\n");
    for (int i = 0; i < n; ++i) {
        scanf(" %c", &A[i]);
    }
    int a1 = 'a' - '1';
    int a2 = 'A' - '1';
    int a3 = 'A' - 'a';

    SqQueue* s = (SqQueue*) malloc(sizeof(SqQueue));
    InitSqQueue(s);
    for (int i = 0; i < n; ++i) {
        EnQueue(s,A[i]);
    }
    while (s->front != s->rear) {
        compare(s, a1, a2, a3, n);
    }
    return 0;
}