#include <stdio.h>
#include <math.h>
//opera��o com inteiros
void opInt(){
	int a,b,c;
	char op;
	printf("Digite o primeiro numero:");
	scanf("%d", &a);
	printf("Digite o operador:");
	scanf("\n%c", &op);
	printf("Digite o segundo numero:");
	scanf("%d", &b);
	loop:
	switch (op){
		case '+':
		c=a+b;
		break;
		case '-':
		c=a-b;
		break;
		case '*':
		c=a*b;
		break;
		case '/':
		if(b==0){
				printf("Divisao por zero!!!\n");
				op='s';
			}
		else
			c=a/b;
		break;
		case '^':
		c=pow(a,b);
		default:
		printf("Operacao invalida. Digite uma valida como +,-,*,/,^, ou s para sair.\n");
		scanf("\n%c",&op);
		if (op!='s')
			goto loop;
		break;
	}
	if(op!='s')
		printf("%d %c %d = %d\n", a, op, b, c);	
}
//opera��o com reais
void opDouble(){
	double a,b,c;
	char op;
	printf("Digite o primeiro numero:");
	scanf("%lf", &a);
	printf("Digite o operador:");
	scanf("\n%c", &op);
	printf("Digite o segundo numero:");
	scanf("%lf", &b);
	loop:
	switch (op){
		case '+':
		c=a+b;
		break;
		case '-':
		c=a-b;
		break;
		case '*':
		c=a*b;
		break;
		case '/':
			if(b==0){
				printf("Divisao por zero!!!\n");
				op='s';
			}
			else
			c=a/b;
		break;
		case '^':
		c=pow(a,b);
		default:
		printf("Operacao invalida. Digite uma valida como +,-,*,/,^, ou s para sair.\n");
		scanf("\n%c",&op);
		if (op!='s')
			goto loop;
		break;
	}
	if(op!='s')
		printf("%.2lf %c %.2lf = %.2lf\n", a, op, b, c);	
}
//estrutura para o numero complexo
typedef struct{
	double real; //parte real
	double imagi;//parte imagin�ria
}complex;
//impress�o do n�mero complexo. Ele evita mostrar argumentos com zero (apenas mostrando 0 se todos os dois forem zerados)
void outComplex(complex comp){
	if (comp.real!=0||(comp.real==0&&comp.imagi==0)) 
		printf("%.2lf",comp.real);
	if(comp.imagi>0)
		printf("+%.2lfi",comp.imagi);
	else if (comp.imagi<0){
		printf("%.2lfi",comp.imagi);
	}
}
//operacao com complexos
void opComplex(){
	complex a,b,c;
	char op;
	printf("Digite o primeiro numero\n");
	printf("Parte real:");
	scanf("%lf", &a.real);
	printf("Parte imaginaria:");
	scanf("%lf", &a.imagi);
	printf("Digite o operador:");
	scanf("\n%c", &op);
	if (op!='^'){
	printf("Digite o segundo numero\n");
	printf("Parte real:");
	scanf("%lf", &b.real);
	printf("Parte imaginaria:");
	scanf("%lf", &b.imagi);
	}
	loop:
	switch (op){
		case '+':
			c.real=(a.real+b.real);
			c.imagi=(a.imagi+b.imagi);
			break;
		case '-':
			c.real=(a.real-b.real);
			c.imagi=(a.imagi-b.imagi);
			break;
		case '*':
			c.real=(a.real*b.real-a.imagi*b.imagi);
			c.imagi=(a.real*b.imagi+a.imagi*a.real);
			break;
		case '/':
			if(b.real==0&&b.imagi==0){
				printf("Divisao por zero!!!\n");
				op='s';
			}
			else{
				c.real=(a.real*b.real+a.imagi*b.imagi)/(b.real*b.real+b.imagi*b.imagi);
				c.imagi=(a.imagi*b.real-a.real*b.imagi)/(b.real*b.real+b.imagi*b.imagi);
			}
			break;
		case '^': 
			printf("Digite o segundo numero (inteiro):");
			scanf("%d", b.real);
			b.imagi=0;
			c.real=1;
			c.imagi=0;
			if(b.real<0){
			b.real*=-1;
			b.imagi=-1;
			}
			int i;
			for (i=0;i<=b.real;i++){
			c.real=(a.real*c.real-a.imagi*c.imagi);
			c.imagi=(a.real*c.imagi+a.imagi*c.real);
			}
			i=0;
			if (b.imagi==-1){
			c.real=c.real/(c.real*c.real+c.imagi*c.imagi);
			c.imagi=(-1*b.imagi)/(c.real*c.real+c.imagi*c.imagi);
			b.imagi=0;
			b.real*=-1;
			}
		break;
		default:
		printf("Operacao invalida. Digite uma valida como +,-,*,/,^, ou s para sair.\n");
		scanf("\n%c",&op);
		if (op!='s')
			goto loop;
		break;
	}
	    if(op!='s'){
		outComplex(a);
		printf(" %c ", op);
		outComplex(b);
		printf(" = ");
		outComplex(c);
		printf("\n");
		}
}
//estrutura para fra��o
typedef struct{
int num;
int den;
}fraction;
//simplifica��o de matriz
fraction simple(fraction x){
int veri=0;
fraction f= x;
//opera��o para ajustar fra��es negativas
if (f.den<0){
f.den*=-1;
veri++;
}
//se os dois numeros forem negativos, a matriz simplificada ser� positiva
if (f.num<0){
f.num*=-1;
veri--;
}
//metodo rapido de simplifica��o
//numero que vai ser utilizado para divis�o mutua dos numeros
int i;
for (i=2; i<=(f.num)&&i<=(f.den); i++){
//dividindo at� n�o conseguir mais
while (f.num%i==0&&f.den%i==0){
if ((f.num%i)==0&&(f.den%i==0)){
f.num=f.num/i;
f.den=f.den/i;
}
}
}
i=2;
//se for verificado que � negativo, multiplica o numerador por negativo
if (veri){
f.num*=-1;
}
return f;
}
void outFraction(fraction f){
printf("%d", f.num);
if(f.den!=1&&f.num!=0){
	printf("/%d", f.den);
}
}
void opFrac(){
	fraction a, b,c;
	char op;
	do{
	printf("Digite o primeiro numero\n");
	printf("Numerador:");
	scanf("%d", &a.num);
	printf("Denominador:");
	scanf("%d", &a.den);
	if (a.den==0)
		printf("Fracao nao possivel. Zero no denominador");
	}while(a.den==0);
	printf("Digite o operador:");
	scanf("\n%c", &op);
	if (op!='^'){
	do{
	printf("Digite o segundo numero\n");
	printf("Numerador:");
	scanf("%d", &b.num);
	printf("Denominador:");
	scanf("%d", &b.den);
	if (b.den==0)
		printf("Fracao nao possivel. Zero no denominador");
	}while(b.den==0);
	}
	loop:
	switch (op){
		case '+':
		c.num=(a.num*b.den)+(b.num*a.den);
		c.den=(a.den*b.den);
		break;
		case '-':
		c.num=(a.num*b.den)-(b.num*a.den);
		c.den=(a.den*b.den);
		break;
		case '*':
		c.num=a.num*b.num;
		c.num=a.den*b.den;
		break;
		case '/':
		if(b.num==0){
				printf("Divisao por zero!!!\n");
				op='s';
			}
		else
			c.num=a.num*b.den;
			c.den=a.den*b.num;
		break;
		case '^': 
		printf("Digite o segundo numero (inteiro):");
		scanf("%d", b.num);
		c.num=(int) pow(a.num,b.num);
		c.den=(int) pow(a.den,b.num);
		break;
		default:
		printf("Operacao invalida. Digite uma valida como +,-,*,/,^, ou s para sair.\n");
		scanf("\n%c",&op);
		if (op!='s')
			goto loop;
		break;
	}
	if(op!='s'){
		a=simple(a);
		b=simple(b);
		c=simple(c);
		outFraction(a);
		printf(" %c ", op);
		outFraction(b);
		printf(" = ");
		outFraction(c);
		printf("\n");
	}
}

double** matriz(int x, int y) { 
	int i,j;
    // Criando o ponteiro de ponteiros para armazenar os valores
    double **temp = (double **) malloc(x * sizeof(double *));
    for(i = 0; i  < x; i++){
        temp[i] = (double *) malloc(y * sizeof(double)); 
        for (j=0; j<y; j++){
        	scanf("%lf", &temp[i][j]);
        }
    }
  	return temp;
}
void outMat(double **mat, int i, int j){
	int x;
	int y;
	for (x=0; x<i;x++){
		for (y=0; y<j;y++){
			printf(".2%lf ", mat[x][y]);
		}
		printf("\n");
	}
}
void opMat(){
	int i,j; //primeira matriz
	int k,l; //segunda matriz
	int m,n,p; //terceira matriz
	char op;
	double **b;
	printf("Primeira matriz\n");
	printf("Numero de Linhas:");
	scanf("%d",&i);
	printf("Numero de Colunas:");
	scanf("%d",&j);
	double **a=matriz(i,j);
	printf("Digite o operador:");
	scanf("\n%c",&op);
	if(op!='^'){
	printf("Segunda matriz\n");
	printf("Numero de Linhas:");
	scanf("%d",&k);
	printf("Numero de Colunas:");
	scanf("%d",&l);
	b=matriz(k,l);
 	}
	double **c = (double**)malloc(i * sizeof(double*)); 	
	loop:
	switch (op){
		case '+':
		if (i!=k||j!=l){
			printf("Matrizes de tamanhos diferentes");
		}
		else{
  		for (m = 0; m < i; m++){ 
       		c[m] = (double*) malloc(j * sizeof(double)); 
       		for (n = 0; n < j; n++){ 
            c[m][n]=a[m][n]+b[m][n];
       	}
  		}
		}
		break;
		case '-':
		if (i!=k||j!=l){
			printf("Matrizes de tamanhos diferentes");
		}
		else{
  		for (m = 0; m < i; m++){ 
       		c[m] = (double*) malloc(j * sizeof(double)); 
       		for (n = 0; n < j; n++){ 
            c[m][n]=a[m][n]-b[m][n];
       	}
  		}
		}
		break;
		case '*':
		if(j!=k)
			printf("Multiplicacao nao possivel");
		else{
			for (m=0; m<i;m++){
				c[m] = (double*) malloc(j * sizeof(double)); 
				for(n=0;n<l;n++){
					c[m][n]=0;
					for(p=0;p<j;p++){
						c[m][n]+=a[p][n]*b[m][p]; //multiplica�ao linha por coluna
					}
				}
			}
		}
		break;
		case '^':
			if(i!=j)
				printf("Matriz nao quadrada");
				op='s';
			else{
				for (m=0; m<i;m++){
				c[m] = (double*) malloc(j * sizeof(double)); 
				for(n=0;n<l;n++){
					c[m][n]=0;
					if(i==j)
						c[m][n]=1;
					else
						c[m][n]=0;
					}
				}
			printf("Digite o numero inteiro positivo:");
			scanf("%d",k);
			//repeti��o de v�rias multiplica��es
			for (l=0;l<=k;l++){
			for (m=0; m<i;m++){
				for(n=0;n<l;n++){
					c[m] = (double*) malloc(j * sizeof(double)); 
					for(p=0;p<j;p++){
						c[m][n]+=a[p][n]*c[m][p];
					}
				}
			}
			}
		}
		break;
		default:
		printf("Operacao invalida. Digite umsa valida como +,-,*,/,^, ou s para sair.\n");
		scanf("\n%c",&op);
		if (op!='s')
			goto loop;
		break;
	}
	if(op!='s')
		outMat(a,i,j);
		printf("%c\n\n",op);
		if (op=='^')
			printf("%d\n\n", k);
		else{
			outMat(b,k,l);
		}
		printf("=\n\n");
		outMat(c,m,n);
}
int main(){
	char tipo;
	loop:
	printf("Escolha o tipo de numeros que vao ser utilizados:\n->i prara inteiro\n->f para fracao\n->r para real\n->c para complexos\n->m para matriz\n->s para sair\n");
	scanf("\n%c",&tipo); 
	switch (tipo){
		case 'i':
			opInt();
			break;
		case 'r':
			opDouble();
			break;
		case 'f':
			opFrac();
			break;
		case 'c':
			opComplex();
			break;
		case 'm':
			opMat();
			break;
		case 's':
			return 0;
			break;
		default:
			printf("Escolha invalida.\n");
	}
	goto loop;
}
