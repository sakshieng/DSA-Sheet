// creating a bool using enum
//one enum will be created as bool then put elements as tru or false resp.
#include <stdio.h>
  
// Declaration of enum
typedef enum { F, T } boolean;
  
int main()
{
    boolean bool1, bool2;
    bool1 = F;
  
    if (bool1 == F) {
        printf("bool1 is false\n");
    }
    else {
        printf("bool1 is true\n");
    }
    bool2 = 2;
    if (bool2 == F) {
        printf("bool2 is false\n");
    }
    else {
        printf("bool2 is true\n");
    }
}