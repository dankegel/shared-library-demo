#include <stdio.h>
#include "foo.h"

int main(int argc, char **argv)
{
    printf("Hello, world! %d\n", foo(argc));
    return 0;
}
