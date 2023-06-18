#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 1000
#define MAX_DATA_LENGTH 1000

typedef struct {
    int opcode;
    int arg1;
    int arg2;
} Instruction;

Instruction code[MAX_CODE_LENGTH];
int data[MAX_DATA_LENGTH];
int codeLength = 0;
int dataLength = 0;

void execute() {
    int pc = 0;
    int accumulator = 0;
  
    while (pc < codeLength) {
        Instruction inst = code[pc];
      
        switch (inst.opcode) {
            case 0:  // LOAD
                accumulator = data[inst.arg1];
                break;
            case 1:  // ADD
                accumulator += data[inst.arg1];
                break;
            case 2:  // STORE
                data[inst.arg1] = accumulator;
                break;
            case 3:  // PRINT
                printf("%d\n", accumulator);
                break;
            case 4:  // HALT
                return;
            default:
                printf("Unknown instruction\n");
                return;
        }
      
        pc++;
    }
}

void emit(int opcode, int arg1, int arg2) {
    if (codeLength >= MAX_CODE_LENGTH) {
        printf("Code memory overflow\n");
        exit(1);
    }
  
    Instruction inst;
    inst.opcode = opcode;
    inst.arg1 = arg1;
    inst.arg2 = arg2;
  
    code[codeLength++] = inst;
}

void load(int addr, int value) {
    if (dataLength >= MAX_DATA_LENGTH) {
        printf("Data memory overflow\n");
        exit(1);
    }
  
    data[addr] = value;
    dataLength++;
}

int main() {
    emit(0, 0, 0);    // LOAD 0
    emit(1, 1, 0);    // ADD 1
    emit(2, 0, 0);    // STORE 0
    emit(3, 0, 0);    // PRINT
    emit(4, 0, 0);    // HALT
  
    load(0, 42);      // data[0] = 42
    load(1, 10);      // data[1] = 10
  
    execute();
  
    return 0;
}
