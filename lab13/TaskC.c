#include <stdio.h>
#include <locale.h>
#include <wchar.h>

const int standart = 4325504; //10000100000000010000000 - с,з,ц
const int sogl = 66567902; //Все согласные

int main(){
    
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wchar_t x;
    int cur_set = 0;
    while(wscanf(L"%lc", &x)!=EOF){ //Считывание символа
        if(x==' '){
            if((((cur_set & sogl) | standart)==standart) && ((cur_set & sogl)!=0)){ //Вывод ответа при разделителе
                wprintf(L"%s ", "YES");
            } 
            cur_set = 0;
            continue;
        }
        cur_set = cur_set | (1 << ((int)x - 1072)); //Внесение элемента в множество
    }
    return 0;
}