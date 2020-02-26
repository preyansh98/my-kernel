#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "ram.h"
#define CPU_QUANTA 2 

struct CPU {
    int IP;
    char IR[1000]; 
    int quanta; 
} cpu; 

int run(int quanta);
int isCPUAvailable();
int getCPU_IP(); 
void setCPU_IP(int ip); 
void initCPU();  
    
int run(int quanta){ 
    while(cpu.quanta > 0){    
        int isNextInstructionValid = -1; 
        char* nextInstruction = getLineFromRAM(&isNextInstructionValid, cpu.IP); 
         
        if(isNextInstructionValid == -1){
            initCPU(); 
            break;
        } 

        //next instruction valid. 
        strcpy(cpu.IR, nextInstruction);
        
        parse(cpu.IR); 

        cpu.IP++;
        cpu.quanta--; 
    }
    cpu.quanta = CPU_QUANTA;
    return 0; 
}

int isCPUAvailable(){
    if(cpu.quanta == CPU_QUANTA) return 0; 
    else return -1; 
}

int getCPU_IP(){
    return cpu.IP; 
}

void setCPU_IP(int ip) {
    cpu.IP = ip; 
}

void initCPU(){
    cpu.quanta = CPU_QUANTA;   
}
