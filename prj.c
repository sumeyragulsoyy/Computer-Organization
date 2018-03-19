#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int heap[100000];
int heapsize;
int rowIndex,columnIndex;
 
char Numbers[100][100];// array question
char expression[1000]; // for string evaulation 
int minValue,maxValue;
//1.question
void Init(){
	heapsize=0;
	heap[0]=heapsize;
}

int Insert(int value){
	heapsize++;
	heap[heapsize]=value;
	int nowIndex=heapsize;
		while(heap[nowIndex/2]>value && (nowIndex/2)!=0 ){ // if value is min than root of its
		 heap[nowIndex]=heap[nowIndex/2];
		 nowIndex/=2;
		}	
heap[nowIndex]=value;
heap[0]=heapsize;
return nowIndex;
}

int Delete(){
	int now,child;
	if(heap[0]!=0){
	
	
	int minNode=heap[1];
	heap[1]=heap[heapsize];
	heapsize--;
	heap[0]=heapsize;
	for(now=1;now*2<=heapsize;now=child){
		child=now*2;
		if(child!=heapsize && heap[child+1]<heap[child]){
			child++;
		}
		if(heap[now]>heap[child]){
			int temp=heap[now];
			heap[now]=heap[child];
			heap[child]=temp;
		}else{
			// root is min of children .It doesn't need to change
		}
	}
	return minNode;
}else{
	printf("heap is empty ");
	
}

}

	

void Print(){
	int j=0;
	int i,a;
	
	
	for( i=1;i<=heapsize;i++){
		printf("[%d]%d",i,heap[i]);
		j++;
		
		if(j%2==1 && i!=1 ){ // row inside ordering 
			printf("-");
		}else{
			printf("  ");
		}
		
		if(i == 2*j-1){ // next line 
			printf("\n");
			j=0;
		}	
	}
	if(j!=0){
		int b=2*(i-j)-1;
		for(a=i;a<=b;a++){
	
		 if(a%2==1 ){
				printf("X  ");
			}else{
				printf("X-");
			}
			
		}
	}
}


void MenuOfQ1(){
	int flag=1;
	int subChoice;
	int value;
	printf("\nThe address of the heap: 0x%x",&heap);
	
			while(flag==1){
			
                printf("\nMenu of Q1:\n"
                               "1. Insert an item to the heap\n"
                               "2. Delete an item from the heap\n"
                               "3. Print the heap\n"
                               "4. Return back\n"
                               "Please select an option: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        printf("\nPlease enter the value of item: ");
                        scanf("%d",&value);
                        printf("\nThe value of %d is placed at location %d of the heap array!",value,Insert(value));
                        printf("\n\n");
                        break;
                    case 2:
                    	if(heapsize!=0 && heapsize>0){
                    		 printf("\nThe value of %d is deleted from the heap!",Delete());
                        
						}else
                        printf("-----Heap is EMPTY!!----");
                        printf("\n\n");
                        break;
                    case 3:
                        printf("\nThe size of the heap is %d.\n",heap[0]);
                        Print();
                        printf("\n\n");
                        break;
                    case 4:

                        printf("\n\n");
                        flag=0;
                        break;
                    
                        
            }
        }
}
//3.question
void createArray(char s[] ,int row){
	int i,j,number;
    j=0,number=0;
    for(i=0;i<(strlen(s));i++){
    	if(s[i]==' ' || s[i]=='\n'){
    		Numbers[number][j]='\0';
    		number++;  // to next word
    		j=0; // to next word index=0
    		
		}else {
			Numbers[number][j]=s[i];
			j++;
		}
	}
	int column=(number+1)/row;
	int numArray[row][column];
	int a=0;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			numArray[i][j]=atoi(Numbers[a]);
			printf("%d ",numArray[i][j]);
			a++;
		}
		int z,m;
		int min=numArray[0][0];
		for(z=0;z<=rowIndex;z++){
			for(m=0;m<=columnIndex;m++){
				if(min>numArray[z][m]){
					min =numArray[z][m];
				}
			}	
		}
		minValue=min;
		int max=numArray[0][0];
		for(z=0;z<=rowIndex;z++){
			for(m=0;m<=columnIndex;m++){
				if(max<numArray[z][m]){
					max =numArray[z][m];
				}
			}	
		}
		maxValue=max;
		
		printf("\n");
	}
	
}
//2.question
int evaulate(char exp[]){
	char operator [1000]; // a var for travel on operator
	int operand[1000];   // b var for tarvel on operand
	char digits[1][10]; 
	char number[1][10];   // number between operators
	int a =0,b=0,c=0;    // operator array inside to check operator
	operand[0]=-5;
	operator[0]='?';
	 int i,flag,result,s;
	 char opr;
	 int cnt=0;
	for(i=0;i<strlen(exp);i++){	
		if(exp[i]=='(' || exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' ){ // char operator control
		    printf("%c",exp[i]);
			a++;
			operator[a]=exp[i];
			printf(" _%c_ ",operator[a]);
			flag=0;
		}else if ( exp[i]>=48 && exp[i]<=57 ){
        digits[0][b]=exp[i];
		flag=1;  // digitte operator arasý 12 yi almak için
		cnt++;   // array üzerinde silme iþlemi yapmýyorum
		b++;				
									
		}	
		if(exp[i]==')'){
			flag=0;
		}
		if(flag==0 && b!=0){ // take number to operand array
			c++;
			for(s=0;s<cnt;s++){
				number[0][s]=digits[0][s];
			}
			operand[c]=atoi(number[0]);
			        printf("\n_%d_\n",operand[c]);
			
			b=0;
			cnt=0;
		}
		if(exp[i]==')'){
			 opr=operator[a];
			switch(opr){
				case '+':
					result=operand[c-1]+operand[c];
						printf("\n%d %d\n",operand[c-1],operand[c]);
					break;
				case '-':
					result=operand[c-1]-operand[c];	
						printf("\n%d %d\n",operand[c-1],operand[c]);
					break;
				case '*':
					result=operand[c-1]*operand[c];
						printf("\n%d %d\n",operand[c-1],operand[c]);
					break;
				case '/':
					result=operand[c-1]/operand[c];
						printf("\n%d %d\n",operand[c-1],operand[c]);
				break;
			}
			a=a-2;
			c--;
			operand[c]=result;
			        printf("#%d#",operand[c]);		
		}		
	}
	int j,k;
	printf("\n\n");
	for(j=0;j<=b;j++){
		printf("**%d **",operand[j]);	
	}
	printf("\n\n");
	for(k=0;k<=a;k++){
		printf("%c",operator[k]);
	}
	
	if(a==0){
		return operand[b];
	}
		
}

int main(){
//	s[0]=" ";
char str[1000];
	Init();
    int row;
    int flag=1;
    int mainChoice;
    int subChoice;
    printf("\nWelcome to our MIPS project!\n");
    while(flag==1){
        printf("\nMain Menu:\n"
                       "1. Build a min-heap\n"
                       "2. Evaluate an expression\n"
                       "3. Construct a 2D array\n"
                       "4. Exit\n"
                       "Please select an option: ");


        scanf("%d", &mainChoice);
        switch (mainChoice)
        {
            case 1:
				MenuOfQ1();
                printf("\n\n");
                break;
       		 
            case 2:
                printf("\nEnter the input string: ");
                scanf("%s",&expression);
                evaulate(expression);
                printf("\n\n");
                break;
            case 3:
                printf("\nEnter the input string: ");
                scanf(" %[^\t\n]s",&str);
                
                
                
                
               printf("\nEnter the number of rows: ");
                scanf("%d",&row);
				createArray(str,row);
				
                printf("\nEnter the row index: ");
                scanf("%d",&rowIndex);
                printf("\nEnter the column index: ");
			 	scanf("%d",&columnIndex);
			 	
                printf("The beginning address of the 2D array is Ox%x: \n",&str);
                printf("The memory address of the cell Array[%d][%d] is: Ox%x \n",rowIndex,columnIndex,&str[rowIndex]);
                printf("The MIN value between Array[0][0] and Array[%d][%d] is: %d\n",rowIndex,columnIndex,minValue);
                printf("The MAX value between Array[0][0] and Array[%d][%d] is: %d",rowIndex,columnIndex,maxValue);
                printf("\n\n");
                break;
            case 4:
                printf("\nProgram ends. Bye :)\n");
                printf("\n\n");
                flag=0;
                return 0;
                break;
            default:
                printf("\nDefault ");
                printf("\n\n");
        }
    }

    return 0;
}
/*if(exp[i]==')'){  // 5) 5 i almak için ve )) geldiðinde çalýþmasýn
				  digits[0][b]=exp[i-1];	
				 flag=0;
				}else{ // take digit 
					digits[0][b]=exp[i]; // 	
					flag=1;
				}
				 printf("!%c!",digits[0][b]);
				cnt++;
				b++;
					 // take digits of number
					// for next digit	
					*/
