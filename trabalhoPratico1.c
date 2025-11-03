/*
Trabalho Pratico 1 - Arthur Campello Gausmann

Leetcode 840.
*/

bool lemonadeChange(int* bills, int billsSize) {
    int nota5 = 0;
    int nota10 = 0;
    for ( int i = 0; i < billsSize; i++ ) {
        if ( bills[i] == 5 ) {
            nota5 += 1;
        } else if ( bills[i] == 10 ) {
            if ( nota5 > 0 ) {
                nota5 -= 1;
                nota10 += 1;
            } else {
                return false;
            }
        } else if (bills[i] == 20) {
            if ( nota5 > 0 && nota10 > 0 ) {
                nota5 -= 1;
                nota10 -= 1;
            } else if ( nota5 > 2 ) {
                nota5 -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}