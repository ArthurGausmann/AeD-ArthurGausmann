#include <stdio.h>

// 3 = Fizz, 5 = Buzz, 3&5 = FizzBuzz

void main() {
    for ( int i = 1; i <= 100; i++ ) {
        int num = i;
        if ( (num % 3) == 0 && (num % 5) == 0){
            printf( "FizzBuzz!\n" );
        } else if ( (num % 3) == 0) {
            printf( "Fizz!\n" );
        } else if ( (num % 5) == 0) {
            printf( "Buzz!\n" );
        } else {
            printf("%d\n", num);
        }
    };
}