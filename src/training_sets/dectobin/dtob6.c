//#include <stdio.h>
//#include <stdlib.h>
int main(int argc, char *argv[]) 
{
	int n, num;
	scanf("%d", &num);
	n=num;
    char *s = malloc(sizeof(int) * 8);
    int i, c = 0;
    printf("%d\n", num);

    for (i = sizeof(int) * 8 - 1; i >= 0; i--) {
        n = num >> i;
        *(s + c) = (n & 1) ? '1' : '0';
        c++;
    }
    *(s + c) = NULL;
    printf("%s", s);
    return EXIT_SUCCESS;
}

