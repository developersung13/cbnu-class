/****************************************************************************************************/
///*                           HW#1 : 3D Sierpinski Gasket                                                */
///*  작성자 : 성열암                                              날짜 : 2022년 9월 20일                 */
///*                                                                                                                         */
///* 문제 정의 :  2D triangle Gasket을 3D tetrahedron Gasket으로 변경.                  */
///*                   - - - - - - -                                                                                       */
///* 기능 :  정사면체가 입체적으로 보일 수 있도록 2차원의 정점을 3차원으로 변경하고,    */
///*            MyReshape 함수를 사용하여 왜곡문제를 해결함.                                       */
///*            - - - - - - -                                                                                              */
///**************************************************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록

void MyDisplay( ) { // 디스플레이 콜백함수 정의
    float vertices[4][3]={{ 0, 0, 0 },{ 250, 500, 100 },{ 500, 250, 250 }, {250, 100, 250}}; // 가시부피 내 표시할 점 4개의 좌표를 지정
    float p[3] = { 250, 100, 250 }; // 찍힐 포인트 좌표를 지정
    int i, j;
    glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화
    for (j = 0; j < 50000; j++){
        i = rand() % 4; // 점 4개에 대한 0~3 값이 나타날 수 있도록 난수 사용
        p[0] = (p[0] + vertices[i][0]) / 2.0; // x좌표 재설정
        p[1] = (p[1] + vertices[i][1]) / 2.0; // y좌표 재설정
        p[2] = (p[2] + vertices[i][2]) / 2.0; // z좌표 재설정
        glBegin(GL_POINTS); // 도형 그리기 시작
        glVertex3fv(p); // 위에서 계산된 p의 값으로 각 정점들을 연결함
        glEnd(); // 도형 그리기 종료
    }
    glFlush(); // 화면에 출력(버퍼코드를 실행)
}

// 객체 색생을 지정하는 사용자 함수 정의
void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // 배경색을 흰색으로 지정, 불투명하게 설정
    glColor3f(1.0, 0.0, 0.0); // 그려질 객체들의 색상을 빨간색으로 지정
}

// Window(창)의 크기 변경에 대한 콜백함수 정의(매개변수로써 신규 [너비, 높이]값을 받아옴)
void MyReshape(int newWidth, int newHeight) {
    glViewport(0, 0, newWidth, newHeight); // 정규화된 디바이스 좌표에서 창 좌표로 [x, y]의 아핀 변환 지정
    GLfloat widthFac = (GLfloat)newWidth / (GLfloat)500; // glutInitWindowSize(500, 500);을 따라서 너비 값 지정
    GLfloat heightFac = (GLfloat)newHeight / (GLfloat)500; // glutInitWindowSize(500, 500);을 따라서 높이 값 지정
    glMatrixMode(GL_PROJECTION);// 행렬 모드를 "투영 행렬"로 설정
    glLoadIdentity(); // 항등 행렬로 초기화
    glOrtho(0.0 * widthFac, 500.0 * widthFac, 0.0 *
            heightFac, 500.0 * heightFac, -500.0, 500); // 새롭게 정의되는 창의 정보(너비 & 높이 & 깊이)를 토대로 가시 부피가 적절히 그려질 수 있도록 지정
}

void RegisterCallback() { // 콜백함수를 호출하는 사용자 함수 정의
    glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록
    glutReshapeFunc(MyReshape); // Window(창)의 크기 변경에 대한 콜백함수 등록
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc, argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 RGB 모드로 초기화
    glutInitWindowSize(500, 500); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Sierpinski Gasket"); // "Sierpinski Gasket"의 타이틀로 새로운 Window(창) 생성
    MyInit(); // 객체 색생을 지정하는 사용자 함수 호출
    RegisterCallback(); // 콜백함수를 종합시켜 놓은 사용자 함수 호출
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
}
