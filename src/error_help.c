/*
** PERSONAL PROJECT, 2019
** collatz
** File description:
** collatz help error functions
*/

#include "../include/my.h"

int err_invalid_args(void)
{
    my_putstr("Error: one or both of the arguments is invalid\n");
    my_putstr("Try './collatz --help' for more information.\n");
    return (FAILURE);
}

int err_nb_args(void)
{
    my_putstr("Error: invalid number of arguments\n");
    my_putstr("Try './collatz --help' for more information.\n");
    return (FAILURE);
}

static void help2(void)
{
    my_putstr("An invalid option will quit the program.  You can quit the prog"
    "ram\n\twhile it's running by hitting CTRL+C.\n\n   \033[1mExit status:"
    "\033[0m\n\t0\tif the calculations were finished,\n\t84\tif an invalid arg"
    "ument was passed to the program.\n\n \033[1mPRINTING FORMAT\033[0m\n\t$>"
    "\033[4mN\033[0m -> \033[4mu1\033[0m -> \033[4mu2\033[0m -> \033[4mu3"
    "\033[0m -> ... -> 1\n\n \033[1mAUTHOR\033[0m\n\tWritten by Quentin di Meo"
    ".\n\n \033[1mREPORTING BUGS\033[0m\n\tReport any bug or functioning error"
    " to <quentin.di-meo@epitech.eu>\n\n");
}

int help(void)
{
    my_putstr("\n\tWelcome to Collatz.\n\n \033[1mUSAGE\033[0m\n\t./collatz "
    "\033[4mN\033[0m \033[4mMS\033[0m\n\n \033[1mDESCRIPTION\033[0m\n\t"
    "The Collatz sequence starts with a given number and follows a very\n\t"
    "simple pattern:  if the number is even, it is divided by 2; if the\n\t"
    "number is odd,  it is multiplied by 3 and 1 is added to its total.\n\t"
    "The sequence stops looping when it reaches  1 so this program will\n\t"
    "stop computing the sequence when it hits on 1.  The program prints\n\t"
    "the result after every iteration and counts them. The total number\n\t"
    "of iterations is displayed when the loop has ended.  The max value\n\tfor"
    " this calculator  \033[1m500,000,000\033[0m.  Any superior number will r"
    "esult\n\tin an error.\n\n\t\033[4mN\033[0m\n\t\tChoose \033[4mN\033[0m a"
    "s starting number.\n\n\t\033[4mMS\033[0m\n\t\tSlow down the program by wa"
    "iting  \033[4mMS\033[0m  milliseconds after\n\t\tevery iteration. I'm sug"
    "gesting 500, the limit is 1,000.\n\t\tAny higher value will be ignored.\n"
    "\n\t\033[1m-h\033[0m, \033[1m--help\033[0m (used as sole argument)\n\t\t"
    "Display this help.\n\n\t");
    help2();
    return (SUCCESS);
}
