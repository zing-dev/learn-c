//
// Created by zhangrongxiang on 2018/1/17 14:09
// File main
//

#include <stdio.h>
#include <stdlib.h>
#include "./parson/parson.h"

void print_commits_info(const char *username, const char *repo) {
    JSON_Value *root_value;
    JSON_Array *commits;
    JSON_Object *commit;
    size_t i;
    char curl_command[512];
    char cleanup_command[256];
    char output_filename[] = "commits.json";

    /* it ain't pretty, but it's not a libcurl tutorial */
    sprintf(curl_command,
            "curl -s \"https://api.github.com/repos/%s/%s/commits\" > %s",
            username, repo, output_filename);
    sprintf(cleanup_command, "rm -f %s", output_filename);
    system(curl_command);

    /* parsing json and validating output */
    root_value = json_parse_file(output_filename);
    if (json_value_get_type(root_value) != JSONArray) {
        system(cleanup_command);
        return;
    }

    /* getting array from root value and printing commit info */
    commits = json_value_get_array(root_value);
    printf("%-10.10s %-10.10s %s\n", "Date", "SHA", "Author");
    for (i = 0; i < json_array_get_count(commits); i++) {
        commit = json_array_get_object(commits, i);
        printf("%.10s %.10s %s\n",
               json_object_dotget_string(commit, "commit.author.date"),
               json_object_get_string(commit, "sha"),
               json_object_dotget_string(commit, "commit.author.name"));
    }

    /* cleanup code */
    json_value_free(root_value);
    system(cleanup_command);
}

int main() {
    printf("Hello World....\n");
    print_commits_info("torvalds", "linux");
}