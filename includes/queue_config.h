#ifndef QUEUE_CONFIG_H_
#define QUEUE_CONFIG_H_

const size_t Def_Capacity = 1 << 3;         // should be a degree of 2
    
const size_t Cmd_Mask = Def_Capacity - 1;   // allows to make a U-turn to the front of the queue

typedef int elem_t;

#endif