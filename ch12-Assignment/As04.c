#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_PHONE_LEN 15
#define MAX_CONTACTS 20
#define MAX_FILENAME_LEN 100 


typedef struct {
    char name[MAX_NAME_LEN];
    char phoneNumber[MAX_PHONE_LEN];
} CONTACT;


int ExecuteContactManager_11();
int LoadContactsFromFile_11(const char* fullpath, CONTACT* contacts, int max_size);
void SearchContacts_11(const CONTACT* contacts, int count);
void ClearInputBuffer();

int main()
{
    ExecuteContactManager_11();
    return 0;
}


int ExecuteContactManager_11()
{
    const char BASEPATH[256] = "C:\\Users\\jmk54\\OneDrive\\Desktop\\txt\\";
    char filename[MAX_FILENAME_LEN];
    char fullpath[256];

    CONTACT contact_list[MAX_CONTACTS];
    int total_contacts = 0;

    printf("연락처 파일명? ");
    if (scanf_s("%99s", filename, MAX_FILENAME_LEN) != 1) {
        printf("파일 이름 입력에 실패했습니다.\n");
        ClearInputBuffer();
        return 1;
    }
    ClearInputBuffer();

    snprintf(fullpath, sizeof(fullpath), "%s%s", BASEPATH, filename);

    total_contacts = LoadContactsFromFile_11(fullpath, contact_list, MAX_CONTACTS);

    if (total_contacts < 0) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    printf("%d개의 연락처를 로딩했습니다.\n", total_contacts);

    SearchContacts_11(contact_list, total_contacts);

    return 0;
}

int LoadContactsFromFile_11(const char* fullpath, CONTACT* contacts, int max_size)
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

void SearchContacts_11(const CONTACT* contacts, int count)
{
    char search_name[MAX_NAME_LEN];
    int found_index;

    while (1)
    {
        printf("이름(. 입력 시 종료)? ");
        if (scanf_s("%s", search_name, (int)sizeof(search_name)) != 1) {
            ClearInputBuffer(); continue;
        }
        if (strcmp(search_name, ".") == 0) break;

        found_index = -1;
        for (int i = 0; i < count; i++)
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
            printf("연락처를 찾을 수 없습니다.\n");
        }
        ClearInputBuffer();
    }
}

void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}