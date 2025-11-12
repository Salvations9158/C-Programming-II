#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

int ExecuteFileStorage();
int GenerateAndSaveNumbers(int N, const char* base_filename);
void ClearInputBuffer();

int main()
{
    ExecuteFileStorage();
    return 0;
}
int ExecuteFileStorage()
{
    int num_count;
    char filename[100];

    srand((unsigned int)time(NULL));

    printf("정수의 개수 N? ");
    if (scanf_s("%d", &num_count) != 1 || num_count <= 0) {
        printf("오류: 유효한 정수 개수를 입력해야 합니다.\n");
        ClearInputBuffer();
        return 1;
    }
    ClearInputBuffer();

    printf("파일명? ");
    if (scanf_s("%99s", filename, 100) != 1) {
        printf("오류: 파일 이름 입력 실패.\n");
        ClearInputBuffer();
        return 1;
    }

    if (GenerateAndSaveNumbers(num_count, filename) != 0) {
        return 1;
    }

    printf("\n%s.txt와 %s.dat 파일을 생성했습니다.\n", filename, filename);

    return 0;
}

int GenerateAndSaveNumbers(int N, const char* base_filename)
{
    const char BASEPATH[256] = "C:\\Users\\jmk54\\OneDrive\\Desktop\\txt\\";
    char fullpath_txt[256];
    char fullpath_dat[256];

    int* numbers = NULL;
    int success = 0;

    numbers = (int*)malloc(N * sizeof(int));
    if (numbers == NULL) {
        printf("오류: 동적 메모리 할당에 실패했습니다.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 1000;
    }

    snprintf(fullpath_txt, sizeof(fullpath_txt), "%s%s.txt", BASEPATH, base_filename);
    snprintf(fullpath_dat, sizeof(fullpath_dat), "%s%s.dat", BASEPATH, base_filename);

    FILE* fp_txt = NULL;
    if (fopen_s(&fp_txt, fullpath_txt, "w") != 0) {
        printf("오류: 텍스트 파일을 열 수 없습니다.\n");
        success = 1;
        goto cleanup;
    }

    for (int i = 0; i < N; i++) {
        fprintf(fp_txt, "%d ", numbers[i]);
    }
    fclose(fp_txt);

    FILE* fp_dat = NULL;
    if (fopen_s(&fp_dat, fullpath_dat, "wb") != 0) {
        printf("오류: 2진 파일을 열 수 없습니다.\n");
        success = 1;
        goto cleanup;
    }

    size_t written_count = fwrite(numbers, sizeof(int), N, fp_dat);

    if (written_count != N) {
        printf("경고: 2진 파일에 모든 데이터를 저장하지 못했습니다 (저장된 개수: %zu/%d).\n", written_count, N);
    }

    fclose(fp_dat);


cleanup:
    free(numbers);

    return success;
}

void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}