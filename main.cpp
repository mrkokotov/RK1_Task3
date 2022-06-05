//Поскольку проект читает файлы из своей папки, надо чтобы QT помещал exe файл в папку с файлами условий для заданий 1-3.

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QList>


typedef uint8_t Uint8;






const char value[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

char* task3(FILE* in)
{
    char c = 0;
    int length = 0;
    int count_hex=0;

    char chars[64];

    for(int i = 0; i < 63; ++i)
    {
        chars[i] = 0;
    }

    static char result[16];
    static char result1[16];

    while(fscanf(in, "%c", &c) != EOF)
    {
        chars[length] = c;
        length++;
    }

    for(int i = 0; i < length; i += 4)
    {
        int temp = 0;

        for(int j = 0; j < 4; ++j)
        {
            temp |= (((chars[i + j] == 0x30) ? 0 : 1) << j);
        }

        result[i / 4] = value[temp];
        count_hex++;
    }
    for(int k=0;k<count_hex;k++)
    {
        result1[k]=result[count_hex-1-k];
    }

    return result1;
}





int main()
{
    FILE* in;
    FILE* out;
//3 номер
    in = fopen("task3.txt", "r");

    char* nums = task3(in);

    nums[16] = '\0';

    std::cout << nums;

    fclose(in);

    std::cout << "\n\n";



    }//Конец.
