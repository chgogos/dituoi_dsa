#include <cstdio>
#include <cstdlib>

int main(int argc, char **argv)
{
    int *p = (int *)malloc(sizeof(int));
    *p = 2;
    (*p)++;
    printf("Value in p: 0x%X dereference p: %d\n", p, *p);
    free(p);
    return 0;
}