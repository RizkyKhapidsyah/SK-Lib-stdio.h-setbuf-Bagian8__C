#pragma warning(disable:4996)

#include <stdio.h>
#include <conio.h>

/*
    Source by Microsoft
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main(void) {
    char buf[BUFSIZ];
    FILE* stream1, * stream2;

    fopen_s(&stream1, "data1", "a");
    fopen_s(&stream2, "data2", "w");

    if ((stream1 != NULL) && (stream2 != NULL)) {
        // "stream1" uses user-assigned buffer:
        setbuf(stream1, buf); // C4996
        // Note: setbuf is deprecated; consider using setvbuf instead
        printf("stream1 set to user-defined buffer at: %Fp\n", buf);

        // "stream2" is unbuffered
        setbuf(stream2, NULL); // C4996
        printf("stream2 buffering disabled\n");
        _fcloseall();
    }

    _getch();
    return 0;
}