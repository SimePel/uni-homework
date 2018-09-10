#ifndef WEEKDAY_LOAD_H
#define WEEKDAY_LOAD_H

// Weekdays starts from Saturday, because formula that I use, to perform date to weekday, calculates for 0 - Saturday.
enum Weekdays {
    Saturday,    
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
};

struct weekday_load {
    enum Weekdays weekday;
    unsigned int count;
};
typedef struct weekday_load weekday_load;

weekday_load new_weekday_load();
char* str_weekday(enum Weekdays);
void print_weekday_load(weekday_load);

#endif // WEEKDAY_LOAD_H