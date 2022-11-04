///*************************************************************************/
///*                      HW#4-1 : 로봇 손-팔 모델링                          */
///*  작성자 : 성열암                            날짜 : 2022년 10월 17일 */
///*                                                                                         */
///*  문제 정의 :  로봇 손-팔 모델링                                           */
///*                - - - - - - -                                                         */
///*  기능 :                                                                              */
///*    <1 키를 누르면> 첫번째 손가락을 접었다 펼쳤다 반복         */
///*    <2 키를 누르면> 두번째 손가락을 접었다 펼쳤다 반복         */
///*    <3 키를 누르면> 세번째 손가락을 접었다 펼쳤다 반복         */
///*    <4 키를 누르면> 모든 손가락이 접었다 펼쳤다 반복            */
///*    <S 키를 누르면> 움직이던 손가락이 움직임을 멈춤             */
///*    <마우스 왼쪽 버튼을 클릭하면> 어깨, 팔꿈치 및 모든          */
///*    손가락을 움직여서 Robot Arm이 특정 물건을 잡는            */
///*    것처럼 회전                                                                    */
///*    <마우스 오른쪽 버튼을 클릭하면> 팔꿈치 및 모든 손가락을. */
///*    움직여서 Robot Arm의 원래                                            */
///*                - - - - - - -                                                         */
///*********************************************************************** /

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록
#include <iostream>

static int shoulder = 0, elbow = 0; // 어꺠, 팔꿈치 각도 조정 변수 선언
static int finger1 = 0, finger2 = 0, finger3 = 0;; // 손가락 각도 조정 변수 선언
static int re_finger1 = 5, re_finger2 = 5, re_finger3 = 5; // 손가라 모션 조정 변수 선언
static float re_all = 2.5; // 모션 값 지정 변수 선언
GLboolean Running = false, // 모션 동작의 작동 여부를 지정하는 변수로 사용
          Running1 = false, // 모션 동작의 작동 여부를 지정하는 변수로 사용
          Running2 = false, // 모션 동작의 작동 여부를 지정하는 변수로 사용
          Running3 = false; // 모션 동작의 작동 여부를 지정하는 변수로 사용

// 사용자 초기화 함수 정의
void MyInit(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // 배경을 검은색으로 지정
}

// 1번 손가락 함수 정의
void finger_1() {
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 이동, 축소/확대
        glTranslatef(1.0, 0.0, 0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.25, 0.0, 0.3); // Pivot으로 지정할 위치를 원점으로 이동
        glScalef(0.5, 0.1, 0.2); // 객체 크기 조정
        glutWireCube(1.0); // 손가락 마디 그리기(1)
        glPushMatrix(); // 현재 위치에서 새로운 객체를 그림
            glTranslatef(0.5, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
            glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
            glTranslatef(0.5, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
            glutWireCube(1.0); // 손가락 마다 그리기(2)
            glPushMatrix(); // 현재 위치에서 새로운 객체를 그림
                glTranslatef(0.5, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
                glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
                glTranslatef(0.5, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
                glutWireCube(1.0); // 손가락 마디 그리기(3)
            glPopMatrix(); // 손가락 마디 그리기(3) 종료
        glPopMatrix(); // 손가락 마디 그리기(2) 종료
    glPopMatrix(); // 손가락 마디 그리기(1) 종료
}

// 2번 손가락 함수 정의
void finger_2() {
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 이동, 축소/확대
        glTranslatef(1.0, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.25, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
        glScalef(0.5, 0.1, 0.2); // 객체 크기 조정
        glutWireCube(1.0); // 손가락 마디 그리기(1)
        glPushMatrix(); // 현재 위치에서 새로운 객체를 그림
            glTranslatef(0.5, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
            glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
            glTranslatef(0.5, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동
            glutWireCube(1.0); //손가락 마디 그리기(2)
            glPushMatrix(); // 현재 위치에서 새로운 객체를 그림
                glTranslatef(0.5, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
                glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
                glTranslatef(0.5, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
                glutWireCube(1.0); // 손가락 마디 그리기 (3)
            glPopMatrix(); // 손가락 마디 그리기(1) 종료
        glPopMatrix(); // 손가락 마디 그리기(2) 종료
    glPopMatrix(); // 손가락 마디 그리기(3) 종료
}

// 2번 손가락 함수 정의
void finger_3() {
    glPushMatrix(); // 원점을 기준으로 객체 생성 및 이동, 축소/확대
    glTranslatef(1.0, 0.0, -0.8); // Pivot 지정 및 객체 위치 변경
    glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
    glTranslatef(0.25, 0.0, 0.5); // Pivot으로 지정할 위치를 원점으로 이동
    glScalef(0.5, 0.1, 0.2); // 객체 크기 조정
    glutWireCube(1.0); // 손가락 마디 그리기(1)
        glPushMatrix(); // 현재 위치에서 새로운 객체를 그림
        glTranslatef(0.5, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
        glTranslatef(0.5, 0.0, 0.0);    // Pivot으로 지정할 위치를 원점으로 이동
        glutWireCube(1.0); // 손가락 마디 그리기(2)
            glPushMatrix(); // 현재 위치에서 새로운 객체를 그림
                glTranslatef(0.5, 0.0, 0.0); // Pivot 지정 및 객체 위치 변경
                glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // 원점을 기준으로 객체 회전
                glTranslatef(0.5, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동
                glutWireCube(1.0); // 손가락 마디 그리기(3)
            glPopMatrix(); // 손가락 마디 그리기(1) 종료
        glPopMatrix(); // 손가락 마디 그리기(2) 종료
    glPopMatrix(); // 손가락 마디 그리기(3) 종료
}

// 디스플레이 콜백함수 정의
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // 초기화 색상 설정
    glColor3f(1, 1, 1); // 그려지는 객체를 흰색으로 설정
    glPushMatrix(); // 원점을 기준으로 객체 생성
    glRotatef(-75, 0, 1, 1); // 원점을 기준으로 객체 회전
        glTranslatef(-1, 0, 0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)shoulder, 0, 0, 1); // 원점을 기준으로 회전
        glTranslatef(1, 0, 0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glScalef(2, 0.4, 1); // 객체 크기 조정
            glutWireCube(1); // 위 팔 그리기
        glPopMatrix(); // 위 팔 그리기 종료
        glTranslatef(1, 0, 0); // Pivot 지정 및 객체 위치 변경
        glRotatef((GLfloat)elbow, 0, 0, 1);  // 원점을 기준으로 회전
        glTranslatef(1, 0, 0); // Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix(); // 원점을 기준으로 객체 생성
            glScalef(2, 0.4, 1); // 객체 크기 조정
            glutWireCube(1); // 아래 팔 그리기
        glPopMatrix(); // 아래 팔 그리기 종료
    
        finger_1(); // 1번 손가락 그리기
        finger_2(); // 2번 손가락 그리기
        finger_3(); // 3번 손가락 그리기
    glPopMatrix(); // 객체 그리기 종료
    glutSwapBuffers(); // 후면 버퍼와 전면 버퍼를 교체
}

// 타이머 콜백함수 정의
void MyTimer(int value) {
    // 1번 손가락 모션 설정
    if (value == 1 && Running && Running1) {
        finger1 += re_finger1;
        if (finger1 >= 90) re_finger1 = -5;
        else if (finger1 <= 0) re_finger1 = 5;
        glutTimerFunc(50, MyTimer, 1);
    }
    // 2번 손가락 모션 설정
    else if (value == 2 && Running && Running2) {
        finger2 += re_finger2;
        if (finger2 >= 90) re_finger2 = -5;
        else if (finger2 <= 0) re_finger2 = 5;
        glutTimerFunc(50, MyTimer, 2);
    }
    // 3번 손가락 모션 설정
    else if (value == 3 && Running && Running3) {
        finger3 += re_finger3;
        if (finger3 >= 90) re_finger3 = -5;
        else if (finger3 <= 0) re_finger3 = 5;
        glutTimerFunc(50, MyTimer, 3);
    } glutPostRedisplay(); // 현재 위도우를 강제적으로 다시 재생함
}

void MyTimer2(int value) {
    // 잡는 모션 설정
    if (re_all == 2.5) {
        if (shoulder <= 20) shoulder += re_all;
        if (elbow <= 95) elbow += 2 * re_all;
        if (finger1 <= 90) finger1 += 2 * re_all;
        if (finger2 <= 90) finger2 += 2 * re_all;
        if (finger3 <= 90) finger3 += 2 * re_all;
        if (elbow > 95) return;
    }
    // 피는 모션 설정
    else if (re_all == -2.5) {
        if (shoulder >= 0) shoulder += re_all;
        if (elbow >= 0) elbow += 2 * re_all;
        if (finger1 >= 0) finger1 += 2 * re_all;
        if (finger2 >= 0) finger2 += 2 * re_all;
        if (finger3 >= 0) finger3 += 2 * re_all;
        if (elbow < 0) return;
    } glutTimerFunc(50, MyTimer2, 1);
    glutPostRedisplay(); // 현재 위도우를 강제적으로 다시 재생함
}

// 마우스 클릭 콜백함수 정의
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    Running = true, Running1 = true, Running2 = true, Running3 = true;
    // 마우스 좌 클릭 시 모션 설정
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        re_all = 2.5;
        glutTimerFunc(50, MyTimer2, 1);
    }
    // 마우스 우 클릭 시 모션 설정
    else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
        re_all = -2.5;
        glutTimerFunc(50, MyTimer2, 1);
    } glutPostRedisplay(); // 현재 위도우를 강제적으로 다시 재생함
}

// 키보드 콜백함수 정의
void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's': // 모션 정지
        std::cout << "stop";
        Running = false;
        Running1 = false;
        Running2 = false;
        Running3 = false;
        break;
    case 'S': // 모션 정지
        std::cout << "stop";
        Running = false;
        Running1 = false;
        Running2 = false;
        Running3 = false;
        break;
    case '1': // 첫 번째 손가락을 움직이도록 함
        Running = true;
        Running1 = true;
        glutTimerFunc(50, MyTimer, 1);
        break;
    case '2': // 두 번째 손가락을 움직이도록 함
        Running = true;
        Running2 = true;
        glutTimerFunc(50, MyTimer, 2);
        break;
    case '3': // 세 번째 손가락을 움직이도록 함
        Running = true;
        Running3 = true;
        glutTimerFunc(50, MyTimer, 3);
        break;
    case '4': // 모든(1~3번) 손가락을 움직이도록 함
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
    case 27: // ESC 입력 시 프로그램 종료
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay(); // 현재 위도우를 강제적으로 다시 재생함
}

// 윈도우 창 크기 조절에 대한 콜백 함수 정의
void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // 뷰포트 설정
    glMatrixMode(GL_PROJECTION); // 투상 좌표계의 공간 앞으로 계산
    glLoadIdentity(); // 항등행렬로 초기화
    gluPerspective(130.0, (GLfloat)w / (GLfloat)h, 1, 50.0); // 시야각 설정
    glMatrixMode(GL_MODELVIEW); // 모델 좌표계와 시점 좌표계의 공간을 앞으로 계산
    glLoadIdentity(); // 항등행렬로 초기화
    glTranslatef(0.0, 0.0, -5.0); // 위치 조정
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc, argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 RGB 모드로 초기화
    glutInitWindowSize(800, 800); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(50, 50); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Robot Arm"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutReshapeFunc(MyReshape); // 크기 지정 및 변경에 대한 이벤트 콜백함수 등록
    glutKeyboardFunc(MyKeyboard); // 키보드 이벤트 콜백함수 등록
    glutMouseFunc(MyMouseClick); // 마우스 이벤트 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
