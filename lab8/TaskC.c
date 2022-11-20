#include <stdio.h>
int Min(int x, int y){		//‘ункци€ дл€ сравнени€ двух чисел и нахождени€ минимального из них.
 if (x <= y) { return x; }
 else { return y; }
}
int main() {

 int count; //ѕеременна€ дл€ хранени€ количества данных.
 scanf_s("%i", &count);
 int remainders2[3] = { 100000000, 100000000, 100000000 }; //ћассив первых трех минимальных чисел с остатком 2 от делени€ на 3.
 int remainders0 = 100000000;							   //ѕеременна€ дл€ хранени€ минимального числа с остатком 0 от делени€ на 3.
 int remainders1[3] = { 100000000, 100000000, 100000000 }; //ћассив первых трех минимальных чисел с остатком 1 от делени€ на 3.
 int current_number;

 for (int i = 0; i < count; i++) {
  scanf_s("%i", &current_number); //—читывание числа

  if (current_number % 3 == 0) { remainders0 = min(current_number, remainders0); } //ѕроверка: €вл€етьс€ ли число минимальным с остатком 0? и присвоение переменной минимального числа его значени€.

  if (current_number % 3 == 1) {
   if (current_number < remainders1[0]) { remainders1[2] = remainders1[1]; remainders1[1] = remainders1[0]; remainders1[0] = current_number; } //ѕроверка: €вл€етьс€ ли число в тройке минимальных с отстком 1?
   else if (current_number < remainders1[1]) { remainders1[2] = remainders1[1]; remainders1[1] = current_number; }							   //и последующа€ подстановка числа в массив минимальных чисел.
   else if (current_number < remainders1[2]) { remainders1[2] = current_number; }
  }

  if (current_number % 3 == 2) {
   if (current_number < remainders2[0]) { remainders2[2] = remainders2[1]; remainders2[1] = remainders2[0]; remainders2[0] = current_number; } //ѕроверка: €вл€етьс€ ли число в тройке минимальных с отстком 2?
   else if (current_number < remainders2[1]) { remainders2[2] = remainders2[1]; remainders2[1] = current_number; }							   //и последующа€ подстановка числа в массив минимальных чисел.
   else if (current_number < remainders2[2]) { remainders2[2] = current_number; }
  }
 }
 printf("%i" , Min(Min(remainders1[0]+ remainders1[1]+ remainders1[2], (remainders1[0] + remainders2[0] + remainders0)), remainders2[0]+ remainders2[1]+ remainders2[2])); //¬ывод минимального из трех возможных сумм.
 return 0;
}