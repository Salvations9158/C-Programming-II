#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ints(const void* a, const void* b)
{
    return (*(const int*)a - *(const int*)b);
}

int ExecuteMergeAndSort();
long GetFileSize(const char* fullpath);
int LoadBinaryFile(const char* fullpath, int* array_ptr, int start_index);
void ClearInputBuffer();

int main()
{
    ExecuteMergeAndSort();
    return 0;
}

int ExecuteMergeAndSort()
{
    const char BASEPATH[256] = "C:\\Users\\jmk54\\OneDrive\\Desktop\\txt\\";
    char file1_name[100], file2_name[100], output_name[100];
    char fullpath1[256], fullpath2[256], fullpath_out[256];

    int* merged_array = NULL;
    int count1 = 0, count2 = 0, total_count = 0;
    int success = 0; 

    printf("첫 번째 파일명? ");
    scanf_s("%99s", file1_name, 100);
    ClearInputBuffer();

    printf("두 번째 파일명? ");
    scanf_s("%99s", file2_name, 100);
    ClearInputBuffer();

    printf("저장할 파일명? ");
    scanf_s("%99s", output_name, 100);
    ClearInputBuffer();

    snprintf(fullpath1, sizeof(fullpath1), "%s%s", BASEPATH, file1_name);
    snprintf(fullpath2, sizeof(fullpath2), "%s%s", BASEPATH, file2_name);
    snprintf(fullpath_out, sizeof(fullpath_out), "%s%s", BASEPATH, output_name);

    long size1 = GetFileSize(fullpath1);
    long size2 = GetFileSize(fullpath2);

    if (size1 < 0 || size2 < 0) {
        return 1;
    }

    count1 = (int)(size1 / sizeof(int));
    count2 = (int)(size2 / sizeof(int));
    total_count = count1 + count2;

    if (total_count == 0) {
        printf("두 파일 모두 읽을 데이터가 없습니다.\n");
        return 1;
    }

    printf("정수 %d개를 읽었습니다.\n", count1);
    printf("정수 %d개를 읽었습니다.\n", count2);

    merged_array = (int*)malloc(total_count * sizeof(int));
    if (merged_array == NULL) {
        printf("동적 메모리 할당에 실패했습니다.\n");
        return 1;
    }


    if (LoadBinaryFile(fullpath1, merged_array, 0) != count1) {
        success = 1; goto cleanup;
    }
    if (LoadBinaryFile(fullpath2, merged_array, count1) != count2) {
        success = 1; goto cleanup;
    }

    qsort(merged_array, total_count, sizeof(int), compare_ints);

    FILE* fp_out = NULL;
    if (fopen_s(&fp_out, fullpath_out, "wb") != 0) {
        printf("오류: 출력 2진 파일을 열 수 없습니다.\n");
        success = 1; goto cleanup;
    }

    size_t written_count = fwrite(merged_array, sizeof(int), total_count, fp_out);
    if (written_count == total_count) {
        printf("정수 %d개를 저장했습니다.\n", total_count);
    }
    else {
        printf("저장된 데이터 개수가 불일치합니다 (%zu/%d).\n", written_count, total_count);
    }

    fclose(fp_out);

cleanup:
    free(merged_array);
    return success;
}

long GetFileSize(const char* fullpath)
{
    FILE* fp = NULL;
    long size = -1;

    if (fopen_s(&fp, fullpath, "rb") != 0) {
        printf("파일 (%s)을 열 수 없습니다.\n", fullpath);
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    fclose(fp);
    return size;
}

int LoadBinaryFile(const char* fullpath, int* array_ptr, int start_index)
{
    FILE* fp = NULL;
    int read_count = 0;

    long file_size = GetFileSize(fullpath);
    if (file_size < 0) return -1;
    int expected_count = (int)(file_size / sizeof(int));

    if (fopen_s(&fp, fullpath, "rb") != 0) {
        return -1;
    }

    read_count = (int)fread(array_ptr + start_index, sizeof(int), expected_count, fp);

    if (read_count != expected_count) {
        printf("파일 (%s)에서 예상치 못한 읽기 오류가 발생했습니다.\n", fullpath);
    }

    fclose(fp);
    return read_count;
}

void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}