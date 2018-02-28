#include<stdio.h>
void InputSignal(float a[], int &nH0, int nH)
{
	printf("Nhap tin hieu: \n");
	for(int i=0; i<nH; i++)
	{
		
		scanf("%f", &a[i]);
	}
	printf("n0 tai phan tu thu may (n0 > 0):  ");
	scanf("%d", &nH0);
}
void ShowSignal(float a[], int nH0, int nH)
{
	for(int i=0; i<nH; i++)
	{
		printf("%.3f  ", a[i]);
	}
	printf("\n");
	for(int i=0; i<nH0-1; i++)
	{
		printf("       ");
	}
	printf("n0");
}
void DaoXung(float a[], float H[], int nH, int &n0, int nH0)
{
	int count = 0;
   for(int i = nH-1; i >= 0; i--)
   {
   		a[count]= H[i];
   		count++;
   }
   	n0 = nH + 1 - nH0;
   	
}
int main()
{
	/*
	nH la so xung cua TH H
	nH0 la vi tri n0 cua TH H
	
	*/
	printf("H[n] co bao nhieu xung? ");
	int nH, nH0;
	scanf("%d", &nH);
	fflush(stdin);
	float H[nH], H1[nH];
	InputSignal(H, nH0, nH);
	ShowSignal(H, nH0, nH);
	printf("\n");
	
	int nDao0;
	DaoXung(H1, H, nH, nDao0, nH0);
	ShowSignal(H1, nDao0, nH);
	return 0;
}
