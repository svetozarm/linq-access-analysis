#include <stdio.h>
#include <iostream>

#include "cpplinq.hpp"
#include "data.hpp"

int computes_a_sum ()
{
    using namespace cpplinq;
    int ints[] = {3,1,4,1,5,9,2,6,5,4};

    auto result =    from_array (ints)
        >> where ([](int i) {return i%2 ==0;})  // Keep only even numbers
        >> sum ()                               // Sum remaining numbers
        ;
    return result;
}

int main(int argc, char **argv){
    data_record *r = data_gen_random(1000);

    for (int i = 0; i < 1000; i++) {
        data_print_record(&(r[i]));
    }    

    return 0;
}
