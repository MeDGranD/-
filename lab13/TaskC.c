#include <stdio.h>
#include <locale.h>
#include <wchar.h>

const int standart = 4325504; //10000100000000010000000 - с,з,ц

int main(){
    
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wchar_t x;
    int cur_set = 0;
    while(wscanf(L"%lc", &x)!=EOF){
        if(x==' '){
            if((cur_set & standart)==standart){
                wprintf(L"%s ", "YES");
            } 
            cur_set = 0;
            continue;
        }
        cur_set = cur_set | (1 << ((int)x - 1072));
    }
    return 0;
}