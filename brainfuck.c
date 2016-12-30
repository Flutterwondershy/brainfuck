#include"brainfuck.h"

int brainfuck(char chaine[])
{
    int i = 0;
    memoire* memoireActuel = malloc(sizeof(memoire));
    memoire* boucle;
    if(memoireActuel == NULL)
        return 0;
    initMemoire(memoireActuel, NULL, NULL);
    for(; chaine[i] != '\0'; i++)
    {
        switch(chaine[i])
        {
            case '+': memoireActuel->octet++; break;
            case '-': memoireActuel->octet--; break;

            case ',': memoireActuel->octet = fgetc(stdin); break;
            case '.': fputc(memoireActuel->octet, stdout); break;

            case '<': memoireActuel = memoireActuel->precedent; break;
            case '>':
                if(memoireActuel->suivant == NULL)
                {
                    memoireActuel->suivant = malloc(sizeof(memoire));
                    (memoireActuel->suivant)->precedent = memoireActuel;
                }
                if(memoireActuel->suivant == NULL) return 0;

                initMemoire(memoireActuel->suivant, memoireActuel, NULL);
                memoireActuel = memoireActuel->suivant;
            break;
            case '[':
                boucle = memoireActuel;
            break;
            case ']':
                if(boucle->octet)
                    for(;chaine[i] != '[' ; i--);
            break;
        }
    }
    freeMemoire(memoireActuel);
    return 1;
}
void initMemoire(memoire* structure, memoire* precedent, memoire* suivant)
{
    structure->precedent = precedent;
    structure->octet = 0;
    structure->suivant = suivant;
}
void freeMemoire(memoire* structure)
{
    while(structure->precedent != NULL) structure = structure->precedent;
    while(structure->suivant != NULL)
    {
        structure = structure->suivant;
        free(structure->precedent);
    }
    free(structure);
}
