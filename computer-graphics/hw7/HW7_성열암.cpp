/////********************************************************************************/
///*                                    HW#7 :  조명 종합                                                    */
///*  작성자 : 성열암                                   날짜 : 2022년 11월 29일                    */
///*                                                                                                                   */
///*  문제 정의 : 전신 Can Robot에 조명 효과 구현                                               */
///*                - - - - - - -                                                                                   */
///* 기능 : <R 또는 r 키를 누르면> 양팔과 양다리를 적절히 움직여 달리는 모습   */
///   로봇에 조명을 입힘                                                                                     */
///   거울모드로 진행하였습니다                                                                         */
///   기존 로봇 구현에서 달리기 기능과 조명을 추가하였습니다.                              */
///   광원을 중간에 위치시켰습니다.                                                                    */
///   뛰는 모습을 관찰하기 쉽도록 View를 옆으로 설정하였습니다.                          */
///*                - - - - - - -                                                                                   */
///**********************************************************************************/

#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <cstring>
using namespace std;

GLint Running = true;

// 기존 기능들을 구현하기 위한 변수 선언
static int Heading=0, re_heading = 5;
static int shoulder_right = 0, elbow_right = 0;
static int re_shoulder_right = 5, re_elbow_right = 5;
static int shoulder_left = 0, elbow_left = 0;
static int re_shoulder_left = 5, re_elbow_left = 5;
static int leg_right = 0, Knee_right = 0;
static int re_leg_right = 5, re_Knee_right = 5;
static int leg_left = 0, Knee_left = 0;
static int re_leg_left = 5, re_Knee_left = 5;

// 달리기 동작 시 제어 값으로 사용되는 변수 선언
static int RunArmL = 0, RunArmR = 0;
static int re_RunArmL = 5, re_RunArmR = 5;
static int RunLegL = 0, RunLegR = 0;
static int re_RunLegL = 5, re_RunLegR = 5;
static int counttt = 0;

// 달리기 동작을 확인하기 쉽도록 View 시선을 옆으로 설정하
GLdouble eyeX = 1.0, eyeY = 0.0, eyeZ = 0.0;
GLdouble focusX = 0.0, focusY = 0.0, focusZ = 0.0;
GLdouble upX = 0.0, upY = 1.0, upZ = 0.0;

void RightArm() {
    // 오른팔 전체 그리기
    glPushMatrix();
    glRotatef(-50.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.7, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)shoulder_right, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glRotatef((GLfloat)RunArmR, 0.0, 1.0, 0.0); // 원점을 기준으로 회전
    glTranslatef(0.3, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동

   
    glPushMatrix();//---------------------------------------오른팔---------------------------------------
    glColor3f(1.0, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.5);
    glutSolidCube(1.0); // 윗팔
    glPopMatrix(); //---------------------------------------오른팔pop------------------------------------

    glTranslatef(0.3, 0.0, 0.0); // Pivot 지정 및 객체 이동

    glRotatef((GLfloat)elbow_right, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glRotatef(90, 0.0, 1.0, 0.0); // 원점을 기준으로 회전
    glTranslatef(0.3, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동

    //---------------------------------------오른아래팔---------------------------------------
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.6, 0.2, 0.5);
    glutSolidCube(1.0); // 아래팔
    glPopMatrix();
    //---------------------------------------오른아래팔pop------------------------------------

    glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 이동
    //glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.0, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동

    //---------------------------------------오른손---------------------------------------
    glPushMatrix();    // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.3, 0.3, 0.3);
    glutWireSphere(0.5, 10, 10);
    glPopMatrix();
    //---------------------------------------오른손pop------------------------------------
    glPopMatrix(); // 오른팔 전체 push
}

void LeftArm() {
    glPushMatrix(); // 왼팔 전체
    glRotatef(-140.0, 0.0, 0.0, 1.0);
    glTranslatef(0.1, -0.7, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)shoulder_left, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glRotatef((GLfloat)RunArmL, 0.0, 1.0, 0.0); // 원점을 기준으로 회전
    glTranslatef(0.3, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동

    glPushMatrix();//---------------------------------------왼팔---------------------------------------
    glColor3f(1.0, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.5);
    glutSolidCube(1.0); // 윗팔
    glPopMatrix(); //---------------------------------------왼팔pop------------------------------------

    glTranslatef(0.3, 0.0, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)elbow_left, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glRotatef(90, 0.0, 1.0, 0.0); // 원점을 기준으로 회전
    glTranslatef(0.3, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동

    //---------------------------------------왼아래팔---------------------------------------
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.6, 0.2, 0.5);
    glutSolidCube(1.0); // 아래팔
    glPopMatrix();
    //---------------------------------------왼아래팔pop------------------------------------
    glTranslatef(0.3, 0.0, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)elbow_left, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
    //---------------------------------------왼손---------------------------------------
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.3, 0.3, 0.3);
    glutWireSphere(0.5, 10, 10);
    glPopMatrix();
    //---------------------------------------왼손pop------------------------------------
    glPopMatrix(); // 왼팔 전체 push
}

void RightLeg() {
    glPushMatrix(); // 오른다리 전체
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.3, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)leg_right, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glRotatef((GLfloat)RunLegR, 0.0, 1.0, 0.0); // 원점을 기준으로 회전
    glTranslatef(0.4, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동

    glPushMatrix(); //---------------------------------------오른다리---------------------------------------
    glColor3f(0.0, 0.5, 1.0);
    glScalef(0.8, 0.2, 0.5);
    glutSolidCube(1.0); // 오른다리
    glPopMatrix(); //---------------------------------------오른다리pop------------------------------------

    glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)Knee_right, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glRotatef((GLfloat)-RunLegR, 0.0, 1.0, 0.0); // 원점을 기준으로 회전
    glTranslatef(0.4, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동

    //---------------------------------------오른아래다리---------------------------------------
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(0.0, 1.0, 0.5);
    glScalef(0.8, 0.2, 0.5);
    glutSolidCube(1.0); // 아래팔
    glPopMatrix();
    //---------------------------------------오른아래다리pop------------------------------------
    glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)Knee_right, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
    //---------------------------------------오른발---------------------------------------
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.3, 0.3, 0.3);
    glutWireSphere(0.5, 10, 10);
    glPopMatrix();
    //---------------------------------------오른발push------------------------------------
    glPopMatrix(); // 왼팔 전체 push
}

void LeftLeg() {
    glPushMatrix(); // 왼다리 전체
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(0.5, -0.3, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)leg_left, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glRotatef((GLfloat)RunLegL, 0.0, 1.0, 0.0); // 원점을 기준으로 회전
    glTranslatef(0.4, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동

    glPushMatrix(); //---------------------------------------왼다리---------------------------------------
    glColor3f(0.0, 0.5, 1.0);
    glScalef(0.8, 0.2, 0.5);
    glutSolidCube(1.0); // 왼다리
    glPopMatrix(); //---------------------------------------왼다리pop------------------------------------

    glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)Knee_left, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glRotatef((GLfloat)-RunLegL, 0.0, 1.0, 0.0); // 원점을 기준으로 회전
    glTranslatef(0.4, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동

    //---------------------------------------왼아래다리---------------------------------------
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(0.0, 1.0, 0.5);
    glScalef(0.8, 0.2, 0.5);
    glutSolidCube(1.0); // 아래다리
    glPopMatrix();
    //---------------------------------------왼아래다리pop------------------------------------ㅗ
    glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)Knee_left, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
    //---------------------------------------왼발---------------------------------------
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(0.0, 1.0, 0.0);
    glScalef(0.3, 0.3, 0.3);
    glutWireSphere(0.5, 10, 10);
    glPopMatrix();
    //---------------------------------------왼발pop------------------------------------
    glPopMatrix(); // 왼팔 전체 push
}

void Head() {
    glPushMatrix();//---------------------------------------왼팔---------------------------------------
    glTranslatef(0.0, 0.8, 0.0); // Pivot 지정 및 객체 이동
    glColor3f(0.0, 0.5, 1.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(Heading, 0.0, 1.0, 0.0);
    glScalef(0.7, 0.7, 0.7);
    glutWireSphere(0.5, 10, 10);
    glPopMatrix(); //---------------------------------------왼팔pop------------------------------------
}

// 광원 설정
void InitLight() {
    //조명 특성
    GLfloat light0_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat light0_diffuse[] = { 0.8, 0.7, 0.6, 1.0 };
    GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

    glEnable(GL_DEPTH_TEST); //깊이 버퍼 활성화
    glEnable(GL_LIGHTING); //조명 활성화
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
}

void MyDisplay() {
    GLfloat LightPosition[] = { 0.0, 0.0, 1.5, 1.0 };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5); // 색상이 전역변수로 바뀌도록 설정
    glPushMatrix();//---------------------------------------초기설정push---------------------------------------
    gluLookAt(eyeX, eyeY, eyeZ, focusX, focusY, focusZ, upX, upY, upZ);
    glTranslatef(0.0, 1.0, 0.0);
    glScalef(1.0, 2.0, 1.0);
    glutSolidCube(1.0); // 몸통
    
    RightArm(); // 오른팔
    LeftArm(); // 왼팔
    RightLeg(); // 오른다리
    LeftLeg(); // 왼다리
    Head(); // 머리

    glPopMatrix();//---------------------------------------초기설정pop---------------------------------------
    glutSwapBuffers();
}

void MyTimer(int value) {
    // 타이머 콜백함수를 이용하여 머리, 팔, 다리를 움직였다가 돌아오게함
    if (value == 1 && Running) {
        Heading += re_heading;
        if (Heading == 0) {
            re_heading == 0;
            return;
        }
        
        if (Heading >= 90) re_heading = -5;
        else if (Heading <= -90) re_heading = 5;
        glutTimerFunc(50, MyTimer, 1);
    } else if (value == 2 && Running) {
        // 회전한 후 다시 돌아오도록 설정함 아래도 이와 같음
        shoulder_left -= re_shoulder_left;
        elbow_left += re_elbow_left;
        if (shoulder_left >= 0) {
            re_shoulder_left = 5;
            re_elbow_left = 5;
            if (shoulder_left == 0) return;
        } else if (shoulder_left <= -90) {
            re_shoulder_left = -5;
            re_elbow_left = -5;
        }
        glutTimerFunc(50, MyTimer, 2);
    } else if (value == 3 && Running) {
        shoulder_right += re_shoulder_right;
        if (shoulder_right >= 90) {
            re_shoulder_right = -5;
        } else if (shoulder_right <= 0) {
            re_shoulder_right = 5;
            if (shoulder_right == 0) return;
        }
        glutTimerFunc(50, MyTimer, 3);
    } else if (value == 4 && Running) {
        leg_left -= re_leg_left;
        if (leg_left >= 0) {
            re_leg_left = 5;
            if (leg_left == 0) return;
        } else if (leg_left <= -90) re_leg_left = -5;
        glutTimerFunc(50, MyTimer, 4);
    } else if (value == 5 && Running) {
        leg_right += re_leg_right;
        Knee_right -= re_Knee_right;
        if (leg_right >= 90) {
            re_leg_right = -5;
            re_Knee_right = -5;
        } else if (leg_right <= 0) {
            re_leg_right = 5;
            re_Knee_right = 5;
            if (leg_right == 0) return;
        }
        glutTimerFunc(50, MyTimer, 5);
    } else if (value == 6 && Running) { // 달리는 모습 구현
        RunArmL += re_RunArmL;
        RunArmR -= re_RunArmR;

        RunLegL -= re_RunLegL;
        // 왼쪽 다리가 먼저 시작하도록 조건을 맞춤
        if (counttt == 1) RunLegR += re_RunLegR;
        // 앞뒤로 팔을 움직임
        if (RunArmL >= 30) {
            re_RunArmL = -5;
            re_RunArmR = -5;
        } else if (RunArmL <= -30) {
            re_RunArmL = 5;
            re_RunArmR = 5;
        }

        // 달리기할 때 다리는 앞으로 가기에 앞에서만 움직이도록 각도를 설정함
        if (RunLegL >= 60) {
            counttt = 1;
            re_RunLegL = 5;

        } else if (RunLegL <= 0) re_RunLegL = -5;
        if (RunLegR >= 60) re_RunLegR = -5;
        else if (RunLegR <= 0) re_RunLegR = 5;
        glutTimerFunc(50, MyTimer, 6);
    }
    glutPostRedisplay();
}

// 메뉴를 누르면 타이머콜백을 이용하여 각 기능들이 수행되도록 함
void MyMainMenu(int entryID) {
    Running = true;
    if (entryID == 1)           glutTimerFunc(50, MyTimer, 1);
    else if (entryID == 2)      glutTimerFunc(50, MyTimer, 2);
    else if (entryID == 3)      glutTimerFunc(50, MyTimer, 3);
    else if (entryID == 4)      glutTimerFunc(50, MyTimer, 4);
    else if (entryID == 5)      glutTimerFunc(50, MyTimer, 5);
    else if (entryID == 6)      exit(0);
    glutPostRedisplay(); // 현재의 윈도우를 재생하도록 요구
}

// Running은 멈추고 다시 실행시키기 위한 변수
void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's':
        Running = false;
        break;
    case 'r':
        Running = true;
        glutTimerFunc(50, MyTimer, 6);
        break;
    case 'R':
        Running = true;
        glutTimerFunc(50, MyTimer, 6);
        break;
    }
    glutPostRedisplay();
}

// 사용자 초기화 함수 정의
void MyInit() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //신체 메뉴 설정
    glutAddMenuEntry("Head Moving", 1);
    glutAddMenuEntry("LeftArm Moving", 2);
    glutAddMenuEntry("RightArm Moving", 3);
    glutAddMenuEntry("LeftLeg Moving", 4);
    glutAddMenuEntry("RightLeg Moving", 5);
    glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

// main 함수 정의
int main(int argc, char** argv) {
    glutInit(&argc, argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // 디스플레이 모드 초기화
    glutInitWindowSize(800, 600); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(100, 100); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Lighting Can Robot"); // 인수를 타이틀로 지정한 Window(창) 생성
    InitLight(); // 조명 설정
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutReshapeFunc(MyReshape); // Window(창)의 크기 변경에 대한 이벤트 콜백함수 등록
    glutKeyboardFunc(MyKeyboard); // 키보드 이벤트 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
