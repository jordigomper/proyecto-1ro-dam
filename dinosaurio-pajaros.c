//dinosuruis rex
//BY jotaGe

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define f 29
#define c 118
#define oculto 137

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

void print_pantalla(char pantalla[f][c], int salto,int mov,int cactus_ale,int nube_ale,int pajaro, int score,int *fin);//imprimir pantalla
void control_salto (int *salto, int *flag_salto);
void control_mov(int *mov, int *pajaro);
void gen_obj(int *cactus_ale, int *nube_ale);
void obj_dinosaurio(char pantalla[f][c],int x,int y,int salto);
void obj_cactus(char pantalla[f][c], int x, int y);
void obj_pajaro1(char pantalla[f][c], int x, int y,int pajaro, int mov);
void obj_pajaro2(char pantalla[f][c], int x, int y, int pajaro, int mov);
void obj_nube (char pantalla[f][c], int x, int y, int pajaro);

void clrscr();
int gettextattr();
void settextattr(int x);
void textcolor(int color);
void textbackground(int color);
HANDLE g_consOut;

int main (){
	system ("color 79");
	char pantalla[f][c];//pantalla de juego
	int x,y;//variables para for
	int fin=0, score=0;
	int flag_salto=0,salto=0;
	int mov=0, pajaro=0;//aqui van todos los objetos en movimiento. mov es para mover toda la pantalla
	int cactus_ale=0,nube_ale=0;
	srand(time(NULL)) ;	
	g_consOut = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD originalColors = gettextattr();

	do{
		control_salto(&salto, &flag_salto);
		control_mov(&mov,&pajaro);
		gen_obj(&cactus_ale,&nube_ale);
		system("cls");
		print_pantalla(pantalla,salto,mov,cactus_ale,nube_ale,pajaro,score,&fin);
		score++;
	}while(fin!=1);
	system("cls");
	system("pause");
	return 0;
}

void print_pantalla(char pantalla[f][c],int salto,int mov,int cactus_ale, int nube_ale, int pajaro, int score,int *fin){
	int x,y,fin2=0;			
	for(x=0;x<f;x++){
		for(y=1;y<c;y++){
			//if(pantalla[x][y]){
				pantalla[x][y]=' ';
				textbackground(WHITE);
    			textcolor(WHITE);
		//	} 
			if(pantalla[x][y+1]=='*' && score!=0){
				pantalla[x][y]='*';
				pantalla[x][y+1]=' ';
				textbackground(DKGRAY);
    			textcolor(DKGRAY);
			}
			else if(pantalla[x][y+1]=='n' && score!=0){
				pantalla[x][y]='n';
				pantalla[x][y+1]=' ';
				textbackground(DKGRAY);
    			textcolor(DKGRAY);
    		}
			else if(x == f-2){
				pantalla[x][y]='-';
				textbackground(DKGRAY);
    			textcolor(DKGRAY);
			} 
			else pantalla[x][y]=' ';
			obj_pajaro1(pantalla,x,y,pajaro,mov);
			obj_pajaro2(pantalla,x,y,pajaro,mov);
			obj_dinosaurio(pantalla,x,y,salto);
			if(cactus_ale<5) obj_cactus(pantalla,x,y);
			if(cactus_ale<10) obj_nube(pantalla,x,y,pajaro);	
				
		printf("%c",pantalla[x][y]);	
	}							
	printf("\n");
	}
	printf("SCORE: %d", score);		
}

void control_mov(int *mov, int *pajaro){
	*mov=*mov-1;
	if(*mov%2==0)*pajaro=*pajaro-1;
}

void obj_pajaro1 (char pantalla[f][c], int x, int y, int pajaro, int mov){
	int aux;
	aux=pajaro;
	if(x==10 && y==(115+aux))if(mov%2==0){
		pantalla[x][y]='V';
    	textcolor(DKGRAY);
	}
	if(x==11 && y==(114+aux)){
		pantalla[x][y]='<';
    	textcolor(DKGRAY);
	}
	if(x==11 && y==(115+aux)){
		pantalla[x][y]='o';
    	textcolor(DKGRAY);
	}
	if(x==11 && y==(116+aux)){
		pantalla[x][y]='>';
    	textcolor(DKGRAY);
	}
	if(x==11 && y==(117+aux)){
		pantalla[x][y]='<';
    	textcolor(DKGRAY);
	}
	if(x==12 && y==(115+aux))if(mov%2!=0){
		pantalla[x][y]='^';
    	textcolor(DKGRAY);
	}
}

void obj_pajaro2(char pantalla[f][c], int x, int y, int pajaro, int mov){
	int aux;
	aux=mov;
	if(x==8 && y==(125+aux))if(mov%2==0){
		pantalla[x][y]='V';
		textcolor(DKGRAY);
	}
	if(x==9 && y==(124+aux)){
		pantalla[x][y]='<';
		textcolor(DKGRAY);
	}
	if(x==9 && y==(125+aux)){
		pantalla[x][y]='o';
		textcolor(DKGRAY);
	}
	if(x==9 && y==(126+aux)){
		pantalla[x][y]='>';
		textcolor(DKGRAY);
	}
	if(x==9 && y==(127+aux)){
		pantalla[x][y]='<';
		textcolor(DKGRAY);
	}
	if(x==10  && y==(125+aux))if(mov%2!=0){
		pantalla[x][y]='^';
    	textcolor(DKGRAY);
	}
}

void obj_nube (char pantalla[f][c], int x, int y, int pajaro){

	if(x==0 && y>=100 && y<=121){
		pantalla[x][y]='n';
		textcolor(DKGRAY);
    	textbackground(DKGRAY);
	}
	if(x==1 && y>=101 && y<=125){
		pantalla[x][y]='n';
		textcolor(DKGRAY);
    	textbackground(DKGRAY);
	}
	if(x==2 && y>=102 && y<=128){
		pantalla[x][y]='n';
		textcolor(DKGRAY);
    	textbackground(DKGRAY);
	}
}

void obj_cactus(char pantalla[f][c], int x, int y){
	int aux=0;
	if(x==21 && y>=114 && y<=115){
		pantalla[x][y]='*';
	}
	else if(x==22 && y>=114 && y<=115){
		pantalla[x][y]='*';
	}
	else if(x==23 && y==112 || x==23 && y>=114 && y<=115){
		pantalla[x][y]='*';	
	}
	else if(x==24 && y>=112 && y<=115 || x==24 && y==117){
		pantalla[x][y]='*';	
	}
	else if(x==25 && y>=114 && y<=117){
		pantalla[x][y]='*';	
	}
	else if(x==26 && y>=114 && y<=115){
		pantalla[x][y]='*';	
	}
}

void control_salto (int *salto, int *flag_salto){
int tecla;
if(kbhit()) tecla = getch();
if(tecla==' ' || *flag_salto>0){
	*flag_salto=*flag_salto+1;
	if(*flag_salto>0 && *flag_salto<=7)*salto=*salto-1;
	else if(*flag_salto==8);
	else if(*flag_salto>8 && *flag_salto<=15)*salto=*salto+1;
	else *flag_salto=0;
}
}

void gen_obj(int *cactus_ale, int *nube_ale){
	*cactus_ale=rand()%100 ;
	*nube_ale=rand()%13+3;
}

void obj_dinosaurio(char pantalla[f][c],int x,int y,int salto){
	int aux;
	aux=salto+1;
	if(x==(19+aux) && y>=9 && y<=13){
		pantalla[x][y]='#';
		textbackground(DKGRAY);
    	textcolor(DKGRAY);
	}
	else if(x==(20+aux) && y==9 || x==(20+aux) && y== 11){
		pantalla[x][y]='#';
		textbackground(DKGRAY);
    	textcolor(DKGRAY);
	}
	else if(x==(21+aux) && y>=9 && y<=13){
		pantalla[x][y]='#';
		textbackground(DKGRAY);
    	textcolor(DKGRAY);	
	}
	else if(x==(22+aux) && y==6 || x==(22+aux) && y>=8 && y<=11){
		pantalla[x][y]='#';
		textbackground(DKGRAY);
    	textcolor(DKGRAY);
	}
	else if(x==(23+aux) && y>=6 && y<=13){
		pantalla[x][y]='#';
		textbackground(DKGRAY);
    	textcolor(DKGRAY);
	}
	else if(x==(24+aux) && y>=7 && y<=11){
		pantalla[x][y]='#';
		textbackground(DKGRAY);
    	textcolor(DKGRAY);
	}
	else if(x==(25+aux) && y==8 || x==(25+aux) && y==10){
		pantalla[x][y]='#';
		textbackground(DKGRAY);
    	textcolor(DKGRAY);
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
