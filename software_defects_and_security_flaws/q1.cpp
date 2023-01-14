#include <string.h>
#include <cstdio>

#define pass "password"

int main()
{
   char isValidPass = 0;
   char buf[75];

   printf("Enter the password: \n");
   std::fgets(buf, 75, stdin);

   if (strcmp(buf, pass) == 0)
      isValidPass = 1;

   if (isValidPass == 1)
      printf("You have the correct password.\n");
}
