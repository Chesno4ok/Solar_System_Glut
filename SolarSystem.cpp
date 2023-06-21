#include <iostream>
#include <glut.h>
#include <cmath>
#include <string>
#include <string.h>
#include <conio.h>



using namespace std;
# define pi         3.14159265358979323846  

int winh = 1920;
int winl = 1080;


float kx = 0;
float ky = 0;
float kz = 1;
double t = 0.01;

string answ = "";
int l = 0;


char keys;



class ent
{

public:
	double x = 0;
	double y = 0;

	double px = 0;
	double py = 0;

	double size = 0;


	double rad = 0;
	double speed = 1;
	double spd1 = 0;
	double i = 0;

	float r = 1;
	float g = 1;
	float b = 1;

	int a = 1;

	bool Up = true;
	void UpdateRotation(ent p, double r)
	{
		rad = r;

		py = p.x;
		px = p.y;

		x = p.x + (r * -cos(i * pi / 180));
		y = p.y + (r * sin(i * pi / 180));

		if (i >= 360)
			i = 0;

		i += speed;
	}

};
int dot_len = 30;

ent* dot = new ent[dot_len];

void UpdateSolSys()
{
	dot[0].r = 1; dot[0].g = 0.17; dot[0].b = 0.0;
	dot[0].size = 35 * kz;


	dot[1].speed = 4.17 * t;
	dot[1].UpdateRotation(dot[0], 67.9 * kz);//Меркурий
	dot[1].size = 5 * kz;
	dot[1].r = 0.125; dot[1].g = 0.125; dot[1].b = 0.125;
	dot[1].px = dot[0].x; dot[1].py = dot[0].y;


	dot[2].r = 0.45; dot[2].g = 0.16; dot[2].b = 0.0;
	dot[2].speed = 1.63 * t;
	dot[2].UpdateRotation(dot[0], 118.2 * kz);//Венера
	dot[2].size = 5 * kz;
	dot[2].px = dot[0].x; dot[2].py = dot[0].y;



	dot[3].speed = 1 * t;
	dot[3].UpdateRotation(dot[0], 159.6 * kz);//Земля
	dot[3].size = 5 * kz;
	dot[3].r = 0; dot[3].g = 0.100; dot[3].b = 0.98; // nice
	dot[3].px = dot[0].x; dot[3].py = dot[0].y;


	dot[5].speed = 50 * t;
	dot[5].UpdateRotation(dot[3], 15 * kz); //Луна
	dot[5].size = 2 * kz;
	dot[5].r = 0.5; dot[5].g = 0.5; dot[5].b = 0.5;
	dot[5].px = dot[3].x; dot[5].py = dot[3].y;


	dot[4].speed = 0.53 * t;
	dot[4].UpdateRotation(dot[0], 238 * kz);//Марс
	dot[4].size = 5 * kz;
	dot[4].r = 1; dot[4].g = 0.4; dot[4].b = 0.0;
	dot[4].px = dot[0].x; dot[4].py = dot[0].y;

	dot[6].speed = 50 * t;
	dot[6].UpdateRotation(dot[4], 15 * kz); //Деймос
	dot[6].size = 1 * kz;
	dot[6].r = 0.5; dot[6].g = 0.5; dot[6].b = 0.5;
	dot[6].px = dot[4].x; dot[6].py = dot[4].y;

	dot[7].speed = 25 * t;
	dot[7].UpdateRotation(dot[4], 20 * kz); //Фобос
	dot[7].size = 1 * kz;
	dot[7].r = 0.5; dot[7].g = 0.5; dot[7].b = 0.5;
	dot[7].px = dot[4].x; dot[7].py = dot[4].y;

	dot[8].speed = 0.084 * t;
	dot[8].UpdateRotation(dot[0], 778.5 * kz); // Юпитер
	dot[8].size = 15 * kz;
	dot[8].r = 0.51; dot[8].g = 0.31; dot[8].b = 0.18;
	dot[8].px = dot[0].x; dot[8].py = dot[0].y;

	dot[9].speed = 50 * t;
	dot[9].UpdateRotation(dot[8], 20 * kz); //Ио
	dot[9].size = 2 * kz;
	dot[9].r = 0.5; dot[9].g = 0.42; dot[9].b = 0.14;
	dot[9].px = dot[8].x; dot[9].py = dot[8].y;


	dot[10].speed = 38 * t;
	dot[10].UpdateRotation(dot[8], 30 * kz); //Европа
	dot[10].size = 2 * kz;
	dot[10].r = 0.73; dot[10].g = 0.92; dot[10].b = 0.91;
	dot[10].px = dot[8].x; dot[10].py = dot[8].y;

	dot[11].speed = 26 * t;
	dot[11].UpdateRotation(dot[8], 40 * kz); //Ганимед
	dot[11].size = 2 * kz;
	dot[11].r = 0.5; dot[11].g = 0.5; dot[11].b = 0.5;
	dot[11].px = dot[8].x; dot[11].py = dot[8].y;

	dot[12].speed = 15 * t;
	dot[12].UpdateRotation(dot[8], 50 * kz); //каллисто
	dot[12].size = 2 * kz;
	dot[12].r = 0.5; dot[12].g = 0.5; dot[12].b = 0.5;
	dot[12].px = dot[8].x; dot[12].py = dot[8].y;


	dot[13].speed = 0.034 * t;
	dot[13].UpdateRotation(dot[0], 1426 * kz); // Сатурн
	dot[13].size = 15 * kz;
	dot[13].r = 0.71; dot[13].g = 0.41; dot[13].b = 0.28;
	dot[13].px = dot[0].x; dot[13].py = dot[0].y;

	dot[24].speed = 15 * t;
	dot[24].UpdateRotation(dot[13], 25 * kz); // кольцо
	dot[24].size = 0 * kz;
	dot[24].r = 1; dot[14].g = 1; dot[14].b = 1;
	dot[24].px = dot[13].x; dot[24].py = dot[13].y;

	dot[25].speed = 15 * t;
	dot[25].UpdateRotation(dot[13], 20 * kz); // кольцо
	dot[25].size = 0 * kz;
	dot[25].r = 1; dot[25].g = 1; dot[25].b = 1;
	dot[25].px = dot[13].x; dot[25].py = dot[13].y;


	dot[14].speed = 15 * t;
	dot[14].UpdateRotation(dot[13], 70 * kz); // Титан
	dot[14].size = 3 * kz;
	dot[14].r = 0.86; dot[14].g = 0.57; dot[14].b = 0.30;
	dot[14].px = dot[13].x; dot[14].py = dot[13].y;

	dot[15].speed = 10 * t;
	dot[15].UpdateRotation(dot[13], 90 * kz); // Эцелад
	dot[15].size = 3 * kz;
	dot[15].r = 0.62; dot[14].g = 0.76; dot[14].b = 0.72;
	dot[15].px = dot[13].x; dot[15].py = dot[13].y;

	dot[16].speed = 5 * t;
	dot[16].UpdateRotation(dot[13], 110 * kz); // Эцелад
	dot[16].size = 3 * kz;
	dot[16].r = 0.86; dot[14].g = 0.57; dot[14].b = 0.30;
	dot[16].px = dot[13].x; dot[16].py = dot[13].y;



	dot[17].speed = 0.012 * t;
	dot[17].UpdateRotation(dot[0], 2869 * kz); // Уран
	dot[17].size = 10 * kz;
	dot[17].r = 0; dot[17].g = 1; dot[17].b = 0.72;
	dot[17].px = dot[0].x; dot[17].py = dot[0].y;

	dot[18].speed = 10 * t;
	dot[18].UpdateRotation(dot[17], 37 * kz); // Титания
	dot[18].size = 5 * kz;
	dot[18].r = 0.56; dot[18].g = 0.59; dot[18].b = 0.47;
	dot[18].px = dot[17].x; dot[18].py = dot[17].y;

	dot[19].speed = 15 * t;
	dot[19].UpdateRotation(dot[17], 24 * kz); // Миранда
	dot[19].size = 4 * kz;
	dot[19].r = 1; dot[19].g = 1; dot[19].b = 1;
	dot[19].px = dot[17].x; dot[19].py = dot[17].y;

	dot[20].speed = 5 * t;
	dot[20].UpdateRotation(dot[17], 26 * kz); // Миранда
	dot[20].size = 4 * kz;
	dot[20].r = 1; dot[20].g = 1; dot[20].b = 1;
	dot[20].px = dot[17].x; dot[20].py = dot[17].y;




	dot[21].speed = 0.006 * t;
	dot[21].UpdateRotation(dot[0], 4494 * kz); // Нептун
	dot[21].size = 10 * kz;
	dot[21].r = 0; dot[21].g = 0.22; dot[21].b = 1;
	dot[21].px = dot[0].x; dot[21].py = dot[0].y;

	dot[22].speed = 15 * t;
	dot[22].UpdateRotation(dot[21], 32 * kz); // Тритон
	dot[22].size = 4 * kz;
	dot[22].r = 0.61; dot[22].g = 0.48; dot[22].b = 0.57;
	dot[22].px = dot[21].x; dot[22].py = dot[21].y;

	dot[23].speed = 10 * t;
	dot[23].UpdateRotation(dot[21], 24 * kz); // Протей
	dot[23].size = 2 * kz;
	dot[23].r = 0.61; dot[23].g = 0.48; dot[23].b = 0.57;
	dot[23].px = dot[21].x; dot[23].py = dot[21].y;



}

void DrawCircle(ent p)
{
	double x = 0, y = 0;
	double speed = 0, spd = 2;
	bool Up = true;
	double r = p.size;




	glBegin(GL_POLYGON);
	glColor3d(p.r, p.g, p.b);
	for (int i = 0; i <= 360; i += 15)
	{
		glVertex2d(
			p.x + (r * -cos(i * pi / 180)),
			p.y + (r * sin(i * pi / 180)));
	}

	glEnd();



}

void DrawLine(ent p)
{
	double x = p.px, y = p.py;
	double speed = 0, spd = 2;
	bool Up = true;
	double r = p.rad;


	glBegin(GL_LINE_LOOP);
	glColor3d(p.r, p.g, p.b);
	for (int i = 0; i <= 360; i += 5)
	{
		glVertex2d(
			p.px + (r * -cos(i * pi / 180)),
			p.py + (r * sin(i * pi / 180)));

	}
	glEnd();



}

int i = 0;
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	if (answ == "focus")
	{
		getline(cin, answ);
		l = stoi(answ);
	}
	else if (l > 0 && l < 30)
	{
		glTranslated(winh / 2 - dot[l].x, winl / 2 - dot[l].y, 0);
	}
	else
	{
		glTranslated(kx * kz, ky * kz, 0);
	}




	cout << "x: " << kx << "y: " << ky << "t: " << t << endl;
	cout << "Press T to enter a command" << endl;
	system("cls");




	glPointSize(5);
	for (int i = 0; i < dot_len; i++)
	{
		DrawCircle(dot[i]);
		DrawLine(dot[i]);
	}


	UpdateSolSys();
	//dot[1].UpdateRotation(dot[0], 150, 2.5);
	glutSwapBuffers();
}

void timer(int)
{

	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}


void processNormalKeys(unsigned char key, int x, int y)
{

	if (key == 27)
		exit(0);
	if (key == *"d")
		kx -= 10;
	if (key == *"a")
		kx += 10;
	if (key == *"w")
		ky -= 10;
	if (key == *"s")
		ky += 10;
	if (key == *"r")
		kz += 0.1;
	if (key == *"f")
		kz -= 0.2;
	if (key == *"q")
		t /= 1.25;
	if (key == *"e")
		t *= 1.25;
	if (key == *"t")
		getline(cin, answ);

}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, winh * 1, 0, winl * 1);
	glMatrixMode(GL_MODELVIEW);
	gluPerspective(100, winl / winh, 1, 100);
}

int main(int argc, char** argv) {

	// инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winh, winl);
	glutCreateWindow("Solar System");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	dot[0].x = winh / 2;
	dot[0].y = winl / 2;
	glColor3d(0.5, 0.5, 0.5);
	glutKeyboardFunc(processNormalKeys);


	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);


	// Основной цикл GLUT
	glutMainLoop();

	return 1;
}
