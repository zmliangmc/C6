#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue2.h"
#define MIN_PER_HR 60.0
bool newcustomer(double x);
Item customertime(long when);
int main(int argc, char const *argv[])
{
    Queue line;
    Item temp;
    int hours;              //模拟的小时数
    int perhour;            //每小时平均多少位顾客
    long cycle, cyclelimit; // 循环计数器、计数器的上限
    long trunaways = 0;     // 被拒绝的顾客数量
    long customers = 0;     // 加入队列的顾客数量
    long served = 0;        // 在模拟期间咨询过Sigmund的顾客数量
    long sum_line = 0;      // 累计的队列总长
    int wait_time = 0;      // 从当前到Sigmund空闲所需的时间
    double min_per_cust;    //顾客到来的平均时间
    long line_wait = 0;     //队列累计的等待时间
    IntializeQueue(&line);
    srand((unsigned int)time(0));
    puts("case study:sigmund lander's advice booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * perhour;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;
    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line))
                trunaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DeQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += QueueItemCount(&line);
    }
    if (customers > 0)
    {
        printf("customers  accepted:  %ld\n", customers);
        printf("   customers  served:  %ld\n", served);
        printf("         turnaways:  %ld\n", trunaways);
        printf("average  queue  size:  %.2f\n", (double)sum_line / cyclelimit);
        printf("  average  wait  time:  %.2f  minutes\n", (double)line_wait / served);
    }
    else
        puts("No customers");
    EmptyTheQueue(&line);
    puts("bey!");
    return 0;
}
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}
Item customertime(long when)
{
    Item cust;
    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;
    return cust;
}
