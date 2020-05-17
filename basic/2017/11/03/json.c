//
// Created by zhangrongxiang on 2017/11/3 15:41
// File json
//

#include <stdio.h>
#include <stdlib.h>
#include "cJSON/cJSON.h"

//gcc json.c cJSON/cJSON.c -I cJSON/ -lm

int main() {
    char string[100];
    sprintf(string, "{\"type\":\"send\",\"path\":\"%s\",\"result\":1}", "/s/s/s/s/s/ss.ss");
    char *out;
    cJSON *json;
    json = cJSON_Parse(string);
    if (!json) { printf("Error before: [%s]\n", cJSON_GetErrorPtr()); }
    else {
        out = cJSON_Print(json);
        cJSON_Delete(json);
        printf("%s\n", out);
        free(out);
    }
}