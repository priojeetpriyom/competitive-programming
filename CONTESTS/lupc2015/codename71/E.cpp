#include <stdio.h>

int main()
{
	int i, h, a, cnt, t;

	scanf("%d", &t);
	while(t--){
			cnt = 0;
		scanf("%d%d", &h, &a);
		while(1){
		if(a <= 0 || h <= 0){
			break;
		}
		h = h + 3;
		a = a + 2;
		 //printf("%d %d\n", h, a);
		cnt++;
		if(a - 10 <= 0){
			h = h - 20 ;
			a = a + 5;
			if(h <= 0){
				break;
			}
			cnt++;

			//printf("%d %d\n", h, a);
		}
		else{
			h = h - 5;
			a = a - 10;
			if(a <= 0 || h <= 0){
			break;
		}
			cnt++;
			//printf("%d %d\n", h, a);
		}

		}
		printf("%d\n", cnt);
	}
	return 0;
}
