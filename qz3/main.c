#include <stdio.h>

FILE* Hanoi;

void rec_dec(char* s) {
	if(*(s)!=0){
		printf("%c,", s[0]);
		return rec_dec(++s);
	}
}

void hanoii(int n,char A,char B,char C){
    if (n) {
	    hanoii(n-1, A, C, B);
	    fprintf(Hanoi,"Move disk %d from %c to %c\n", n, A, C);  
	    hanoii(n-1 , B, A, C);
	}
}

int hanoi_tower(int n){
    Hanoi = fopen("hanoi.txt", "w+");
    hanoii(n,'A','B','C');
	fclose(Hanoi);
}

int multiplication(int i,int j){
    if (j < 10) {
		printf("%d*%d=%d ", i, j, i*j);	
		return multiplication(i, j+1);
	}
	else if (i < 9){
		j = 1;
		printf("\n");
		return multiplication(i+1, j);
	}
}

int main()
{
    char s[]="1234567890";
	rec_dec(s);
    printf("func#1-----------------------\n");
    hanoi_tower(16);
    printf("func#2-----------------------\n");
    multiplication(1,1);
    printf("func#3-----------------------\n");
    return 0;
}