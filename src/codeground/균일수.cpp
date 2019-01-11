#if 0

#include <cstdio>
#include <cstring>

int n, tcase, b;

int main(void){
    
    
    setbuf(stdout, NULL);
    
	scanf("%d", &tcase);

	for (int t = 1; t <= tcase; t++){


		scanf("%d", &n);


		b = 2;
		while (1){
		
			int tmp = n;
			int remain  = n % b ;
			while (tmp > 0){
				if (remain != (tmp %b) ) break;
				remain = tmp % b;
				tmp = tmp / b;
			}
			if (tmp == 0) break;
			
			b++;
		}

		printf("Case #%d\n", t);
		printf("%d\n", b);
	}
}


#endif