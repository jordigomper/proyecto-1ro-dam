//dinosuruis rex
//BY jotaGe

#include <stdio.h>
#define f 29
#define c 110

void escenario(char pantalla[f][c]);//imprimir pantalla

int main (){
	char pantalla[f][c];//pantalla de juego
	int x,y;//variables para for
	
	escenario(pantalla);
	print_escenario(pantalla);
	salto(pantalla);
	system("cls");
	print_escenario(pantalla);
	system("pause");
	return 0;
}

void escenario(char pantalla[f][c]){
	int x,y;//variables para for
	for(x=0;x<f;x++){
		//printf("\nbucle: 1");
		for(y=0;y<c;y++){
			//printf("nbucle: 2");
			if(x==11 && y>=6 && y<=16){
				pantalla[x][y]='#';
			}
			else if(x==12 && y>=5 && y<=8 || x==12 && y>=10 && y<=17){
				pantalla[x][y]='#';
			}
			else if(x==13 && y>=5 && y<=17){
				pantalla[x][y]='#';
				
			}
			else if(x==14 && y>=5 && y<=17){
				pantalla[x][y]='#';
				
			}
			else if(x==15 && y>=5 && y<=17){
				pantalla[x][y]='#';
				
			}
			else if(x==16 && y>=5 && y<=10){
				pantalla[x][y]='#';
				
			}
			else if(x==17 && y>=5 && y<=15){
				pantalla[x][y]='#';
				
			}
			else if(x==18 && y==1 || x==18 && y>=5 && y<=10){
				pantalla[x][y]='#';
				
			}
			else if(x==19 && y==1 || x==19 && y>=4 && y<=10){
				pantalla[x][y]='#';
				
			}
			else if(x==20 && y>=1 && y<=13){
				pantalla[x][y]='#';
				
			}
			else if(x==21 && y>=1 && y<=10 || x==21 && y==13){
				pantalla[x][y]='#';
				
			}
			else if(x==22 && y>=2 && y<=10){
				pantalla[x][y]='#';
				
			}
			else if(x==23 && y>=3 && y<=9){
				pantalla[x][y]='#';
				
			}
			else if(x==24 && y>=4 && y<=8){
				pantalla[x][y]='#';
				
			}
			else if(x==25 && y==4 || x==25 && y==8){
				pantalla[x][y]='#';
				
			}
			else if(x==26 && y==4 || x==26 && y==8){
				pantalla[x][y]='#';
				
			}
			else if(x==27 && y>=4 && y<=5 || x==27 && y>=8 && y<=9){
				pantalla[x][y]='#';
				
			}
			else if(x == f-3) pantalla[x][y]='-';
			else pantalla[x][y]=' ';
	}
								
	}

}

void salto(char pantalla[f][c]){
			int x,y;
	for(x=0;x<f;x++){
		for(y=0;y<c;y++){
			if(pantalla[x][y]=='#'){
				pantalla[x][y]=' ';
				pantalla[x-1][y]='#';
			}
	}
	}
}

void print_escenario(char pantalla[f][c]){
		int x,y;
	for(x=0;x<f;x++){
		for(y=0;y<c;y++){
			printf("%c",pantalla[x][y]);
	}
								
	printf("\n");
	}
	printf("nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
}


