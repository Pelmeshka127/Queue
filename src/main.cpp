#include <stdio.h>

#include "../includes/queue.h"

int main()
{
    queue_s * queue = Queue_Ctor();

    if (queue == nullptr)
    {
        fprintf(stderr, "The initialization of the queue failed in ctor\n");
        return Ctor_Error;
    }


    Queue_Push(queue, 5);


    Queue_Push(queue, 7);


    Queue_Push(queue, 11);


    for (int i = 1; i < 12; i++)
    {
        Queue_Push(queue, i);

        Queue_Pop(queue);

    }

    Queue_Push(queue, 4);

    Queue_Push(queue, 4);

    Queue_Push(queue, 4);

    Queue_Push(queue, 4);

    Queue_Push(queue, 4);

    Queue_Push(queue, 4);

    Queue_Push(queue, 4);

    Queue_Dtor(queue);

    return 0;
}