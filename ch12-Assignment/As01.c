#include <stdio.h>
#include <string.h>

int Execusion();

int main()
{
    Execusion();
    return 0;
}

int Execusion()
{
    const char BASEPATH[256] = "C:\\Users\\jmk54\\OneDrive\\Desktop\\txt\\";
    char filename[100];
    char fullpath[256];

    FILE* fp = NULL;
    char buffer[256];
    int line_num = 1;

    printf("파일이름? ");

    scanf_s("%99s", filename, 100);

    snprintf(fullpath, sizeof(fullpath), "%s%s", BASEPATH, filename);


    if (fopen_s(&fp, fullpath, "r") != 0) 
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) 
    {
        printf("%d: %s", line_num, buffer);
        line_num++;
    }

    fclose(fp);

    return 0;
}