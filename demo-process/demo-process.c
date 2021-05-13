#include "contiki.h"
#include <stdio.h>
PROCESS(myprocess1, "process 1");
PROCESS(myprocess2, "process 2");
PROCESS(myprocess3, "process 3");
AUTOSTART_PROCESSES(&myprocess1,&myprocess2,&myprocess3);

PROCESS_THREAD(myprocess1, ev, data)
{
PROCESS_BEGIN();
printf("This message from process 1\n");

PROCESS_END();
}
PROCESS_THREAD(myprocess2, ev, data)
{
PROCESS_BEGIN();
printf("This message from process 2\n");
PROCESS_END();
}
PROCESS_THREAD(myprocess3, ev, data)
{
PROCESS_BEGIN();
printf("This message from process 3\n");
PROCESS_END();
}
