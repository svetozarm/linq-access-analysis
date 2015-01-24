#include <stdio.h>
#include <iostream>

#include "cpplinq.hpp"
#include "data.hpp"

#define NR_RECORDS 1000000

int main(int argc, char **argv){
    auto r = data_gen_random_vec(NR_RECORDS);

    {
        using namespace cpplinq;

        auto sorted = from(r)
                    >> orderby_ascending ([] (data_record const & d) {return d.first_name;})
                    >> to_vector();
        
        auto result = from(r)
        //auto result = from(sorted)
                    >> orderby_ascending ([] (data_record const & d) {return d.first_name;})
                    >> where ([] (data_record const &d) { return d.first_name[0] == 'a'; })
                    >> to_vector();
    }

    return 0;
}
