#include <stdio.h>
int Abs(int x) {			//Функция, возвращающая модуль выражения.
 if (x >= 0) { return x; }
 else { return -x; }
}
int Min(int x, int y) {		//Функция, возвращающая минимум двух чисел.
 if (x >= y) { return y; }
 else { return x; }
}
int Max(int x, int y) {		//Функция, возвращающая максимум двух чисел.
 if (x >= y) { return x; }
 else { return y; }
}
int Sign(int x) {			//Функция, возвращающая знак выражения.
 if (x >= 0) { return 1; }
 else { return -1; }
}
int main() {
 int i = -25;	//Начальные данные
 int j = -9;
 int l = -8;
 int i1, i2, g; // i2 - переменная, хранящая в себе значение левой границы по i для соответвующего j, i1 соответсвенно для правой границы. g - переменная для хранения текущей иттерации (в задании k).
 for (g = 1; g < 51; g++) {
  int i0 = i;	//Создание копии для последующей подстановки в выражения для исключения изменений.
  int j0 = j;
  int l0 = l;
  i = ((abs(i0 - j0) * l0 - abs(j0 - l0) * i0 + abs(i0 - l0) * j0) % 20) - g + 1; //Вычисление соответсвующих изменений.
  j = (min(i0, j0) * max(j0, l0) * min(i0, l0)) % 25 + 5 * sign(i0) + g - 1;
  l = abs(l0) * sign(i0 - j0) - abs(i0) * sign(j0 - l0) + abs(j0) * sign(i0 - l0);
  i1 = -10 - j;
  i2 = -20 - j;
  if ((i2 <= i) && (i <=i1)) { printf("%s%c%s%i%c%s%i%c%i%c%i", "Hitted!", '\n', "Time is ", g, '\n', "Coordinates and parameter (i, j, l) = ", i, ' ', j, ' ', l); return 0; }
 }
 printf("%s%c%s%i%c%s%i%c%i%c%i", "Missed!", '\n', "Time is ", g, '\n', "Coordinates and parameter (i, j, l) = ", i, ' ', j, ' ', l);
 return 0;
}