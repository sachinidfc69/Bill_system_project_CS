#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
    char item[20];
    float price;
    int qty;
};

struct orders{
    char customer[50];
    int numOfItems;
    struct items itm[50];
};

//functions to generate biils

void generateBillHeader(char name[50]){
    printf("\n\n");
        printf("\t  Hacker.<3 Restaurant ");
        printf("\n\t   -----------------");
        printf("\nDate:2024-04-09");
        printf("\nInvoice To: %s",name);
        printf("\n");
        printf("---------------------------------------\n");
        printf("Items\t\t");
        printf("Qty\t\t");
        printf("Total\t\t");
        printf("\n---------------------------------------");
        printf("\n\n");
}
void generateBillBody(char item[30],int qty, float price){
    printf("%s\t\t",item); 
        printf("%d\t\t",qty); 
        printf("%.2f\t\t",qty * price); 
        printf("\n");
}



void generateBillFooter(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal=total-dis;
    float tax=0.09*netTotal,grandTotal=netTotal + tax;
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nTAX   @9%s\t\t\t%.2f","%",tax);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n---------------------------------------\n");
}

int main(){
	
	int opt,n,i;
	struct orders ord;
	char Flag = 'y';
	
	while(Flag == 'y'){
    	float total = 0;
    	printf("\t========== Hacker.<3 RESTAURANT==========");
    	printf("\n\nPlease select to perform the operation.");
    	printf("\n\n1.Generate Invoice");
    	printf("\n2.Exit");
    	printf("\n\nYour choice:\t");
    	scanf("%d",&opt);
    	fgetc(stdin);
    	
    switch(opt){
        case 1:
        	
        	printf("\nPlease enter the name of the customer:\t");
        	scanf("%[^\n]",ord.customer);
       		printf("\nPlease enter the number of items:\t");
        	scanf("%d",&n);
        	ord.numOfItems = n;
        	
        for(i=0;i<n;i++){
        	fgetc(stdin);
        	printf("\n\n");
            printf("Please enter the item %d:\t",i+1);
            scanf("%[^\n]",ord.itm[i].item);
            printf("Please enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("Please enter the unit price:\t");
            scanf("%f",&ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;
        }

        	generateBillHeader(ord.customer);      	
        	for( i=0;i<ord.numOfItems;i++){
            generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        	}
        	generateBillFooter(total);   
		              
        	break;
        	
    	case 2:
    		printf("\n\t\t Bye Bye :)\n\n");
    		exit(0);
    		
    		break;

    	default:
    		printf("Sorry invalid option");
    		
    		break;
    
    }
    
    printf("\nDo you want to perform another operation?[y/n]:\t");
    scanf("%s",&Flag);
    
    
   }
     printf("\n\t\t Bye Bye :) \n\n");
	 printf("--------------------------------");
	 
return 0;
}
