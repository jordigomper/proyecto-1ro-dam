//dinosuruis rex
//BY jotaGe

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define f 25
#define c 117
#define INTENSE   FOREGROUND_INTENSITY
#define DKBLUE    FOREGROUND_BLUE
#define DKGREEN   FOREGROUND_GREEN
#define DKRED     FOREGROUND_RED
#define DKYELLOW  (RED|GREEN)
#define DKCYAN    (GREEN|BLUE)
#define DKMAGENTA (RED|BLUE)
#define BLUE      (FOREGROUND_BLUE|INTENSE)
#define GREEN     (FOREGROUND_GREEN|INTENSE)
#define RED       (FOREGROUND_RED|INTENSE)
#define YELLOW    (RED|GREEN|INTENSE)
#define CYAN      (GREEN|BLUE|INTENSE)
#define MAGENTA   (RED|BLUE|INTENSE)
#define BLACK     0
#define DKGRAY    INTENSE
#define LTGRAY    (RED|GREEN|BLUE)
#define WHITE     ( RED|GREEN|BLUE|INTENSE)

void print_pantalla(char pantalla[f][c], int salto,int mov,int cactus_ale,int *flag_cactus, int nube_ale, int *flag_nube, int score,int score_hi,int *fin);//imprimir pantalla
void control_salto (int *salto, int *flag_salto);
void control_mov(int *mov);
void gen_obj(int *cactus_ale,int *flag_cactus, int *nube_ale,int *flag_nube);
void obj_dinosaurio(char pantalla[f][c],int x,int y,int salto);
void obj_cactus(char pantalla[f][c], int x, int y, int *fin2);
void obj_nube (char pantalla[f][c], int x, int y, int nube);

void clrscr();
int gettextattr();
void settextattr(int x);
void textcolor(int color);
void textbackground(int color);
HANDLE g_consOut;

int main (){
	system ("color 81");
	char pantalla[f][c];//pantalla de juego
	int x,y;//variables para for
	int fin=0,fin2=0, score=00000,score_hi=0;
	int flag_salto=0,salto=0;
	int mov=0, flag_nube=0,flag_cactus;//aqui van todos los objetos en movimiento. mov es para mover toda la pantalla
	int cactus_ale=0,nube_ale=0;
	srand(time(NULL)) ;	
	g_consOut = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD originalColors = gettextattr();
    
    textbackground(DKGRAY);
    textcolor(WHITE);
    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
    printf("\n\t\t\t\t\t    DIONOSAURIUS REX");
    printf("\n");printf("\n");
    printf("\n\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t--------");
    printf("\n\t\t\t\t\tPULSA UN TECLA PARA JUGAR....");
    printf("\n\t\t\t\t\t           by");
    printf("\n\t\t\t\t\t         jotaGe");
    printf("\n\t\t\t\t\t\t---------");
    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
    
    system("pause");
    for(x=0;x<f+f;x++){
		for(y=1;y<c+f;y++){
			textbackground(WHITE);
    			textcolor(WHITE);
			printf(" ");
		}
	}
	system("cls");
	do{
		do{
			print_pantalla(pantalla,salto,mov,cactus_ale,&flag_cactus,nube_ale,&flag_nube,score,score_hi,&fin);
			control_salto(&salto, &flag_salto);
			control_mov(&mov);
			gen_obj(&cactus_ale,&flag_cactus,&nube_ale,&flag_nube);
			score++;
			if(score>score_hi)score_hi=score;
		}while(fin!=1);

		printf("\nFIN DEL JUEGO");
		printf("\nDeseas seguir jugando? Si=0 No=1");
		fin2=getch();
		fin=0;
		printf("%d",fin2);
		system("pause");
		system("cls");
		score=0;
	}while(fin2!=1);
	system("cls");
	system("pause");
	return 0;
}

void print_pantalla(char pantalla[f][c],int salto,int mov,int cactus_ale,int *flag_cactus, int nube_ale,int *flag_nube, int score,int score_hi,int *fin){
	int x,y,fin2=0;
	*fin=fin2;
	textcolor(BLACK);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t    HI: %d   %d\n",score_hi,score);		
	for(x=0;x<f;x++){
		for(y=1;y<c;y++){
			gotoxy(y,x);
			pantalla[x][y]=' ';
			textbackground(WHITE);
    		textcolor(WHITE);
			if(pantalla[x][y+1]=='*' && score!=0){
				if(pantalla[x][y-1]=='#') *fin=1;
				pantalla[x][y]='*';
				pantalla[x][y+1]=' ';
				textbackground(GREEN);
    			textcolor(GREEN);
			}
			
			else if(pantalla[x][y+1]=='n' && score!=0){
				pantalla[x][y]='n';
				pantalla[x][y+1]=' ';
				textbackground(BLUE);
				textcolor(BLUE);
    		}
			else if(x == f-2){
				pantalla[x][y]='-';
				textbackground(DKRED);
    			textcolor(DKRED);
			}
			obj_dinosaurio(pantalla,x,y,salto);
			if(cactus_ale<5){
				obj_cactus(pantalla,x,y,&fin2);
				*flag_cactus=1;	
			}
			if(nube_ale<8){
				obj_nube(pantalla,x,y,nube_ale);
				*flag_nube=1;
			}
			printf("%c",pantalla[x][y]);
		}
		printf("\n");
	}
	textbackground(WHITE);
    textcolor(DKGRAY);
	//system("cls");
	
}



 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  


void control_mov(int *mov){
	*mov=*mov-1;
}


void obj_nube (char pantalla[f][c], int x, int y, int nube_ale){
	int aux2=nube_ale;
	if(x==(0+aux2) && y>=c-7 && y<=c-5){
		pantalla[x][y]='n';
		textbackground(BLUE);
    	textcolor(BLUE);
	}
	if(x==(1+aux2) && y>=c-8 && y<=c-3){
		pantalla[x][y]='n';
		textbackground(BLUE);
    	textcolor(BLUE);
	}
	if(x==(2+aux2) && y>=c-9 && y<=c){
		pantalla[x][y]='n';
		textbackground(BLUE);
    	textcolor(BLUE);
	}
}

void obj_cactus(char pantalla[f][c], int x, int y,int *fin2){
	int aux=10;
	if(x==f-7 && y>=c-4 && y<=c-3){
		if(pantalla[x][y-2]=='#'){
		*fin2=1;
		}
		pantalla[x][y]='*';
		textbackground(GREEN);
    	textcolor(GREEN);
    	
	}
	else if(x==f-6 && y==c-6 || x==f-6 && y>=c-4 && y<=c-3){
		if(pantalla[x][y-2]=='#'){
		*fin2=1;
		}
		pantalla[x][y]='*';
		textbackground(GREEN);
    	textcolor(GREEN);
	}
	else if(x==f-5 && y>=c-6 && y<=c-3 || x==f-5 && y==c-1){
		if(pantalla[x][y-2]=='#'){
		*fin2=1;
		}
		pantalla[x][y]='*';
		textbackground(GREEN);
    	textcolor(GREEN);	
	}
	else if(x==f-4 && y>=c-4 && y<=c-1){
		if(pantalla[x][y-2]=='#'){
		*fin2=1;
		}
		pantalla[x][y]='*';
		textbackground(GREEN);
    	textcolor(GREEN);
	}
	else if(x==f-3 && y>=c-4 && y<=c-3){
		if(pantalla[x][y-2]=='#'){
		*fin2=1;
		}
		pantalla[x][y]='*';
		textbackground(GREEN);
    	textcolor(GREEN);
	}
}

void control_salto (int *salto, int *flag_salto){
int tecla;
if(kbhit()) tecla = getch();
if(tecla==' ' || *flag_salto>0){
	*flag_salto=*flag_salto+1;
	if(*flag_salto>0 && *flag_salto<=7)*salto=*salto-1;
	else if(*flag_salto>7 && *flag_salto<=15) ;
	else if(*flag_salto>15 && *flag_salto<=22)*salto=*salto+1;
	else *flag_salto=0;
}
}

void gen_obj(int *cactus_ale,int *flag_cactus, int *nube_ale, int *flag_nube){
	if(*flag_cactus>=1 && *flag_cactus<=20){
		*flag_cactus=*flag_cactus+1;
		*cactus_ale=6;
	} 
	else *cactus_ale=rand()%100;
	
	
	if(*flag_nube>=1 && *flag_nube<=45){
		*flag_nube=*flag_nube+1;
		*nube_ale=9;
	} 
	else *nube_ale=rand()%8;
	
}

void obj_dinosaurio(char pantalla[f][c],int x,int y,int salto){
	int aux;
	aux=salto+1;
	if(x==(f-11+aux) && y>=10 && y<=15){
		if(y==15){
			pantalla[x][y]=220;
			textbackground(WHITE);
    		textcolor(DKGREEN);
		}
		else{
			pantalla[x][y]='#';
			textbackground(DKGREEN);
    		textcolor(DKGREEN);
		}
		
	
	}
	else if(x==(f-10+aux) && y>=10 && y<=15){
		if(y==11)
		{
			pantalla[x][y]=254;
			textbackground(WHITE);
	    	textcolor(BLACK);	
		}
		else {
			pantalla[x][y]='#';
			textbackground(DKGREEN);
	    	textcolor(DKGREEN);
		}	
	}
	else if(x==(f-9+aux) && y>=10 && y<= 15){
		if(y==10 && y<=13){
			pantalla[x][y]='#';
			textbackground(DKGREEN);
	    	textcolor(DKGREEN);	
		}
		else {
			pantalla[x][y]=254;
			textbackground(DKGREEN);
    		textcolor(RED);
		}
	}
	else if(x==(f-8+aux) && y>=8 && y<=15){
		pantalla[x][y]='#';	
		textbackground(DKGREEN);
    	textcolor(DKGREEN);
	}
	else if(x==(f-7+aux) && y==3 || x==(f-7+aux) && y>=6 && y<=11){
		pantalla[x][y]='#';
		textbackground(DKGREEN);
    	textcolor(DKGREEN);
	}
	else if(x==(f-6+aux) && y>=3 && y<=13 || x==(f-6+aux) && y==5){
		pantalla[x][y]='#';
		textbackground(DKGREEN);
    	textcolor(DKGREEN);
	}
	else if(x==(f-5+aux) && y>=4 && y<=11){
		pantalla[x][y]='#';
		textbackground(DKGREEN);
    	textcolor(DKGREEN);
	}
	else if(x==(f-4+aux) && y==6 || x==(f-4+aux) && y==10){
		pantalla[x][y]='#';
		textbackground(DKGREEN);
    	textcolor(DKGREEN);
	}
}
//Motor de colores
void clrscr() {
    COORD topLeft = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi; 
    GetConsoleScreenBufferInfo(g_consOut, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(g_consOut, ' ', dwConSize,
            topLeft, &cCharsWritten);
    FillConsoleOutputAttribute(g_consOut, csbi.wAttributes,
            dwConSize, topLeft, &cCharsWritten);
    SetConsoleCursorPosition(g_consOut, topLeft);
}

int gettextattr() {
    CONSOLE_SCREEN_BUFFER_INFO buf;
    GetConsoleScreenBufferInfo(g_consOut, &buf);
    return buf.wAttributes;
}
void settextattr(int x) {
    SetConsoleTextAttribute(g_consOut, (WORD)x);
}
 
void textcolor(int color) {
    SetConsoleTextAttribute(g_consOut, (gettextattr() & 0xf0) | color);
}
 
void textbackground(int color) {
    SetConsoleTextAttribute(g_consOut, (gettextattr() & 0x0f) | (color << 4));
}
