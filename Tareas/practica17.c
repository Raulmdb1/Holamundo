#include <16F877a.h>

#device ADC = 10

#use delay(crystal = 20000000)

#FUSES NOWDT, NOBROWNOUT, NOLVP, HS




//Directiva para utilizar puerto USART

#use rs232(BAUD=9600, XMIT = PIN_C6, RCV=PIN_C7)




#use STANDARD_IO(A)

#use STANDARD_IO(B)




#define bsum PIN_A0

#define bres PIN_A1




int8 index = 0;




// Se define el array con todas las combinaciones del display

int8 numeros[] = {

   //-gfedcba

   0b00111111, // 0

   0b00000110, // 1

   0b01011011, // 2

   0b01001111, // 3

   0b01100110 // 4

   0b01101101, // 5

   0b01111101, // 6

   0b00000111, // 7

   0b01111111, // 8

   0b01101111, // 9
   
   0b01110111, //A
   
   0b01111100, //B
   
   0b00111001, //C
   
   0b01011110, //D
   
   0b01111001, //E
   
   0b01110001, //F

};




void mostrar(){

    output_b(numeros[index]); // Colocar el número en el puerto B

}




void incrementar(){

   if(index == 15) index = 0;

   else index++;

   mostrar();

}




void decrementar(){

   if(index == 0) index = 15;

   else index--;

   mostrar();

}







void main()

{

   setup_uart(9600); //Configurar baudios

   // Inicializar pines

   output_b(0);

   input(bsum);

   input(bres);

   

   

   mostrar();

   

   int8 sact = 0;

   int8 ract = 0;

   

   int8 sprev = 0;

   int8 rprev = 0;

   

   while (TRUE)

    {

       if(input(bsum) == 1){

         while(input(bsum) == 1){} // Se atrapa el hilo, MALA PRÁCTICA

         incrementar();

       }

       

       if(input(bres) == 1){

         while(input(bres) == 1){}// Se atrapa el hilo, MALA PRÁCTICA

         decrementar();

       }

    }

}
