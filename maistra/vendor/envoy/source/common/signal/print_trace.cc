#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include "print_trace.h"
#include <iostream>

/* Obtain a backtrace and print it to stdout. */

#define MAX_STACK_FRAMES 32
void
print_trace (void)
{
  void *array[MAX_STACK_FRAMES];
  char **strings;
  int size, i;
  size = backtrace (array, MAX_STACK_FRAMES);
  strings = backtrace_symbols (array, size);
  if (strings != NULL)
  {
    std::cout << "Obtained " << size << "stack frames.\n";
    for (i = 0; i < size; i++)
      std::cout << strings[i] << "\n";
  }
  free (strings);
}

