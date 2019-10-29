#include "MyCGLibrary.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <gl/glut.h>

int main(int argc, char **argv)
{
	
	// Buat Line DDA
	printf("Masukan X1, Y1, X2, Y2 Untuk Line DDA : ");
	scanf("%d %d %d %d",&line.point1.x, &line.point1.y, &line.point2.x, &line.point2.y);
	
	init_windows_glut(argc, argv, 500,500,"JUDUL");
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutDisplayFunc(display_DDA);
	glutMainLoop();
	
	// Buat Line Bresenham
	printf("Masukan X1, Y1, X2, Y2 Untuk Line Bresenham : ");
	scanf("%d %d %d %d",&line.point1.x, &line.point1.y, &line.point2.x, &line.point2.y);
	
	init_windows_glut(argc, argv, 500,500,"JUDUL");
	glutDisplayFunc(display_line_bresenham);
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutMainLoop();
	
	// Buat Circle
	printf("Masukan XCenter, YCenter, Radius Untuk Circle Mid Points : ");
	scanf("%d %d %d",&circle.xCenter, &circle.yCenter, &circle.radius);
	
	init_windows_glut(argc, argv, 500,500,"JUDUL");
	glutDisplayFunc(display_circle);
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutMainLoop();
	
	// Buat Ellips
	printf("Masukan XCenter, YCenter, RadiusX, RadiusY Untuk Ellips Mid Points : ");
	scanf("%d %d %d %d",&ellips.xCenter, &ellips.yCenter, &ellips.radiusX, &ellips.radiusY);
	
	init_windows_glut(argc, argv, 500,500,"JUDUL");
	glutDisplayFunc(display_ellips);
	glutKeyboardFunc(process_next_screen);
	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ); 
	glutMainLoop();
	
	return 0;
}
