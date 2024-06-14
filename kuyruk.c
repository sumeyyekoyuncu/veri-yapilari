#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int data;
	struct dugum* next;
	
};
struct node *front=NULL;
struct node *rear=NULL;
 
 int kuyrugaekle(int veri){
 	if(front==NULL){
 		struct node *yeni=(struct node*)malloc(sizeof(struct node));
 		yeni->data=veri;
 		yeni->next=NULL;
 		front=rear=yeni;
	 }
	 else{
	    struct node *yeni=(struct node*)malloc(sizeof(struct node));
	    yeni->data=veri;
	    yeni->next=NULL;
	    rear->next=yeni;
	    rear=yeni;
	 }
 }
 void kuyruktancikarma(){
 	if(front==NULL){
 		printf("kuyruk bos");
	 }
	front=front->next;
 }
 void yazdir(){
 	struct node *gecici=front;
     if(gecici==NULL){
     	printf("kuyruk bos");
	 } 	
	 else{
	 	while(gecici!=NULL){
	 		printf("%d\n",gecici->data);
	 		gecici=gecici->next;
		 }
	 }
 	
 }

int main(int argc, char *argv[]) {
	kuyrugaekle(5);
	kuyrugaekle(10);
	kuyrugaekle(15);
	kuyrugaekle(20);
	yazdir();
	printf("FIFO mantigiyla cikarma\n");
	kuyruktancikarma();
    yazdir();
	return 0;
}