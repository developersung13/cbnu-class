///*************************************************************************/
///*                      HW#3 : Callback Programming                      */
///*  작성자 : 성열암                            날짜 : 2022년 10월 06일         */
///*                                                                       */
///*  문제 정의 :  Mouse Callback 응용                                        */
///*                - - - - - - -                                          */
///*  기능 :                                                                */
///*    1. 마우스 왼쪽 버튼을 click :                                          */
///*        4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 연속적으로 이동              */
///*    2. 마우스 오른쪽 버튼을 click :                                         */
///*        이동하고 있는 Polygon이 멈춤                                        */
///*                - - - - - - -                                          */
///*************************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록

int flag; // flag 변숫값을 토대로 타이머 함수 내용의 수행을 제한
double x, y; // 도형의 x, y위치 값을 변경시키기 위해 좌표 조정을 위한 변수 선언

// 사용자 초기화 함수 정의
void MyInit() {
    glClearColor (1.0, 1.0, 1.0, 1.0); // 배경색을 흰색, 불투명하게 지정
    glMatrixMode(GL_PROJECTION); // 행렬 모드를 투영행렬로 설정
    glLoadIdentity(); // 행렬을 단위행렬로 초기화
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시부피 설정
}

// 디스플레이 콜백함수 정의
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화
    glColor3f(0.5, 0.5, 0.5); // 개체를 회색으로 설정
    glBegin(GL_POLYGON); // (다각형)으로 그리기 시작
    glVertex3f(-0.5 + x, -0.5 + y, 0.0); // 첫 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x, -0.5 + y, 0.0); // 두 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x, 0.5 + y, 0.0); // 세 번째 정점의 x, y, z좌표 설정
    glVertex3f(-0.5 + x, 0.5 + y, 0.0); // 네 번째 정점의 x, y, z좌표 설정
    glEnd(); // 그리기 종료
    glFlush(); // 화면에 출력(버퍼코드를 실행)
}

// 타이머 콜백함수 정의
void MyTimer(int value) {
    if (flag) { // flag가 양수이면 x, y좌표 조정 문장 수행
        if (0.5 + x >= 1) return; // 개체가 우측 테두리에 접촉 시 함수 타이머 함수 종료
        x += 0.01; // 아닐 때 개체를 우측으로 이동(x값을 0.01 단위로 증가)
        glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
        glutTimerFunc(40, MyTimer, 1); // 40msec 후에 호출
    }
}

// 마우스 이벤트 콜백함수 등록
void MyMouse(int button, int state, int a, int b) {
    // 마우스 좌클릭 시 flag를 1로 설정하여 타이머 함수 내 문장을 실행하도록 함
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
        flag = 1;
        glutTimerFunc(40, MyTimer, 1); // 40msec 후에 타이머 함수 호출
        glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
    // 마우스 우클릭 시 flag를 0로 설정하여 타이머 함수 내 문장을 실행하지 못 하도록 함
    } else if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) flag = 0;
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc,argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 RGB 모드로 초기화
    glutInitWindowSize(300, 300); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Mouse Callback"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutMouseFunc(MyMouse); // 마우스 이벤트 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
