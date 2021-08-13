#include <iostream>

using namespace std;
#define TAM 50  // Tamaño maximo de cadena
#define stop '*' // Para dejar de ingresar datos en la cadena
void leerCadenaCaracteres(char *ptrA);
int main()
{
   char a[TAM]={0}; // Reservo espacio y declaro en 0 para la cadena de max 50 caracteres
   leerCadenaCaracteres(a); // Lleno cadena a
   char letras[TAM]={0}, digitos[TAM]={0}; // reservo espacio para separar digitos de letras en 2 char diferentes
   int index1=0,index2=0; //Me ayudan a desplazarme por las cadenas de letras y digitos respectivamente

   // Separo Letras de digitos numericos
   for (int i=0;i<TAM;i++) {
       if(a[i]>64 && a[i]< 91){
           *(letras+index1)=a[i];
           index1+=1;}
       if(a[i]>47 && a[i]< 58){
           *(digitos+index2)=a[i];
           index2+=1;}
       if (a[i]<48 && a[i]>90) {
           break;}

   }
   //CUANTOS DIGITOS TENGO
   int condicional=0,sumador=0;
   while(condicional==0){
       for (int j=0; j<TAM;j++) {
           if(digitos[j]!= '\0')sumador+=1;
           else condicional=1;
       }}

   // ME ASEGURO QUE SE PUEDAN DIVIDIR EN 3 CIFRAS
   condicional=0;
   char digitosaux[51]={0};
   for(int k=0;k<51;k++){
       if ((sumador % 3) != 0){
           digitosaux[k]=48;
           sumador+=1;
           continue;}
       if((sumador % 3)==0){
           digitosaux[k]=digitos[condicional];
           condicional+=1;
           continue;
       }}
    int contador=0;
   char numeros[17][3]={0};
        for (int i=0;i<51;i++) {
       **(numeros+contador)=digitosaux[i];
            contador+=1;
   }
   cout<<numeros<<endl;
   // int digitos3[17]={0};
  //  numtmp=0,finalnumber=0,final=0;

  /* for (int j=0;j<4; j++) {
           numtmp= digitosaux[j]-48;

           if(numtmp >0){
           finalnumber *=10;
           finalnumber += digitosaux[j]-48;  }
           if(numtmp==0)finalnumber*=10;
           if(numtmp<0)break;}
  */


    return 0;
}
// Funcion para llenar cadena de caracteres en el main
void leerCadenaCaracteres(char *ptrA){
    char caracter;
    int Idcaracter=0;
        while (Idcaracter<(TAM-1)){
            cout<<"Ingrese un caracter, (cuando haya ingresado el ultimo ingrese *): "<<endl;
            cin>>caracter;
            if(caracter != stop){
                ptrA[Idcaracter]=caracter;
                Idcaracter++;       }
            else {
              break;
            }}
}
