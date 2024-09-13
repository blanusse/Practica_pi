#include <stdio.h>


void swap (int *dato1, int *dato2){

	int aux = *dato1;
	*dato1 = *dato2;
	*dato2 = aux;
}

void horario(int *horas, int *min, int *seg){
	
	*horas = *seg/3600;
	*min = (*seg % 3600)/60;
	*seg = *seg%60;
}

int main(){

	int seg = 50000;
	int horas, min;
	horario(&horas, &min, &seg);

	printf("%d horas\t%d minutos\t%d segundos", horas, min, seg);

}

/*
int main(){
	int num = 4;
	int num2;
	int *pNum = &num2;
	*pNum = 8;
	printf("%d\n%d\n", num2, num);
	int a=3, b=8;
	swap(&a, &b);
	printf("%d\t%d", a, b);
}*/
