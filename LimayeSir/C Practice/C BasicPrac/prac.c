#include <stdio.h>

int main(void) {
	// your code goes 
	char r,b,g;
	char a;
	scanf("%c%c%c%c",&a,&b,&r,&g);
	if(a=='b&&r'|| a=='r&&b'|| a=='g&&r'||a=='r&&g'||a=='r&&r')
	printf("\nr");
	else
	if(a=='b&&b'||a=='b&&g'||a=='g&&b')
	printf("\nb");
	else
	if(a=='g&&g')
	printf("\ng");
	printf("%c%c%c",r,b,g);
	return 0;
}
