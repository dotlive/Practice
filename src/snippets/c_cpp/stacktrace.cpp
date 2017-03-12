#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

void print_stacktrace()
{
    int size = 16;
    void * array[16];
    int stack_num = backtrace(array, size);
    char ** stacktrace = backtrace_symbols(array, stack_num);
    for (int idx = 0; idx < stack_num; ++idx)
    {
        printf("%s\n", stacktrace[idx]);
    }
    free(stacktrace);
}

void func()
{
    printf("stacktrace begin:\n");
    print_stacktrace();
}

int main()
{
    func();
}

