#include "pair.h"


int pairit(pair_t* pair, const void* first, const size_t sfirst, const void* second, const size_t ssecond) {
    if(storeit(&pair->first, first, sfirst) == 0 &&  storeit(&pair->second, second, ssecond) == 0)
        return 0;

    return -1;
}