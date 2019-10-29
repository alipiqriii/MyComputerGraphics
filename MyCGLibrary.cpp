#include "MyCGLibrary.h"
#include <math.h>

// Ini Variable diambil dari File MyCGLibrary.h, bukan variable baru ya. dia masih setia kok, masih jadi dirinya sendiri
Point p1, p2;
Line line;
Circle circle;
Elips ellips; 
Color color;

/* ===== */
/* BASE */
/* ===== */

// Ini Prosedur Buat Nampilin Windows GLUT, Kalau ga ditampilin ya percuma buat apa, perlu aksi dibanding kata kata //
void init_windows_glut(int argc, char** argv, int width, int height,const char title[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(title);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, width, height, 0);
}

// Ini Prosedur Buat Ngeabsolutin Nilai, Biar dia jadi orang baik //
int abs (int n) 
{ 
    return ( (n>0) ? n : ( n * (-1))); 
} 

// Ini Prosedur Buat Ngegambar Titik, Hal Kecil aja Kegambar //
void draw_pixel(int x,int y){
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

// Ini Prosedur Buat Ngehilangin Gambar Di Screen, Biar Bersih gitu hatinya //
void clear_devices(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

// Ini Prosedur Buat Keluar Dari Loop Main OpenGL pake Spasi, klo ga keluar tar ga bisa lanjutin eksekusi setelahnya //
void process_next_screen(unsigned char key, int x, int y) 
{
     switch (key) 
    {   
       case 32 : glutLeaveMainLoop();  break;
    }

}

/* ==== */
/* LINE */
/* ==== */

// Ini Prosedur Buat Ngegambar Garis Pake Metode DDA, Biar Lurus Jalan Kitanya //
void line_DDA(int x0, int y0, int x1, int y1) 
{ 
    int dx = x1 - x0; 
    int dy = y1 - y0; 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
    float xIncrement = dx / (float) steps; 
    float yIncrement = dy / (float) steps; 
    float x = x0; 
    float y = y0; 
    for (int i = 0; i <= steps; i++) 
    { 
        draw_pixel(x,y);
        x += xIncrement;
        y += yIncrement;
    } 
} 

// Ini Prosedur Buat Ngegambar Garis Pake Metode Bresenham, Sayangnya Gabisa Lurus Jalannya //
void line_bresenham(int x0, int y0, int x1, int y1){
	int dx = abs (x0-x1);
	int dy = abs (y0-y1);
	int p = 2 * dy - dx;
	int twoDy = 2*dy;
	int twoDyDx = 2*(dy-dx);
	int x, y, xEnd;
	
	if (x0 > x1){
		x = x1;
		y = y1;
		xEnd = x0;
	} else {
		x = x0;
		y = y0;
		xEnd = x1;
	}
	
	draw_pixel(x,y);
	while (x < xEnd){
		x++;
		if(p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyDx;
		}
	draw_pixel(x,y);
	}
}

/* ====== */
/* CIRCLE */
/* ====== */

// Ini Prosedur Buat Ngegambar Lingkaran Pake Metode Mid Points, Ga usah pusing pusing mikirin tepatnya harus kemana //
void circle_mid_points(int xCenter, int yCenter, int radius)
{
  int x = radius;
  int y = 0;
  int err = 0;
  while (x >= y)
  {
    circle_plot_points(xCenter, yCenter, x, y);
    if (err <= 0)
    {
      y += 1;
      err += 2*y + 1;
    }
    if (err > 0)
    {
      x -= 1;
      err -= 2*x + 1;
    }
  }
}

// Ini Prosedur Buat Ngeplotin Titik Lingkaran, Biar tepat gitu pilihannya //
void circle_plot_points (int xCenter, int yCenter, int x, int y){
	draw_pixel(xCenter + x, yCenter + y);
    draw_pixel(xCenter + y, yCenter + x);
    draw_pixel(xCenter - y, yCenter + x);
    draw_pixel(xCenter - x, yCenter + y);
    draw_pixel(xCenter - x, yCenter - y);
    draw_pixel(xCenter - y, yCenter - x);
    draw_pixel(xCenter + y, yCenter - x);
    draw_pixel(xCenter + x, yCenter - y);
}

/* ======== */
/* ELLIPSE */
/* ======== */

// Ini Prosedur Buat Ngegambar Ellips Pake Metode Mid Points, Elips tuh ga seimbang ga enak kalo ga seimbang //	
void ellipse_mid_point (int xCenter, int yCenter, int radiusX, int radiusY){
	 int radiusX2 = radiusX*radiusX;
	 int radiusY2 = radiusY*radiusY;
	 int twoRadiusX2 = 2*radiusX2;
	 int x0 = 2*radiusY2;
	 int p;
	 int x = 0;
	 int y = radiusY;
	 int px = 0;
	 int py = twoRadiusX2 * y;
	 ellipse_plot_points (xCenter, yCenter, x, y);
	 
	 /* Region 1 */
	 p = ROUND (radiusY2 - (radiusX2 * radiusY) + (0.25 * radiusX2));
	 while (px < py) {
		  x++;
		  px += x0;
		  if (p < 0) {
			p += radiusY2 + px;
		  } else {
		   y--;
		   py -= twoRadiusX2;
		   p += radiusY2 + px - py;
		  }
		  ellipse_plot_points (xCenter, yCenter, x, y);
	 }
	 
	 /* Region 2 */
	 p = ROUND (radiusY2*(x+0.5)*(x+0.5) + radiusX2*(y-1)*(y-1) - radiusX2*radiusY2);
	 while (y > 0) {
		  y--;
		  py -= twoRadiusX2;
		  if (p > 0) {
		   	p += radiusX2 - py;
		  } else {
			   x++;
			   px += x0;
			   p += radiusX2 - py + px;
		  }
		  ellipse_plot_points (xCenter, yCenter, x, y);
	 }
}

// Ini Prosedur Buat Ngeplotin Titik Ellips, Biar tepat gitu pilihannya //
void ellipse_plot_points(int xCenter, int yCenter, int x, int y){
	 draw_pixel (xCenter + x, yCenter + y);
	 draw_pixel (xCenter - x, yCenter + y);
	 draw_pixel (xCenter + x, yCenter - y);
	 draw_pixel (xCenter - x, yCenter - y);
}

/* ============================ */
/* Display Function For OpenGL */
/* ============================ */

// Ini Prosedur Buat Nampilin Garis DDA Di OpenGL, Sering dipanggil ya gabosen tuh ?  //
void display_DDA(){
	line_DDA(line.point1.x, line.point1.y, line.point2.x, line.point2.y);
	glFlush(); 
}

// Ini Prosedur Buat Nampilin Garis Bresenham Di OpenGL, Sering dipanggil ya gabosen tuh ?  //
void display_line_bresenham(){
	line_bresenham(line.point1.x, line.point1.y, line.point2.x, line.point2.y);
	glFlush(); 
}

// Ini Prosedur Buat Nampilin Lingkaran Mid Point Di OpenGL, Sering dipanggil ya gabosen tuh ?  //
void display_circle(){
	circle_mid_points(circle.xCenter, circle.yCenter, circle.radius);
	glFlush(); 
}

// Ini Prosedur Buat Nampilin Elips Mid Point Di OpenGL, Sering dipanggil ya gabosen tuh ?  //
void display_ellips(){
	ellipse_mid_point(ellips.xCenter, ellips.yCenter, ellips.radiusX, ellips.radiusY);
	glFlush(); 
}

/* ============================ */
/* Transformasi */
/* ============================ */

// Translasi
Point translasi(Point pointOld,int xInc,int yInc){
	pointOld.x += xInc;
	pointOld.y += yInc;
	
	return pointOld;
}

// Rotation Line 0,0
Line Rotation(double angle,Line lineRotation){
	Line lineResult;
	angle = -angle;
    int pivotX = lineRotation.point1.x - a;
    int pivotY = lineRotation.point1.y - b;
	double radian=angle*0.01745;
	lineResult.point1.x = pivotX;
	lineResult.point1.y = pivotY;
	lineResult.point2.x=(int)(pivotX +((lineRotation.point2.x-pivotX)*cos(radian)-(lineRotation.point2.y-pivotY)*sin(radian)));
	lineResult.point2.y=(int)(pivotY +((lineRotation.point2.x-pivotX)*sin(radian)+(lineRotation.point2.y-pivotY)*cos(radian)));
    return lineResult;
}

// Rotasi Titik 
//Point rotate(Point pointOld,int xPivot, int yPivot, int angle){
//    int xShifted = pointOld.x - xPivot; 
//    int yShifted = pointOld.y - yPivot; 
//    
//    pointOld.x = xPivot + (xShifted*cos(angle)  - yShifted*sin(angle)); 
//    pointOld.y = yPivot + (xShifted*sin(angle)  + yShifted*cos(angle));
//    
//    return pointOld;
//}

