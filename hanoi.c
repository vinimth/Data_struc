#include <stdio.h> 
  // Estrutura de Dados
  //
  // Título : Computacional 2 (Recursão)
  //
  // Aluno(s):
  // Ariel Citrangulo (1821517260)
  // Gustavo Fuzinelli (1921518973)
  // Vinicius Moreno (171152761)


void torreDeHanoi(int n, char from_rod, char to_rod, char aux_rod)
{ 
    if (n == 1) 
    { 
        printf("\n Mova o disco 1 de %c para %c", from_rod, to_rod); 
        return; 
    } 
    torreDeHanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("\n Mova o disco %d de %c para %c", n, from_rod, to_rod); 
    torreDeHanoi(n-1, aux_rod, to_rod, from_rod); 
} 
  
int main() 
{ 
    int n = 3; // N de discos
    torreDeHanoi(n, 'A', 'C', 'B');  
    return 0; 
} 
