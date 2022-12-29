#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>

long double Function2(long double x); //Возвращает значение функции 2
long double Function3(long double x); //Возвращает значение функции 3

long double derivative(int Nf, long double x); //Возвращает значение  производной функции 2 или 3
long double LDabs(long double x); //Модуль для типа long double

int verify_iteration(); //Проверка на сходимость итерационного метода
long double iteration(long double a, long double b); //Решение итерационным методом

long double dihotomia(long double a, long double b); //Решение методом дихотомии

const double delta = 1.0e-15; //"Бесконечно малая" величина для машинного нуля

int main() {

	long double a, b;

	printf("Enter a b for iteration: ");
	scanf_s("%lf%lf", &a, &b);

	if (verify_iteration()) {
		printf("%lf\n", iteration(a, b));
	}
	else { printf("Function3 is not converge\n"); }

	printf("Enter a b for dihotomia: ");
	scanf_s("%lf%lf", &a, &b);

	printf("Function2 x is equal : %lf\nItself equal : %lf\n", dihotomia(a, b), Function2(dihotomia(1,2)));

	return 0;
}

long double Function2(long double Fx2) { return cos(Fx2) - pow(exp(1), -pow(Fx2, 2) / 2) + Fx2 - 1; }
long double Function3(long double Fx3) { return 1 - Fx3 + sin(Fx3) - log(1 + Fx3); }

long double derivative(int Nf, long double Derx) { 
	if (Nf == 2) { return (Function2(Derx + delta) - Function2(Derx)) / delta; }
	if (Nf == 3) { return (Function3(Derx + delta) - Function3(Derx)) / delta; }
}

long double LDabs(long double Absx) {
	if (Absx < 0) { return -Absx; }
	return Absx;
}

int verify_iteration() {
	for (long double i = 1; i <= 1.5; i += delta) { if (LDabs(derivative(3, i)) >= 1) { return 0; } }
	return 1;
}

long double iteration(long double Ia, long double Ib) {
	long double x = (Ia + Ib) / 2;
	long double temp = Function3(x);
	while (LDabs(temp - x) >= delta) {
		x = temp;
		temp = Function3(x);
	}
	return x;
}

long double dihotomia(long double Da, long double Db) {
	while (1) {
		if (Function2(Da) * Function2((Da + Db) / 2) > 0) { Da = (Da + Db) / 2; }
		else { Db = (Da + Db) / 2; }
		if (Db - Da < delta) { return (Da + Db) / 2; }
	}
}