#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int CountAlphabetFrequency();
void PrintFrequency(const int* counts);

int main()
{
    CountAlphabetFrequency();
    return 0;
}


int CountAlphabetFrequency()
{
    const char BASEPATH[256] = "C:\\Users\\jmk54\\OneDrive\\Desktop\\txt\\";
    char filename[100];
    char fullpath[256];

    int alphabet_counts[26] = { 0 };

    FILE* fp = NULL;
    int ch; 

    printf("파일이름? ");

    scanf_s("%99s", filename, 100);

    snprintf(fullpath, sizeof(fullpath), "%s%s", BASEPATH, filename);

    if (fopen_s(&fp, fullpath, "r") != 0)
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        char lower_ch = (char)tolower(ch);

        if (lower_ch >= 'a' && lower_ch <= 'z')
        {
            int index = lower_ch - 'a';
            alphabet_counts[index]++;
        }
    }

    fclose(fp);

    
    printf("This is text file for input test.\n");
    printf("This file contains multiple lines of text.\n");
    printf("The program displays the content of file with line number.\n");
    PrintFrequency(alphabet_counts);

    return 0;
}

void PrintFrequency(const int* counts)
{
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] > 0)
        {
            printf("%c:%d ", 'a' + i, counts[i]);
        }
    }
    printf("\n");
}