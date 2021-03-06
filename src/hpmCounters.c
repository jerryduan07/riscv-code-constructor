#include <stdio.h>
#include "hpm-util.h"

int main (void){
    // enable priv
    HPM_EN_USER();

    // setup hpm events
    // can only use mhpmevent* here
    HPM_SETUP_EVENTS(mhpmevent3, 0, 1);
    HPM_SETUP_EVENTS(mhpmevent4, 0, 2);
    HPM_SETUP_EVENTS(mhpmevent5, 0, 4);

    printf("started!\n");

    // read hpms
    // can use either mhpm... or hpm... here depending on 
    // if you enable or user mode / supervisor mode reading
    printf("cycle(%lu)\n", HPM_READ(cycle));
    printf("instr(%lu)\n", HPM_READ(instret));

    // note: have to "zero" them out since they are not zero to begin with
    uint64_t start_hpm3 = HPM_READ(mhpmcounter3);
    uint64_t start_hpm4 = HPM_READ(mhpmcounter4);
    uint64_t start_hpm5 = HPM_READ(mhpmcounter5);
    printf("stalling\n");
    uint64_t end_hpm3 = HPM_READ(mhpmcounter3);
    uint64_t end_hpm4 = HPM_READ(mhpmcounter4);
    uint64_t end_hpm5 = HPM_READ(mhpmcounter5);
    printf("%lu = %lu - %lu\n", end_hpm3 - start_hpm3, end_hpm3, start_hpm3);
    printf("%lu = %lu - %lu\n", end_hpm4 - start_hpm4, end_hpm4, start_hpm4);
    printf("%lu = %lu - %lu\n", end_hpm5 - start_hpm5, end_hpm5, start_hpm5);
}
