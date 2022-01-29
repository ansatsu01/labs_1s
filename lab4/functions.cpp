#include "functions.h"
#include <iostream>

const char *my_strstr(const char *a, const char *b)  //task A
{
    for (int i = 0; a[i] != '\0'; i++) {
        int tem = i;
        int j = 0;
        while (a[i++] == b[j++]) {
            if (b[j] == '\0') {
                return &a[tem];
            }
        }
        i = tem;
    }

    return NULL;
}


bool isVowel(char a) {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' ||
        a == 'U')
        return true;
    return false;
}

bool HalfOfLettersInTheWordAreVowels(char *str, int begin, int end) {
    int length = end - begin + 1;
    int num = 0;
    for (int i = begin; i <= end; i++)
        if (isVowel(str[i]))
            num++;
    return length == 2 * num;
}

bool doesConsistOnlyOfLatin(char *str, int begin, int end) {
    if (begin > end)
        return false;

    for (int i = begin; i <= end; ++i)
        if (str[i] < 'a' || str[i] > 'z')
            if (str[i] < 'A' || str[i] > 'Z')
                return false;
    return true;
}


int strlength(char *line) {
    int i = 0;
    while (line[i] != '\0') { i++; }
    return i + 1;
}

int SearchOfLatinWords(char *line) {

    int length = strlength(line);

    int begin = 0;
    int end = 0;
    int numberVow = 0;
    int num = 0;

    for (int i = 0; i < length; ++i) {
        if ((line[i] == ' ') || (line[i] == '\0')) {
            end = i - 1;
            if (doesConsistOnlyOfLatin(line, begin, end)) {
                num++;
                if (HalfOfLettersInTheWordAreVowels(line, begin, end))
                    numberVow++;
            }
            begin = i + 1;
        }
    }
    return num;
}

int NumOfWordsWhereHalfAreVowels(char *line) {

    int length = strlength(line);

    int begin = 0;
    int end = 0;
    int numberVow = 0;
    int num = 0;

    for (int i = 0; i < length; ++i) {
        if ((line[i] == ' ') || (line[i] == '\0')) {
            end = i - 1;
            if (doesConsistOnlyOfLatin(line, begin, end)) {
                num++;
                if (HalfOfLettersInTheWordAreVowels(line, begin, end))
                    numberVow++;
            }
            begin = i + 1;
        }
    }
    return numberVow;
}

