#include<stdio.h>
#include<stdlib.h>
/*
	Cong thuc y[n] = \sum_{k=-\infty}^{\infty} h[k] x[n-k]
*/

struct signal
{
	float *a;
	int n0, n; //n0 chi vi tri n=0, n la so luong phan tu cua array a
};

void Nhap(signal* sig, char c)
{
	
	loop1:
	printf("Tin hieu %c[] co bao nhieu xung? n = ",c);
	scanf("%d", &sig->n);
	if(sig->n<=0) 
	{
		printf("Nhap sai vui long nhap lai!\n");
		goto loop1;
	}
	sig->a = (float *)calloc(sig->n, sizeof(float));
	printf("Nhap xung %c[]: ", c);
	for(int i = 0; i<sig->n; i++)
	{
		scanf("%f", &sig->a[i]);
		
	}
	loop2:
	printf("n=0 cua %c[] o phan tu thu bao nhieu? k = ", c);
	scanf("%d", &sig->n0);
	if(sig->n0<0 || sig->n0 > sig->n)
	{
		printf("Nhap sai vui long nhap lai!\n");
		goto loop2;
	}
}
void Xuat(signal sig, char c)
{
	printf("\n%c[]: \n",c);
	for(int i=0; i<sig.n; i++)
	{
		printf("%10.1f|", sig.a[i]);
	}
	printf("\n");
	for(int i=0; i<sig.n0-1; i++)
	{
		printf("          |");
	}
	printf("n0");
	for(int i; i<sig.n-sig.n0-1; i++)
	{
		printf("          |");
	}
	printf("\n");
}
void conv(signal *sig, const signal H, const signal X)
{
	int e;
	float temp;
	sig->n= H.n + X.n -1;
	sig->a = (float *)calloc(sig->n, sizeof(float));
	for(int i =0; i<sig->n; i++)
	{
		e = i;
		temp = 0.0;
		for(int j=0; j<X.n; j++)
		{
			if(e>=0 && e<H.n)
			{
				temp = temp + (H.a[e]*X.a[j]);	
			}
			e--;
			sig->a[i]=temp;
		}
	}
	sig->n0=sig->n - ((X.n - X.n0 + (H.n - H.n0)));
}
int main()
{
	signal H;
	signal X;
	signal Y;
	Nhap(&H, 'H');
	Nhap(&X, 'X');
	Xuat(H, 'H');
	Xuat(X, 'X');
	conv(&Y, H, X);
	Xuat(Y, 'Y');
	return 0;
}
