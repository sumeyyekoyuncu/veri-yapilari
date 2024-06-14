
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct dugum{
	int veri;  //lıstelerin ozelligi olarak bir eleman hem kendi verisini hem de kendisinden sonraki verinin adresini tutar (hafizada kaybolmamasi icin)
	struct dugum* siradaki;
};
 
 struct dugum* kesisimbulma(struct dugum* bas1 , struct dugum* bas2){
 	struct dugum* gecici1=bas1;
 	while(gecici1 != NULL){
 		struct dugum* gecici2=bas2;
 		while(gecici2!=NULL){
 			if(gecici1->veri==gecici2->veri){
 				return gecici1;	
				  }
 			gecici2=gecici2->siradaki; //kontrol edildiginden point ettikleri yeri kontrol etmeye geceriz
			 }
			 gecici1=gecici1->siradaki;
			 
		 }
		 return NULL; //kesisim yoksa null doner ve donguden cıkılır
 }

int main(int argc, char *argv[]) {
	struct dugum bas1,dugum1,dugum2,dugum3;
	bas1.veri=3; //1.listenin baslangic degeri
	dugum1.veri=6;
	dugum2.veri=8;
	dugum3.veri=10;
	bas1.siradaki=&dugum1;
	dugum1.siradaki=&dugum2;
	dugum2.siradaki=&dugum3;
	dugum3.siradaki=NULL;
	struct dugum bas2,dugum4,dugum5,dugum6;
	bas2.veri=99;
	dugum4.veri=6;
	dugum5.veri=4;
	dugum6.veri=1;
	bas2.siradaki=&dugum4;
	dugum4.siradaki=&dugum5;
	dugum5.siradaki=&dugum6;
	dugum6.siradaki=NULL;
	
 struct dugum* kesisimnoktasi=kesisimbulma(&bas1,&bas2);
	if(kesisimnoktasi!=NULL)
	printf("kesisim noktasi : %d",kesisimnoktasi->veri);
	else 
	printf("kesisme noktalari yok.");
	return 0;
}