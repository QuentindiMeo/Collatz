/*
** PERSONAL PROJECT, 2019
** collatz
** File description:
** collatz computer main
*/

#include <unistd.h>
#include "../include/collatz.h"
#include "../include/my.h"

static void print_wait(int slow)
{
    if (!slow)
        return;
    my_putstr("Slowing down by ");
    my_putnbr(slow * 1000);
    my_putstr(" milliseconds between every calculation.\n");
}

static void print_result(uint number)
{
    my_putnbr(number);
    if (number > 1)
        my_putstr(" -> ");
    else
        my_putchar('\n');
}

static uint collatz(char **av)
{
    uint n = my_atou(av[1]);
    uint slow = (!av[2] ? 0 : my_atou(av[2]));
    uint iter = 0;

    slow = (slow > 1000 ? 0 : slow);
    print_wait(slow);
    print_result(n);
    usleep(slow * 1000);
    for (; n > 1; iter++) {
        if (n % 2)
            n =  3 * n + 1;
        else
            n /= 2;
        print_result(n);
        usleep(slow * 1000);
    }
    return (iter);
}

int main(int ac, char **av)
{
    int iter;

    if (ac == 2 &&
        (my_str_isequal(av[1], "-h") || my_str_isequal(av[1], "--help")))
        return (help());
    if (ac == 1 || ac > 3)
        return (err_nb_args());
    if ((ac == 2 && !my_str_isnum(av[1])) ||
        (ac == 3 && (!my_str_isnum(av[1]) || !my_str_isnum(av[2]))) ||
        my_atou(av[1]) > 500000000)
        return (err_invalid_args());
    iter = collatz(av);
    my_putstr("Calculations done in ");
    my_putnbr(iter);
    my_putstr(" iteration");
    my_putstr(iter != 1 ? "s.\n" : ".\n");
    return (SUCCESS);
}
