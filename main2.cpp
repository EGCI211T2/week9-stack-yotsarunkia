#include <iostream>
#include <cstring>
using namespace std;

#include "stack.h"

int main(int argc, char **argv)
{

  /*
    Exercise 2
   printf("Checking the parentheses in argv arguments\n");
  */
  int i, j;
  for (i = 1; i < argc; i++)
  {
    Stack s;
    for (j = 0; j < strlen(argv[i]); j++)
    {
      char c = argv[i][j];
      if (c == '[' || c == '{')
      {
        s.push(c);
      }
      else if (c == ']' || c == '}')
      {
        char x = s.pop();
        if (x == '(' && c != ')' ||
            x == '[' && c != ']' ||
            x == '{' && c != '}')
        {
          cout << argv[i] << " : Incorrect" << endl;
          j = strlen(argv[i]);
          break;
        }
        else if (x == '(' && c == ')' ||
                 x == '[' && c == ']' ||
                 x == '{' && c == '}')
        {
          if (j == strlen(argv[i]) - 1)
          {
            cout << argv[i] << " : Correct" << endl;
          }
          else
            continue;
        }
        else
        {
          cout << argv[i] << " : Incorrect" << endl;
          j = strlen(argv[i]);
          break;
        }
      }
      if (c == '{' || c == '[')
        {
          if (j==strlen(argv[i])-1)
          {
            cout << argv[i] << " : Incorrect" << endl;
            break;
          }
        }
    }
  }
  return 0;
}
