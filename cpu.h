#ifndef CPU_H
#define CPU_H

struct CPU {
    int IP;
    char IR[1000];
    int quanta = 2; 
};

extern struct CPU cpu; 
int run(int quanta); 

#endif
