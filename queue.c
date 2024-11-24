//
// Created by flasque on 19/10/2024.
//

#include <assert.h>
#include <stdlib.h>
#include "queue.h"

/**
 * @brief Function to create a queue
 * @param size : the size of the queue
 * @return the queue
 */
t_queue createQueue(int size)
{
    // the size of the queue must be positive
    assert(size > 0);
    t_queue queue;
    queue.size = size;
    queue.first = 0;
    queue.last = 0;
    queue.values = (t_position *)malloc(size * sizeof(t_position));
    return queue;
}

void enqueue(t_queue *p_queue, t_position pos)
{
    // the queue must not be full
    assert((p_queue->last - p_queue->first) < p_queue->size);
    p_queue->values[(p_queue->last) % p_queue->size] = pos;
    p_queue->last++;
    return;
}

t_position dequeue(t_queue *p_queue)
{
    // the queue must not be empty
    assert(p_queue->last != p_queue->first);
    p_queue->first++;
    return p_queue->values[(p_queue->first - 1) % p_queue->size];
}

void freeQueue_node(t_node_queue* queue) {
    if (queue != NULL) {
        free(queue->values); // Libérer le tableau utilisé par la file
        free(queue);        // Libérer la structure de la file elle-même
    }
}

t_node_queue createQueue_node(int size)
{
    // the size of the queue must be positive
    assert(size > 0);
    t_node_queue queue;
    queue.size = size;
    queue.first = 0;
    queue.last = 0;
    queue.values = (t_node **)malloc(size * sizeof(t_node*));
    //queue.values = (t_position *)malloc(size * sizeof(t_position));
    return queue;
}

void enqueue_node(t_node_queue *p_node_queue, t_node *node)
{
    // the queue must not be full
    assert((p_node_queue->last - p_node_queue->first) < p_node_queue->size);
    p_node_queue->values[(p_node_queue->last) % p_node_queue->size] = node;
    //p_queue->values[(p_queue->last) % p_queue->size] = pos;
    p_node_queue->last++;
    return;
}
t_node*  dequeue_node(t_node_queue *t_node_queue) {
    // the queue must not be empty
    assert(t_node_queue->last != t_node_queue->first);
    t_node_queue->first++;
    return t_node_queue->values[(t_node_queue->first - 1) % t_node_queue->size];
}