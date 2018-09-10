#include "stdio.h"

#include "ipweekday.h"
#include "list.h"
#include "parser.h"

int main() {
    FILE* f = fopen("log.log", "r");

    List* list = new_filled_list();

    char str[650]; // получено с помощью wc -L
    Date d;
    while (fgets(str, sizeof(str), f) != NULL) {
        d = str_to_date(str);
        update(list, weekday(d));
    }
    fclose(f);
    
    print_week_load(list);
    
    free_list(list);
    return 0;
}