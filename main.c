#include <stdio.h>
#include "brainfuck.h"
int main(int argc, char* argv[])
{
    //On g�rera argv ici
    char programme[] = ">++++++.<-.-.------.>.-.<+.>-.<.>.";

    brainfuck(programme);

    return 0;
}
