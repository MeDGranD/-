#include <stdio.h>
#include <assert.h>
#define N 10000


long long mas[N][N]; //Матрица
int eq[N]; //Матрица сумм для сравнения
int result[N]; //Матрица вывода столбцов

int Equal(int i, int j, long long Size){ //Функция сравнения двух столбцов 
    for(int g = 0; g < Size; g++) { if(mas[g][i]!=mas[g][j]) {return 0;}}
    return 1;
}

void test(){

    assert(Equal(1,2,4));
    mas[0][0] = 1;
    assert(!Equal(0,1,4));
    mas[0][0] = 0;

}

int main(){

    test();
    long long Size;
    scanf("%lli", &Size);
    for (int i = 0; i < Size; i++) { //Считывание матрицы
        for (int j = 0; j < Size; j++) {
            scanf("%lli", &mas[i][j]);
            eq[j]+=mas[i][j];
        }
    }
    for (int i = 0; i < Size; i++) { //Поиск и сравнение одинаковых столбцов матрицы
        for (int j = i+1; j < Size; j++) {
            if (eq[i]==eq[j]) { if(Equal(i, j, Size)){ result[j] = -1; } }
        }
    }
    for(int i = 0; i < Size*Size; i++){ //Вывод конечной матрицы
        if(i%Size==Size-1){printf("\n");}
        if(result[i%Size]==-1){continue;}
        printf("%lli ", mas[i/Size][i%Size]);
    }

    return 0;
}