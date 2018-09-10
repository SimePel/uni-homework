#ifndef PARSER_H
#define PARSER_H

#define MAX_MONTH_STR_SIZE 5

struct Date {
    int day;
    int month;
    int year;
};
typedef struct Date Date;

enum Months {
    Jan,
    Feb,
    Mar,
    Apr,
    May,
    June,
    July,
    Aug,
    Sept,
    Oct,
    Nov,
    Dec,
};

Date str_to_date(char* str);
enum Weekdays weekday(Date d);

#endif // PARSER_H