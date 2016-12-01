#strings_lib
<br>
**A compact C library that contains following functions dependent with stdlib.h**
<br>
<br>
**int getLength(char \*expression)**
<br>
It returns the length of the string 
<br>
<br>
Code 
<br>
<br>
![Alt text](https://github.com/justSomeRandomPal/CS-Hacettepe-Club/blob/master/string_lib/img/getLength.png?raw=true "Get Length")
<br>
<br>
Result
<br>
<br>
![Alt text](https://github.com/justSomeRandomPal/CS-Hacettepe-Club/blob/master/string_lib/img/getLengthsUsage.png?raw=true "Get Length Usage")
<br>
<br>
**enum bool isContains(char aChar, char \*delims)**
<br>
It return true in enum bool type if delims string contains aChar 
<br>
<br>
**void copyNString(char \*dest, char \*source, int n)**
<br>
Copies n string from source to dest
<br>
<br>
**void copyString(char \*dest, char \*source)**
<br>
Copies string from source to dest
<br>
<br>
**char \*\* parseString(char \*expression, char \*delimeters)**
<br>
Parses string expression to subexpressions with respect to delimeters and returns 2D char pointer array that each row is a subexpression

