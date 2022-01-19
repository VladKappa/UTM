#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
// Prototipul funcţiei integral
float integral(float, float, int, int, int);

const float e = 2.71828;

void main()
{
	float i, x0, xm;
	int m, x, a;

	system("cls");
	puts("Enter borders, power value and an integer");
	// Indicarea limitelor de integrare
	printf("x0= ");
	scanf("%f", &x0);
	printf("xm= ");
	scanf("%f", &xm);
	// Indicarea puterii
	printf("m= ");
	scanf("%d", &m);
	printf("x= ");
	scanf("%d", &x); // Indicarea coeficientului
	printf("a= ");
	scanf("%d", &x);
	/*apelul funcţiei recursive, pentru calcularea  integralei*/
	i = integral(x0, xm, m, a, x);
	// Afişarea rezultatelor pe ecran
	printf("I= %.3f", i);
	getch();
}

float integral(float a, float b, int n, int x, int k)
{
	if (n>=2)
	{
		return (pow(e, x*k)*pow(cos(k),n-1)*(x*cos(k)+n*sin(k))/(pow(x,2)+pow(n,2)))+(n*(n-1))/(pow(x,2)+pow(n,2))*integral(a, b, n - 2, x, k);
	}
	if (n == 1) // are loc apelul recursiv al funcţiei
		return (-pow(e,k*x)*(sin(k)*x*cos(k)))/(pow(k, 2)* pow(n,2));

	else if (n == 0) // condiţia de ieşire din recursie
		return pow(e,k*n)/k;
}
