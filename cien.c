#include <stdio.h>
#include <math.h>
//operação com inteiros
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
//operação com reais
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
	double imagi;//parte imaginária
}complex;
//impressão do número complexo. Ele evita mostrar argumentos com zero (apenas mostrando 0 se todos os dois forem zerados)
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
//estrutura para fração
typedef struct{
int num;
int den;
}fraction;
//simplificação de matriz
fraction simple(fraction x){
int veri=0;
fraction f= x;
//operação para ajustar frações negativas
if (f.den<0){
f.den*=-1;
veri++;
}
//se os dois numeros forem negativos, a matriz simplificada será positiva
if (f.num<0){
f.num*=-1;
veri--;
}
//metodo rapido de simplificação
//numero que vai ser utilizado para divisão mutua dos numeros
int i;
for (i=2; i<=(f.num)&&i<=(f.den); i++){
//dividindo até não conseguir mais
while (f.num%i==0&&f.den%i==0){
if ((f.num%i)==0&&(f.den%i==0)){
f.num=f.num/i;
f.den=f.den/i;
}
}
}
i=2;
//se for verificado que é negativo, multiplica o numerador por negativo
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
	if(op!='s')
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
			break;
		case 's':
			return 0;
			break;
		default:
			printf("Escolha invalida.\n");
	}
	goto loop;
}
