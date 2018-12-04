#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
void ProgAyir(char str[]);
void Kofaktor(int satim,int sutum);
void SatSutSec();
int A[3][3];
int det[2][2];
char *words[100];	//bu gelen komut tutmak için bir array tanımlıyorum
int toplam=0;
int main ()
{
   int Mypipe;
   pipe(&Mypipe);
   int i, j;
   for (i = 0; i < 3; i++){
	for (j = 0; j < 3; j++){	//Kullanıcıdan matrisi oluşturacak indis değerlerini alıyorum
		         printf("Matris Indis [%d][%d]:",i,j);
		        scanf("%d",&A[i][j]);
			  }
	} 
	while(1){
    int giris;
   
	if(giris==0)break;
	for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)	//Kullanıcıdan almış olduğumuz değerlerle matrisi yazdırıyoruz
            printf("[%d][%d]=%d\t", i, j, A[i][j]);
    } 
	 SatSutSec(); //Rastgele Satır veya Sütun seçiyoruz
	 printf("sonuc  ==> [%d] \n",toplam);
	 toplam=0;
	 printf("\n islem devam etmek icin 1 basin yeni islem yapmak icin 0 basin \n");
	scanf("%d",&giris);
	}
	 return 0;
}
void SatSutSec(){	//Satır ve Sütun seçiyoruz  
 int cocukkimligi,fv=fork();
 if(fv==0){
	 cocukkimligi=execv("sec",NULL);
 }else{
	 wait(&cocukkimligi);
	 char gelendeger[20];
	 read(3,gelendeger,sizeof(gelendeger)*20);
	 printf("\n\nSeçilen Satır/Sutun= %s \n ",gelendeger);
	 ProgAyir(gelendeger); //Burada gelen string dizisini bölüyorum
	  if(strcmp(words[0],"sat")==0){
		 int arrindex=atoi(words[1]);//Satır indexini aldık
       for(int k=0;k<3;k++)Kofaktor(arrindex,k);
	 }else{
		 int arrindex=atoi(words[1]);//Sütun indexini aldık
       for(int k=0;k<3;k++)Kofaktor(k,arrindex); 
	 }
 }	
}   		 
void ProgAyir(char str[]) {
	char *word;
	char temp[40];
	int i;
	word = strtok(str, " "); //İlk kelimeyi ayırır
	for (i = 0; 1; i++) {
		if (word == NULL) {
			break;
		}
		words[i] = word;
		word = strtok(NULL, " "); //Diğer kelimeleri " " 'a göre ayırır. Kelime yoksa NULL döner.
	}
	int j=0;
	while(j!=i){ //Burada komutların sayısına kadar gidiyorum
		strcpy(temp,words[j]);
		j++;
	}
}
void Kofaktor(int satim,int sutum){
 int sat =satim;
 int sut =sutum;
 char rakam[4];
 int i,j;
//Burada 3x3 olan matrix'i element sırasına göre 2x2 matrix olarak alıp işlem yapıyorum
   for (i = 0; i < 3; i++)
       if (i != sat)
       {
           for (j = 0; j < 3; j++)
               if (j != sut)
               {
                   if (i < sat && j < sut)
                       det[i][j] = A[i][j];
                   else if (i < sat && j > sut)
                       det[i][j-1] = A[i][j];
                   else if (i > sat && j < sut)
                       det[i-1][j]=A[i][j];
                   else
                       det[i-1][j-1]=A[i][j];
               }
       }
		rakam[0]=satim;	//gelen dizin degerini aliyorum
		rakam[1]=sutum;
		rakam[2]=A[satim][sutum];
		int Id,fv = fork();
	 	if (fv == 0){
		   write(4,rakam,4*sizeof(char)); //Pipe ile Kofaktöre değerleri yolluyoruz.
		   write(4,det,4*sizeof(int)); //Pipe ile Kofaktöre değerleri yolluyoruz.
	   	Id=execv("kofak",NULL); //Burada Kofaktörden gelen rakamı değişkene atıyorum
		}else{
			 wait(&Id); //Child process çalışmadıysa Parent'ın işini bitirmesini bekleyip Kofaktör sonuçlarını topluyoruz
			 int n;
			 read(3,&n,sizeof(int));
			 toplam+=n;
			}
	 }