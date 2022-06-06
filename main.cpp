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

    fseek(in, 0, SEEK_END);
    long fsize = ftell(in);
    fseek(in, 0, SEEK_SET);

    char* chars = (char*)malloc(sizeof(char) * fsize);
    static char* result = (char*)malloc(sizeof(char) * (fsize / 4 + 5));

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
    }

    result[fsize / 4 + 1] = '\0';

    free(chars);

    return result;
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

    free(nums);

    fclose(in);

    std::cout << "\n\n";



    }//Конец.
