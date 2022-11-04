///*************************************************************************/
///*                      HW#3 : Callback Programming                      */
///*  작성자 : 성열암                            날짜 : 2022년 10월 06일         */
///*                                                                       */
///*  문제 정의 :  Keyboard Callback 응용 I                                   */
///*                - - - - - - -                                          */
///*  기능 :                                                                */
///*    1. a 또는 A : 4개의 vertex 좌표가 동일하게 왼쪽으로 0.1씩 이동               */
///*    2. f 또는 F : 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 이동              */
///*    3. r 또는 R : 4개의 vertex 좌표가 동일하게 아래쪽으로 0.1씩 이동하고,          */
///*       빨간색으로 Polygon 칠함                                             */
///*    4. v 또는 V : 4개의 vertex 좌표가 동일하게 위쪽으로 0.1씩 이동               */
///*    5. b 또는 B : 파란색으로 Polygon 칠함                                   */
///*                - - - - - - -                                          */
///*************************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록

// 도형의 x, y위치 값을 변경시키기 위해 좌표 조정을 위한 변수 선언 & 파란색 설정 변수 선언
double x, y, setGLColorBlue; 

// 사용자 초기화 함수 정의
void MyInit() {
    glClearColor (1.0, 1.0, 1.0, 1.0); // 배경색을 흰색, 불투명하게 지정
    glMatrixMode(GL_PROJECTION); // 행렬 모드를 투영행렬로 설정
    glLoadIdentity(); // 행렬을 단위행렬로 초기화
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시부피 설정
}

// 디스플레이 콜백함수 정의
void MyDisplay( ) {
    glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화
    // setGLColorBlue의 값을 조정하여 결과적으로 (0, 0, 1)가 나오도록 설계
    glColor3f(0.5-setGLColorBlue, 0.5-setGLColorBlue, 0.5+setGLColorBlue);
    // (다각형)으로 그리기 시작
    glBegin(GL_POLYGON);
    glVertex3f(-0.5 + x, -0.5 + y, 0.0); // 첫 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x, -0.5 + y, 0.0); // 두 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x, 0.5 + y, 0.0); // 세 번째 정점의 x, y, z좌표 설정
    glVertex3f(-0.5 + x, 0.5 + y, 0.0); // 네 번째 정점의 x, y, z좌표 설정
    glEnd(); // 그리기 종료
    glFlush(); // 화면에 출력(버퍼코드를 실행)
}

// 키보드 콜백함수 정의
void MyKeyboard(unsigned char key, int a, int b) {
    switch (key) { // 키보드 입력키를 토대로 switch-case문 내 case값과 비교
        case 'Q': exit(0); break; // Q입력 시 프로그램 종료
        case 'q': exit(0); break; // Q입력 시 프로그램 종료
        case 27: exit(0); break; // Q(아스키 번호==27)입력 시 프로그램 종료
        case 'a': x -= 0.1; break; // a입력 시 x값 -0.1을 수행하여 도형을 좌측으로 이동
        case 'A': x -= 0.1; break; // A입력 시 x값 -0.1을 수행하여 도형을 좌측으로 이동
        case 'f': x += 0.1; break; // b입력 시 x값 +0.1을 수행하여 도형을 우측으로 이동
        case 'F': x += 0.1; break; // B입력 시 x값 +0.1을 수행하여 도형을 우측으로 이동
        case 'r': y -= 0.1; break; // r입력 시 y값 -0.1을 수행하여 도형을 하단으로 이동
        case 'R': y -= 0.1; break; // R입력 시 y값 -0.1을 수행하여 도형을 하단으로 이동
        case 'v': y += 0.1; break; // v입력 시 y값 +0.1을 수행하여 도형을 상단으로 이동
        case 'V': y += 0.1; break; // V입력 시 y값 +0.1을 수행하여 도형을 상단으로 이동
        /* b입력 시 setGLColorBlue의 값을 0.5로 변경하여 결과적으로 개체 색이 파란색으로 변경되도록 설정
        다시 입력 시에는 다시 원래 색으로 변경 */
        case 'b': {
            if (setGLColorBlue == 0) setGLColorBlue = 0.5;
            else setGLColorBlue = 0;
            break;
        }
        /* B입력 시 setGLColorBlue의 값을 0.5로 변경하여 결과적으로 개체 색이 파란색으로 변경되도록 설정
        다시 입력 시에는 다시 원래 색으로 변경 */
        case 'B': {
            if (setGLColorBlue == 0) setGLColorBlue = 0.5;
            else setGLColorBlue = 0;
            break;
        }
    }
    glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc,argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 RGB 모드로 초기화
    glutInitWindowSize(300, 300); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Keyboard Callback(1)"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutKeyboardFunc(MyKeyboard); // 키보드 이벤트 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
