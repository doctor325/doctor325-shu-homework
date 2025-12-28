#include<stdio.h>

int  main()
{
	int n; 
	int result;

	while(1){
        printf("please input a number: ");  
        scanf("%d", &n);               		
        if (n == 1){ 
			return -1;
		}

		result = 	(n*n*n*n+2*n*n*n+3*n*n+2*n)/8;

		printf("calcu result : %d\n", result);

	}

	return 0;
}