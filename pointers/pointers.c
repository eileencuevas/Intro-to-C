#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int counter = 0;
    while (y[counter] != '\0')
    {
        x[counter] = y[counter];
        counter++;
    }
    x[counter] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    char *instance = NULL;

    // loop through str
    while (*str != '\0')
    {
        if (*str == c)
        {
            instance = str;
        }
        str++;
    }
    //return pointer
    return instance;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    char *instance = NULL;    // initialize as NULL (in case nothing is found)
    while (*haystack != '\0') // loop through the haystack string
    {
        // if the current letter of haystack string matches first letter of needle, do the below
        if (*haystack == *needle)
        {
            instance = haystack;    // set instance to point to haystack starting at current index
            while (*needle != '\0') // loop through needle string
            {
                // if next letter in haystack doesn't match next letter in needle, set instance back to null
                if (*haystack != *needle)
                {
                    instance = NULL;
                }
                haystack++;
                needle++;
            }
        }
        haystack++;
    }

    return instance;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
