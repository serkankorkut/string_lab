#include <stdio.h>
#include "strings_lib.h"

int main()
{
    char *str = "Serkan ###  +++Korkut  ^^^ ---    21832132   smks";


    int howManyPieces;

    char **pieces = parseString(str, "^- #+", &howManyPieces);

    int i = 0;

    while (i < howManyPieces)
    {
        printf("%d. piece is %s\n", i, pieces[i]);
        i++;
    }

    char *dest1 = (char*)calloc(100, sizeof(char));


    stringAppend(&dest1, "Some are ");
    stringAppend(&dest1, "satin, ");
    stringAppend(&dest1, "some are ");
    stringAppend(&dest1, "steel, " );
    stringAppend(&dest1, "some are silk and " );
    stringAppend(&dest1, "some are ");
    stringAppend(&dest1, "leather");

    printf("%s\n",dest1);

    char *dest2 = NULL;

    stringAppend(&dest2,"Billie Jean ");
    stringAppend(&dest2,"is not ");
    stringAppend(&dest2,"my ");
    stringAppend(&dest2,"lover");

    printf("%s\n",dest2);

    char* dest3 =NULL;

    i = getLength(dest3);

    stringAppendFaster(&dest3,"Fast company... ",&i);
    stringAppendFaster(&dest3,"fast company... ",&i);
    stringAppendFaster(&dest3,"going nowhere... ",&i);
    stringAppendFaster(&dest3,"going ",&i);
    stringAppendFaster(&dest3,"nowhere ",&i);
    stringAppendFaster(&dest3,"faast",&i);


    printf("%s\n",dest3);

    char* dest4 = (char*)calloc(100, sizeof(char));

    i = getLength(dest4);

    stringAppendFaster(&dest4,"The truth ",&i);
    stringAppendFaster(&dest4,"is just a ",&i);
    stringAppendFaster(&dest4,"rule ",&i);
    stringAppendFaster(&dest4,"you can ",&i);
    stringAppendFaster(&dest4,"bend",&i);

    printf("%s\n",dest4);








    return 0;


}









