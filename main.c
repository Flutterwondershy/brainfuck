#include <stdio.h>
#include "brainfuck.h"
int main(int argc, char* argv[])
{
    //On gèrera argv ici
    char programme[] = ">++++++.<-.-.------.>.-.<+.>-.<.>.";

    brainfuck(programme);

    return 0;
}
