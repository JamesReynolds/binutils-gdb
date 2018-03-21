// From: https://gcc.gnu.org/wiki/Dwarf2EHNewbiesHowto
#include <stdio.h>


void f ()
{
  printf (" in f()\n");
  throw 1;
}


main() {
  try {
  printf(" before throw\n");
    f();
  }
  catch (...) {
  printf(" in catch\n");
    return 0;
  }
  printf(" back in main\n");
return 10;
}
