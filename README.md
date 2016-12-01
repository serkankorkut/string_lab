#strings_lib.h

A compact C library that contains following functions dependent with stdlib.h . You can find the explonation and example of the functions in the library



<br>
<h3>1)Get the length of the string</h3>

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
<h3>2)Return enum bool type true or false if a string contains a char </h3>

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
<h3>3)Copies a string to another. Note that destination string should have dynamically been allocated enough to store source </h3>

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
<h3>4)Copies n characters from a string to another. Note that destination string should have dynamically been allocated enough to store n + 1 characters </h3>

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

    /* Allocate enough space for dest, don't forget to add 1 for null terminator */
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
<h3>5)Parses string expression to subexpressions with a random int's address and it'll return parsed subexpressions with respect to delimeters, that each row is a subexpression and the number of pieces stored in parameter integer</h3>

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

