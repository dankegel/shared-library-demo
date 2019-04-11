#include <stdio.h>
#include "bar.h"

int main(int argc, char **argv)
{
    printf("Hello, world! %d\n", bar(argc));
    return 0;
}
