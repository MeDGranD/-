#include <stdio.h>
#include <assert.h>

typedef enum {
    Search, //Состояние поиска разделителя
    Separator, //Состояние проверки следующего за разделителем символа (число или нет?)
    Number, //Состояние считывания целой части числа
    Dot, //Состояние считывания дробной части числа
    EndNumber //Состояние проверки на следующий за C символ (разделитель или нет) и вывод ответа
} State;

int is_number (char c){ 
    if(('0'<=c)&&(c<='9')){ return 1; } 
    return 0; 
}

int is_C (char c){ 
    if(c=='C'){ return 1; } 
    return 0; 
}

int is_separator(char c){ 
    if((c==' ')||(c=='\n')||(c==',')||(c=='\t')){ return 1; } 
    return 0; 
}

int is_dot(char c){ 
    if(c=='.'){ return 1; } 
    return 0; 
}

int is_minus(char c){
    if(c=='-'){ return 1; }
    return 0;
}

void test(){

    assert(is_number('0'));
    assert(is_C('C'));
    assert(is_separator(' '));
    assert(is_dot('.'));
    assert(is_minus('-'));

    assert(!is_number('C'));
    assert(!is_C('1'));
    assert(!is_separator('/'));
    assert(!is_dot('g'));
    assert(!is_minus('+'));

}

int main(){

    test();

    double temp, dot, z; //Температура (целая часть), дробная часть, кол-во разрядов в dot
    dot = temp = z = 0;
    int negative = 0;
    char c;

    State state = Separator;

    while((c=getchar())!=EOF){

        switch (state){

            case Search:
                if(is_separator(c)){ state = Separator; } //Поиск разделителя
                break;

            case Separator:
                if(is_number(c)){ //Проверка на число
                    temp = (c - '0'); 
                    state = Number; 
                }
                else if(is_minus(c)){
                    negative = 1;
                    state = Number;
                }
                else { state = Search; }
                break;

            case Number:
                if(is_number(c)){ //Считывание числа
                    temp *= 10; 
                    temp += (c - '0'); 
                }
                else if(is_C(c)){ //Окончание числа
                    if(negative) { temp = -(temp*18/10) + 32; }
                    else { temp = temp*18/10 + 32; }
                    negative = 0;
                    state = EndNumber; 
                }
                else if(is_dot(c)){ //Проверка на наличие дробной части
                    temp = temp*18/10 + 32; 
                    z = 10; dot = 0; 
                    state = Dot; 
                }
                else { state = Search; }
                break;

            case EndNumber:
                if(is_separator(c)){ //Проверка на полноценность слова
                    printf("%g%c%c", temp, 'F', ' ');
                    temp = 0;
                    dot = 0;
                    state = Separator; 
                }
                else { state = Search; }
                break;

            case Dot:
                if(is_number(c)){ //Считывание дробной части
                    z*=10;  
                    dot *= 10; 
                    dot += (c - '0'); 
                }
                else if(is_C(c)){ //Проверка на окончание слова
                    dot = dot*18;
                    temp += dot/z;
                    if(z==10){ state = Search; } //Проверка на наличие дробной части
                    else { state = EndNumber; }
                }
                else { state = Search; }
                break;
        }
    }
    return 0;
}