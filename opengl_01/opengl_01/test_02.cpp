//  main.m

#include <GLUT/GLUT.h>

#include <math.h>


/*
 
 三角形
 
 GL_TRIANGLES(三个点成一个三角形)
 
 GL_TRIANGLE_STRIP(相邻三点成一个三角形)
 
 GL_TRIANGLE_FAN(同第二个，后2个和第一个成三角形)
 
 
 
 四边形
 
 GL_QUADS(四点一个)
 
 GL_QUAD_STRIP(相邻四点一个)
 
 
 
 多边形
 
 GL_POLYGON
 
 
 
 glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
 
 */



void drawPoint(void)

{
    
    int i;
    
    
    
    glColor3f (0.0, 0.0, 1.0);
    
    glPointSize(5);
    
    glBegin(GL_POINTS);
    
    for (i = 0; i < 7; i++)
        
        glVertex2f (0.2 + ((GLfloat) i * 0.1), 0.6);
    
    glEnd ();
    
}


void drawLines(void)

{
    
    glColor3f(0.0,0.0,1.0);
    
    glLineWidth(5);
    
    glBegin(GL_LINES);
    
    glVertex2f(0.0, 0.0);
    
    glVertex2f(0.25,0.25);
    
    glVertex2f(0.75,0.25);
    
    glVertex2f(0.0,0.0);
    
    glEnd();
    
}


void drawOneLine(GLfloat a,GLfloat b,GLfloat c,GLfloat d)

{
    
    glBegin(GL_LINES);
    
    glVertex2f(a,b);
    
    glVertex2f(c,d);
    
    glEnd();
    
}


void drawLineStripple(void)

{
    
    glEnable (GL_LINE_STIPPLE);
    
    glColor3f (0.0, 0.0, 1.0);
    
    glLineStipple (1, 0x0101);  /*  dotted  */
    
    drawOneLine (-0.25, 0.8, -0.75, 0.8);
    
    glLineStipple (1, 0x00FF);  /*  dashed  */
    
    drawOneLine (-0.25, 0.6, -0.75, 0.6);
    
    glLineStipple (1, 0x1C47);  /*  dash/dot/dash  */
    
    drawOneLine (-0.25, 0.4, -0.75, 0.4);
    
    
    
    ///* in 2nd row, 3 wide lines, each with different stipple */
    
    glLineWidth (5.0);
    
    glLineStipple (1, 0x0101);  /*  dotted  */
    
    drawOneLine (-0.25, 0.2, -0.75, 0.2);
    
    glLineStipple (1, 0x00FF);  /*  dashed  */
    
    drawOneLine (-0.25, 0.0, -0.75, 0.0);
    
    glLineStipple (1, 0x1C47);  /*  dash/dot/dash  */
    
    drawOneLine (-0.25, -0.2, -0.75, -0.2);
    
    glLineWidth (1.0);
    
    ///* in 4th row, 6 independent lines with same stipple  */
    
    int i;
    
    for (i = 0; i < 6; i++) {
        
        drawOneLine (0.05 + ((GLfloat) i * 0.01), 0.5,
                     
                     0.05 + ((GLfloat)(i+1) * 0.01), 0.5);
        
    }
    
    //
    
    ///* in 5th row, 1 line, with dash/dot/dash stipple    */
    
    ///* and a stipple repeat factor of 5                  */
    
    glLineStipple (5, 0x1C47);  /*  dash/dot/dash  */
    
    drawOneLine (50.0, 25.0, 350.0, 25.0);
    
    
    
    glDisable (GL_LINE_STIPPLE);
    
    
    
}


void drawLineStrip()

{
    
    glColor3f (0.0, 0.0, 1.0);
    
    glPointSize(5);
    
    // glBegin(GL_LINE_STRIP);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2f(0.0,0.0);
    
    glVertex2f(-0.3,-0.5);
    
    glVertex2f(0.3,-0.5);
    
    glEnd ();
    
}


void myDisplay(void)

{
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    // glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    
    
    
    //设置颜色
    
    glColor3f(1.0,1.0,0.0);
    
    
    
    //画出矩形
    
    glBegin(GL_POLYGON);
    
    glVertex3f(0.25,0.25,0.25);
    
    glVertex3f(0.75,0.25,0.0);
    
    glVertex3f(0.75,0.75,0.0);
    
    glVertex3f(0.25,0.75,0.0);
    
    //glVertex3f(0.0,0.5,0.0);
    
    glEnd();
    
    drawPoint();
    
    drawLines();
    
    drawLineStripple();
    
    drawLineStrip();
    
    glFlush();
    
}



void drawARect(){
    
    glClear(GL_COLOR_BUFFER_BIT); //表示清除颜色
    
    //画一个多边形
    
    glBegin(GL_POLYGON);
    
    //函数命名规则 gl前缀+Vertex内容+2参数个数+f参数类型
    
    glVertex2f(-0.5, -0.5);
    
    glVertex2f(-0.5, 0.5);
    
    glVertex2f(0.5, 0.5);
    
    glVertex2f(0.5, -0.5);
    
    glEnd();
    
    glFlush();  //让GL命令立即执行
    
}


const int n = 20;

const GLfloat R = 0.5f;

const GLfloat Pi = 3.1415926536f;

void drawARound(){
    
    int i ;
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    
    for (i = 0; i< n; ++i) {
        
        glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));
        
    }
    
    glEnd();
    
    glFlush();
    
}


void drawAFiveStar(){
    
    glClear(GL_COLOR_BUFFER_BIT); //表示清除颜色
    
    GLfloat a = 1 / (2-2*cos(72*Pi/180));
    
    GLfloat bx = a * cos(18 * Pi/180);
    
    GLfloat by = a * sin(18 * Pi/180);
    
    GLfloat cy = -a * cos(18 * Pi/180);
    
    GLfloat
    
    PointA[2] = { 0, a },
    
    PointB[2] = { bx, by },
    
    PointC[2] = { 0.5, cy },
    
    PointD[2] = { -0.5, cy },
    
    PointE[2] = { -bx, by };
    
    
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 按照A->C->E->B->D->A的顺序，可以一笔将五角星画出
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2fv(PointA);
    
    glVertex2fv(PointC);
    
    glVertex2fv(PointE);
    
    glVertex2fv(PointB);
    
    glVertex2fv(PointD);
    
    glEnd();
    
    glFlush();
    
}


const GLfloat factor = 0.1f;

void drawSins(){
    
    glClear(GL_COLOR_BUFFER_BIT); //表示清除颜色
    
    GLfloat x;
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_LINES);
    
    glVertex2f(-1.0f, 0.0f);
    
    glVertex2f(1.0f, 0.0f);         // 以上两个点可以画x轴
    
    glVertex2f(0.0f, -1.0f);
    
    glVertex2f(0.0f, 1.0f);         // 以上两个点可以画y轴
    
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    
    for(x=-1.0f/factor; x<1.0f/factor; x+=0.01f)
        
    {
        
        glVertex2f(x*factor, sin(x)*factor);
        
    }
    
    glEnd();
    
    glFlush();
    
}


int main(int argc, char * argv[])
{
    
    glutInit(&argc, argv);
    
    //设置显示模式，RGB,单缓存
    
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    
    //设置窗体位置
    
    glutInitWindowPosition(100, 100);
    
    //设置窗体大小
    
    glutInitWindowSize(400, 400);
    
    //创建窗体但不显示
    
    glutCreateWindow("第一个OpenGL程序");
    
    //设置显示时刷新的函数体   当需要显示时，调用display
    
//    glutDisplayFunc(&drawARect);
    
//    glutDisplayFunc(&drawARound);
    
//    glutDisplayFunc(&drawAFiveStar);
    
//    glutDisplayFunc(&drawSins);
    
    glutDisplayFunc(&myDisplay);
    
    
    
    //显示
    
    glutMainLoop();
    
    return 0;
    
    
}