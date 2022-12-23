#include <stdio.h>
#define N 3 //Размер матрицы

long long mas[N][N]; //Матрица

int main() {

	long long start = N * (N - 1); //Начальный элемент вывода матрицы
	long long kol = 0; //Счетчик выведенных элементов

	for (int i = 0; i < N * N; i++) { scanf("%lli", &mas[i/N][i%N]); } //Считывание матрицы

	while (1){
		
		while (start / N != start % N) { printf("%lli ", mas[start / N][start % N]); start -= N; kol++; if (kol == N * N) break; } // { Вывод; Изменение start; Инкремент kol; ПРоверка на конец матрицы; }
		if (kol == N * N) { break; }
		while (start % N != N - start / N - 1) { printf("%lli ", mas[start / N][start % N]); start++; kol++; if (kol == N * N) break; } //Конец прохода "Влево"
		if (kol == N * N) { break; }

		while (start % N != start / N) { printf("%lli ", mas[start / N][start % N]); start += N; kol++; if (kol == N * N) break; }
		if (kol == N * N) { break; }
		while (start % N != N - start / N) { printf("%lli ", mas[start / N][start % N]); start--; kol++; if (kol == N * N) break; } //Конец прохода "Вправо"
		if (kol == N * N) { break; }
	}

	return 0;
}