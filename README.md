#strings_lib.h

A compact C library that contains following functions dependent with stdlib.h . You can find the explonation and example of the functions in the library

<br>

<h3>1)Compares two strings as strcmp style(returns negative number for str1 is smaller than str2 alphabetically, positive for reverse case, and 0 for str1 and str2 are are equal)  </h3>

<br>



Prototype

 ``` c
int stringCompare(char * str1, char * str2)
```

Usage
  
  ``` c
#include <stdio.h>
#include "strings_lib.h"

int main()
{
    char* str1 = "Hallo";
    char* str2 = "Hello";

    int a = stringCompare(str1,str2);
    
    printf("%d\n",a);

    return 0;
}
   
```

Output
```sh
-4
```



<br>

<h3>2)Get the length of the string</h3>

<br>



Prototype

 ``` c
int getLength(char *expression)
```

Usage
  
  ``` c
#include <stdio.h>
#include "strings_lib.h"

int main()
{
    char* str = "Hallo";
    
    printf("Length of str is %d\n",getLength(str) );

    return 0;
}
   
```

Output
```sh
Length of str is 5
```



<br>
<h3>3)Return enum bool type true or false if a string contains a char </h3>

<br>



Prototype

 ``` c
enum bool isContains(char* string,char aChar)
```

Usage
  
  ``` c
#include <stdio.h>
#include "strings_lib.h"

int main()
{
    char* str = "Hallo";

    if(isContains(str,'a' ) == true)
    {
        printf("%s contains %c",str,'a');
    }

    return 0;
}  
```

Output
```sh
Hallo contains a
```



<br>
<h3>4)Copies a string to another. Note that destination string should have been dynamically allocated enough to store source </h3>

<br>



Prototype

 ``` c
void copyString(char *dest, char *source)
```

Usage
  
  ``` c
#include <stdio.h>
#include "strings_lib.h"

int main()
{
    char* str = "Hallo";

    /* Allocate enough space for dest, don't forget to add 1 for null terminator */
    char* dest = (char*)calloc(getLength(str) + 1, sizeof(char));

    copyString(dest,str);

    printf("String dest is %s\n",dest);


    return 0;
}
```

Output
```sh
String dest is Hallo
```
<br>


<br>
<h3>5)Copies n characters from a string to another. Note that destination string should have been dynamically allocated enough to store n + 1 characters </h3>

<br>



Prototype

 ``` c
void copyNString(char *dest, char *source, int n)
```

Usage
  
  ``` c
#include <stdio.h>
#include "strings_lib.h"

int main()
{
    char* str = "Hallo";

    /* Allocate enough space for n, don't forget to add 1 for null terminator */
    char* dest = (char*)calloc( 3 + 1, sizeof(char));

    copyString(dest,str,3);

    printf("String dest is %s\n",dest);


    return 0;
}
```

Output
```sh
String dest is Hal
```
<br>

<br>
<h3>6)Parses string expression to subexpressions with a random int's address and it'll return parsed subexpressions with respect to delimeters, that each row is a subexpression and the number of pieces stored in parameter integer</h3>

<br>



Prototype

 ``` c
char ** parseString(char *expression, char *delimeters,int *howManyPieces)
```

Usage
  
  ``` c
#include <stdio.h>
#include "strings_lib.h"

int main()
{
    char *str = "Serkan ###  +++Korkut  ^^^ ---    21832132   smks";


    int howManyPieces;

    char **pieces = parseString(str, "^- #+",&howManyPieces);

    int i = 0;

    while (i<howManyPieces)
    {
        printf("%d. piece is %s\n",i, pieces[i]);
        i++;
    }


    return 0;


}


```

Output
```sh
0. piece is Serkan
1. piece is Korkut
2. piece is 21832132
3. piece is smks
```

<h3>7)Append strings. Takes dest char pointer's address, a src char pointer for adding the tail of dest pointer. dest char pointer could be either have allocated or have not  </h3>

<br>



Prototype

 ``` c
void stringAppend(char **dest, char *src)
```

Usage
  
  ``` c
#include <stdio.h>
#include "strings_lib.h"

int main()
{
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


    return 0;


}


```

Output
```sh
Some are satin, some are steel, some are silk and some are leather
Billie Jean is not my lover
```

<h3>8)Append strings faster. It's faster because it don't traverse from dest char pointers first element every time when function calls. It stores where dest char pointer ends in the startIndex. So you should assign startIndex to returning value of getLength(*dest) and then use startIndex's address as third parameter. Takes dest char pointer's address, a src char pointer for adding the tail of dest pointer and an integer's address (that you should have assigned getLength(*dest) for the first time you call the function). dest char pointer could be either have allocated or have not  </h3>

<br>



Prototype

 ``` c
void stringAppendFaster(char **dest, char *src,int *startIndex)
```

Usage
  
  ``` c
#include <stdio.h>
#include "strings_lib.h"

int main()
{
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


```

Output
```sh
Fast company... fast company... going nowhere... going nowhere faast
The truth is just a rule you can bend
```

