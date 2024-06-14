#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void diziyiolusturma(long dizi[],long size){                            //big O notasyonu hesaplama
	int i;                                                              // 1
	for(i=0;i<size;i++){
		dizi[i]=i;                                                     //N
	}                                                                 // bu fonksiyonda T(N)=1+N
}
long arama(long dizi[],long size,long sayi){
	long i;                                                          //1
	for(i=0;i<size;i++){                                             //N
		if(dizi[i]==sayi){                                           //N
			return i;                                                //1
		}
		
	}
			return -1;                                              //1

}                                                                   //bu fonksiyonda T(N)=2N+3
int main(int argc, char *argv[]) {
   clock_t baslangic,bitis;                                          
   double sure;                                                    
   baslangic = clock();                                            
   long dizi1[1000],dizi2[10000],dizi3[10000];
   diziyiolusturma(dizi1,1000);
   arama(dizi1,1000,1000);                                          //main fonksiyonun çalışma zamanı çağırılan fonksiyonlardan en yavaşı olarak ele alınır
   diziyiolusturma(dizi2,10000);                                    //bu durumda en yavaş fonskiyon olan arama fonksiyonudur bu da T(N)=2N+3 olur    
   arama(dizi2,10000,10000);  
   bitis = clock();
   diziyiolusturma(dizi3,5000);
  arama(dizi3,5000,5000);
   sure=(double)(bitis - baslangic);
   printf("programin calisma suresi: %f",sure);
   
    

	return 0;
}