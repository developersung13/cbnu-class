///*************************************************************************/
///*                           HW#2 : GL, GLU Modeling                     */
///*  작성자 : 성열암                            날짜 : 2022년 9월 30일          */
///*                                                                       */
///* 문제 정의 : 2D Primitive들을 정확히 구현                                    */
///*                - - - - - - -                                          */
///* 기능 : GL_POINTS를 사용하여 점을 표현                                       */
///*                - - - - - - -                                          */
///*************************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록

// 디스플레이 콜백함수 정의
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화
    glColor3f(0.3, 0.5, 0.7); // 그려지는 개체의 색을 파란색으로 지정
    glPointSize(8.0); // 점(포인트) 사이즈 8로 지정
    glBegin(GL_POINTS); // 점으로 그리기 시작
    glVertex3f(-0.5, -1, 0); // 점(1) 좌표 표시
    glVertex3f(0.5, -1, 0); // 점(2) 좌표 표시
    glVertex3f(1, 0, 0); // 점(3) 좌표 표시
    glVertex3f(0.5, 1, 0); // 점(4) 좌표 표시
    glVertex3f(-0.5, 1, 0); // 점(5) 좌표 표시
    glVertex3f(-1, 0, 0); // 점(6) 좌표 표시
    glEnd(); // 그리기 종료
    glFlush(); // 화면에 출력(버퍼코드를 실행)
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc, argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 RGB 모드로 초기화
    glutInitWindowSize(500, 500); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("GL Modeling - 2D Primitive(GL_POINTS)"); // "GL Modeling - 2D Primitive(GL_POINTS)"의 타이틀로 새로운 Window(창) 생성
    glClearColor(1.0, 1.0, 1.0, 1.0); // 배경색을 흰색으로 지정, 불투명하게 설정
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); // 가시부피 지정
    glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록
    glutMainLoop(); // // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 함수를 반환하여 프로그램 종료
}
