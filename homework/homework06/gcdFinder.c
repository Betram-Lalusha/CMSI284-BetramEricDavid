#include <stdio.h>
#include <assert.h>
extern int gcd(int num1, int num2);
int main(int argc, char *argv[]) {
   assert(gcd(6,3) == 3);
   assert(gcd(12, 2) == 2);
   assert(gcd(9,6) == 3);
   assert(gcd(100, 50) == 50);
   assert(gcd(5,1) == 1);
   assert(gcd(27,18) == 9);
   return 0;
}