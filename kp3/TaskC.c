#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

long double Function(long double Fx); //������ ��� ������ ���������� �������
long long Factorial(int Fn); //������� ����������
long double sumT(int Sn, long double Sx); //������� �� ������� �������

long double eps = 1; //���������� ��������� ����
int i; //����������-������� ��������

void test() {

	assert(Factorial(2)==2);
	assert(Function(0)==0);
	assert(sumT(1, 0)==0);

}


int main() {

	while (LDBL_EPSILON != eps) { eps /= 2; } //���������� ��������� ����

	test();

	int n, k; //���-�� ������ �������, ���������� ��������
	long double a, b; //������ � ����� �������
	printf("Enter n k a b : ");
	scanf_s("%i%i%lf%lf", &n, &k, &a, &b);
	printf("x\t\tTaylor's Row\tFunction\titerations\n");

	long double x = a;

	for(int j = 0; j < 51; j++){

		printf("%lf\t%lf\t%lf\t%i\n", x, sumT(k, x), Function(x), i);
		x += (b - a) / n;

	}

	return 0;
}

long double Function(long double Fx) { return sin(Fx) * sin(Fx); }

long long Factorial(int Fn) { 

	if (Fn == 0) { return 1; } 
	return Fn*Factorial(Fn-1);

}

long double sumT(int Sk, long double Sx) {

	long double sum = 0;
	long double temp; 

	for (i = 1; 1; i++) {

		temp = (pow(-1, i - 1) * pow(2, 2 * i - 1) * pow(Sx, 2 * i)) / Factorial(2 * i);
		if (pow(-1, i - 1)*temp <= eps) { return sum; }
		sum += temp;

	}
	return sum;

}