/*
FORK:
Divide o processamento em dois, como se reiniciasse o codigo e 
tivesse um procesoso PAI e um processo FILHO, procesos pai executa primeiro
*/

#include <iostream>
#include <unistd.h>

int main() {

    
    if (fork() == 0) 
                    
        std::cout<<"Processo filho.\n";
    else
        std::cout<<"Processo pai.\n";

    return 0;
} 