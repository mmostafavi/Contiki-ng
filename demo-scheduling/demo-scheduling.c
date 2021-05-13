#include "contiki.h"
#include "sys/clock.h"
#include "sys/rtimer.h"
#include "lib/list.h"
#include <stdio.h>
PROCESS(demo_taskscheduling, "demo task scheduling");
AUTOSTART_PROCESSES(&demo_taskscheduling);
static struct rtimer rtimer_timer;
struct simple_task {
struct simple_task *next;
int value;
};
static struct simple_task *s;
static int number_task = 10;
static int is_completed = -1;
LIST(task_list);
void
perform_rtime_callback(struct rtimer *t, void *ptr)
{
printf("task callback called\n");
int num = *((int*)ptr);
printf("perform task=%d\n", num);
s = list_item_next(s);
if(s!=NULL){
rtimer_set(&rtimer_timer, RTIMER_NOW() + (RTIMER_SECOND/2), 1,
perform_rtime_callback,&s->value);
}else{
printf("all tasks completed\n");
is_completed = 1;
}
}
PROCESS_THREAD(demo_taskscheduling, ev, data)
{
PROCESS_BEGIN();
printf("demo task schedule\n");
list_init(task_list);
int i;
printf("prepare task data\n");
struct simple_task task[10];
for(i=0;i<number_task;i++){
task[i].value = i + 1;
list_add(task_list, &task[i]);
}
s = list_head(task_list);
rtimer_set(&rtimer_timer, RTIMER_NOW() + (RTIMER_SECOND/2), 1,
perform_rtime_callback,&s->value);
while(1) {
if(is_completed>0)
break;
}
printf("program exit\n");
PROCESS_END();
}
