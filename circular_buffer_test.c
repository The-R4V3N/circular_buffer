/**
 * @file circular_buffer_test.c
 * @author Oliver Joisten (https://the-r4v3n.github.io/github.io/#)
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
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    float avg = 0;
    // Check if buffer is clear.
    circular_buffer_clear();
    assert(is_empty());
    (void)printf("--------------------------------\n");
    (void)printf("------------Testing-------------\n");
    (void)printf("--------------------------------\n");
    (void)printf("Testing clear ...........Passed!\n");

    // Check writing to the buffer.
    circular_buffer_write(1);
    circular_buffer_write(2);
    circular_buffer_write(3);
    circular_buffer_write(4);
    circular_buffer_write(5);
    circular_buffer_write(6);
    circular_buffer_write(7);
    assert(CIRCULAR_BUFFER_LENGTH == circular_buffer_available());
    (void)printf("--------------------------------\n");
    (void)printf("Testing writing .........Passed!\n");
    (void)printf("--------------------------------\n");

    // Check reading from the buffer.
    assert(2 == circular_buffer_read());
    assert(3 == circular_buffer_read());
    assert(4 == circular_buffer_read());
    assert(CIRCULAR_BUFFER_LENGTH - 3 == circular_buffer_available());
    (void)printf("Testing reading .........Passed!\n");
    (void)printf("--------------------------------\n");

    // Check testing if the buffer is full.
    assert(!is_full());
    (void)printf("Testing is full .........Passed!\n");
    (void)printf("--------------------------------\n");

    // Check testing availabe.
    assert(3 == circular_buffer_available());
    (void)printf("Testing avaiable.........Passed!\n");
    (void)printf("--------------------------------\n");

    // Check testing the buffer average value.
    assert(circular_buffer_average());
    (void)printf("Testing avarage .........Passed!\n");
    (void)printf("--------------------------------\n");
    (void)printf("--------------------------------\n");
    (void)printf("------------All Tests-----------\n");
    (void)printf("--------------------------------\n");
    (void)printf("------Successfully Passed!------\n");
    (void)printf("--------------------------------\n");

    return 0;
}
