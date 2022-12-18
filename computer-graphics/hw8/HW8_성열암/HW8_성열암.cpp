/////********************************************************************************/
///*                                    HW#8 :  종합                           */
///*  작성자 : 성열암                                   날짜 : 2022년 12월 18일     */
///*                                                                                */
///*  문제 정의 :                                                                   */
///   지금까지 수행한 실습과제의 내용을 종합하여 객체를 모델링                      */
///*  하고, 콜백프로그래밍, 모델변환, 시점변환, 투영변환, 뷰폿변환, 가시성          */
///*  검사, 조명, 텍스춰 등 수업시간에 배웠던 기술이 모두 쓰일 수 있도록            */
///*  프로그램을 만들어보시오.                                                      */
///*                - - - - - - -                                                   */
///* 기능 :                                                                         */
///* 1.  각 문의 상단에 문 번호와, 모델링된 캐릭터 하단에 프로그램 진행 상황을        */
///*  안내해 주는 텍스트를 표시합니다.
///* 2.  메뉴 창에서 “Shuffle the answer” 메뉴 클릭 시 각 문 뒤로
///* (O: 1개, X: 2개) 모델링 모형의 위치가 임의로 지정되어 배치되며,
///* 프로그램의 진행(몬티홀 딜레마의 검증 초기 설정)이 시작됩니다.            */
///* 3.  2번 기능 실행 후, 메뉴 창에서 “Open the door (1, 2, 3)” 중에서
///* 하나의 메뉴 클릭 시 X가 배치되어 있는 위치 중 임의의 한 곳을 프로그램이
///* 선택하여 해당 위치의 문을 자동적으로 열고 닫습니다.(몬티홀 딜레마 1단계)             */
///* 4.  3번 기능 실행 후, 메뉴 창에서 “Open the door (1, 2, 3)”를 마지막으로
///* 다시 클릭 시, 선택했던 문이 열림과 동시에 캐릭터가 해당 문을 향해 회전하여 손으로
///* 가리키게 되고, 1번 기능에서 (O, X) 모델링 모형의 위치가 정해졌던 대로 문 뒤에 위치하고
///* 있던 모델링 모형(O 또는 X)이 보이게 되며, O가 위치한 문이 선택되었을 때 “You're Right!!”,
///* X가 위치한 문이 선택되었을 때에는 “You're wrong..” 라는 텍스트와 함께 몬티홀 딜레마의
///* 한 단계 검증 과정이 마무리됩니다.             */
///* 5. 메뉴 창에서 “(Show/No Show) the answer” 클릭 시 후면 및 은면 제거 기능이 적용되어
///* 문 뒤의 숨겨진 답을 볼 수 있게 됩니다.              */
///* 6. 메뉴 창에서 “Apply (ON/OFF) the Light Effect” 클릭 시 조명 효과가 적용됩니다.
///* 7. A, S, D, W 및 키보드 우측의 방향키 입력 시 카메라의 방향과 위치를 조정할 수 있습니다.
///* 8. 키보드 상단의 F1키 입력 시 카메라의 방향과 위치를 초기 상태로 되돌립니다.
///* 9. 메뉴 창에서 “Exit” 클릭 시 프로그램이 종료됩니다.                                                     */
///*                - - - - - - -                                                   */
///**********************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/glaux.h>
#include <iostream>
#include <cstring>
#include <time.h>

#pragma comment(lib, "glaux.lib")
#pragma comment (lib,"legacy_stdio_definitions.lib")

using namespace std;

// 캐릭터 및 문 모션 동작 시 제어 값으로 사용되는 변수 선언
static int Heading = 0, re_heading = 5;
static int shoulder_right = 0, elbow_right = 0;
static int re_shoulder_right = 5, re_elbow_right = 5;
static int shoulder_left = 0, elbow_left = 0;
static int re_shoulder_left = 5, re_elbow_left = 5;
static int leg_right = 0, Knee_right = 0;
static int re_leg_right = 5, re_Knee_right = 5;
static int leg_left = 0, Knee_left = 0;
static int re_leg_left = 5, re_Knee_left = 5;
static int RunArmL = 0, RunArmR = 0;
static int re_RunArmL = 5, re_RunArmR = 5;
static int RunLegL = 0, RunLegR = 0;
static int re_RunLegL = 5, re_RunLegR = 5;
static int door_1 = 0, re_door_1 = 5;
static int door_2 = 0, re_door_2 = 5;
static int door_3 = 0, re_door_3 = 5;
static double correctPosX = 0, wrong_1PosX = -0.5, wrong_2PosX = -0.5;
static int userDegree = 0;

// 카메라 시점 조정 시 제어 값으로 사용되는 변수 선언
GLdouble eyeX = 0.0, eyeY = 0.3, eyeZ = 1.0;
GLdouble focusX = 0.0, focusY = 0.0, focusZ = 0.0;
GLdouble upX = 0.0, upY = 0.1, upZ = 0.0;

// 정답 및 오답의 위치를 지정하기 위한 난숫값으로 사용되는 변수 선언
int randNum, randNum2;

// 조명 및 은면/후면 제거의 여부를 판별하기 위한 변수 선언
int showAns = 0;
int showLight = 0;

// 몬티홀 딜레마의 시연 단계(step)를 저장하기 위한 변수 선언
int continueStep = 0;

// 문의 첫 번째 선택 여부를 파악하기 위한 변수 선언
int firstChoose = 1;

// 사용자가 몇 번 문을 선택하였는지 그 값을 저장하기 위한 변수
int userChoose = 0;

// 문(1~3)이 현재 움직이고 있는지의 여부를 파악하기 위한 변수 선언
int door_running = false;

// 안내 문구 텍스트 문자열이 저장될 변수 선언
char choosingMsg[100];

// 텍스쳐 매핑의 비트맵 이미지로 사용될 파일명 저장 변수 선언
char fileName[100];

// 텍스쳐 매핑 변수 선언
GLuint texture[1];

// 화면에 텍스트 표시
void drawText(float x, float y, float z, std::string text) {
    glRasterPos3f(x, y, z);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

/* 몬티홀 딜레마의 시연 단계(step)에 따른 적절한
 텍스트를 화면에 표시해 주기 위하여 사용하는 함수 */
void drawGameSupportText() {
    glutSwapBuffers();
    // 유저가 Shuffle the answer 메뉴 클릭 후 문을 처음으로 선택하였을 때의 조건
    if (continueStep == 2) {
        if (userChoose == 1)
            strcpy_s(choosingMsg, "You choose No.1 door. Change or not??");
        else if (userChoose == 2)
            strcpy_s(choosingMsg, "You choose No.2 door. Change or not??");
        else if (userChoose == 3)
            strcpy_s(choosingMsg, "You choose No.3 door. Change or not??");
    }
    // 유저가 문을 두 번째로 선택하였을 때의 조건
    else if (continueStep == 3) {
        if (userChoose == randNum)
            strcpy_s(choosingMsg, "You're Right!!");
        else
            strcpy_s(choosingMsg, "You're wrong..");
    }

    switch (continueStep) {
        case 0: // 프로그램을 처음 실행했을 때의 단계
            drawText(-6, -3, 0, "Please, SELECT (Shuffle the answer) MENU!!");
            break;
        case 1: // 메뉴에서 Shuffle the answer를 클릭한 이후의 단계
            drawText(-4, -3, 0, "Choose the door on the MENU!!");
            break;
        case 2: // 첫 번째로 문을 선택하였을 때의 단계
            drawText(-5.5, -3, 0, choosingMsg);
            break;
        case 3: // 두 번째로 문을 선택하였을 때의 단계
            drawText(-2, -3, 0, choosingMsg);
            drawText(-9, -4, 0, "If you want to play again, select (Shuffle the answer) MENU");
            break;
    }
}

// 텍스쳐 매핑을 위한 함수 정의
AUX_RGBImageRec* LoadBMP(const char* Filename) {
    FILE* File = NULL;
    if (!Filename) return NULL;
    fopen_s(&File, Filename, "r");

    // seFilename을 유니코드 스트링으로 바꾸기
    int size = strlen(Filename);
    wchar_t* w_Filename = new wchar_t[size];

    for (int i = 0; i < size; ++i)  w_Filename[i] = Filename[i];
    w_Filename[size] = NULL;

    if (File) {
        fclose(File);
        // 파일에서 메모리로 로드
        return auxDIBImageLoad(w_Filename);
    }
    return NULL;
}

// 텍스쳐 매핑 수행 함수 정의
void LoadGLTextures() {
    int Status = FALSE;
    AUX_RGBImageRec* TextureImage[1];
    memset(TextureImage, 0, sizeof(void*) * 1);

    // 프로젝트 폴더 내 fileName으로 존재하는 파일을 기반으로 텍스쳐 매핑 기능 수행
    if (TextureImage[0] = LoadBMP(fileName)) {
        Status = TRUE;
        glGenTextures(1, &texture[0]);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
    }
    if (TextureImage[0]) {
        if (TextureImage[0]->data) {
            free(TextureImage[0]->data);
        }

        free(TextureImage[0]);
    }
    return;
}

// (은면/후면) 제거 기능 수행 함수 정의
void InitVisibility() {
    if (showAns) { // showAns가 참일 때 수행
        // (은면/후면) 제거 기능 적용
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CW);
        glPolygonMode(GL_BACK, GL_LINE);
        glCullFace(GL_FRONT);
        glEnable(GL_DEPTH_TEST);
    } else { // showAns가 거잣일 때 수행
        // (은면/후면) 제거 기능 해제
        glDisable(GL_CULL_FACE);
        glPolygonMode(GL_BACK, GL_FILL);
        glDisable(GL_DEPTH_TEST);
    }
}

// 광원 설정 함수 정의
void InitLight() {
    if (showLight) {
        //조명 특성 정의
        GLfloat ambient[] = { 0.5, 0.4, 0.3, 1 };
        GLfloat diffuse[] = { 0.8, 0.7, 0.6, 1 };
        GLfloat specular[] = { 1, 1, 1, 1 };
        GLfloat position[] = { 100, 100, 0, -10 };

        // Gouraud 쉐이딩 적용
        glShadeModel(GL_SMOOTH);

        glClearColor(0, 0, 0, 0);
        glEnable(GL_DEPTH_TEST); // 깊이 버퍼 활성화
        glEnable(GL_LIGHTING); // 조명 활성화
        glEnable(GL_LIGHT0); // 0번 조명 활성화

        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient); // 주변광 적용
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse); // 반사광 적용
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular); // 분산광 적용
        glLightfv(GL_LIGHT0, GL_POSITION, position); // 광원 위치 설정
    } else {
        glDisable(GL_LIGHTING); // 조명 비활성화
        glDisable(GL_LIGHT0); // 0번 조명 비활성화
    }
}

// 바닥을 그리는 함수 정의
void DrawGround() {
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(-12.0, -2.3, 10.0);
    glVertex3f(12.0, -2.3, 10.0);
    glVertex3f(12.0, -2.3, -10.0);
    glVertex3f(-12.0, -2.3, -10.0);
    glEnd();
}

// 정답 및 오답 모델링 모형을 그리는 함수 정의
void DrawRandomAnswer() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
        // 정답(동그라미)
        glTranslatef(-8.0, 0.8, -12.5); // Pivot 지정 및 객체 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0, 0, 1.0); // 객체 색 지정
            glScalef(1.5, 1, 1); // 객체 크기 조정
            glTranslatef(correctPosX, 0, 0); // Pivot 지정 및 객체 이동
            glutSolidTorus(0.2, 0.8, 2, 100); // Torus 그리기
        glPopMatrix(); // 그리기 종료

        // 오답-1(엑스)
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glTranslatef(wrong_1PosX, 0, -4.5); // Pivot 지정 및 객체 이동
            glColor3f(1, 0, 0); // 객체 색 지정
            glLineWidth(5); // 라인 두께 조정
            glBegin(GL_LINES); // 선 그리기 시작
            glVertex3f(0, 0.5, 5); // 정점(1) 지정
            glVertex3f(1.3, -0.5, 5); // 정점(2) 지정
            glEnd(); // 선 그리기 종료
            glBegin(GL_LINES); // 선 그리기 시작
            glVertex3f(0, -0.5, 5); // 정점(1) 지정
            glVertex3f(1.3, 0.5, 5); // 정점(2) 지정
            glEnd(); // 선 그리기 종료
        glPopMatrix(); // 그리기 종료

        // 오답-2(엑스)
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glTranslatef(wrong_2PosX, 0, -4.5); // Pivot 지정 및 객체 이동
            glColor3f(1, 0, 0); // 객체 색 지정
            glLineWidth(5); // 라인 두께 조정
            glBegin(GL_LINES); // 선 그리기 시작
            glVertex3f(0, 0.5, 5); // 정점(1) 지정
            glVertex3f(1.3, -0.5, 5); // 정점(2) 지정
            glEnd(); // 선 그리기 종료
            glBegin(GL_LINES); // 선 그리기 시작
            glVertex3f(0, -0.5, 5); // 정점(1) 지정
            glVertex3f(1.3, 0.5, 5); // 정점(2) 지정
            glEnd(); // 선 그리기 종료
        glPopMatrix(); // 그리기 종료
    glPopMatrix(); // 그리기 종료
}

// 좌측 벽을 그리는 함수 정의
void LeftWall() {
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-12.0, -2.3, 10.0);
    glVertex3f(-12.0, -2.3, -10.0);
    glVertex3f(-12.0, 5, -10.0);
    glVertex3f(-12.0, 5, 10.0);
    glEnd();
}

// 우측 벽을 그리는 함수 정의
void RightWall() {
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(12.0, -2.3, -10.0);
    glVertex3f(12.0, -2.3, 10.0);
    glVertex3f(12.0, 5, 10.0);
    glVertex3f(12.0, 5, -10.0);
    glEnd();
}

// 정면 벽을 그리는 함수 정의
void FrontWall() {
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-12.0, -2.3, -10.0);
    glVertex3f(-9, -2.3, -10.0);
    glVertex3f(-9, 5, -10.0);
    glVertex3f(-12.0, 5, -10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-9, 2, -10.0);
    glVertex3f(-5, 2, -10.0);
    glVertex3f(-5, 5, -10.0);
    glVertex3f(-9, 5, -10.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-5, -2.3, -10.0);
    glVertex3f(-2, -2.3, -10.0);
    glVertex3f(-2, 5, -10.0);
    glVertex3f(-5, 5, -10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-5, 2, -10.0);
    glVertex3f(2, 2, -10.0);
    glVertex3f(2, 5, -10.0);
    glVertex3f(-5, 5, -10.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(2, -2.3, -10.0);
    glVertex3f(5, -2.3, -10.0);
    glVertex3f(5, 5, -10.0);
    glVertex3f(2, 5, -10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(5, 2, -10.0);
    glVertex3f(9, 2, -10.0);
    glVertex3f(9, 5, -10.0);
    glVertex3f(5, 5, -10.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(9.0, -2.3, -10.0);
    glVertex3f(12, -2.3, -10.0);
    glVertex3f(12, 5, -10.0);
    glVertex3f(9.0, 5, -10.0);
    glEnd();

    // 1번 문 그리기
    glPushMatrix(); // 원점을 기준으로 객체 생성
        glTranslatef(-5.6, -0.18, -10.5); // Pivot 지정 및 객체 이동
        glRotatef(door_1, 0.0, 1.0, 0.0); // 원점을 기준으로 객체 회전
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(1, 1, 1); // 객체 색 지정
            glTranslatef(-1.5, 0, 0); // Pivot 지정 및 객체 이동
            glScalef(4.2, 4.35, 0.5); // 객체 크기 조정
            // 텍스쳐 매핑 시 사용할 비트맵 파일명 설정
            strcpy_s(fileName, "woodenTexture.bmp");
            LoadGLTextures(); // 텍스쳐 매핑 수행
            glutSolidCube(1); // 큐브 그리기
            // 명명된 텍스쳐 바인딩 생성
            glBindTexture(GL_TEXTURE_2D, 0);
        glPopMatrix(); // 그리기 종료
    glPopMatrix(); // 그리기 종료

    // 2번 문 그리기
    glPushMatrix();
        glTranslatef(1.5, -0.18, -10.5); // Pivot 지정 및 객체 이동
        glRotatef(door_2, 0.0, 1.0, 0.0); // 원점을 기준으로 객체 회전
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.7, 0.5, 0); // 객체 색 지정
            glTranslatef(-1.5, 0, 0); // Pivot 지정 및 객체 이동
            glScalef(4.2, 4.35, 0.5); // 객체 크기 조정
            //LoadGLTextures();
            glutSolidCube(1); // 큐브 그리기
            //glBindTexture(GL_TEXTURE_2D, 0);
        glPopMatrix(); // 그리기 종료
    glPopMatrix(); // 그리기 종료

    // 3번 문 그리기
    glPushMatrix();
        glTranslatef(8.6, -0.18, -10.5); // Pivot 지정 및 객체 이동
        glRotatef(door_3, 0.0, 1.0, 0.0); // 원점을 기준으로 객체 회전
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.9, 0.8, 1); // 객체 색 지정
            glTranslatef(-1.5, 0, 0); // Pivot 지정 및 객체 이동
            glScalef(4.2, 4.35, 0.5); // 객체 크기 조정
            //LoadGLTextures();
            glutSolidCube(1); // 큐브 그리기
            //glBindTexture(GL_TEXTURE_2D, 0);
        glPopMatrix(); // 그리기 종료
    glPopMatrix(); // 그리기 종료
}

// 캐릭터의 오른팔 전체를 그리는 함수 정의
void RightArm() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
    glRotatef(-50.0, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
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
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();
    //---------------------------------------오른손pop------------------------------------
    glPopMatrix(); // 오른팔 전체 push
}

// 캐릭터의 왼팔 전체를 그리는 함수 정의
void LeftArm() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
    glRotatef(-140.0, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
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
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();
    //---------------------------------------왼손pop------------------------------------
    glPopMatrix(); // 왼팔 전체 push
}

// 캐릭터의 오른다리 전체를 그리는 함수 정의
void RightLeg() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
    glRotatef(-90.0, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
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
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();
    //---------------------------------------오른발push------------------------------------
    glPopMatrix(); // 왼팔 전체 push
}

// 캐릭터의 왼다리 전체를 그리는 함수 정의
void LeftLeg() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
    glRotatef(-90.0, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
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
    glutSolidSphere(0.5, 10, 10);
    glPopMatrix();
    //---------------------------------------왼발pop------------------------------------
    glPopMatrix(); // 왼팔 전체 push
}

// 캐릭터의 머리를 그리는 함수 정의
void Head() {
    glPushMatrix();//---------------------------------------머리---------------------------------------
    glLineWidth(1); // 라인 두께 조정
    glTranslatef(0.0, 0.8, 0.0); // Pivot 지정 및 객체 이동
    glColor3f(0.5, 0.5, 1.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(Heading, 0.0, 1.0, 0.0);
    glScalef(0.7, 0.7, 0.7);
    glutWireSphere(0.5, 10, 10);
    glPopMatrix(); //---------------------------------------머리pop------------------------------------
}

// 캐릭터를 그리는 함수 정의
void DrawCharacter() {
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
    glRotatef(userDegree, 0, 1, 0); // 원점을 기준으로 캐릭터 회전
    Head(); // 머리 그리기
    RightArm(); // 오른팔 그리기
    LeftArm(); // 왼팔 그리기
    RightLeg(); // 오른다리 그리기
    LeftLeg(); // 왼다리 그리기
    glColor3f(0.2, 0.2, 0.2); // 객체 색 지정
    glutSolidCube(1.0); // 몸통 그리기
    glPopMatrix(); // 그리기 종료
}

// 디스플레이 콜백 함수 정의
void MyDisplay() {
    InitLight(); // 조명 설정 함수 호출
    InitVisibility(); // (후면/은면) 설정 호출

    GLfloat LightPosition[] = { 0.0, 0.0, 1.5, 1.0 }; // 조명 위치값 변수 선언
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 버퍼 초기화
    glColor3f(0.5, 0.5, 0.5); // 색상이 전역변수로 바뀌도록 설정
    glPushMatrix();//---------------------------------------초기설정push---------------------------------------
    gluLookAt(eyeX, eyeY, eyeZ, focusX, focusY, focusZ, upX, upY, upZ); // 시점 좌표 설정
    glTranslatef(0.0, 1.0, 0.0); // Pivot 지정 및 객체 이동
    glScalef(1.0, 2.0, 1.0); // 객체 크기 조정

    DrawRandomAnswer(); // (정답 및 오답) 모델링 모형 그리기

    DrawGround(); // 바닥 그리기
    LeftWall(); // 좌측벽 그리기
    RightWall(); // 우측벽 그리기
    FrontWall(); // 정면벽 그리기

    DrawCharacter(); // 캐릭터 그리기

    drawText(-8.0, 2.2, -9.5, "Door 1"); // 1번 문 위에 텍스트 추가
    drawText(-1.4, 2.2, -9.5, "Door 2"); // 2번 문 위에 텍스트 추가
    drawText(5.3, 2.2, -9.5, "Door 3"); // 3번 문 위에 텍스트 추가

    drawGameSupportText(); // 화면 내 안내 문구 텍스트를 추가하는 함수 호출

    glutSwapBuffers(); // 버퍼 교체

    glPopMatrix();//---------------------------------------초기설정pop---------------------------------------
    glutSwapBuffers(); // 버퍼 교체
}

// 타이머 콜백 함수 정의
void MyTimer(int value) {
    if (value == 1) { // 메뉴 창에서 Shuffle the answer 클릭 시 수행하는 조건
        // 캐릭터 및 문의 위치를 초기화
        continueStep = 1;
        userDegree = 0;
        eyeX = 0.0, eyeY = 0.3, eyeZ = 1.0;
        focusX = 0.0, focusY = 0.0, focusZ = 0.0;
        upX = 0.0, upY = 0.1, upZ = 0.0;
        RunArmL = 0, RunArmR = 0;
        re_RunArmL = 5, re_RunArmR = 5;
        RunLegL = 0, RunLegR = 0;
        re_RunLegL = 5, re_RunLegR = 5;
        shoulder_right = 0, elbow_right = 0;
        re_shoulder_right = 5, re_elbow_right = 5;
        shoulder_left = 0, elbow_left = 0;
        re_shoulder_left = 5, re_elbow_left = 5;
        leg_right = 0, Knee_right = 0;
        re_leg_right = 5, re_Knee_right = 5;
        leg_left = 0, Knee_left = 0;
        re_leg_left = 5, re_Knee_left = 5;
        door_1 = 0;
        door_2 = 0;
        door_3 = 0;
        door_running = false;
        firstChoose = 1;
        userChoose = 0;
        randNum = rand() % 3 + 1;
        cout << "\n정답: " << randNum << "번 문\n";
        // 정답이 1번 문에 있을 때 (정답 및 오답) 모델링 모형의 위치 설정
        if (randNum == 1) {
            correctPosX = 0;
            wrong_1PosX = 7.3;
            wrong_2PosX = 15;
        }
        // 정답이 2번 문에 있을 때 (정답 및 오답) 모델링 모형의 위치 설정
        else if (randNum == 2) {
            correctPosX = 5.3;
            wrong_1PosX = -0.5;
            wrong_2PosX = 15;
        }
        // 정답이 3번 문에 있을 때 (정답 및 오답) 모델링 모형의 위치 설정
        else if (randNum == 3) {
            correctPosX = 10.5;
            wrong_1PosX = -0.5;
            wrong_2PosX = 7.3;
        }
    } else if (value == 2) { // 메뉴 창에서 Open the door 1 클릭 시 수행하는 조건
        if (continueStep == 1) { // Shuffle the answer 메뉴 클릭 후 처음으로 문을 선택하였을 때의 조건
            userChoose = 1;
            if (firstChoose == 1) {
                // 내가 선택한 문이 아닌 오답이 위치한 문들 중에서 임의의 문을 선택
                do {
                    randNum2 = rand() % 3 + 1;
                } while (randNum2 == randNum || randNum2 == userChoose);
                cout << "오답이 위치한 문: " << randNum2 << "번 문\n";
                firstChoose = 0;
            }
            
            // 내가 선택한 문이 아닌 오답이 위치한 문들 중에서 임의의 문을 선택하여 개방 후 닫음
            door_running = true;
            if (randNum2 == 2) {
                door_2 += re_door_2;
                if (door_2 == -5) {
                    door_2 = 0;
                    re_door_2 = 5;
                    continueStep = 2;
                    glutPostRedisplay();
                    door_running = false;
                    return;
                }
                
                if (door_2 >= 130) re_door_2 = -5;
                glutTimerFunc(50, MyTimer, 2);
            }
            else if (randNum2 == 3) {
                door_3 += re_door_3;
                if (door_3 == -5) {
                    door_3 = 0;
                    re_door_3 = 5;
                    continueStep = 2;
                    glutPostRedisplay();
                    door_running = false;
                    return;
                }
                
                if (door_3 >= 130) re_door_3 = -5;
                glutTimerFunc(50, MyTimer, 2);
            }
        }
        // 두 번째 이후로 문을 선택하였을 때의 조건
        else if (continueStep == 2 || continueStep == 3) {
            userChoose = 1;
            continueStep = 3;
            
            userDegree = 35;
            shoulder_left -= re_shoulder_left;
            elbow_left += re_elbow_left;
            if (shoulder_left >= 0) {
                re_shoulder_left = 5;
                re_elbow_left = 5;
            }
            else if (shoulder_left <= -130) {
                re_shoulder_left = -5;
                re_elbow_left = -5;
            }
            
            door_running = true;
            door_1 += re_door_1;
            if (door_1 == -5) {
                door_1 = 0;
                re_door_1 = 5;
                door_running = false;
                return;
            }
            
            if (door_1 >= 130) re_door_1 = -5;
            
            glutTimerFunc(50, MyTimer, 2);
        }
    } else if (value == 3) { // 메뉴 창에서 Open the door 2 클릭 시 수행하는 조건
        if (continueStep == 1) { // Shuffle the answer 메뉴 클릭 후 처음으로 문을 선택하였을 때의 조건
            userChoose = 2;
            if (firstChoose == 1) {
                // 내가 선택한 문이 아닌 오답이 위치한 문들 중에서 임의의 문을 선택
                do {
                    randNum2 = rand() % 3 + 1;
                } while (randNum2 == randNum || randNum2 == userChoose);
                cout << "오답이 위치한 문: " << randNum2 << "번 문\n";
                firstChoose = 0;
            }

            // 내가 선택한 문이 아닌 오답이 위치한 문들 중에서 임의의 문을 선택하여 개방 후 닫음
            door_running = true;
            if (randNum2 == 1) {
                door_1 += re_door_1;
                if (door_1 == -5) {
                    door_1 = 0;
                    re_door_1 = 5;
                    continueStep = 2;
                    glutPostRedisplay();
                    door_running = false;
                    return;
                }

                if (door_1 >= 130) re_door_1 = -5;
                glutTimerFunc(50, MyTimer, 3);
            }
            else if (randNum2 == 3) {
                door_3 += re_door_3;
                if (door_3 == -5) {
                    door_3 = 0;
                    re_door_3 = 5;
                    continueStep = 2;
                    glutPostRedisplay();
                    door_running = false;
                    return;
                }
                if (door_3 >= 130) re_door_3 = -5;
                glutTimerFunc(50, MyTimer, 3);
            }
        }
        // 두 번째 이후로 문을 선택하였을 때의 조건
        else if (continueStep == 2 || continueStep == 3) {
            userChoose = 2;
            continueStep = 3;

            userDegree = 0;
            shoulder_left -= re_shoulder_left;
            elbow_left += re_elbow_left;
            if (shoulder_left >= 0) {
                re_shoulder_left = 5;
                re_elbow_left = 5;
            }
            else if (shoulder_left <= -130) {
                re_shoulder_left = -5;
                re_elbow_left = -5;
            }

            door_running = true;
            door_2 += re_door_2;
            if (door_2 == -5) {
                door_2 = 0;
                re_door_2 = 5;
                door_running = false;
                return;
            }

            if (door_2 >= 130) re_door_2 = -5;
            glutTimerFunc(50, MyTimer, 3);
        }
    } else if (value == 4) { // 메뉴 창에서 Open the door 3 클릭 시 수행하는 조건
        if (continueStep == 1) { // Shuffle the answer 메뉴 클릭 후 처음으로 문을 선택하였을 때의 조건
            userChoose = 3;
            if (firstChoose == 1) {
                // 내가 선택한 문이 아닌 오답이 위치한 문들 중에서 임의의 문을 선택
                do {
                    randNum2 = rand() % 3 + 1;
                } while (randNum2 == randNum || randNum2 == userChoose);
                cout << "오답이 위치한 문: " << randNum2 << "번 문\n";
                firstChoose = 0;
            }

            // 내가 선택한 문이 아닌 오답이 위치한 문들 중에서 임의의 문을 선택하여 개방 후 닫음
            door_running = true;
            if (randNum2 == 1) {
                door_1 += re_door_1;
                if (door_1 == -5) {
                    door_1 = 0;
                    re_door_1 = 5;
                    continueStep = 2;
                    glutPostRedisplay();
                    door_running = false;
                    return;
                }

                if (door_1 >= 130) re_door_1 = -5;
                glutTimerFunc(50, MyTimer, 4);
            }
            else if (randNum2 == 2) {
                door_2 += re_door_2;
                if (door_2 == -5) {
                    door_2 = 0;
                    re_door_2 = 5;
                    continueStep = 2;
                    glutPostRedisplay();
                    door_running = false;
                    return;
                }

                if (door_2 >= 130) re_door_2 = -5;
                glutTimerFunc(50, MyTimer, 4);
            }
        }
        // 두 번째 이후로 문을 선택하였을 때의 조건
        else if (continueStep == 2 || continueStep == 3) {
            userChoose = 3;
            continueStep = 3;

            if (firstChoose == 1) {
                firstChoose = 0;
                return;
            }

            userDegree = -35;
            shoulder_right += re_shoulder_right;
            if (shoulder_right >= 130) {
                re_shoulder_right = -5;
            }
            else if (shoulder_right <= 0) {
                re_shoulder_right = 5;
            }

            door_running = true;
            door_3 += re_door_3;
            if (door_3 == -5) {
                door_3 = 0;
                re_door_3 = 5;
                door_running = false;
                return;
            }

            if (door_3 >= 130) re_door_3 = -5;
            glutTimerFunc(50, MyTimer, 4);
        }
    } else if (value == 5) // 메뉴 창에서 (Show/No Show) the answer 메뉴 클릭 시
        showAns = !showAns; // 기존 변숫값의 반대로 대입(On/Off 스위치 역할)
    else if (value == 6) // 메뉴 창에서 Apply (ON/OFF) the Light Effect 메뉴 클릭 시
        showLight = !showLight; // 기존 변숫값의 반대로 대입(On/Off 스위치 역할)
    glutPostRedisplay(); // 강제로 display event 발생
}

// 메뉴를 누르면 타이머콜백을 이용하여 각 기능들이 수행되도록 함
void MyMainMenu(int entryID) {
    if (entryID == 1) { // 1번 메뉴 클릭 시
        if (door_running) return;
        glutTimerFunc(50, MyTimer, 1);
    } else if (entryID == 2) { // 2번 메뉴 클릭 시
        if (door_running) return;
        glutTimerFunc(50, MyTimer, 2);
    } else if (entryID == 3) { // 3번 메뉴 클릭 시
        if (door_running) return;
        glutTimerFunc(50, MyTimer, 3);
    } else if (entryID == 4) { // 4번 메뉴 클릭 시
        if (door_running) return;
        glutTimerFunc(50, MyTimer, 4);
    } else if (entryID == 5) // 5번 메뉴 클릭 시
        glutTimerFunc(50, MyTimer, 5);
    else if (entryID == 6) // 6번 메뉴 클릭 시
        glutTimerFunc(50, MyTimer, 6);
    else if (entryID == 7) // 7번 메뉴 클릭 시
        exit(0); // 프로그램 강제 종료
    glutPostRedisplay(); // 강제로 display event 발생
}

// 키보드 콜백 함수 정의
void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': // a 입력 시 카메라를 왼쪽으로 이동
            eyeX -= 0.5;
            focusX -= 0.5;
            break;
        case 'A': // A 입력 시 카메라를 왼쪽으로 이동
            eyeX -= 0.5;
            focusX -= 0.5;
            break;
        case 'd': // d 입력 시 카메라를 오른쪽으로 이동
            eyeX += 0.5;
            focusX += 0.5;
            break;
        case 'D': // D 입력 시 카메라를 오른쪽으로 이동
            eyeX += 0.5;
            focusX += 0.5;
            break;
        case 'w': // w 입력 시 카메라를 앞으로 이동
            eyeZ -= 0.5;
            focusZ -= 0.5;
            break;
        case 'W': // W 입력 시 카메라를 앞으로 이동
            eyeZ -= 0.5;
            focusZ -= 0.5;
            break;
        case 's': // s 입력 시 카메라를 뒤로 이동
            eyeZ += 0.5;
            focusZ += 0.5;
            break;
        case 'S': // S 입력 시 카메라를 뒤로 이동
            eyeZ += 0.5;
            focusZ += 0.5;
            break;
        case 'q': // q 입력 시 카메라를 아래로 이동
            eyeY -= 0.5;
            focusY -= 0.5;
            break;
        case 'Q': // Q 입력 시 카메라를 아래로 이동
            eyeY -= 0.5;
            focusY -= 0.5;
            break;
        case 'e': // e 입력 시 카메라를 위로 이동
            eyeY += 0.5;
            focusY += 0.5;
            break;
        case 'E': // E 입력 시 카메라를 위로 이동
            eyeY -= 0.5;
            focusY -= 0.5;
            break;
        }
    glutPostRedisplay(); // 강제로 display event 발생
}

// 사용자 초기화 함수 정의
void MyInit() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // 객체 기본 색 설정
    glMatrixMode(GL_PROJECTION); // 투상 좌표계의 공간 앞으로 계산
    glLoadIdentity(); // 항등행렬로 초기화

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시부피 설정

    GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //신체 메뉴 설정
    glutAddMenuEntry("Shuffle the answer", 1); // 1번 메뉴 지정
    glutAddMenuEntry("Open the door 1", 2); // 2번 메뉴 지정
    glutAddMenuEntry("Open the door 2", 3); // 3번 메뉴 지정
    glutAddMenuEntry("Open the door 3", 4); // 4번 메뉴 지정
    glutAddMenuEntry("(Show/No Show) the answer", 5); // 5번 메뉴 지정
    glutAddMenuEntry("Apply (ON/OFF) the Light Effect", 6); // 6번 메뉴 지정
    glutAddMenuEntry("Exit", 7); // 7번 메뉴 지정
    glutAttachMenu(GLUT_RIGHT_BUTTON); // 마우스 우클릭 시 메뉴 창 표시
}

// 윈도우 창 크기 조절에 대한 콜백 함수 정의
void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // 뷰포트 설정
    glMatrixMode(GL_PROJECTION); // 투상 좌표계의 공간 앞으로 계산
    glLoadIdentity(); // 항등행렬로 초기화
    gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0); // 시야각 설정
    glMatrixMode(GL_MODELVIEW); // 모델 좌표계와 시점 좌표계의 공간을 앞으로 계산
    glLoadIdentity(); // 항등행렬로 초기화
    glTranslatef(0.0, -3.0, -7.0); // 위치 조정
}

// 키보드 특수키 입력에 대하여 처리해 주는 콜백 함수 정의
void MySpecial(int key, int x, int y) {
    switch (key) {
        eyeX = 0.0, eyeY = 30.8, eyeZ = 30.5;
        focusX = 0.0, focusY = 10.0, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;

        // 우측 방향키 입력 시 카메라 초점을 우측으로 이동
        case GLUT_KEY_RIGHT:
            focusX += 0.1;
            break;
        // 좌측 방향키 입력 시 카메라 초점을 좌측으로 이동
        case GLUT_KEY_LEFT:
            focusX -= 0.1;
            break;
        // 상향 방향키 입력 시 카메라 초점을 상단으로 이동
        case GLUT_KEY_UP:
            eyeY -= 0.1f;
            break;
        // 하향 방향키 입력 시 카메라 초점을 하단으로 이동
        case GLUT_KEY_DOWN:
            eyeY += 0.1f;
            break;
        // F1키 입력 시 시점, 캐릭터, 문의 위치를 초기화
        case GLUT_KEY_F1:
            eyeX = 0.0, eyeY = 0.3, eyeZ = 1.0;
            focusX = 0.0, focusY = 0.0, focusZ = 0.0;
            upX = 0.0, upY = 0.1, upZ = 0.0;
            break;
    }
    glutPostRedisplay(); // 강제로 display event 발생
}

// main 함수 정의
int main(int argc, char** argv) {
    srand(time(NULL)); // 시간에 따라 난숫값이 다르게 설정될 수 있도록 지정
    glutInit(&argc, argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // 디스플레이 모드 초기화
    glutInitWindowSize(800, 600); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(100, 100); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("OpenGL을 이용한 몬티홀 딜레마"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glEnable(GL_TEXTURE_2D); // 2D 텍스쳐 매핑 기능 활성화
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutReshapeFunc(MyReshape); // Window(창)의 크기 변경에 대한 이벤트 콜백함수 등록
    glutKeyboardFunc(MyKeyboard); // 키보드 이벤트 콜백함수 등록
    glutSpecialFunc(MySpecial);
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
