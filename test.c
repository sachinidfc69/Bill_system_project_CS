#include<stdio.h>
int main(){
	char c;
	FILE *fp;
    fp = fopen("RestaurantBill.dat","r+");
	while(1){
        		c = fgetc(fp);
        		if(c == EOF)break;
        		printf("%c",c);
        		
			}
    		fclose(fp);
	return 0;
}
