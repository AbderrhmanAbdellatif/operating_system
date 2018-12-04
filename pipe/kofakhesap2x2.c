#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
int main(int argc) {
	char A[4];
	read(3,A,sizeof(char)*4); //detrminant3x3 gönderilen değerleri pipe ile okuyorum
	int satlar=A[0];	
	int sutlar=A[1]; 
	int dizi_eleman=A[2];	//aldığımız değerleri değişkenlere atıyorum
	int detdizisi[2][2];
	read(3,detdizisi,sizeof(int)*4); //detrminant3x3 gönderilen değerleri pipe ile okuyorum
   int j,i;
	for (i = 0; i < 2; i++)
   {
       printf("\n");
       for (j = 0; j < 2; j++)
           printf("B[%d][%d]=%d\t", i, j, detdizisi[i][j]);
   }
   int detdizisinideger=(detdizisi[0][0]*detdizisi[1][1] - detdizisi[1][0]*detdizisi[0][1]); //2x2'lik matris'in çözümünü yapıyorum
   printf("\nDeterminat ==>%d\n",detdizisinideger);
   printf("\n %d * %d \n",satlar,sutlar);
   int ust=(int)pow(-1,satlar+sutlar); //matris'in satır ve sütununa göre üs alma işlemini yapıyorum
   int detA =ust*detdizisinideger;	//2x2 lik determinant sonucunu hesaplıyorum
   printf("\nÜst= %d  Det Dizisinin Değeri= %d  Sonuç detA= %d \n",ust,detA,detdizisinideger);
   int detAa=dizi_eleman*detA;
   printf("\ndeta= %d x %d  detA= %d  detAa= %d \n ",satlar,sutlar,detdizisinideger,detAa);
   write(4,&detAa,sizeof(int));	//Kofaktor sonucunu pipe yapısı ile ana main'e gönderiyorum
	return 0;	
}

