#include <stdio.h>

int pt(int z)
{
	int cntp;
	for(; z > 0; z--){
		cntp = cntp * z;
	}
	return cntp;
}

int main()
{
	double a, d, i, j, cnt, x, y;
	int n, p;
	while(2 == scanf("%d%d", &n, &p)){
		cnt = 0;
		x = p/100;
		y = 1-(p/100);
		if(n % 3 == 0){
			d = n / 3;
			a = pt(d);
//			printf("%d\n", d);
			cnt = x * d;
	//		printf("%lf\n", cnt);

			for(i = 1, j = 1; i < d; i+=2, j++){
				cnt =cnt - (j*(2*x)) +  (3*y);
			}
			cnt = cnt * a;
		}
		if(n % 3 == 1){
			d = (n / 3) - 1;
		//	printf("%d\n", d);
		a = pt(d+1);
			cnt = (x * d) + (2*y);
						//printf("%lf\n", cnt);

			for(i = 1, j = 1; i < d; i+=2, j++){
				cnt = cnt - (j*x) +  (3*y);
			}
			cnt = cnt * a;
		}
		if(n % 3 == 2){
			d = (n / 3);
			//			printf("%d\n", d);
			a = pt(d+1);
			cnt = ((p/100) * d) + (1*(1-(p/100)));
				//		printf("%lf\n", cnt);

			for(i = 1, j = 1; i < d; i+=2, j++){
				cnt = cnt - (j*(2*(p/100))) +  ((3*(1-(p/100))));
			}
			cnt = cnt * a;
		}
		printf("%lf\n", cnt);
	}
	return 0;
}
