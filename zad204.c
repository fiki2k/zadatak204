/*   Ako u programu izmedju rijeci ima vise od 1 razmaknice program treba namjestit da ima 1 razmaknica.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VELICINA 100


char * razmaknica(const char * string);


int main()
{
    char string[MAX_VELICINA];
    char * noviString;

    printf("Unesi neki string : ");
    gets(string);

    printf("\nString na pocetku : \"%s\"\n", string);

    noviString = razmaknica(string);

    printf("\nString nakon brisanja viska razmaknica : \"%s\"\n", noviString);

    return 0;
}



char * razmaknica(const char * string)
{
    int i, j;
    char * noviString;

    noviString = (char *)malloc(strlen(string) + 1);

    i = 0;
    j = 0;

    while(string[i] != '\0')
    {
        /* Ako smo nasli prazan oprostor */
        if(string[i] == ' ')
        {
            noviString[j] = ' ';
            j++;

            /* Prskoci ostale razmaknice */
            while(string[i] == ' ')
                i++;
        }

        noviString[j] = string[i];

        i++;
        j++;
    }
    
    noviString[j] = '\0';

    return noviString;
}
