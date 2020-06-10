#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <io.h>
#include <time.h>
#define NMAX 100
#define RAND_MAX 30
//stack
    struct stack 
    {
        int* elem[NMAX];
        int top;
    };
    void init(struct stack* stk) 
    {
        stk->top = 0;
    }
    void push(struct stack* stk, struct queue* f) {
        if (stk->top < NMAX) 
        {
            stk->elem[stk->top] = f;
            stk->top++;
        }
        else
            printf("Стек полон, количество элементов: %d !\n", stk->top);
    }
    int isempty(struct stack* stk) 
    {
        if (stk->top == 0)    return 1;
        else return 0;
    }
    void stkPrint(struct stack* stk) 
        {
        int i;
        i = stk->top; // i - количество элементов в стеке
        if (isempty(stk) == 1) return; // стек пуст
        printf("\nSTACK::\n");
        do {
            i--;
            printf("%d\n", stk->elem[i]);
        } while (i > 0);
    }
    //queue
    struct queue 
    {
    int qu[NMAX];
    int rear, frnt;
    };
    void initq(struct queue* q) 
    {
        q->frnt = 1;
        q->rear = 0;
        return;
    }
    void insertq(struct queue* q, int x) 
    {
        if (q->rear < NMAX - 1) {
            q->rear++;
            q->qu[q->rear] = x;
        }
        else
            printf("Очередь полна!\n");
        return;
    }
    int isemptyq(struct queue* q) 
    {
        if (q->rear < q->frnt)    return 1;
        else  return 0;
    }
    void printq(struct queue* q) {
        int h;
        if (isemptyq(q) == 1) {
            printf("Очередь пуста!\n");
            return;
        }
        printf("\nQueue:");
        for (h = q->frnt; h <= q->rear; h++)
            printf("%d ", q->qu[h]);
        return;
    }
    //rabota s summ
    int maxSUM(struct queue* q, int max)
    {
        int max1=0;
        for (int h = q->frnt; h <= q->rear; h++)
        {

                max1 = max1 + q->qu[h];
        }
        if (max1 > max) 
        { return max1; }
        else return max;
    }
    int vivmaxsumm(struct queue *q, int max, int i) 
    {
        int max1 = 0;
        for (int h = q->frnt; h <= q->rear; h++)
        {

            max1 = max1 + q->qu[h];
        }
        if (max1 == max)
        {
            return i;
        }
        else return - 1;
    
    }
    void maxsumm(struct stack* stk)
    {
        int maxsumma = 0, maxsummaI = -1;;
        for (int i = stk->top - 1; i >= 0; i--)
        {
            maxsumma = maxSUM(stk->elem[i], maxsumma);
        }
        printf("\nMAX SUMMA:%d",maxsumma);
        for (int i = stk->top - 1; i >= 0; i--)
        {
            maxsummaI=vivmaxsumm(stk->elem[i], maxsumma, i);
            if (maxsummaI == -1)
                continue;
            if (maxsummaI == i) 
            {
                printf("\nQueue with max summ:");
                printq(stk->elem[i]);
            }
        }

    }
    int maxNUM(struct queue *q, int max) 
    {
        printq(q);
        int h;
        for (h = q->frnt; h <= q->rear; h++)
        {
            if (max < q->qu[h])
                max = q->qu[h];
        }
        return max;
    
    }
    int vivMaxNUM(struct queue* q, int max, int i)
    {
        for (int h = q->frnt; h <= q->rear; h++)
        {
            if (max == q->qu[h])
                return i;
        }
        return -1;

    }
    void maxnumm(struct stack* stk)
    {
        int maxI = -1 , max = 0;
        for (int i=stk->top-1; i >=0; i--)
        {
            max=maxNUM(stk->elem[i], max);
        }
        printf("\nMAX NUMBER:%d", max);
        for (int i = stk->top - 1; i >= 0; i--)
        {
            maxI = vivMaxNUM(stk->elem[i], max, i);
            if (maxI == -1)
                continue;
            if (maxI == i) 
            {
                printf("\nQueue with max number:");
                printq(stk->elem[i]);

            }
        }
    
    }
    //SLIM
    void queueSLIM(struct queue *q, struct stack *slim) 
    {
        for (int h = q->frnt; h <= q->rear; h++)
            push(slim,q->qu[h]);
    
    }
    void stkSLIMperedacha(struct stack *stk, struct stack *slim) 
    {
        for (int i = stk->top - 1; i >= 0; i--) 
        {
            queueSLIM(stk->elem[i], slim);
        }
    
    }
    //main
    int main()
{
    struct stack* stk, *stkSLIM;
    srand(time(NULL));
    int n,i;
    stk = (struct stack*)malloc(sizeof(struct stack));
    init(stk);
    printf("Write stack number: ");
    scanf("%d", &n);
    struct queue* traffic = (struct queue*)malloc(sizeof(struct queue) * n);
    for (struct queue *p = traffic; p < traffic+n; p++) 
    {
        initq(p);
        for (i = 0; i < 5; i++)
            {
                int test = rand()%RAND_MAX;
                insertq(p, test);
            }
        push(stk, p);
    }
    maxnumm(stk);
    maxsumm(stk);
    stkSLIM = (struct stack*)malloc(sizeof(struct stack));
    init(stkSLIM);
    stkSLIMperedacha(stk, stkSLIM);
    stkPrint(stkSLIM);
    free(stk);
    free(traffic);
    free(stkSLIM);

}
