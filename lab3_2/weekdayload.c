#include <stdio.h>

#include "weekdayload.h"

// new_weekday_load returns initialized weekday_load struct.
weekday_load new_weekday_load() {
    return (weekday_load) { Saturday, 0u };
}

// str_weekday returns string equivalent for the enum weekday. 
char* str_weekday(enum Weekdays w) {
    if (w == Saturday) {
        return "Saturday";
    } else if (w == Sunday) {
        return "Sunday";
    } else if (w == Monday) {
        return "Monday";
    } else if (w == Tuesday) {
        return "Tuesday";
    } else if (w == Wednesday) {
        return "Wednesday";
    } else if (w == Thursday) {
        return "Thursday";
    } else if (w == Friday) {
        return "Friday";
    }
    return "Undefined";
}

// print_weekday_load prints one line about weekday_load.
void print_weekday_load(weekday_load wl) {
    printf("%-9s : %-5u requests\n", str_weekday(wl.weekday), wl.count);
}