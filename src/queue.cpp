#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../includes/queue.h"

const int Poison = 0;

static void Queue_Dump(queue_s * const queue);

//---------------------------------------------------------------------------------------------//

queue_s * Queue_Ctor()
{
    queue_s * queue = {};

    queue = (queue_s *)calloc (1, sizeof(queue_s));
    if (queue == nullptr)
        return nullptr;

    queue->capacity = Def_Capacity;
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;  

    queue->data = (elem_t *)calloc (queue->capacity, sizeof(elem_t));
    if (queue->data == nullptr)
        return nullptr;  
    
    for (size_t i = 0; i < queue->capacity; i++)
        queue->data[i] = Poison;

#ifdef QUEUE_DUMP
    Queue_Dump(queue);
#endif
    
    return queue;
}

//---------------------------------------------------------------------------------------------//

int Queue_Push(queue_s * const queue, elem_t value)
{
    assert(queue);
    assert(value);

    if (queue->size == queue->capacity  && queue->head == queue->tail)
    {
        fprintf(stderr, "Queue is overflow. You cannot push anymore\n");
        return Overflow;
    }

    queue->data[queue->tail] = value;

    queue->tail++;
    queue->tail &= Cmd_Mask;

    queue->size++;

#ifdef QUEUE_DUMP
    Queue_Dump(queue);
#endif

    return No_Error;
}

//---------------------------------------------------------------------------------------------//

int Queue_Pop(queue_s * const queue)
{
    assert(queue);

    if (queue->size == 0)
    {
        fprintf(stderr, "The size of the queue is 0. The queue is underflow\n");
        return Underflow;
    }

    elem_t popping_value     = queue->data[queue->head];
    queue->data[queue->head] = Poison;

    queue->head++;
    queue->head &= Cmd_Mask;

    queue->size--;

#ifdef QUEUE_DUMP
    Queue_Dump(queue);
#endif

    return popping_value;

}

//---------------------------------------------------------------------------------------------//

int Queue_Dtor(queue_s * const queue)
{
    assert(queue);

    for (size_t i = 0; i < queue->capacity; i++)
        queue->data[i] = Poison;

    queue->head     = 0;
    queue->tail     = 0;
    queue->size     = 0;

#ifdef QUEUE_DUMP
    Queue_Dump(queue);
#endif

    queue->capacity = 0;
    free(queue->data);

    return No_Error;
}

//---------------------------------------------------------------------------------------------//

static void Queue_Dump(queue_s * const queue)
{
    assert(queue);

    printf("\n\n");
    printf("//-------------------------------------------//\n");
    printf("The capacity of queue is %zu\n", queue->capacity);
    printf("The size of queue is %d\n", queue->size);
    printf("The index of the Head is %d\n", queue->head);
    printf("The index of the Tail is %d\n", queue->tail);
    for (size_t i = 0; i < queue->capacity; i++)
        printf("The vaule of %zu element is %d\n", i, queue->data[i]);
    printf("//-------------------------------------------//\n");
}