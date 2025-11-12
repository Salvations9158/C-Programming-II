#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_NAME_LEN 30
#define MAX_PHONE_LEN 15
#define MAX_CONTACTS 20
#define MAX_FILENAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char phoneNumber[MAX_PHONE_LEN];
} CONTACT;

int ExecuteContactManager_12();
int LoadContactsFromFile_12(const char* fullpath, CONTACT* contacts, int max_size);
void SearchAndRegisterContacts_12(CONTACT contacts[], int* count_ptr);
int SaveContactsToFile_12(const char* fullpath, const CONTACT* contacts, int count);
void ClearInputBuffer();

int main()
{
    ExecuteContactManager_12();
    return 0;
}

int ExecuteContactManager_12()
{
    const char BASEPATH[256] = "C:\\Users\\jmk54\\OneDrive\\Desktop\\txt\\";
    char filename[MAX_FILENAME_LEN];
    char fullpath[256];

    CONTACT contact_list[MAX_CONTACTS];
    int total_contacts = 0;

    printf("연락처 파일명? ");
    if (scanf_s("%99s", filename, MAX_FILENAME_LEN) != 1) {
        printf("오류: 파일 이름 입력에 실패했습니다.\n");
        ClearInputBuffer();
        return 1;
    }
    ClearInputBuffer();

    snprintf(fullpath, sizeof(fullpath), "%s%s", BASEPATH, filename);

    total_contacts = LoadContactsFromFile_12(fullpath, contact_list, MAX_CONTACTS);

    if (total_contacts < 0) {
        printf("파일을 열 수 없습니다. 빈 목록으로 시작\n");
        total_contacts = 0;
    }

    printf("%d개의 연락처를 로딩했습니다.\n", total_contacts);

    SearchAndRegisterContacts_12(contact_list, &total_contacts);

    SaveContactsToFile_12(fullpath, contact_list, total_contacts);

    return 0;
}

int LoadContactsFromFile_12(const char* fullpath, CONTACT* contacts, int max_size)
{
    FILE* fp = NULL;
    int count = 0;

    if (fopen_s(&fp, fullpath, "r") != 0) {
        return -1;
    }

    while (count < max_size &&
        fscanf_s(fp, "%s %s",
            contacts[count].name, (int)sizeof(contacts[count].name),
            contacts[count].phoneNumber, (int)sizeof(contacts[count].phoneNumber)) == 2)
    {
        count++;
    }

    fclose(fp);
    return count;
}


void SearchAndRegisterContacts_12(CONTACT contacts[], int* count_ptr)
{
    char search_name[MAX_NAME_LEN];
    char new_phone[MAX_PHONE_LEN];
    char add_choice;
    int found_index;

    while (1)
    {
        printf("이름(. 입력 시 종료)? ");
        if (scanf_s("%s", search_name, (int)sizeof(search_name)) != 1) {
            ClearInputBuffer(); continue;
        }
        if (strcmp(search_name, ".") == 0) break;

        found_index = -1;
        for (int i = 0; i < *count_ptr; i++)
        {
            if (strcmp(contacts[i].name, search_name) == 0)
            {
                found_index = i;
                break;
            }
        }

        if (found_index != -1)
        {
            printf("%s의 전화번호 %s로 전화를 겁니다....\n",
                contacts[found_index].name, contacts[found_index].phoneNumber);
        }
        else
        {
            printf("연락처를 찾을 수 없습니다. 연락처를 등록하시겠습니까 (y/n)? ");
            ClearInputBuffer();
            if (scanf_s(" %c", &add_choice, (int)sizeof(add_choice)) != 1) continue;
            add_choice = (char)tolower(add_choice);

            if (add_choice == 'y')
            {
                if (*count_ptr >= MAX_CONTACTS) {
                    printf("연락처 목록이 가득 찼습니다 (최대 %d개).\n", MAX_CONTACTS);
                    ClearInputBuffer(); continue;
                }

                printf("전화번호? ");
                if (scanf_s("%s", new_phone, (int)sizeof(new_phone)) != 1) {
                    ClearInputBuffer(); continue;
                }

                strcpy_s(contacts[*count_ptr].name, 30, search_name);
                strcpy_s(contacts[*count_ptr].phoneNumber, 30 , new_phone);
                (*count_ptr)++;
                printf("새 연락처 (%s: %s)가 성공적으로 등록되었습니다.\n", search_name, new_phone);
            }
        }
        ClearInputBuffer();
    }
}

int SaveContactsToFile_12(const char* fullpath, const CONTACT* contacts, int count)
{
    if (count == 0) return 0;

    FILE* fp = NULL;
    if (fopen_s(&fp, fullpath, "w") != 0) {
        printf("오류: 파일에 저장할 수 없습니다.\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %s\n", contacts[i].name, contacts[i].phoneNumber);
    }

    printf("%s로 %d개의 연락처를 저장했습니다.\n", fullpath, count);
    fclose(fp);
    return 0;
}

void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}