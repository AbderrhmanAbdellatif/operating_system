#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>
int main (){

	int satsutNum[2];
	char temp[20];
   	int i, j, size;
   	time_t t;  //Random sayı için değişken tanımlıyorum
   	size = 100000;
   	srand((unsigned) time(&t));  //Program her defasında farklı bir sayıyı üretiyor
   	for( i = 0 ; i < size ; i++ )satsutNum[0]=(rand() %(2-0+1))+0;  //Satır yada Sütun için 0-2 arası değer üretiyorum
   	for( j=0; j<size ;j++)satsutNum[1]=(rand()%10);	//Satır yada Sütun için üretiyorum eğer Tek ise Sütun, Çift ise Satır
	if(satsutNum[1]%2==0)strcpy(temp,"sat ");	//Çift ise Satır oluyor
	else strcpy(temp,"sut ");	//Değilse Sütun oluyor
	int StrtoInt =satsutNum[0];
	char str[12];
	sprintf(str, "%d", StrtoInt);	//Integer --> String çeviriyorum
	strcat(temp,str);	//Sonuna ekleme yapıyorum 
	write(4,temp,sizeof(char)*20); //Ana main'e gönderiyoruz.

	return 0;	
}