#ifndef QUEUE_H_
#define QUEUE_H_

#include "queue_config.h"

#define QUEUE_DUMP

struct queue_s {
    size_t capacity;
    unsigned char head;
    unsigned char tail;
    unsigned char size;
    elem_t * data;
};

//---------------------------------------------------------------------------------------------//

/// @brief 
/// @return 
queue_s * Queue_Ctor();

//---------------------------------------------------------------------------------------------//

/// @brief 
/// @param queue 
/// @param value 
/// @return 
int Queue_Push(queue_s * const queue, elem_t value);

//---------------------------------------------------------------------------------------------//

/// @brief 
/// @param queue 
/// @return 
int Queue_Pop(queue_s * const queue);

//---------------------------------------------------------------------------------------------//

/// @brief 
/// @param queue 
/// @return 
int Queue_Dtor(queue_s * const queue);

//---------------------------------------------------------------------------------------------//

/// @brief Error codes
enum {
    No_Error,
    Alloc_Error,
    Ctor_Error,
    Overflow,
    Underflow,
};

#endif