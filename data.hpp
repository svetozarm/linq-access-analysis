#ifndef DATA_HPP
#define DATA_HPP

#include <stdlib.h>
#include <iostream>

#define LEN_FIRST_NAME 16
#define LEN_LAST_NAME 16

typedef struct _data_record {
    char first_name[LEN_FIRST_NAME];
    char last_name[LEN_LAST_NAME];
#ifdef PADDING_SIZE
    unsigned char padding[PADDING_SIZE];
#endif
} data_record;

data_record *data_gen_random(unsigned int number) {
    data_record *d = (data_record *) malloc(number * sizeof(data_record));
    for (int i = 0; i < number; i++) {
        data_record *rec = &(d[i]);
        for (int j = 0; j < LEN_FIRST_NAME; j++) {
            rec->first_name[j] = 'a' + (rand() % 26);
        }
        rec->first_name[LEN_FIRST_NAME - 1] = 0;

        for (int j = 0; j < LEN_LAST_NAME; j++) {
            rec->last_name[j] = 'a' + (rand() % 26);
        }
        rec->last_name[LEN_LAST_NAME - 1] = 0;
    }
    return d;
}

void data_print_record(data_record *d) {
    std::cout << d->first_name << " " << d->last_name << std::endl;
}

#endif
