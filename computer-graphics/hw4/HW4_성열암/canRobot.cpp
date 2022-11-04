///**************************************************************************/
///*                        HW#4-2. 전신 Can Robot 모델링                 */
///*  작성자 : 성열암                              날짜 : 2022년 10월 17일 */
///*                                                                                           */
///* 문제 정의 : 다음과 같은 모양의 전신 Can Robot 구현              */
///*                - - - - - - -                                                           */
///* 기능 : 차렷 자세를 초기 기본자세로 설정하여 모델링,                */
///*          메뉴 생성                                                                    */
///*          <머리 움직이기>                                                         */
///*          <오른팔 움직이기>                                                      */
///*          <왼쪽팔 움직이기>                                                      */
///*          <오른다리 움직이기>                                                   */
///*          <왼쪽다리 움직이기>                                                   */
///*         메뉴 클릭  : 해당 메뉴에 맞는 신체가 한 번 움직였다가.     */
///*         원래대로 돌아옴                                                           */
///*         S 누르면 움직이는 신체가 멈춤                                      */
///*         - - - - - - -                                                                  */
///************************************************************************ */

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록
#include <iostream> // std::cout 함수를 사용하기 위하여 등록

GLint Running = true; // 동작의 중지 및 재생을 가능하게 조정하는 변수

// Can Robot의 개별 부위 모션에 대한 조정을 위한 변수들을 선언
static int Heading=0, re_heading = 5;
static int shoulder_right = 0, elbow_right = 0;
static int re_shoulder_right = 5, re_elbow_right = 5;
static int shoulder_left = 0, elbow_left = 0;
static int re_shoulder_left = 5, re_elbow_left = 5;
static int leg_right = 0, Knee_right = 0;
static int re_leg_right = 5, re_Knee_right = 5;
static int leg_left = 0, Knee_left = 0;
static int re_leg_left = 5, re_Knee_left = 5;


// 머리 객체에 대한 그리기 함수
void Head() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
        glTranslatef(0.0, 0.8, 0.0); // Pivot 지정 및 객체 위치 변경
        glColor3f(0.0, 0.5, 1.0);  // 객체 색 지정
        glRotatef(90, 0.0, 1.0, 0.0); // 원점을 기준으로 객체 회전
        glRotatef(Heading, 0.0, 1.0, 0.0); // 원점을 기준으로 객체 회전
        glScalef(0.7, 0.7, 0.7); // 객체 크기 조정
        glutWireSphere(0.5, 10, 10); // 머리를 그림
    glPopMatrix(); // 머리 그리기 종료
}

// 왼팔 객체에 대한 그리기 함수
void LeftArm() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
        glRotatef(-140.0, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.1, -0.7, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)shoulder_left, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.3, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(1.0, 0.0, 0.0); // 객체 색 지정
            glScalef(0.6, 0.2, 0.5); // 객체 크기 조정
            glutWireCube(1.0); // 윗팔을 그림
        glPopMatrix(); // 윗팔 그리기 종료
        glTranslatef(0.3, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)elbow_left, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.3, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.0, 1.0, 0.0); // 객체 색 지정
            glScalef(0.6, 0.2, 0.5); // 객체 크기 조정
            glutWireCube(1.0); // 아래팔을 그림
        glPopMatrix(); // 아래팔 그리기 종료
        glTranslatef(0.3, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)elbow_left, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.0, 1.0, 0.0); // 객체 색 지정
            glScalef(0.3, 0.3, 0.3); // 객체 크기 조정
            glutWireSphere(0.5, 10, 10); // 왼손을 그림
        glPopMatrix(); // 왼손 그리기 종료
    glPopMatrix(); // 왼팔(전체 부분) 그리기 종료
}

// 오른팔 객체에 대한 그리기 함수
void RightArm() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
        glRotatef(-50.0, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.0, 0.7, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)shoulder_right, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.3, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(1.0, 0.0, 0.0); // 객체 색 지정
            glScalef(0.6, 0.2, 0.5); // 객체 크기 조정
            glutWireCube(1.0); // 윗팔을 그림
        glPopMatrix(); // 윗팔 그리기 종료
        glTranslatef(0.3, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)elbow_right, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.3, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.0, 1.0, 0.0); // 객체 색 지정
            glScalef(0.6, 0.2, 0.5); // 객체 크기 조정
            glutWireCube(1.0); // 아래팔을 그림
        glPopMatrix(); // 아래팔 그리기 종료
        glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)elbow_right, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix();    // 원점을 기준으로 객체 생성 및 축소/확대
            glColor3f(0.0, 1.0, 0.0); // 객체 색 지정
            glScalef(0.3, 0.3, 0.3); // 객체 크기 조정
            glutWireSphere(0.5, 10, 10); // 오른손을 그림
        glPopMatrix(); // 오른손 그리기 종료
    glPopMatrix(); // 오른팔(전체 부분) 그리기 종료
}

// 왼다리 객체에 대한 그리기 함수
void LeftLeg() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
        glRotatef(-90.0, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.5, -0.3, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)leg_left, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.4, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.0, 0.5, 1.0); // 객체 색 지정
            glScalef(0.8, 0.2, 0.5); // 객체 크기 조정
            glutWireCube(1.0); // 왼다리를 그림
        glPopMatrix(); // 왼다리 그리기 종료
        glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)Knee_left, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.4, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.0, 1.0, 0.5); // 객체 색 지정
            glScalef(0.8, 0.2, 0.5); // 객체 크기 조정
            glutWireCube(1.0); // 왼다리 하부 그리기
        glPopMatrix(); // 왼다리 하부 그리기 종료
        glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)Knee_left, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.0, 1.0, 0.0); // 객체 색 지정
            glScalef(0.3, 0.3, 0.3); // 객체 크기 조정
            glutWireSphere(0.5, 10, 10); // 왼발을 그림
        glPopMatrix(); // 왼발 그리기 종료
    glPopMatrix(); // 왼다리(전체 부분) 그리기 종료
}

// 오른다리 객체에 대한 그리기 함수
void RightLeg() {
    glPushMatrix(); // 원점을 기준으로 객체 생성
        glRotatef(-90.0, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.5, 0.3, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)leg_right, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.4, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.0, 0.5, 1.0); // 객체 색 지정
            glScalef(0.8, 0.2, 0.5); // 객체 크기 조정
            glutWireCube(1.0); // 오른다리를 그림
        glPopMatrix(); // 오른다리 그리기 종료
        glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)Knee_right, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.4, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glColor3f(0.0, 1.0, 0.5); // 객체 색 지정
            glScalef(0.8, 0.2, 0.5); // 객체 크기 조정
            glutWireCube(1.0); // 오른다리 하부를 그림
        glPopMatrix(); // 오른다리 하부 그리기 종료
        glTranslatef(0.4, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)Knee_right, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix();    // 원점을 기준으로 객체 생성 및 축소/확대
            glColor3f(0.0, 1.0, 0.0); // 객체 색 지정
            glScalef(0.3, 0.3, 0.3); // 객체 크기 지정
            glutWireSphere(0.5, 10, 10); // 오른발을 그림
        glPopMatrix(); // 오른발 그리기 종료
    glPopMatrix(); // 오른다리(전체 부분) 그리기 종료
}

// 디스플레이 콜백함수 정의
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // 초기화 색상 설정
    glColor3f(0.5, 0.5, 0.5); // 그려지는 객체를 회색으로 설정
    glPushMatrix(); // 원점을 기준으로 객체 생성
        glTranslatef(0.0, 1.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glScalef(1.0, 2.0, 1.0); // 객체 크기 조정
        glutWireCube(1.0); // 몸통을 그림
        Head(); // 머리를 그림
        LeftArm(); // 왼팔을 그림
        RightArm(); // 오른팔을 그림
        LeftLeg(); // 왼다리를 그림
        RightLeg(); // 오른다리를 그림
    glPopMatrix(); // 객체 그리기 종료
    glutSwapBuffers(); // 후면 버퍼와 전면 버퍼를 교체
}

// 타이머 콜백함수 정의
void MyTimer(int value) {
    // 타이머 콜백함수를 이용하여 머리를 움직이고 다시 원래대로 위치시키게 함
    if (value == 1 && Running) {
        Heading += re_heading;
        if (Heading == 0) {
            re_heading == 0;
            return;
        }
        if (Heading >= 90) re_heading = -5;
        else if (Heading <= -90) re_heading = 5;
        glutTimerFunc(50, MyTimer, 1);
    }
    // 타이머 콜백함수를 이용하여 왼팔을 움직이고 다시 원래대로 위치시키게 함
    else if (value == 2 && Running) {
        shoulder_left -= re_shoulder_left; // 회전 후 다시 돌아오도록 설정함 아래도 이와 같음
        elbow_left += re_elbow_left;
        if (shoulder_left >= 0) {
            re_shoulder_left = 5;
            re_elbow_left = 5;
            if (shoulder_left == 0) return;
        } else if (shoulder_left <= -90) {
            re_shoulder_left = -5;
            re_elbow_left = -5;
        } glutTimerFunc(50, MyTimer, 2);
    }
    // 타이머 콜백함수를 이용하여 오른팔을 움직이고 다시 원래대로 위치시키게 함
    else if (value == 3 && Running) {
        shoulder_right += re_shoulder_right;
        if (shoulder_right >= 90) re_shoulder_right = -5;
        else if (shoulder_right <= 0) {
            re_shoulder_right = 5;
            if (shoulder_right == 0) return;
        }
        glutTimerFunc(50, MyTimer, 3);
    }
    // 타이머 콜백함수를 이용하여 왼다리를 움직이고 다시 원래대로 위치시키게 함
    else if (value == 4 && Running) {
        leg_left -= re_leg_left;
        if (leg_left >= 0) {
            re_leg_left = 5;
            if (leg_left == 0) return;
        } else if (leg_left <= -90) re_leg_left = -5;
        glutTimerFunc(50, MyTimer, 4);
    }
    // 타이머 콜백함수를 이용하여 오른다리 움직이고 다시 원래대로 위치시키게 함
    else if (value == 5 && Running) {
        leg_right += re_leg_right;
        Knee_right -= re_Knee_right;
        if (leg_right >= 90) {
            re_leg_right = -5;
            re_Knee_right=-5;
        } else if (leg_right <= 0) {
            re_leg_right = 5;
            re_Knee_right = 5;
            if (leg_right == 0) return;
        }
        glutTimerFunc(50, MyTimer, 5);
    } glutPostRedisplay(); // 현재 위도우를 강제적으로 다시 재생함
}

// 메인 메뉴에 대한 설정 함수
void MyMainMenu(int entryID) {
    Running = true;
    // 메뉴 클릭 시 타이머 콜백함수를 이용하여 각 기능들이 수행되도록 함
    if (entryID == 1)           glutTimerFunc(50, MyTimer, 1);
    else if (entryID == 2)      glutTimerFunc(50, MyTimer, 2);
    else if (entryID == 3)      glutTimerFunc(50, MyTimer, 3);
    else if (entryID == 4)      glutTimerFunc(50, MyTimer, 4);
    else if (entryID == 5)      glutTimerFunc(50, MyTimer, 5);
    else if (entryID == 6)      exit(0); // 프로그램 강제 종료
    glutPostRedisplay(); // 현재 위도우를 강제적으로 다시 재생함
}

// 키보드 입력 이벤트 콜백함수 정의
void MyKeyboard(unsigned char key, int x, int y) {
    // s or S 입력 시 로봇에서 움직이고 있는 부분의 동작을 전면 정지시킴
    switch (key) {
    case 's':
        Running = false;
        break;
    case 'S':
        Running = false;
        break;
    }
    glutPostRedisplay(); // 현재 위도우를 강제적으로 다시 재생함
}

// 사용자 초기화 함수 정의
void MyInit() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // 객체 기본 색을 흰색으로 설정
    glMatrixMode(GL_PROJECTION); // 투상 좌표계의 공간 앞으로 계산
    glLoadIdentity(); // 항등행렬로 초기화
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시부피 설정
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu); // 전신에 대한 메인 메뉴 생성
    glutAddMenuEntry("머리 움직이기", 1); // 메뉴 1 추가
    glutAddMenuEntry("오른팔 움직이기", 2); // 메뉴 2 추가
    glutAddMenuEntry("왼쪽팔 움직이기", 3); // 메뉴 3 추가
    glutAddMenuEntry("오른다리 움직이기", 4); // 메뉴 4 추가
    glutAddMenuEntry("왼쪽다리 움직이기", 5); // 메뉴 5 추가
    glutAddMenuEntry("종료", 6); // 메뉴 6 추가
    glutAttachMenu(GLUT_RIGHT_BUTTON); // 우클릭 시 메뉴 표시
}

// 윈도우 창 크기 조절에 대한 콜백 함수 정의
void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // 뷰포트 설정
    glMatrixMode(GL_PROJECTION); // 투상 좌표계의 공간 앞으로 계산
    glLoadIdentity(); // 항등행렬로 초기화
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); // 시야각 설정
    glMatrixMode(GL_MODELVIEW); // 모델 좌표계와 시점 좌표계의 공간을 앞으로 계산
    glLoadIdentity(); // 항등행렬로 초기화
    glTranslatef(0.0, 0.0, -5.0); // 위치 조정
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc, argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 RGB 모드로 초기화
    glutInitWindowSize(800, 600); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(100, 100); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Can Robot"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutReshapeFunc(MyReshape); // 크기 지정 및 변경에 대한 이벤트 콜백함수 등록
    glutKeyboardFunc(MyKeyboard); // 키보드 이벤트 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
