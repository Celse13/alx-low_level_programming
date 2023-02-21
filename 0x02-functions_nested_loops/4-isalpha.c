#include "main.h"
/**
* _isalpha-check if char is lowercase
* run _isalpha-check.
* Return:1-if lowercase/uppercase,0-if not.
*/
int _isalpha(int c) {
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
return 1;
}
else {
return 0;
}
}



