#ifndef BRAINFUCK_H_INCLUDED
#define BRAINFUCK_H_INCLUDED
    #include <stdlib.h>
    #include <stdio.h>
    typedef struct memoire memoire;
    struct memoire
    {
        memoire* precedent;
        unsigned char octet;
        memoire* suivant;
    };

    int brainfuck(char chaine[]);
    void initMemoire(memoire*, memoire* precedent, memoire* suivant);
    void freeMemoire(memoire*);

#endif // BRAINFUCK_H_INCLUDED
