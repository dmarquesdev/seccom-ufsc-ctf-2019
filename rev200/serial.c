#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Serial: F4A23-B05C6-CC94A-B2458
// Flag: WHY_S0_S3R14L_H4HA_L33T_THE_FUN_B3GIN

void errorMsg() {
    printf("Wrong serial!\n");
    exit(0);
}

int i(char a) {
    if (a >= '0' && a <= '9') {
        return atoi(&a);
    } else if (a >= 'A' && a <= 'F') {
        return a - 'A' + 10;
    } else {
        exit(0);
    }
}

int main() {
    char serial[23];
    printf("Welcome to our system!\n");
    printf("Please input your serial to activate your software: ");
    fgets(serial, 24, stdin);

    if(strlen(serial) < 23) errorMsg();

    if(serial[5] != '-' || serial[11] != '-' || serial[17] != '-') errorMsg();
    if (serial[0] != 'F') errorMsg(); //F
    if (i(serial[1]) != i(serial[3]) * 2) errorMsg(); //4 = 2 * 2
    if (serial[2] != 'A') errorMsg(); // A
    if (serial[3] != serial[19]) errorMsg(); // 2 = 2
    if (i(serial[4]) > 2 && i(serial[4]) < 4) errorMsg(); // 3 > 2 & 3 < 4
    if (serial[6] != i(serial[2]) + 1) errorMsg(); // B = B
    if (serial[7] != '0') errorMsg(); // 0
    if (i(serial[8]) * 2 != i(serial[2])) errorMsg(); // 5 * 2 = A
    if (i(serial[9]) != i(serial[0]) - 3) errorMsg(); // C = F - 3
    if (serial[9] != serial[12] || serial[9] != serial[13]) errorMsg(); // C = C
    if (i(serial[10]) != i(serial[4]) * 2) errorMsg(); // 6 = 3 * 2
    if (i(serial[14]) != i(serial[7]) + 9) errorMsg(); // 9 = 9
    if (serial[15] != serial[1]) errorMsg(); // 4 = 4
    if (i(serial[16]) != i(serial[18]) - 1) errorMsg(); // A = B - 1
    if (i(serial[18]) != i(serial[7]) + i(serial[6])) errorMsg(); // B = 0 + B
    if (serial[19] != '2') errorMsg(); // 2
    if (i(serial[20]) != i(serial[3]) + i(serial[19])) errorMsg(); //4 = 2 + 2
    if (i(serial[21]) != i(serial[14]) - i(serial[15])) errorMsg(); // 5 = 9 - 4
    if (i(serial[22]) != i(serial[20]) << 1) errorMsg(); // 8 = 4 << 2

    char decoded[37] = "\x11\x7c\x18\x6d\x60\x1d\x1d\x63\x06\x11\x07\x19\x0f\x1c\x71\x00\x09\x6c\x1d\x7e\x07\x06\x6c\x19\x60\x09\x77\x6c\x6b\x17\x7e\x6a\x01\x05\x6a\x0a\x0d";
    int i;

    for (i = 0; i < sizeof(decoded); i++) {
        decoded[i] ^= serial[i % sizeof(serial)];
    }

    printf("Flag: SECCOM-2019{%s}\n", decoded);
}