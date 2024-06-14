#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* sag;
	struct node* sol;
	 
	
};
struct node* dugumolustur(int data){
	 struct node* yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data=data;
	yeni->sag=NULL;
	yeni->sol=NULL;
	return yeni;
}
struct node* elemanekle(struct node* kok,int data){
	if(kok==NULL){
		return dugumolustur(data);
	}
	if(data < kok->data){
		kok->sol=elemanekle(kok->sol,data);
		}
		else if(data> kok->data){
			kok->sag=elemanekle(kok->sag,data);
		}
		return kok;
	}
	void inorder(struct node* kok){
		if(kok!=NULL){
			inorder(kok->sol);
			printf("%d  ",kok->data);
			inorder(kok->sag);
		}
	}
	void preorder(struct node* kok){
		if(kok!=NULL){
			printf("%d  ",kok->data);
			preorder(kok->sol);
			preorder(kok->sag);
		}
	}
    void postorder(struct node* kok){
    	if(kok!=NULL){
    		postorder(kok->sol);
    		postorder(kok->sag);
    		printf("%d  ",kok->data);
		}
	}
int main(int argc, char *argv[]) {
	struct node* kok=NULL;
	int n,i,eleman;
	printf("eleman sayiniz?\n");
	scanf("%d",&n);
	printf("Elemanlari giriniz: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &eleman);
        kok = elemanekle(kok, eleman);
    }
    printf("inorder dolasmasi:");
    inorder(kok);
    printf("\n");
    printf("preorder dolasmasi:");
    preorder(kok);
    printf("\n");
    printf("postorder dolasmasi:");
    postorder(kok);
	return 0;
}