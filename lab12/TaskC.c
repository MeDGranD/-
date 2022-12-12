#include <stdio.h>
#include <assert.h>

long long IncrementChet(long long number){
    int negative = 0;
    if (number==0) { return 1; }
    if (number < 0) { number *= -1; negative = 1; }
    long long result = 0;
    long long R = 1;
    while(number>0){
        if ((number%10)%2 == 0){ result = result + ((number%10)+1)*R; }
        else { result += (number%10)*R; }
        R *= 10;
        number/=10;
    }
    if (negative) { return -result; }
    else { return result; }
}
void test(){ assert(IncrementChet(10)==11); }
int main(){
    test();
    long long number;
    while(scanf("%lli", &number)){ printf("%lli%c", IncrementChet(number), ' '); }
    return 0;
}