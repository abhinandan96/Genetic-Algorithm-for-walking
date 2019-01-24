#include <glut.h>
#include <iostream>
#include <time.h>
#include <math.h>

#define IMAGE_ROWS 64     
#define IMAGE_COLS 64
float counter = 0.0;
float ts = 0.0, ti = 0.0001;
GLubyte imageData[IMAGE_ROWS][IMAGE_COLS][3];

void printArray(float** arr)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << arr[i][j];
		}
		std::cout << "\n";
	}
}

float** getArray(float x, float y, float z, float s)
{
	float** arr = new float*[8];
	arr[0] = new float[3];
	arr[0][0] = x - s;
	arr[0][1] = y - s;
	arr[0][2] = z - s;
	arr[1] = new float[3];
	arr[1][0] = x - s;
	arr[1][1] = y - s;
	arr[1][2] = z + s;
	arr[2] = new float[3];
	arr[2][0] = x + s;
	arr[2][1] = y - s;
	arr[2][2] = z - s;
	arr[3] = new float[3];
	arr[3][0] = x + s;
	arr[3][1] = y - s;;
	arr[3][2] = z + s;
	arr[4] = new float[3];
	arr[4][0] = x - s;
	arr[4][1] = y + s;;
	arr[4][2] = z - s;
	arr[5] = new float[3];
	arr[5][0] = x - s;
	arr[5][1] = y + s;;
	arr[5][2] = z + s;
	arr[6] = new float[3];
	arr[6][0] = x + s;
	arr[6][1] = y + s;;
	arr[6][2] = z - s;
	arr[7] = new float[3];
	arr[7][0] = x + s;
	arr[7][1] = y + s;;
	arr[7][2] = z + s;

	return arr;
}

void make_face(float cx, float cy, float cz, float** arr)
{
	glLoadIdentity();
	glColor3f(cx, cy, cz);
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glEnd();

	glLineWidth(2.5);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glEnd();
	//glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glEnd();
	//glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glEnd();
}

void make_fac(float cx, float cy, float cz, float** arr)
{
	glLoadIdentity();
	glColor3f(cx, cy, cz);
	glBegin(GL_QUADS);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(arr[0][0], arr[0][1], arr[0][2]);
	glVertex3f(arr[2][0], arr[2][1], arr[2][2]);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(arr[1][0], arr[1][1], arr[1][2]);
	glVertex3f(arr[3][0], arr[3][1], arr[3][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(arr[4][0], arr[4][1], arr[4][2]);
	glVertex3f(arr[5][0], arr[5][1], arr[5][2]);
	glVertex3f(arr[7][0], arr[7][1], arr[7][2]);
	glVertex3f(arr[6][0], arr[6][1], arr[6][2]);
	glEnd();

}

void make_base()
{
	glLoadIdentity();
	glColor3f(0, 191, 255);
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0.0, 1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0, 1.0); glVertex3f(-10.0, -0.25, -15.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(10.0, -0.25, -15.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(10.0, -0.25, 5.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(-10.0, -0.25, 5.0);
	glEnd();
}

void gen_color()
{
	float colx, coly, colz;
	colx = (rand() % 10);
	colx = colx / 10;
	coly = (rand() % 10);
	coly = coly / 10;
	colz = (rand() % 10);
	colz = colz / 10;
}

void display()
{
	float h = 1, depth = -4.0, cs = 0.125, xs = 0.0, defx = 0.0, kspr = 100000.0, dynlen = 0.0, movx = 0.0, movy = 0.0, movz = 0.0;
	int l, n, ll, nn, nc, i, j, k, i1, j1, k1, tempnum, atempnum;
	int count = 0, cubex = 2, cubey = 2, cubez = 2, inc = 0, cubecount = 0;
	float temp_axis[2000][3], orglen[2000][1], frc[500][3], forspg[500][3], arr[500][3], centres[100][3];
	float vel[2000][3] = { 0 };
	float axisx, axisy, axisz;
	float **cub;
	float tempforce[500][3] = { 0.0 };
	float x, y, z;
	int xarr[8], axarr[8], yarr[8], ayarr[8], zarr[8], azarr[8], avgnum[500];
	int ncube = cubex*cubey*cubez, ncom = 0, ancom = 0;
	int common[54][54][8], acommon[54][54][8];
	int abc = 1, xyz = 2;
	for (i = 0; i<ncube; i++)
	{
		for (j = 0; j < ncube; j++)
		{
			for (k = 0; k < 8; k++)
			{
				common[i][j][k] = 99;
				acommon[i][j][k] = 98;
			}
		}
	}
	for (movz = 0; movz < 0.25 * cubez; movz = movz + 0.25)
	{
		for (movy = 0; movy < 0.25 * cubey; movy = movy + 0.25)
		{
			for (movx = 0; movx < 0.25 * cubex; movx = movx + 0.25)
			{
				cub = getArray(xs + movx, h + movy, depth - movz, cs);
				centres[cubecount][0] = xs + movx;
				centres[cubecount][1] = h + movy;
				centres[cubecount][2] = depth - movz;
				//std::cout << "Centres x" << centres[cubecount][0] << "y" << centres[cubecount][1] << "z" << centres[cubecount][2];
				for (nc = 0; nc < 8; nc++)
				{
					arr[nc + inc][0] = cub[nc][0];
					//std::cout << cub[nc][0] << " ";
					arr[nc + inc][1] = cub[nc][1];
					//std::cout << cub[nc][1] << " ";
					arr[nc + inc][2] = cub[nc][2];
					//std::cout << cub[nc][2] << " ";
					//std::cout << "\n";
				}
				cubecount = cubecount + 1;
				inc = inc + 8;
				//std::cout << "\n";
			}
		}
	}

	//std::cout << "\n";
	count = 0;
	for (nc = 0; nc < (8 * ncube); nc = nc + 8)
	{
		for (l = 0; l < 8; l++)
		{
			for (n = l + 1; n < 8; n++)
			{
				temp_axis[count][0] = arr[n + nc][0] - arr[l + nc][0];
				temp_axis[count][1] = arr[n + nc][1] - arr[l + nc][1];
				temp_axis[count][2] = arr[n + nc][2] - arr[l + nc][2];
				orglen[count][0] = sqrt(pow(temp_axis[count][0], 2) + pow(temp_axis[count][1], 2) + pow(temp_axis[count][2], 2));
				std::cout << orglen[count][0];
				std::cout << "\n";
				count = count + 1;
			}
		}
		std::cout << "\n";
	}
	count = 0;
	for (i = 0; i < ncube; i++)
	{
		for (j = 0; j < ncube; j++)
		{
			if (i == j)
			{
				continue;
			}
			for (i1 = 0; i1 < 8; i1++)
			{
				xarr[i1] = 99;
				axarr[i1] = 99;
				yarr[i1] = 98;
				ayarr[i1] = 98;
				zarr[i1] = 97;
				azarr[i1] = 97;
			}
			std::cout << " I " << i << " J " << j;
			std::cout << "  " << std::endl;
			std::cout << "cu1be x" << centres[i][0] << "   y" << centres[i][1] << "  z" << centres[i][2] << std::endl;
			std::cout << "cu2be x" << centres[j][0] << "   y" << centres[j][1] << "  z" << centres[j][2] << std::endl;
			x = centres[i][0] - centres[j][0];
			y = centres[i][1] - centres[j][1];
			z = centres[i][2] - centres[j][2];
			if ((abs(x) > 0.4) || (abs(y) > 0.4) || (abs(z) > 0.4))
			{
				continue;
			}
			std::cout << x << "x " << y << "y" << z << "z" << std::endl;
			if (x == -2 * cs)
			{
				xarr[0] = 2, xarr[1] = 3, xarr[2] = 6, xarr[3] = 7;
				axarr[0] = 0, axarr[1] = 1, axarr[2] = 4, axarr[3] = 5;
			}
			else if (x == 2 * cs)
			{
				xarr[0] = 0, xarr[1] = 1, xarr[2] = 4, xarr[3] = 5;
				axarr[0] = 2, axarr[1] = 3, axarr[2] = 6, axarr[3] = 7;
			}
			else if (x == 0)
			{
				for (i1 = 0; i1 < 8; i1++)
				{
					xarr[i1] = i1;
					axarr[i1] = i1;
				}
			}
			if (y == -2 * cs)
			{
				yarr[0] = 4, yarr[1] = 5, yarr[2] = 6, yarr[3] = 7;
				ayarr[0] = 0, ayarr[1] = 1, ayarr[2] = 2, ayarr[3] = 3;
			}
			else if (y == 2 * cs)
			{
				yarr[0] = 0, yarr[1] = 1, yarr[2] = 2, yarr[3] = 3;
				ayarr[0] = 4, ayarr[1] = 5, ayarr[2] = 6, ayarr[3] = 7;
			}
			else if (y == 0)
			{
				for (i1 = 0; i1 < 8; i1++)
				{
					yarr[i1] = i1;
					ayarr[i1] = i1;
				}
			}
			if (z == -2 * cs)
			{
				zarr[0] = 1, zarr[1] = 3, zarr[2] = 5, zarr[3] = 7;
				azarr[0] = 0, azarr[1] = 2, azarr[2] = 4, azarr[3] = 6;
			}
			else if (z == 2 * cs)
			{
				zarr[0] = 0, zarr[1] = 2, zarr[2] = 4, zarr[3] = 6;
				azarr[0] = 1, azarr[1] = 3, azarr[2] = 5, azarr[3] = 7;
			}
			else if (z == 0)
			{
				for (i1 = 0; i1 < 8; i1++)
				{
					zarr[i1] = i1;
					azarr[i1] = i1;
				}
			}
			for (i1 = 0; i1 < 8; i1++)
			{
				for (j1 = 0; j1 < 8; j1++)
				{
					for (k1 = 0; k1 < 8; k1++)
					{
						if ((xarr[i1] == yarr[j1]) && (yarr[j1] == zarr[k1]))
						{
							common[i][j][ncom] = xarr[i1];
							ncom++;
							//std::cout << "common " << xarr[i1] << " i  " << i1 << std::endl;
						}
						if ((axarr[i1] == ayarr[j1]) && (ayarr[j1] == azarr[k1]))
						{
							//std::cout << "common  on adjacent" << axarr[i1] << std::endl;
							acommon[i][j][ancom] = axarr[i1];
							ancom++;
						}
					}
				}
			}
			ncom = 0;
			ancom = 0;
		}
	}
	while (ts < 10.0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for (n = 0; n < ncube * 8; n = n + 8)
		{
			for (l = 0; l < 8; l++)
			{
				cub[l][0] = arr[l + n][0];
				//std::cout << cub[l][0] << " ";
				cub[l][1] = arr[l + n][1];
				//std::cout << cub[l][1] << " ";
				cub[l][2] = arr[l + n][2];
				//std::cout << cub[l][2] << " ";
				//std::cout << "\n";
			}
			make_face(255, 255, 0, cub);
			//std::cout << "\n";
		}

		make_base();
		glutSwapBuffers();
		for (ll = 0; ll < ncube * 8; ll++)
		{
			for (nn = 0; nn < 3; nn++)
			{
				frc[ll][nn] = 0.0;
				forspg[ll][nn] = 0.0;
			}
		}
		count = 0;
		dynlen = 0.0;
		for (nn = 0; nn < ncube * 8; nn = nn + 8)
		{
			for (l = 0; l < 8; l = l++)
			{
				for (n = l + 1; n < 8; n++)
				{
					axisx = arr[n + nn][0] - arr[l + nn][0];
					axisx = round(axisx * 1000.0) / 1000.0;
					//std::cout << axisx << " ";
					axisy = arr[n + nn][1] - arr[l + nn][1];
					axisy = round(axisy * 1000.0) / 1000.0;
					//std::cout << axisy << " ";
					axisz = arr[n + nn][2] - arr[l + nn][2];
					axisz = round(axisz * 1000.0) / 1000.0;
					//std::cout << axisz << " " << "\n";
					dynlen = sqrt(pow(axisx, 2) + pow(axisy, 2) + pow(axisz, 2));
					//dynlen = round(dynlen * 1000.0) / 1000.0;
					defx = orglen[count][0] - dynlen;
					defx = round(defx * 1000.0) / 1000.0;
					//std::cout << defx << "\n";
					//std::cout << dynlen << " ";

					forspg[l + nn][0] = forspg[l + nn][0] + ((axisx * defx * kspr) / dynlen);
					//forspg[l][0] = round(forspg[l][0] * 10000.0) / 10000.0;
					forspg[l + nn][1] = forspg[l + nn][1] + ((axisy * defx * kspr) / dynlen);
					//forspg[l][1] = round(forspg[l][1] * 10000.0) / 10000.0;
					forspg[l + nn][2] = forspg[l + nn][2] + ((axisz * defx * kspr) / dynlen);
					//forspg[l][2] = round(forspg[l][2] * 10000.0) / 10000.0;

					forspg[n + nn][0] = forspg[n + nn][0] - ((axisx * defx * kspr) / dynlen);
					//forspg[n][0] = round(forspg[n][0] * 10000.0) / 10000.0;
					forspg[n + nn][1] = forspg[n + nn][1] - ((axisy * defx * kspr) / dynlen);
					//forspg[n][1] = round(forspg[n][1] * 10000.0) / 10000.0;
					forspg[n + nn][2] = forspg[n + nn][2] - ((axisz * defx * kspr) / dynlen);
					//forspg[n][2] = round(forspg[n][2] * 10000.0) / 10000.0;

					//std::cout << count << "\n";
					count = count + 1;
				}
				frc[l + nn][0] = forspg[l + nn][0];
				//frc[l][0] = round(frc[l][0] * 10000.0) / 10000.0;
				//std::cout << frc[l + nn][0] << " ";
				frc[l + nn][1] = forspg[l + nn][1] + 9.81;
				//frc[l][1] = round(frc[l][1] * 10000.0) / 10000.0;
				//std::cout << frc[l + nn][1] << " ";
				frc[l + nn][2] = forspg[l + nn][2];
				//frc[l][2] = round(frc[l][2] * 10000.0) / 10000.0;
				//std::cout << frc[l + nn][2] << " ";
				//std::cout << "\n";
			}
		}
		for (nn = 0; nn < ncube * 8; nn = nn + 8)
		{
			for (l = 0; l < 8; l++)
			{
				//std::cout << arr[l][1] << "\n";
				if (arr[l + nn][1] < -0.25)
				{
					//vel[l][0] = vel[l][0];
					//vel[l][0] = round(vel[l][0] * 1000.0) / 1000.0;
					vel[l + nn][1] = -vel[l + nn][1];
					vel[l + nn][1] = round(vel[l + nn][1] * 1000.0) / 1000.0;
					//vel[l][2] = vel[l][2];
					//vel[l][2] = round(vel[l][2] * 1000.0) / 1000.0;
				}
				else
				{
					vel[l + nn][0] = vel[l + nn][0] + (frc[l + nn][0] * ti);
					//vel[l][0] = round(vel[l][0] * 1000.0) / 1000.0;
					vel[l + nn][1] = vel[l + nn][1] + (frc[l + nn][1] * ti);
					//vel[l][1] = round(vel[l][1] * 1000.0) / 1000.0;
					vel[l + nn][2] = vel[l + nn][2] + (frc[l + nn][2] * ti);
					//vel[l][2] = round(vel[l][2] * 1000.0) / 1000.0;
					//std::cout << vel[l][0] << " ";
					//std::cout << vel[l][1] << " ";
					//std::cout << vel[l][2] << " ";
					//std::cout << "\n";
				}
				arr[l + nn][0] = arr[l + nn][0] - (vel[l + nn][0] * ti);
				//arr[l][0] = round(arr[l][0] * 1000.0) / 1000.0;
				arr[l + nn][1] = arr[l + nn][1] - (vel[l + nn][1] * ti);
				//arr[l][1] = round(arr[l][1] * 1000.0) / 1000.0;
				arr[l + nn][2] = arr[l + nn][2] - (vel[l + nn][2] * ti);
				//arr[l][2] = round(arr[l][2] * 1000.0) / 1000.0;
				//std::cout << arr[l][0] << " ";
				//std::cout << arr[l][1] << " ";
				//std::cout << arr[l][2] << " ";
				//std::cout << "\n";
			}
		}
		//std::cout << "\n";
		for (i = 0; i < ncube * 8; i++)
		{
			tempforce[i][0] = arr[i][0];
			tempforce[i][1] = arr[i][1];
			tempforce[i][2] = arr[i][2];
			avgnum[i] = 1;
			/*if (abc == 1)
			{
			std::cout << "Array " << i << "  x: " << arr[i][0] << "  y: " << arr[i][1] << " z: " << arr[i][2] << std::endl;
			std::cout << "Initial Average " << i << "  " << avgnum[i] << std::endl;
			}*/
		}
		ts = ts + ti;
		for (i = 0; i < ncube; i++)
		{
			for (j = 0; j < ncube; j++)
			{
				if (i == j)
				{
					continue;
				}
				for (i1 = 0; i1 < 4; i1++)
				{
					if (acommon[i][j][i1] > 10)
					{
						break;
					}
					tempnum = i * 8 + common[i][j][i1];
					atempnum = j * 8 + acommon[i][j][i1];
					tempforce[tempnum][0] += arr[atempnum][0];
					tempforce[tempnum][1] += arr[atempnum][1];
					tempforce[tempnum][2] += arr[atempnum][2];
					avgnum[tempnum] += 1;
					/*if (abc == 1)
					{
					std::cout << "I, J, i1  " << i << "  " << j << "  "<<i1 << std::endl;
					std::cout << "tempnum : " << tempnum << "  atempnum  : " << atempnum << std::endl;
					std::cout << "average num at timestep : " << avgnum[tempnum] << std::endl;
					}*/
				}
			}
		}
		for (i = 0; i < ncube * 8; i++)
		{
			arr[i][0] = tempforce[i][0] / avgnum[i];
			arr[i][1] = tempforce[i][1] / avgnum[i];
			arr[i][2] = tempforce[i][2] / avgnum[i];
			/*if (abc == 1)
			{
			std::cout << "Updated Array " << i << "  x: " << arr[i][0] << "  y: " << arr[i][1] << " z: " << arr[i][2] << std::endl;
			std::cout << "Average " << avgnum[i] << std::endl;
			}*/
			avgnum[i] = 1;
		}
		abc += 1;
		ts = ts + ti;
		//std::cout << ts << "\n";
	}
}

void loadTextureImageData()
{
	int value;
	for (int row = 0; row < IMAGE_ROWS; row++)
	{
		for (int col = 0; col < IMAGE_COLS; col++)
		{
			value = (((row & 0x1) == 0) ^ ((col & 0x1) == 0)) * 255;
			imageData[row][col][0] = (GLubyte)value;
			imageData[row][col][1] = (GLubyte)value;
			imageData[row][col][2] = (GLubyte)value;
		}
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (float)w / (float)h, 0.25, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void initOpenGL()
{
	glClearColor(0.2, 0.3, 0.3, 1.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	loadTextureImageData();
	glTexImage2D(GL_TEXTURE_2D, 0, 3, IMAGE_COLS, IMAGE_ROWS, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Test");
	initOpenGL();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}