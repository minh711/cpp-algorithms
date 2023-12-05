#include <iostream>

using namespace std;

// Function prototype
void *letter_flip(char *s);

int main()
{
    char s[20] = "Flip Me Now!";
    letter_flip(s);
    cout << s << endl;
    return 0;
}

/**
 * @brief Flip the letter in a string from lowercase to uppercase and uppercase
 * to lowercase.
 *
 * @param s The target string
 */
void *letter_flip(char *s)
{
    // while the pointer is not point to the null terminator
	for(char *p = s; *p != '\0'; p++)
    {
		// uppercase to lowercase
		if (*p >= 65 && *p<= 90)          *p += 32;
        // lowercase to uppercase
        else if (*p >= 97 && *p<= 122)    *p -= 32;
	}
}