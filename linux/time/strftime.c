//
// Created by zing on 5/18/2020.
//
#include <stdio.h>
#include <time.h>

//%a	缩写的星期几名称	Sun
//%A	完整的星期几名称	Sunday
//%b	缩写的月份名称	Mar
//%B	完整的月份名称	March
//%c	日期和时间表示法	Sun Aug 19 02:56:02 2012
//%d	一月中的第几天（01-31）	19
//%H	24 小时格式的小时（00-23）	14
//%I	12 小时格式的小时（01-12）	05
//%j	一年中的第几天（001-366）	231
//%m	十进制数表示的月份（01-12）	08
//%M	分（00-59）	55
//%p	AM 或 PM 名称	PM
//%S	秒（00-61）	02
//%U	一年中的第几周，以第一个星期日作为第一周的第一天（00-53）	33
//%w	十进制数表示的星期几，星期日表示为 0（0-6）	4
//%W	一年中的第几周，以第一个星期一作为第一周的第一天（00-53）	34
//%x	日期表示法	08/19/12
//%X	时间表示法	02:50:06
//%y	年份，最后两个数字（00-99）	01
//%Y	年份	2012
//%Z	时区的名称或缩写	CDT
//%%	一个 % 符号	%

/* Format TP into S according to FORMAT.
   Write no more than MAXSIZE characters and return the number
   of characters written, or 0 if it would exceed MAXSIZE.  */

int main(int argc, char *argv[]) {
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    char buffer[20];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
    printf("%s\n", buffer);
    return (0);
}
