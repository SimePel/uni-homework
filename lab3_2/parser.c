#include "stdio.h"
#include "string.h"

#include "weekdayload.h"
#include "parser.h"

// strmonth_to_int returns enum of month string representation
static int strmonth_to_int(char month[MAX_MONTH_STR_SIZE]) {   
    if (strncmp(month, "Jan", 3) == 0) {
        return Jan;
    } else if (strncmp(month, "Feb", 3) == 0) {
        return Feb;
    } else if (strncmp(month, "Mar", 3) == 0) {
        return Mar;
    } else if (strncmp(month, "Apr", 3) == 0) {
        return Apr;
    } else if (strncmp(month, "May", 3) == 0) {
        return May;
    } else if (strncmp(month, "Jun", 3) == 0) {
        return June;
    } else if (strncmp(month, "Jul", 3) == 0) {
        return July;
    } else if (strncmp(month, "Aug", 3) == 0) {
        return Aug;
    } else if (strncmp(month, "Sep", 3) == 0) {
        return Sept;
    } else if (strncmp(month, "Oct", 3) == 0) {
        return Oct;
    } else if (strncmp(month, "Nov", 3) == 0) {
        return Nov;
    } else if (strncmp(month, "Dec", 3) == 0) {
        return Dec;
    }
    return -1;
}

// str_to_date gets string from log file, isolates only Date record and returns it.
Date str_to_date(char* str) {
    while(*(str++) != '[') ;
    
    int day;
    sscanf(str, "%d", &day);
    
    while(*(str++) != '/') ;

    char month[MAX_MONTH_STR_SIZE];
    for(int i = 0; *str != '/'; i++, str++) {
        month[i] = *str;
    }
    
    int year;
    sscanf(str, "/%d", &year); 

    return (Date) { 
        .day=day,
        .month=strmonth_to_int(month),
        .year=year,
    };
}

// month_code returns month code for the formula.
static int month_code(int month) {
    if (month == Apr || month == July) {
        return 0;
    } else if (month == Jan || month == Oct) {
        return 1;
    } else if (month == May) {
        return 2;
    } else if (month == Aug) {
        return 3;
    } else if (month == Feb || month == Mar || month == Nov) {
        return 4;
    } else if (month == June) {
        return 5;
    } else if (month == Dec || month == Sept) {
        return 6;
    }
    return -1;
}

// year_code returns year code for the formula.
static int year_code(int year) {
    int last_two_digits = year % 100;
    return (6 + last_two_digits + last_two_digits / 4) % 7;
}

// weekday calculates weekday with special formula by Date.
enum Weekdays weekday(Date d) {
    return (enum Weekdays) (d.day + month_code(d.month) + year_code(d.year)) % 7;
}