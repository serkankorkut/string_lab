#include <stdio.h>
#include "strings_lib.h"

int main()
{

    char *str = "Serkan ###  +++Korkut  ^^^ ---    21832132   smks";

    char *lengthOfFive = "Hello";

    printf("Our string is between quotes: \"%s\" and the length of it is %d\n", lengthOfFive, getLength(lengthOfFive));

    char *dest = (char *) calloc(100, sizeof(char));

    copyNString(dest, str, 3);

    printf("%s\n", dest);

    copyString(dest, str);

    printf("%s\n", dest);

    int howManyPieces;

    char **pieces = parseString(str, "^- #+",&howManyPieces);

    int i = 0;
    while (i<howManyPieces)
    {
        printf("%s\n", pieces[i]);
        i++;
    }


    return 0;


}


















