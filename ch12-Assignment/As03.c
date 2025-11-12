#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ID_LEN 30
#define MAX_PW_LEN 30
#define MAX_USERS 10

typedef struct {
    char id[MAX_ID_LEN];
    char password[MAX_PW_LEN];
} LOGIN;

int ExecuteLoginSystem();
int LoadUsersFromFile(LOGIN* users, int max_users);
void ProcessLogin(const LOGIN* users, int user_count);
void ClearInputBuffer();

int main()
{
    ExecuteLoginSystem();
    return 0;
}

int ExecuteLoginSystem()
{
    LOGIN user_list[MAX_USERS];
    int loaded_users = 0;

    loaded_users = LoadUsersFromFile(user_list, MAX_USERS);

    ProcessLogin(user_list, loaded_users);

    return 0;
}

int LoadUsersFromFile(LOGIN* users, int max_users)
{
    const char BASEPATH[256] = "C:\\Users\\jmk54\\OneDrive\\Desktop\\txt\\";
    const char filename[] = "password.txt";
    char fullpath[256];
    FILE* fp = NULL;
    int count = 0;

    snprintf(fullpath, sizeof(fullpath), "%s%s", BASEPATH, filename);

    if (fopen_s(&fp, fullpath, "r") != 0)
    {
        printf("파일을 열 수 없습니다. 경로: %s\n", fullpath);
        return -1;
    }

    while (count < max_users &&
        fscanf_s(fp, "%s %s",
            users[count].id, (int)sizeof(users[count].id),
            users[count].password, (int)sizeof(users[count].password)) == 2)
    {
        count++;
    }

    fclose(fp);
    return count;
}

void ProcessLogin(const LOGIN* users, int user_count)
{
    char input_id[MAX_ID_LEN];
    char input_pw[MAX_PW_LEN];

    while (1)
    {
        printf("ID? ");

        if (scanf_s("%s", input_id, (int)sizeof(input_id)) != 1) {
            printf("오류: ID 입력 실패\n");
            ClearInputBuffer();
            continue;
        }

        if (strcmp(input_id, ".") == 0) {
            printf("로그인 시도를 종료합니다.\n");
            break;
        }

        int found_id_index = -1;
        for (int i = 0; i < user_count; i++)
        {
            if (strcmp(users[i].id, input_id) == 0)
            {
                found_id_index = i;
                break;
            }
        }

        if (found_id_index == -1)
        {
            printf("아이디를 찾을 수 없습니다.\n");
            ClearInputBuffer(); 
            continue;
        }

        printf("Password? ");
        if (scanf_s("%s", input_pw, (int)sizeof(input_pw)) != 1) {
            printf("오류: Password 입력 실패\n");
            ClearInputBuffer();
            continue;
        }

        if (strcmp(users[found_id_index].password, input_pw) == 0)
        {
            printf("로그인 성공\n");
        }
        else
        {
            printf("로그인 실패\n");
        }

        ClearInputBuffer(); 
    }
}


void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}