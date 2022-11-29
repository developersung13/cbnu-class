/*******************************************************************************************************/
/*                                 HW#6 : glViewport()을 통한 뷰폿변환   */
/*  작성자 : 성열암                                 날짜 : 2022년 11월 8일 */
/*                                                                                                     */
/* 문제 정의 :                                                                                         */
/* 2개 이상의 물체를 한 뷰폿에 그리고, 한 윈도우에 4개의 뷰폿을 띄워 서로 비교한다.                    */
/* 기능 :                                                                                              */
/* 1. 우상단과 좌하단의 뷰폿에 Teapot과 Sphere 두 물체를 그린다.                                       */
/* 2. 우상단의 뷰폿은 원근투영으로 설정한다.                                                           */
/* 3. 좌하단의 뷰폿은 평행투영으로 설정한다.                                                           */
/* 4. Mouse Callback을 통해 마우스가 해당 뷰폿이 있는 위치에서 좌클릭으로 화면을 드래그하면            */
/*    카메라가 마우스의 움직임에 따라 x, y축에서 이동한다.                                             */
/* 5. Mouse Callback을 통해 마우스가 해당 뷰폿이 있는 위치에서 앞뒤로 스크롤하면                       */
/*    카메라가 마우스의 움직임에 따라 z축에서 이동한다. (이동 범위에 제한 설정)                        */
/* 6. 각각의 뷰폿 내 Teapot의 위치는 뷰폿의 중심으로, Sphere은 Teapot의 뒤로 고정한다.                 */
/* 7. ReShape Callback과 Display Callback을 통해 윈도우 크기 변환에 따른 물체 왜곡을 방지한다.         */
/*******************************************************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록

GLfloat Width, Height; // 화면의 너비, 높이 값을 담을 수 있는 전역 변수 선언
GLfloat size[2];
GLfloat camera1[3], camera2[3]; // 1번 2번 객체에 대한 각각의 카메라 시점을 조정하는 변수를 선언
GLint mousePos[2]; // 마우스 모션 좌표를 저장할 변수 선언

// 사용자 초기화 함수 정의
void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // 흰색으로 화면 지우기
    glGetFloatv(GL_LINE_WIDTH_RANGE, size); // 선 두께의 범위를 size에 저장

    // 1번 카메라 시점 x, y, z값 설정
    camera1[0] = 0;
    camera1[1] = 0;
    camera1[2] = 1.5;

    // 2번 카메라 시점 x, y, z값 설정
    camera2[0] = 5.0;
    camera2[1] = 5.0;
    camera2[2] = 5.0;
}

// 객체를 그리는 사용자 정의 함수
void DrawScene() {
    glColor3f(0.0, 0.0, 0.0); // 객체의 색 지정
    glPushMatrix(); // 행렬 스택에 현재 변환 행렬 저장
    glLineWidth(size[0] * 5); // 선 두께 지정 (최솟값의 5배)
    glBegin(GL_LINES); // x축 그리기
    glVertex3f(-2.0, 0.0, 0.0); // 좌표 지정
    glVertex3f(2.0, 0.0, 0.0); // 좌표 지정
    glEnd(); // 그리기 종료
    glBegin(GL_LINES); // y축 그리기
    glVertex3f(0.0, -2.0, 0.0); // 좌표 지정
    glVertex3f(0.0, 2.0, 0.0); // 좌표 지정
    glEnd(); // 그리기 종료
    glBegin(GL_LINES); // z축 그리기
    glVertex3f(0.0, 0.0, -2.0); // 좌표 지정
    glVertex3f(0.0, 0.0, 2.0); // 좌표 지정
    glEnd(); // 그리기 종료
    glPopMatrix(); // 행렬 스택에서 top에 있는 행렬 삭제

    glColor3f(0.3, 0.3, 0.7); // Teapot의 색 지정
    glPushMatrix(); // 행렬 스택에 현재 변환 행렬 저장
    glTranslatef(0.0, 0.0, 0.0); // Teapot 위치 조정
    glutWireTeapot(1.0); // Teapot을 1.0의 크기로 그리기
    glPopMatrix(); // 행렬 스택에서 top에 있는 행렬 삭제

    glColor3f(0.5, 0.1, 0.0); // cube 색 지정
    glPushMatrix(); // 행렬 스택에 현재 변환 행렬 저장
    glTranslatef(-1.0, 0.0, -1.0); // cube위치 조정
    glutWireCube(1.0); // cube를 1.0의 크기로 그리기
    glPopMatrix(); // 행렬 스택에서 top에 있는 행렬 삭제
}

// 디스플레이 콜백함수 정의
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 색 버퍼, 깊이 버퍼를 삭제하여 화면에서 그림 지우기
    glColor3f(1.0, 1.0, 1.0); // 색깔 지정
    
    glMatrixMode(GL_PROJECTION); // 투영 행렬 선택
    glLoadIdentity(); // 투영 행렬을 항등 행렬로 초기화

    glOrtho(-2.0, 2.0, -2.0 * Height / Width, 2.0 * Height / Width, 0.5, 5.0); // 직교 투영 생성
    glMatrixMode(GL_MODELVIEW); // 모델뷰 행렬 선택
    glLoadIdentity(); // 모델뷰 행렬을 항등 행렬로 초기화

    glViewport(0, 0, Width / 2, Height / 2); // 좌측 하단에 뷰폿 생성
    glPushMatrix(); // 행렬 스택에 삽입
    gluLookAt(camera1[0], camera1[1], camera1[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    DrawScene();
    glPopMatrix();
    glViewport(Width / 2, 0, Width / 2, Height / 2); // 우측 하단에 뷰폿 생성
    glPushMatrix();
    gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glPopMatrix();
    glViewport(0, Height / 2, Width / 2, Height / 2); // 좌측 상단에 뷰폿 생성
    glPushMatrix();
    gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
    glPopMatrix();
    glViewport(Width / 2, Height / 2, Width / 2, Height / 2); // 우측 상단에 뷰폿 생성
    glMatrixMode(GL_PROJECTION); // 투영 행렬 선택
    glPushMatrix();
    glLoadIdentity(); // 투영 행렬을 항등 행렬로 초기화
    gluPerspective(30, Width / Height, 3.0, 50.0); // 원근 투영 생성
    glMatrixMode(GL_MODELVIEW); // 모델뷰 행렬 선택
    glPushMatrix();
    gluLookAt(camera2[0], camera2[1], camera2[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    DrawScene();
    glPopMatrix();
    glMatrixMode(GL_PROJECTION); // 투영 행렬 선택
    glPopMatrix();
    glutSwapBuffers(); // 전면 버퍼와 백 버퍼를 교체하여 화면에 그림 그리기
}

// 윈도우 창 크기 조절에 대한 콜백 함수 정의
void MyReshape(int w, int h) {
    Width = w; // 새 너비 값을 Width 전역 변수 값에 할당
    Height = h; // 새 높이 값을 Height 전역 변수 값에 할당
}

// 좌하단 객체를 바라보는 카메라의 시점 변환 설정
void MyMouseMove1_XY(GLint x, GLint y) {
    GLint deltaX = x - mousePos[0];
    GLint deltaY = y - mousePos[1];
    camera1[0] = deltaX / 5;
    camera1[1] = deltaY / 5;
    glutPostRedisplay();
}

// 우상단 객체를 바라보는 카메라의 시점 변환 설정
void MyMouseMove2_XY(GLint x, GLint y) {
    GLint deltaX = x - mousePos[0];
    GLint deltaY = y - mousePos[1];
    camera2[0] = deltaX / 5;
    camera2[1] = deltaY / 5;
    glutPostRedisplay();
}

// 마우스 드래그 시 변화된 좌표값을 배열에 저장
void MyMouseMove(GLint x, GLint y) {
    mousePos[0] = x;
    mousePos[1] = y;
}

// 마우스 이벤트에 대한 콜백함수 정의
void MyMouseClick(GLint button, GLint state, GLint x, GLint y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x < Width / 2 && y > Height / 2)
            glutMotionFunc(MyMouseMove1_XY);
        else if (x > Width / 2 && y < Height / 2)
            glutMotionFunc(MyMouseMove2_XY);
    } else if (button == 3) { // 위로 스크롤
        if (x < Width / 2 && y > Height / 2 && camera1[2] >= -6.0) {
            camera1[2] -= 0.25;
            glutPostRedisplay();
        } else if (x > Width / 2 && y < Height / 2 && camera2[2] >= -15.0) {
            camera2[2] -= 0.25;
            glutPostRedisplay();
        }
    } else if (button == 4) { // 아래로 스크롤
        if (x < Width / 2 && y > Height / 2 && camera1[2] <= 6.0) {
            camera1[2] += 0.25;
            glutPostRedisplay();
        } else if (x > Width / 2 && y < Height / 2 && camera2[2] <= 15.0) {
            camera2[2] += 0.25;
            glutPostRedisplay();
        }
    }
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc, argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // 디스플레이 모드를 DOUBLE, RGBA 모드로 초기화
    glutInitWindowSize(500, 500); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Viewpory Partition"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutReshapeFunc(MyReshape); // 크기 지정 및 변경에 대한 이벤트 콜백함수 등록
    glutPassiveMotionFunc(MyMouseMove); // 마우스 모션에 대한 이벤트 콜백함수 등록
    glutMouseFunc(MyMouseClick); // 마우스 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
