/**
 * @file circular_buffer.c
 * @author Oliver Joisten (o.joisten@live.se)
 * @brief Implement a single instance circular buffer according to the requirements below.
 *            The buffer is an array of type int.
 *            Length of the array is a macro defined in the header file
 *            The module shall have a clear function to clear the buffer.
 *            The module shall have a function to read data from the buffer.
 *            The module shall have a function to write data to the buffer.
 *            If the buffer is full, the oldest data shall be overwritten.
 *            The module shall have a function to return the number of data elements stored in the buffer.
 *            The module shall have a function to check if the buffer is full or not.
 *            Header file of the module shall be well-described using the doxygen format.
 *            The module shall be tested using assertion.
 * @version 0.1
 * @date 2022-11-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "circular_buffer.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#if ((CIRCULAR_BUFFER_LENGTH < 1) || (CIRCULAR_BUFFER_LENGTH > 1024))
#error QUEUE_SIZE shall be an integer in the range of 1 and 1024
#endif

static int buffer[CIRCULAR_BUFFER_LENGTH];
static int head = 0;
static int tail = 0;
static int available = 0;

void circular_buffer_clear(void)
{
    head = 0;
    tail = 0;
    available = 0;
}

int circular_buffer_read(void)
{
    int temp = 0;
    if (available > 0)
    {
        temp = buffer[head];
        head = (head + 1) % CIRCULAR_BUFFER_LENGTH;
        available--;
    }
    return temp;
}

void circular_buffer_write(int value)
{
    buffer[tail] = value;
    tail = (tail + 1) % CIRCULAR_BUFFER_LENGTH;

    if (available == CIRCULAR_BUFFER_LENGTH)
    {

        head = (head + 1) % CIRCULAR_BUFFER_LENGTH;
    }
    else
    {
        available++;
    }
}

int circular_buffer_available(void)
{
    return available;
}

bool is_empty(void)
{
    return (available == 0);
}

bool is_full(void)
{
    return (available == CIRCULAR_BUFFER_LENGTH);
}

float circular_buffer_average(void)
{
    float avg = 0;

    if (available > 0)
    {
        for (int i = 0; i < available; i++)
        {
            avg += buffer[(head + i) % CIRCULAR_BUFFER_LENGTH];
        }

        avg = avg / available;
    }

    return avg;
}