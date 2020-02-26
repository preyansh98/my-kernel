#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "pcb.h"
#include "kernel.h"
#include "ram.h"

int myinit(char *filename); 
int scheduler();
void addToReady(PCB* pcb);  

void main(){
    shellUI();	
}

int myinit(char *filename){
    FILE *p = NULL; 
    
    p = fopen(filename, "rt"); 
    
    if(p == NULL) 
        return -1; 

    int startLoc = -1; 
    int endLoc = -1; 
    
    addToRAM(p, &startLoc, &endLoc); 
    
    if(startLoc == -1 || endLoc == -1)
        return -1; 
    
    PCB* pcb = makePCB(startLoc, endLoc); 
    addToReady(pcb); 
    
    return 0;   
}

int scheduler(){
    return 0; 
}

void addToReady(PCB* pcb){
    
}
