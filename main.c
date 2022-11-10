#include <stdio.h>

extern int dll();

int main()
{
    printf("+main()\n");
    dll();
    printf("-main()\n");
    return 0;
}