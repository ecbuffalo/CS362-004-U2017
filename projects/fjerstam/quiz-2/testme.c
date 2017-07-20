#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // ASCII range is 32 to 127. 127-32=95
    char c = rand() % 95;
    
    // Add 32 to get back to ASCII chars
    c += 32;
    return c;
}

char *inputString()
{
    int i;
    char c;
    int strLength = 6;
    char string[strLength];
    int range = 26; //26 letters
    
    i = 0;
    while(i < strLength-1) {
        c = rand() % range;
        c += 'a'; // move char to letters ASCII range
        string[i] = c;
        i += 1;
    }

    string[i] = '\0';
    char *s = string;
    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
