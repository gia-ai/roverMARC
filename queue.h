//
// Created by flasque on 19/10/2024.
//

#ifndef UNTITLED1_QUEUE_H
#define UNTITLED1_QUEUE_H
#include "loc.h"

typedef struct node t_node;
/**
 * @brief Structure for the queue of integers
 */
typedef struct s_queue
{
    t_position *values;
    int size;
    int last;
    int first;
} t_queue;
typedef struct s_node_queue
{
 //t_position *values;
 t_node ** values;
 int size;
 int last;
 int first;
} t_node_queue;
/**
 * @brief Function to create a queue
 * @param size : the size of the queue
 * @return the queue
 */
t_queue createQueue(int);
t_node_queue createQueue_node(int);
/**
 * @brief Function to enqueue a value in the queue
 * @param p_queue : pointer to the queue
 * @param value : the position to enqueue
 * @return none
 */
void enqueue(t_queue *,t_position);
void enqueue_node(t_node_queue *,t_node*);
/**
 * @brief Function to dequeue a value from the queue
 * @param p_queue : pointer to the queue
 * @return the value dequeued
 */
t_position dequeue(t_queue *);
t_node* dequeue_node(t_node_queue *);

void freeQueue_node(t_node_queue* queue);
#endif //UNTITLED1_QUEUE_H
