#include "ft_printf.h"
//#ifdef NUM
int main()
{
    setlocale(LC_ALL, "");

    int i = 0;
    int j = 0;
    // char a1 = 'a';
    // char a2 = 'a';

    char *ptr_c = (char*)malloc(sizeof(char));
    int ptr_i = 43;
    long ptr_l = 874748;

    //int nmb = 42;
    //char *s = 0;
    //wchar_t *b = L"ΘΘΘΘ";
    //int c = 945;
    printf("\n--------------------\n");

    i = ft_printf("|%s|", NULL);
    printf("\n");
    j = printf("|%s|", NULL);


    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);

    return (0);
}

// TITLE("Strings:\n");
// PRINTF("|%s|", NULL);
// PRINTF("|%s|", "ПрэвЭд!");
// PRINTF("|%s|\t","ç±³");
// TITLE("String options(field width, presicion and justification):\n");
// {
// const char A[] = "this is tEEEEst!";
// *****PRINTF("|%5.3s|\t\t|%3.5s|\t|%7s|\t|%7.3s|",A, A,A,NULL);
// *****PRINTF("|%07.5s|\t|%02.5s|\t|%.10s|\t\t|%.5s|\t",A,A,A, "");
// *****PRINTF("|%-7.5s|\t|%-2.5s|\t|%-.10s|\t\t|%-.5s|\t",A,A,A, "");
// *****PRINTF("|%-07.5s|\t|%-02.5s|\t|%-020s|\t|%-0.5s|\t",A,A,A, "");
// }