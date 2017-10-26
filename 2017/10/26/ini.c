//
// Created by zhangrongxiang on 2017/10/26 10:27
// File ini
//

/**********************************************************************
* 文件名称：GetConfig.c
* 内容摘要：演示Linux下配置文件的读取方法
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 数据类型重定义
typedef unsigned char UINT8;
typedef signed int INT32;
typedef unsigned int UINT32;

// 员工信息结构体定义
typedef struct {
    UINT8 szEmployeeName[128];    // 员工姓名
    INT32 iEmployeeAge;           // 员工年龄
} T_EmployeeInfo;

// 雇主信息结构体定义
typedef struct {
    UINT8 szEmployerName[128];    // 雇主姓名
    INT32 iEmployerAge;           // 雇主年龄
} T_EmployerInfo;

// 函数声明
void GetCompletePath(
        UINT8 *pszConfigFileName,
        UINT8 *pszWholePath
);

void GetStringContentValue(
        FILE *fp,
        UINT8 *pszSectionName,
        UINT8 *pszKeyName,
        UINT8 *pszOutput,
        UINT32 iOutputLen
);

void GetConfigFileStringValue(
        UINT8 *pszSectionName,
        UINT8 *pszKeyName,
        UINT8 *pDefaultVal,
        UINT8 *pszOutput,
        UINT32 iOutputLen,
        UINT8 *pszConfigFileName
);

INT32 GetConfigFileIntValue(
        UINT8 *pszSectionName,
        UINT8 *pszKeyName,
        UINT32 iDefaultVal,
        UINT8 *pszConfigFileName
);

INT32 main() {
    T_EmployeeInfo tEmployeeInfo = {0};
    T_EmployerInfo tEmployerInfo = {0};

    // 获取并打印员工信息
    // 获取员工姓名
    GetConfigFileStringValue("EMPLOYEEINFO", "EmployeeName", "", tEmployeeInfo.szEmployeeName,
                             sizeof(tEmployeeInfo.szEmployeeName), "conf.ini");

    // 获取员工年龄
    tEmployeeInfo.iEmployeeAge = GetConfigFileIntValue("EMPLOYEEINFO", "EmployeeAge", 20, "conf.ini");
    if (tEmployeeInfo.iEmployeeAge == -1)  // 判断获取到的年龄是否正确
    {
        printf("Get EmployeeAge failed!\n");
        return -1;
    }

    // 打印读取到的员工姓名和年龄
    printf("EmployeeName is %s, EmployeeAge is %d\n", tEmployeeInfo.szEmployeeName, tEmployeeInfo.iEmployeeAge);

    // 获取并打印雇主信息
    // 获取雇主姓名
    GetConfigFileStringValue("EMPLOYERINFO", "EmployerName", "", tEmployerInfo.szEmployerName,
                             sizeof(tEmployerInfo.szEmployerName), "conf.ini");

    // 获取员工年龄
    tEmployerInfo.iEmployerAge = GetConfigFileIntValue("EMPLOYERINFO", "EmployerAge", 30, "conf.ini");
    if (tEmployerInfo.iEmployerAge == -1)  // 判断获取到的年龄是否正确
    {
        printf("Get EmployerAge failed!\n");
        return -1;
    }

    // 打印读取到的员工姓名和年龄
    printf("EmployerName is %s, EmployerAge is %d\n", tEmployerInfo.szEmployerName, tEmployerInfo.iEmployerAge);

    return 0;
}


/**********************************************************************
* 功能描述： 获取配置文件完整路径(包含文件名)
* 输入参数： pszConfigFileName-配置文件名
             pszWholePath-配置文件完整路径(包含文件名)
********************************************************************/
void GetCompletePath(UINT8 *pszConfigFileName, UINT8 *pszWholePath) {
    UINT8 *pszHomePath = NULL;
    UINT8 szWholePath[256] = {0};

    // 先对输入参数进行异常判断
    if (pszConfigFileName == NULL || pszWholePath == NULL) {
        printf("GetCompletePath: input parameter(s) is NULL!\n");
        return;
    }

    pszHomePath = (UINT8 *) getenv("HOME");     // 获取当前用户所在的路径
    if (pszHomePath == NULL) {
        printf("GetCompletePath: Can't find home path!\n");
        return;
    }

    // 拼装配置文件路径
//    snprintf(szWholePath, sizeof(szWholePath) - 1, "%s/////////%s", pszHomePath, pszConfigFileName);
    snprintf(szWholePath, sizeof(szWholePath) - 1, "E:\\ClionProjects\\workspace\\learn-c\\2017\\10\\26\\conf.ini");

    strncpy(pszWholePath, szWholePath, strlen(szWholePath));
}


/**********************************************************************
* 功能描述： 获取具体的字符串值
* 输入参数： fp-配置文件指针
             pszSectionName-段名, 如: GENERAL
             pszKeyName-配置项名, 如: EmployeeName
             iOutputLen-输出缓存长度
* 输出参数： pszOutput-输出缓存
********************************************************************/
void GetStringContentValue(
        FILE *fp,
        UINT8 *pszSectionName,
        UINT8 *pszKeyName,
        UINT8 *pszOutput,
        UINT32 iOutputLen
) {
    UINT8 szSectionName[100] = {0};
    UINT8 szKeyName[100] = {0};
    UINT8 szContentLine[256] = {0};
    UINT8 szContentLineBak[256] = {0};
    UINT32 iContentLineLen = 0;
    UINT32 iPositionFlag = 0;

    // 先对输入参数进行异常判断
    if (fp == NULL || pszSectionName == NULL || pszKeyName == NULL || pszOutput == NULL) {
        printf("GetStringContentValue: input parameter(s) is NULL!\n");
        return;
    }

    sprintf(szSectionName, "[%s]", pszSectionName);
    strcpy(szKeyName, pszKeyName);

    while (feof(fp) == 0) {
        memset(szContentLine, 0x00, sizeof(szContentLine));
        fgets(szContentLine, sizeof(szContentLine), fp);      // 获取段名

        // 判断是否是注释行(以;开头的行就是注释行)或以其他特殊字符开头的行
        if (szContentLine[0] == ';' || szContentLine[0] == '\r' || szContentLine[0] == '\n' ||
            szContentLine[0] == '\0') {
            continue;
        }

        // 匹配段名
        if (strncasecmp(szSectionName, szContentLine, strlen(szSectionName)) == 0) {
            while (feof(fp) == 0) {
                memset(szContentLine, 0x00, sizeof(szContentLine));
                memset(szContentLineBak, 0x00, sizeof(szContentLineBak));
                fgets(szContentLine, sizeof(szContentLine), fp);     // 获取字段值

                // 判断是否是注释行(以;开头的行就是注释行)
                if (szContentLine[0] == ';') {
                    continue;
                }

                memcpy(szContentLineBak, szContentLine, strlen(szContentLine));

                // 匹配配置项名
                if (strncasecmp(szKeyName, szContentLineBak, strlen(szKeyName)) == 0) {
                    iContentLineLen = strlen(szContentLine);
                    for (iPositionFlag = strlen(szKeyName); iPositionFlag <= iContentLineLen; iPositionFlag++) {
                        if (szContentLine[iPositionFlag] == ' ') {
                            continue;
                        }
                        if (szContentLine[iPositionFlag] == '=') {
                            break;
                        }

                        iPositionFlag = iContentLineLen + 1;
                        break;
                    }

                    iPositionFlag = iPositionFlag + 1;    // 跳过=的位置

                    if (iPositionFlag > iContentLineLen) {
                        continue;
                    }

                    memset(szContentLine, 0x00, sizeof(szContentLine));
                    strcpy(szContentLine, szContentLineBak + iPositionFlag);

                    // 去掉内容中的无关字符
                    for (iPositionFlag = 0; iPositionFlag < strlen(szContentLine); iPositionFlag++) {
                        if (szContentLine[iPositionFlag] == '\r' || szContentLine[iPositionFlag] == '\n' ||
                            szContentLine[iPositionFlag] == '\0') {
                            szContentLine[iPositionFlag] = '\0';
                            break;
                        }
                    }

                    // 将配置项内容拷贝到输出缓存中
                    strncpy(pszOutput, szContentLine, iOutputLen - 1);
                    break;
                } else if (szContentLine[0] == '[') {
                    break;
                }
            }
            break;
        }
    }
}


/**********************************************************************
* 功能描述： 从配置文件中获取字符串
* 输入参数： pszSectionName-段名, 如: GENERAL
             pszKeyName-配置项名, 如: EmployeeName
             pDefaultVal-默认值
             iOutputLen-输出缓存长度
             pszConfigFileName-配置文件名
* 输出参数： pszOutput-输出缓存
********************************************************************/
void GetConfigFileStringValue(UINT8 *pszSectionName, UINT8 *pszKeyName, UINT8 *pDefaultVal, UINT8 *pszOutput,
                              UINT32 iOutputLen, UINT8 *pszConfigFileName) {
    FILE *fp = NULL;
    UINT8 szWholePath[256] = {0};

    // 先对输入参数进行异常判断
    if (pszSectionName == NULL || pszKeyName == NULL || pszOutput == NULL || pszConfigFileName == NULL) {
        printf("GetConfigFileStringValue: input parameter(s) is NULL!\n");
        return;
    }

    // 获取默认值
    if (pDefaultVal == NULL) {
        strcpy(pszOutput, "");
    } else {
        strcpy(pszOutput, pDefaultVal);
    }

    // 打开配置文件
    GetCompletePath(pszConfigFileName, szWholePath);
    fp = fopen(szWholePath, "r");
    if (fp == NULL) {
        printf("GetConfigFileStringValue: open %s failed!\n", szWholePath);
        return;
    }

    // 调用函数用于获取具体配置项的值
    GetStringContentValue(fp, pszSectionName, pszKeyName, pszOutput, iOutputLen);

    // 关闭文件
    fclose(fp);
    fp = NULL;
}

/**********************************************************************
* 功能描述： 从配置文件中获取整型变量
* 输入参数： pszSectionName-段名, 如: GENERAL
             pszKeyName-配置项名, 如: EmployeeName
             iDefaultVal-默认值
             pszConfigFileName-配置文件名
* 返 回 值： iGetValue-获取到的整数值   -1-获取失败
********************************************************************/
INT32 GetConfigFileIntValue(UINT8 *pszSectionName, UINT8 *pszKeyName, UINT32 iDefaultVal, UINT8 *pszConfigFileName) {
    UINT8 szGetValue[512] = {0};
    INT32 iGetValue = 0;

    // 先对输入参数进行异常判断
    if (pszSectionName == NULL || pszKeyName == NULL || pszConfigFileName == NULL) {
        printf("GetConfigFileIntValue: input parameter(s) is NULL!\n");
        return -1;
    }

    GetConfigFileStringValue(pszSectionName, pszKeyName, NULL, szGetValue, 512 - 1,
                             pszConfigFileName);    // 先将获取的值存放在字符型缓存中

    if (szGetValue[0] == '\0' || szGetValue[0] == ';')    // 如果是结束符或分号, 则使用默认值
    {
        iGetValue = iDefaultVal;
    } else {
        iGetValue = atoi(szGetValue);
    }

    return iGetValue;
}