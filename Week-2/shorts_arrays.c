#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void set_array(int array[4]);
int set_int(int x);

int main(void)
{
    int a = 10;
    int c = 5;
    int b[4] = { 0, 1, 2, 3 };
    a = set_int(a);
    set_int(c); // não foi atribuido o resultado da função em uma variável
    set_array(b);
    printf("%d %d %d\n", a, b[0], c);
}

void set_array(int array[4])
{
    array[0] = 22;
}

int set_int(int x)
{
    x = 22;
    return x;
}