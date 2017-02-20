/*
 Created by Serkan Korkut on 29/11/16.
*/
enum bool
{
    true, false
};



#include <stdlib.h>

#ifndef STRINGS_LIB_H
#define STRINGS_LIB_H



/* Returns true if aChar is one of the delimeters  */
enum bool isContains(char *string,char aChar)
{
    enum bool ret = false;

    int i;

    for (i = 0; string[i] != '\0'; i++)
    {
        if (aChar == string[i])
        {
            ret = true;

            return ret;
        }
    }

    return ret;


}

int stringCompare(char * str1, char * str2)
{

      int result = 0;


    if( *str1 == '\0' && *str2 == '\0'  )
    {
        return 0;
    }

    if(*str1 == '\0')
    {
        return -1;
    }

    if(*str2 == '\0')
    {
        return 1;
    }



    while(*str1 != '\0'  && *str2 != '\0'  )
    {

       result = result + *str1 - *str2;

        str1++;
        str2++;

    }
    
    if(*str1 == '\0')
    {
        if(result == 0)
        {
            return -1;
        }
        else
        {
            while(*str2 != '\0')
            {
                result = result - *str2;
                str2++;
            }
        }
    }
    
    if(*str1 == '\0')
    {
        if(result == 0)
        {
            return 1;
        }
        else
        {
            while(*str1 != '\0')
            {
                result = result + *str1;
                str1++;
            }
        }
        
    }
    return length;


}

/* Copies n chars from source string to dest string, dest string MUST HAVE ALLOCATED DYNAMICALLY, enough to store the n + 1 chars */
void copyNString(char *dest, char *source, int n)
{
    int i = 0;

    while (i < n)
    {
        *dest++ = *source++;
        i++;
    }
}

/* Copies source string to dest string, dest string MUST HAVE ALLOCATED DYNAMICALLY, enough to store the source */
void copyString(char *dest, char *source)
{

    while (*source != '\0')
    {
        *dest++ = *source++;

    }
}

char **parseString(char *expression, char *delimeters,int *howManyPieces)
{
    int i;
    int discreteDelimCount = 0;

    /* Count the delims */
    for (i = 0; i < getLength(expression); i++)
    {
        if ((isContains(delimeters,expression[i]) == true && isContains(delimeters,expression[i + 1]) == false))
        {


            discreteDelimCount++;


        }
    }

    /* To store different lengths of each sub expression and starting points of them */
    int *subExpLengths = (int *) calloc(discreteDelimCount, sizeof(int));
    int *subExpStartingPoints = (int *) calloc(discreteDelimCount, sizeof(int));


    /*Count expression has how many delimeters and how long each sub expression is */
    int backSum = 0;

    *howManyPieces = discreteDelimCount + 1;


    /* We should again set 0 to discreteDelimCount, to control the discreteDelimCount as an accessing index for sub expression lengths and starting points  */
    discreteDelimCount = 0;

    for (i = 0; i < getLength(expression); i++)
    {
        /* To check it's a delimeter while the next element is not a delimeter,
         * if we don't check it, it will count adjacent delimeters more than 1   */
        if ((isContains(delimeters,expression[i ]) == true && isContains(delimeters,expression[i + 1]) == false))
        {

            if (discreteDelimCount == 0)
            {
                /*Set the first sub expression length to i, first sub expression's starting point is 0 and second one is i + 1
                 * since we have checked expression[i+1] is not a delimeter at the parent if */
                subExpLengths[discreteDelimCount] = i;
                subExpStartingPoints[discreteDelimCount] = 0;
                subExpStartingPoints[discreteDelimCount + 1] = i + 1;
            }
            else
            {
                /* To subtract previous delimeter's point from current point for sub expressions' lentgths  */
                /* Ignore subtracting the actual delimeters because it will lead overcomplexity because we don't know the count of each one  */

                backSum = backSum + subExpLengths[discreteDelimCount - 1];

                subExpLengths[discreteDelimCount] = i - backSum;


                /* The next char is the starting point of next sub expression
                 * since we have checked expression[i+1] is not a delimeter at the parent if  */
                subExpStartingPoints[discreteDelimCount + 1] = i + 1;



            }
            discreteDelimCount++;


        }
    }



    /* If you split a thing with n line, you got n + 1 pieces. That's why we add 1 to discreteDelimCount */


    char **retString = (char **) calloc((*howManyPieces  ), sizeof(char *));


    for (i = 0; i < *howManyPieces; i++)
    {
        /* Add 1 to subExpLengths[i] just to make sure there enough is enough place for \0  */
        retString[i] = (char *) calloc(subExpLengths[i] + 1, sizeof(char));
    }


    /* */
    for (i = 0; i < *howManyPieces; i++)
    {
        int accessIndex = 0;

        while (isContains(delimeters , expression[subExpStartingPoints[i] + accessIndex]) == false)
        {
            retString[i][accessIndex] = expression[accessIndex+ subExpStartingPoints[i]];
            accessIndex++;
        }

    }




    free(subExpLengths);

    free(subExpStartingPoints);



    return retString;

}

/* Append strings. **dest is the adress of the string you want to extend.
  *src is the char pointer of the string you want to add the tail of *dest */
void stringAppend(char** dest, char* src)
{

    int startIndex;
    /* Set starting index */
    startIndex = getLength(*dest);

    /* Set allocation for dest, extend as for itself, for src and plus one for null terminator  */
    *dest = (char*)realloc(*dest, (getLength(*dest)+getLength(src) +1 ) * sizeof(char) );



    /* Take a pointer to dest   */
    char* pointerToDest = *dest;


    /* While src have new characters */
    while(*src)
    {
        /* Set the char from starting index(end of *dest) */
        pointerToDest[startIndex] = *src;

        /* Increase src's pointer and start index */
        src++;

        (startIndex)++;

    }

    /* Set the null terminator */
    pointerToDest[startIndex] = '\0';









}

/* Append strings. It's faster than stringAppend because you don't traverse the *dest every time.
   We just store the ending index of it. startIndex should be the adress of the variable that you
   have assigned getLength(*dest). You assign it just for the first time for the same *dest  */
void stringAppendFaster(char** dest, char* src,int* startIndex)
{



    /* Set allocation for dest, extend as for itself, for src and plus one for null terminator  */
    *dest = (char*)realloc(*dest, (getLength(*dest)+getLength(src) +1 ) * sizeof(char) );



    /* Take a pointer to dest   */
    char* pointerToDest = *dest;


    /* While src have new characters */
    while(*src)
    {
        /* Set the char from starting index(end of *dest) */
        pointerToDest[*startIndex] = *src;

        /* Increase src's pointer and start index */
        src++;

        (*startIndex)++;

    }

    /* Set the null terminator */
    pointerToDest[*startIndex] = '\0';









}

#endif
