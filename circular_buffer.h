/**
 * @file circular_buffer.h
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

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdio.h>
#include <stdbool.h>

#define CIRCULAR_BUFFER_LENGTH 6

/**
 * @brief This function is used to clear the buffer.
 *
 */
void circular_buffer_clear(void);

/**
 * @brief This function is used to write a value to the circular buffer.
 *
 * @param value The input value.
 */
void circular_buffer_write(int value);

/**
 * @brief This function is used to read a value from the circular buffer.
 *
 * @return int The read value.
 */
int circular_buffer_read(void);

/**
 * @brief This function to check if the buffer is empty or not.
 *
 * @return true if is empty else false.
 */
bool is_empty(void);

/**
 * @brief  This function to check if the buffer is full or not
 *
 * @return true if is full else false.
 */
bool is_full(void);

/**
 * @brief This function to return the number of data elements stored in the buffer.
 *
 * @return int number of data elements stored in the buffer.
 */
int circular_buffer_available(void);

/**
 * @brief This function to return the average value of data elements stored in the buffer.
 *
 * @return float average of data elements stored in the buffer.
 */
float circular_buffer_average(void);

#endif /* CIRCULAR__BUFFER_H */
