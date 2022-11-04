///*************************************************************************/
///*                      HW#3 : Callback Programming                      */
///*  작성자 : 성열암                            날짜 : 2022년 10월 06일         */
///*                                                                       */
///*  문제 정의 : Timer Callback 응용                                         */
///*                - - - - - - -                                          */
///*  기능 : 프로그램이 실행되면 코드5-8에 있는 도형이 오른쪽으로 0.1씩 연속적으로          */
///*  움직이게 하고, 오른쪽 경계에 부딪히면 도형의 색깔이 변하게 한 후, 다시 도형이          */
///*  왼쪽으로 0.1씩 연속적으로 움직이는 과정을 반복함. 마우스 왼쪽 키를 누르면             */
///*  움직이는 도형이 멈춤.                                                     */
///*                - - - - - - -                                          */
///*************************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록

/* 색 지정 시 구분자로 사용할 변수 및 도형의 테두리 접촉
여부 확인용 조건 변수 flag, flag2변수 선언  */
GLint setColor, flag, flag2;
GLfloat x; // 도형의 x위치 값을 변경시키기 위해 좌표 조정을 위한 변수 선언

// 디스플레이 콜백함수 정의
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화
    switch (setColor) { // 색 지정에 대한 변숫값을 토대로 switch-case문 내 case값과 비교
        // 색 지정 변숫값이 0일 때 파란색으로 지정
        case 0: glColor3f(0.0, 0.5, 0.8); break;
        // 색 지정 변숫값이 1일 때 빨간색으로 지정
        case 1: glColor3f(1, 0, 0); break;
        // 색 지정 변숫값이 2일 때 초록색으로 지정
        case 2: glColor3f(0, 1, 0);
    }
    
    glBegin(GL_POLYGON); // (다각형)으로 그리기 시작
    glVertex3f(-0.5 + x, -0.5, 0.0); // 첫 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x, -0.5, 0.0); // 두 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x, 0.5, 0.0); // 세 번째 정점의 x, y, z좌표 설정
    glVertex3f(-0.5 + x, 0.5, 0.0); // 네 번째 정점의 x, y, z좌표 설정
    glEnd(); // 그리기 종료
    glutSwapBuffers(); // 개체를 전부 그린 이후에 전면버퍼와 후면버퍼를 교체함
}

// 타이머 콜백함수 정의
void MyTimer(int value) {
    if (!flag) {
        // 우측 테두리에 닿기 전까지 밑 조건 실행
        if (0.5 + x >= 1) {
            setColor = 1; // 개체를 빨간색으로 설정할 수 있도록 변수를 1로 할당
            flag2 = 1;
        // 좌측 테두리에 닿기 전까지 밑 조건 실행
        } else if (-0.5 + x <= -0.9) {
            setColor = 2; // 개체를 녹색으로 설정할 수 있도록 변수를 2로 할당
            flag2 = 0;
        }
        if (!flag2) x += 0.1; // 개체가 우측 테두리 닿지 않았을 때에는 도형 x좌표를 +0.1함
        else x -= 0.1; // 개체가 좌측 테두리 닿지 않았을 때에는 도형 x좌표를 -0.1함
    }
    
    glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
    // 200msec 후에 타이머 함수 재호출
    glutTimerFunc(200, MyTimer, 1); 
}

// 마우스 이벤트 콜백함수 정의
void MyMouse(int button, int state, int a, int b) {
    // 마우스 좌클릭 시 flag를 1로 설정하여 타이머 함수 내 문장을 실행하지 못 하도록 함
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
        flag = 1;
}

// 사용자 초기화 함수 정의
void MyInit() {
    glClearColor (1.0, 1.0, 1.0, 1.0); // 배경색을 흰색, 불투명하게 지정
    glMatrixMode(GL_PROJECTION); // 행렬 모드를 투영행렬로 설정
    glLoadIdentity(); // 행렬을 단위행렬로 초기화
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); // 가시부피 설정
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc,argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // 디스플레이 모드를 RGB 및 DOUBLE 모드로 초기화
    glutInitWindowSize(300, 300); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Timer Callback"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutMouseFunc(MyMouse); // 마우스 이벤트 콜백함수 등록
    // 40msec 후에 타이머 함수 호출
    glutTimerFunc(40, MyTimer, 1); 
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
