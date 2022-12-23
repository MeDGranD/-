#include <stdio.h>
#include <assert.h>
#define Size 3

long long mas[Size][Size]; //Матрица
int eq[Size]; //Матрица сумм для сравнения
int result[Size]; //Матрица вывода столбцов

int Equal(int i, int j){ //Функция сравнения двух столбцов 
    for(int g = 0; g < Size; g++) { if(mas[g][i]!=mas[g][j]) {return 0;}}
    return 1;
}

void test(){

    assert(Equal(1,2));
    mas[0][0] = 1;
    assert(!Equal(0,1));
    mas[0][0] = 0;

}

int main(){

    test();

    for (int i = 0; i < Size; i++) { //Считывание матрицы
        for (int j = 0; j < Size; j++) {
            scanf("%lli", &mas[i][j]);
            eq[j]+=mas[i][j];
        }
    }
    for (int i = 0; i < Size; i++) { //Поиск и сравнение одинаковых столбцов матрицы
        for (int j = i+1; j < Size; j++) {
            if (eq[i]==eq[j]) { if(Equal(i, j)){ result[j] = -1; } }
        }
    }
    for(int i = 0; i < Size*Size; i++){ //Вывод конечной матрицы
        if(i%Size==Size-1){printf("\n");}
        if(result[i%Size]==-1){continue;}
        printf("%lli ", mas[i/Size][i%Size]);
    }

    return 0;
}