#include <stdio.h>
#include <math.h>

int main (void) {

   /*
    *
    * Matr.: 17/0033813
    * Trab.: 0001
    *
    */

   long double A, B, C;

   printf("Digite o numero A: ");
   scanf("%Lf", &A);

   printf("Digite o numero B: ");
   scanf("%Lf", &B);

   printf("Digite o numero C: ");
   scanf("%Lf", &C);

   long double sP = (A + B + C)/2;

   printf("Diagonal do retangulo de lados A e B = %.2Lf\n", sqrtl((A * A) + (B * B)));
   printf("Area do triangulo de lados A, B e C = %.2Lf\n", sqrtl((sP)* (sP - A) * (sP - B) * (sP - C)));
   printf("Area do circulo de raio C = %.2Lf\n", 3.141592653589793238462643383279 * powl(C, 2));
   printf("Fim de programa");
}
