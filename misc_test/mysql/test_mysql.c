#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"

int main()
{
    int ret = 0;

    MYSQL * connect = NULL;
    connect = mysql_init(connect);
    if (connect == NULL)
    {
        ret = mysql_errno(connect);
        printf("mysql_init error, %s\n", mysql_error(connect));
        return ret;
    }
    printf("mysql_init ok...\n");

    connect = mysql_real_connect(connect, "localhost", "root", "123456", "mysql", 3306, NULL, 0);
    if (connect == NULL)
    {
        ret = mysql_errno(connect);
        printf("mysql_real_connect error, err is: %s\n", mysql_error(connect));
        return ret;
    }
    printf("mysql_real_connect ok...\n");

    const char * query = "select Host, User from user";
    ret = mysql_real_query(connect, query, strlen(query));
    if (ret != 0)
    {
        printf("mysql_query error\n");
        return ret;
    }

    MYSQL_RES * result = mysql_store_result(connect);
    if (result == NULL)
    {
        printf("mysql_store_result error\n");
        return -1;
    }

    int field_num = mysql_field_count(connect);
    int i = 0;

    //表头
    printf("\n------------------------------------------\n");
    MYSQL_FIELD * fields = mysql_fetch_fields(result);
    for (i= 0; i < field_num; i++)
    {
        printf("%-15s", fields[i].name);
    }
    printf("\n------------------------------------------\n");

    //表内容
    MYSQL_ROW row = NULL;
    while ((row = mysql_fetch_row(result)) != NULL)
    {
        for (i= 0; i < field_num; i++)
        {
            printf("%-15s", row[i]);
        }
        printf("\n");
    }

    mysql_free_result(result);//释放内存
    mysql_close(connect);
    printf("\nmysql_close...\n");

    return ret;
}
