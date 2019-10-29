#ifndef MYCG_LIB_035_ALIPIQRI
#define MYCG_LIB_035_ALIPIQRI

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <gl/glut.h>
#include <gl/freeglut.h>

#define ROUND(a) ((int) (a+0.5))

/* ============== */
/* Struktur data */
/* ============= */

typedef struct Point
{
   int x;
   int y;
}Point;

typedef struct Line
{
	struct Point point1;
	struct Point point2;
}Line;

typedef struct Circle
{
	int xCenter;
	int yCenter;
	int radius;
}Circle;

typedef struct Elips
{
	int xCenter;
	int yCenter;
	int radiusX;
	int radiusY;
}Elips;

typedef struct Color
{
	int R;
	int G;
	int B;
}Color;

/* =============================================================== */
/* Deklarasi Variable Global GLUT hanya bisa lewat variable GLOBAL*/
/* =============================================================== */

// Extern tuh biar bisa di share gitu ke file lain, karna di share ya tinggal di panggil aja ntar juga nyantol
extern Point p1, p2;
extern Line line;
extern Circle circle;
extern Elips ellips;
extern Color color;

/* ===== */
/* BASE */
/* ===== */

// Ini Prosedur Buat Ngeabsolutin Nilai, Biar dia jadi orang baik //
int abs (int n);

// Ini Prosedur Buat Nampilin Windows GLUT, Kalau ga ditampilin ya percuma buat apa, perlu aksi dibanding omongan doang //
void init_windows_glut(int argc, char** argv, int width, int height,const char title[]);

// Ini Prosedur Buat Ngegambar Titik, Hal Kecil aja Kegambar //
void draw_pixel(int x,int y);

// Ini Prosedur Buat Ngehilangin Gambar Di Screen, Biar Bersih gitu hatinya //
void clear_devices();

// Ini Prosedur Buat Keluar Dari Loop Main OpenGL pake Spasi, klo ga keluar tar ga bisa lanjutin eksekusi setelahnya //
void process_next_screen(unsigned char key, int x, int y);

/* ==== */
/* LINE */
/* ==== */

// Ini Prosedur Buat Ngegambar Garis Pake Metode DDA, Biar Lurus Jalan Kitanya //
void line_DDA(int x0, int y0, int x1, int y1);

// Ini Prosedur Buat Ngegambar Garis Pake Metode Bresenham, Sayangnya Gabisa Lurus Jalannya //
void line_bresenham(int x0, int y0, int x1, int y1);

/* ====== */
/* CIRCLE */
/* ====== */

// Ini Prosedur Buat Ngegambar Lingkaran Pake Metode Mid Points, Ga usah pusing pusing mikirin tepatnya harus kemana //
void circle_mid_points(int xCenter, int yCenter, int radius);

// Ini Prosedur Buat Ngeplotin Titik Lingkaran, Biar tepat gitu pilihannya //
void circle_plot_points (int xCenter, int yCenter, int x, int y);

/* ======== */
/* ELLIPSE */
/* ======== */

// Ini Prosedur Buat Ngegambar Ellips Pake Metode Mid Points, Elips tuh ga seimbang ga enak kalo ga seimbang //
void ellipse_mid_point (int xCenter, int yCenter, int radiusX, int radiusY);

// Ini Prosedur Buat Ngeplotin Titik Ellips, Biar tepat gitu pilihannya //
void ellipse_plot_points(int xCenter, int yCenter, int x, int y);

/* ============================ */
/* Display Function For OpenGL */
/* ============================ */

// Ini Prosedur Buat Nampilin Garis DDA Di OpenGL, Sering dipanggil ya gabosen tuh ?  //
void display_DDA();

// Ini Prosedur Buat Nampilin Garis Bresenham Di OpenGL, Sering dipanggil ya gabosen tuh ?  //
void display_line_bresenham();

// Ini Prosedur Buat Nampilin Lingkaran Mid Point Di OpenGL, Sering dipanggil ya gabosen tuh ?  //
void display_circle();

// Ini Prosedur Buat Nampilin Elips Mid Point Di OpenGL, Sering dipanggil ya gabosen tuh ?  //
void display_ellips();

/* ============================ */
/* Transformasi */
/* ============================ */

// Translasi
Point translasi(Point pointOld,int xInc,int yInc);

// Rotation Line 0,0
Line Rotation(double angle,Line lineRotation);
#endif


