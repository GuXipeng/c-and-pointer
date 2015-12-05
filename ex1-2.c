#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *ch;
	int cow = 1;
	while (gets(ch) != '\0'){
		printf("%d Input:%s\n", cow, *ch);
		cow++;
	}
	return 0;
}
