///***********************************************************************/
///*                           HW#5-2 : 모델뷰 변환 종합                                */
///*  작성자 : 성열암                              날짜 : 2022년 11월 01일         */
///*                                                                                                    */
///* 문제 정의 : Robot arm 모델뷰 전환하기                                         */
///*                - - - - - - -                                                                    */
///* 기능 : 앞뒤 오른쪽 왼쪽 위 아래 방향으로 움직이는 로봇팔을 볼 수      */
///        있도록 함                                                                        */
///*        그 외 북동쪽, 북서쪽, 남서쪽, 남동쪽에서 바라볼 수 있도록 함     */
///*                - - - - - - -                                                                    */
///***********************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std; // 입출력 함수 사용을 위한 namespace 정의

// 모델 좌표 조정에 대한 변수 선언 및 정의
GLdouble eyeX= 0.0, eyeY = 0.5, eyeZ = 8.0;
GLdouble focusX = 0.0, focusY = -0.5, focusZ = 0.0;
GLdouble upX = 0.0, upY = 1.0, upZ = 0.0;

static int shoulder = 0, elbow = 0;
static int finger1 = 0, finger2 = 0, finger3 = 0;;
static int re_finger1 = 5, re_finger2 = 5, re_finger3 = 5;
static float re_all = 2.5;

// 모델 동작 애니메이션 조정에 대한 변수 선언 및 정의
GLboolean Running = false;
GLboolean Running1 = false;
GLboolean Running2 = false;
GLboolean Running3 = false;

// 사용자 초기화 함수 정의
void MyInit(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // 배경색 지정
    glShadeModel(GL_FLAT); // 음영 지정
}

void finger_one() {
    glPushMatrix();    // 원점을 기준으로 객체 생성 및 축소/확대
    //---------------------------------------손가락1---------------------------------------ㅜ
    glTranslatef(1.0, 0.0, 0.0);    // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.25, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동
    glColor3f(0.0, 0.0, 1.0);
    glScalef(0.5, 0.1, 0.2);
    glutWireCube(1.0); //손가락마디1-1
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동
    glColor3f(0.0, 0.0, 1.0);
    glutWireCube(1.0); //손가락마디1-2
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동
    glColor3f(0.0, 0.0, 1.0);

    glutWireCube(1.0); //손가락마디1-3
    glTranslatef(-0.75, 0.0, 0.0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //---------------------------------------손가락1pop------------------------------------ㅗ
}

void finger_two() {
    glPushMatrix();    // 원점을 기준으로 객체 생성 및 축소/확대
    //---------------------------------------손가락2---------------------------------------ㅜ
    glTranslatef(1.0, 0.0, 0.0);    // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전

    glTranslatef(0.25, 0.0, 0.25);    // Pivot으로 지정할 위치를 원점으로 이동
    glColor3f(0.0, 0.0, 1.0);
    glScalef(0.5, 0.1, 0.2);
    glutWireCube(1.0); //손가락마디2-1
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동
    glColor3f(0.0, 0.0, 1.0);
    glutWireCube(1.0); //손가락마디2-2
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동
    glColor3f(0.0, 0.0, 1.0);

    glutWireCube(1.0); //손가락마디2-3
    glTranslatef(-0.75, 0.0, 0.0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //---------------------------------------손가락2pop------------------------------------ㅗ

}

void finger_three() {
    glPushMatrix();    // 원점을 기준으로 객체 생성 및 축소/확대
    //---------------------------------------손가락3---------------------------------------ㅜ
    glTranslatef(1.0, 0.0, 0.0);    // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.25, 0.0, -0.25);    // Pivot으로 지정할 위치를 원점으로 이동
    glColor3f(0.0, 0.0, 1.0);
    glScalef(0.5, 0.1, 0.2);
    glutWireCube(1.0); //손가락마디3-1
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동
    glColor3f(0.0, 0.0, 1.0);
    glutWireCube(1.0); //손가락마디3-2
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동
    glColor3f(0.0, 0.0, 1.0);

    glutWireCube(1.0); //손가락마디3-3
    glTranslatef(-0.75, 0.0, 0.0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    ////---------------------------------------손가락3pop------------------------------------ㅗ

}

// 땅 그리기
void DrawGround() {
    glColor3f(0.5, 0.5, 0.5); // 객체 색 지정(회색)
    glBegin(GL_POLYGON); // 객체 그리기 시작
    glVertex3f(-2.0, -0.71, 2.0); // 객체 이동
    glVertex3f(2.0, -0.71, 2.0);
    glVertex3f(2.0, -0.71, -2.0);
    glVertex3f(-2.0, -0.71, -2.0);
    glEnd(); // 객체 그리기 종료

    glColor3f(0.3, 0.3, 0.3); // 객체 색 조정
    glBegin(GL_LINES); // 객체 그리기 시작
    for (float x = -2.0; x <= 2.2; x += 0.2) {
        glVertex3f(x, -0.7, -2.0);
        glVertex3f(x, -0.7, 2.0);
    }

    for (float z = -2.0; z <= 2.2; z += 0.2) {
        glVertex3f(-2.0, -0.7, z);
        glVertex3f(2.0, -0.7, z);
    }
    glEnd(); // 객체 그리기 종료
}

// 디스플레이 콜백함수 정의
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 프레임 버퍼 초기화
    glMatrixMode(GL_MODELVIEW); // 모델뷰 행렬 지정
    glLoadIdentity(); // 항등행렬로 초기화

    //gluLookAt(0.0, 3.5, 3.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt(eyeX, eyeY, eyeZ, focusX, focusY, focusZ, upX, upY, upZ); // 시점 조정

    DrawGround(); // 땅 그리기

    glPushMatrix();//---------------------------------------초기설정push---------------------------------------ㅜ
    glRotatef(-50.0, 0.0, 0.0, 1.0);
    glTranslatef(-1.5, 0.0, 0.0);     // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동

    //---------------------------------------윗팔---------------------------------------ㅜ
    glPushMatrix();    // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(1.0, 0.0, 0.0);
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0); //윗팔
    glPopMatrix();
    //---------------------------------------윗팔pop------------------------------------ㅗ

    glTranslatef(1.0, 0.0, 0.0);    // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동

    //---------------------------------------아래팔---------------------------------------ㅜ
    glPushMatrix();    // 원점을 기준으로 객체 생성 및 축소/확대
    glColor3f(0.0, 1.0, 0.0);
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0); //아래팔
    glPopMatrix();
    //---------------------------------------아래팔pop------------------------------------ㅗ

    // 손가락 그리기
    finger_one();
    finger_two();
    finger_three();
    glPopMatrix();//---------------------------------------초기설정pop---------------------------------------ㅗ
    glutSwapBuffers(); // 프론트 & 백버퍼 변경
}

// 윈도우 창 크기 조절에 대한 콜백 함수 정의
void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // 뷰포트 지정
    glMatrixMode(GL_PROJECTION); // 프로젝션 행렬 지정
    glLoadIdentity(); // 항등행렬로 초기화

    gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100); // 시점 조정
}

// 타이머 콜백 함수(1) 정의
void MyTimer(int value) { //각각의 손가락을 수행시킴
    // 객체 애니메이션 설정
    if (value == 1 && Running && Running1) {
        finger1 += re_finger1;
        if (finger1 >= 90) {
            re_finger1 = -5;
        }
        else if (finger1 <= 0) {
            re_finger1 = 5;
        }

        glutTimerFunc(50, MyTimer, 1);
    }
    // 객체 애니메이션 설정
    else if (value == 2 && Running && Running2) {
        finger2 += re_finger2;
        if (finger2 >= 90) {
            re_finger2 = -5;
        }
        else if (finger2 <= 0) {
            re_finger2 = 5;
        }

        glutTimerFunc(50, MyTimer, 2);
    }
    // 객체 애니메이션 설정
    else if (value == 3 && Running && Running3) {
        finger3 += re_finger3;
        if (finger3 >= 90) {
            re_finger3 = -5;
        }
        else if (finger3 <= 0) {
            re_finger3 = 5;
        }
        glutTimerFunc(50, MyTimer, 3);
    }
    glutPostRedisplay(); // 애니메이션 변경을 적용할 수 있도록 이벤트 호출

}

// 타이머 콜백 함수(2) 정의
void MyTimer2(int value) {
    if (re_all == 2.5) {
        cout << "왼쪽";
        if (shoulder <= 20) {
            shoulder += re_all;
        }

        if (elbow <= 95) {
            elbow += 2 * re_all;
        }
        //손 쥐는 모습
        if (finger1 <= 90) { finger1 += 2 * re_all; }
        if (finger2 <= 90) { finger2 += 2 * re_all; }
        if (finger3 <= 90) { finger3 += 2 * re_all; }

        if (elbow > 95) return;
    } else if (re_all == -2.5) {
        cout << "오른쪽";
        if (shoulder >= 0) {
            shoulder += re_all;
        }

        if (elbow >= 0) {
            elbow += 2 * re_all;
        }
        //손 펴는 모습
        if (finger1 >= 0) { finger1 += 2 * re_all; }
        if (finger2 >= 0) { finger2 += 2 * re_all; }
        if (finger3 >= 0) { finger3 += 2 * re_all; }

        if (elbow < 0) return;
    }
    glutTimerFunc(50, MyTimer2, 1); // 타이머 함수 호출
    glutPostRedisplay(); // 애니메이션 변경을 적용할 수 있도록 이벤트 호출
}

// 마우스 콜백 함수 정의
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    Running = true, Running1 = true, Running2 = true, Running3 = true;

    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { //왼쪽 마우스
        //cout << "왼쪽";
        re_all = 2.5;
        glutTimerFunc(50, MyTimer2, 1);
    } else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) { //오른쪽 마우스
        //cout << "오른쪽";
        re_all = -2.5;
        glutTimerFunc(50, MyTimer2, 1);
    }
    glutPostRedisplay(); // 애니메이션 변경을 적용할 수 있도록 이벤트 호출
}

// 키보드 특수키 입력에 대한 이벤트 콜백함수 등록
void MySpecial(int key, int x, int y) { //화살표 키를 이용하여 카메라의 위치를 움직임
    switch (key) {
        case GLUT_KEY_RIGHT: // 우측 화살표 클릭 시
            eyeX += 0.1;
            break;
        case GLUT_KEY_LEFT: // 좌측 화살표 클릭 시
            eyeX -= 0.1;
            break;
        case GLUT_KEY_UP: // 상단 화살표 클릭 시
            eyeY += 0.1;
            break;
        case GLUT_KEY_DOWN: // 하단 화살표 클릭 시
            eyeY -= 0.1;
            break;
    }
    glutPostRedisplay(); // 애니메이션 변경을 적용할 수 있도록 이벤트 호출
}

// 키보드 입력에 대한 콜백함수 등록
void MyKeyboard(unsigned char key, int x, int y) { //키보드를 누르면 각 기능들을 수행하게 함
    switch (key) {

    case '1': //첫번째 손가락이 움직이도록 함
        Running = true;
        Running1 = true;
        glutTimerFunc(50, MyTimer, 1);
        break;
    case '2': //두번째 손가락이 움직이도록 함
        Running = true;
        Running2 = true;
        glutTimerFunc(50, MyTimer, 2);
        break;
    case '3': //세번째 손가락이 움직이도록 함
        Running = true;
        Running3 = true;
        glutTimerFunc(50, MyTimer, 3);
        break;
    case '4': //다시 움직이게 함
        Running = true;
        if (!Running1) {
            Running1 = true;
            glutTimerFunc(50, MyTimer, 1);
        }

        if (!Running2) {
            Running2 = true;
            glutTimerFunc(50, MyTimer, 2);
        }

        if (!Running3) {
            Running3 = true;
            glutTimerFunc(50, MyTimer, 3);
        }
        break;
    case '5': //정지
        Running = false;
        Running1 = false;
        Running2 = false;
        Running3 = false;
        break;

    case 's': //기본 기능을 확인하기 위해 기능 유지
        shoulder = (shoulder + 5) % 360;
        break;


    case 'f': //front 앞에서 보기 기능
        eyeX = 0.0, eyeY = 0.5, eyeZ = 8.0;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;
    case 'b': //back 뒤에서 보기 기능
        eyeX = 0.0, eyeY = 0.5, eyeZ = -8.0;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;
    case 'r': //right 오른쪽에서 보기 기능
        eyeX = 8.0, eyeY = 0.5, eyeZ = 0.0;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;
    case 'l': //left 왼쪽에서 보기 기능
        eyeX = -8.0, eyeY = 0.5, eyeZ = 0.0;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;
    case 'u': //up 위에서 보기 기능
        eyeX = 0.0, eyeY = 8.0, eyeZ = 0.5;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;
    case 'd': //down 아래에서 보기 기능
        eyeX = 0.0, eyeY = -8.0, eyeZ = 0.5;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;

    case 'q': //북서쪽에서 보기 기능
        eyeX = -6.0, eyeY = 6.0, eyeZ = 0.5;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;
    case 'e': //북동쪽에서 보기 기능
        eyeX = 6.0, eyeY = 6.0, eyeZ = 0.5;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;
    case 'z': //남서쪽에서 보기 기능
        eyeX = -6.0, eyeY = -6.0, eyeZ = 0.5;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;
    case 'c': //남동쪽에서 보기 기능
        eyeX = 6.0, eyeY = -6.0, eyeZ = 0.5;
        focusX = 0.0, focusY = -0.5, focusZ = 0.0;
        upX = 0.0, upY = 1.0, upZ = 0.0;
        break;
    }
    glutPostRedisplay(); // 애니메이션 변경을 적용할 수 있도록 이벤트 호출
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc, argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드를 SINGLE | RGB 모드로 초기화
    glutInitWindowSize(500, 500); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("VCS (View Coordinate System)"); // 인수를 타이틀로 지정한 Window(창) 생성
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutReshapeFunc(MyReshape); // 크기 지정 및 변경에 대한 이벤트 콜백함수 등록
    glutKeyboardFunc(MyKeyboard); // 키보드 이벤트 콜백함수 등록
    glutSpecialFunc(MySpecial); // 키보드 특수키 콜백함수 등록
    glutMouseFunc(MyMouseClick); // 마우스 이벤트에 대한 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main 함수 종료
}
