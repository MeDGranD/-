#include <stdio.h>
int Min(int x, int y){		//������� ��� ��������� ���� ����� � ���������� ������������ �� ���.
 if (x <= y) { return x; }
 else { return y; }
}
int main() {

 int count; //���������� ��� �������� ���������� ������.
 scanf_s("%i", &count);
 int remainders2[3] = { 100000000, 100000000, 100000000 }; //������ ������ ���� ����������� ����� � �������� 2 �� ������� �� 3.
 int remainders0 = 100000000;							   //���������� ��� �������� ������������ ����� � �������� 0 �� ������� �� 3.
 int remainders1[3] = { 100000000, 100000000, 100000000 }; //������ ������ ���� ����������� ����� � �������� 1 �� ������� �� 3.
 int current_number;

 for (int i = 0; i < count; i++) {
  scanf_s("%i", &current_number); //���������� �����

  if (current_number % 3 == 0) { remainders0 = min(current_number, remainders0); } //��������: ��������� �� ����� ����������� � �������� 0? � ���������� ���������� ������������ ����� ��� ��������.

  if (current_number % 3 == 1) {
   if (current_number < remainders1[0]) { remainders1[2] = remainders1[1]; remainders1[1] = remainders1[0]; remainders1[0] = current_number; } //��������: ��������� �� ����� � ������ ����������� � ������� 1?
   else if (current_number < remainders1[1]) { remainders1[2] = remainders1[1]; remainders1[1] = current_number; }							   //� ����������� ����������� ����� � ������ ����������� �����.
   else if (current_number < remainders1[2]) { remainders1[2] = current_number; }
  }

  if (current_number % 3 == 2) {
   if (current_number < remainders2[0]) { remainders2[2] = remainders2[1]; remainders2[1] = remainders2[0]; remainders2[0] = current_number; } //��������: ��������� �� ����� � ������ ����������� � ������� 2?
   else if (current_number < remainders2[1]) { remainders2[2] = remainders2[1]; remainders2[1] = current_number; }							   //� ����������� ����������� ����� � ������ ����������� �����.
   else if (current_number < remainders2[2]) { remainders2[2] = current_number; }
  }
 }
 printf("%i" , Min(Min(remainders1[0]+ remainders1[1]+ remainders1[2], (remainders1[0] + remainders2[0] + remainders0)), remainders2[0]+ remainders2[1]+ remainders2[2])); //����� ������������ �� ���� ��������� ����.
 return 0;
}