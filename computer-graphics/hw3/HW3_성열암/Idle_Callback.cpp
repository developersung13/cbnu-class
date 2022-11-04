///*************************************************************************/
///*                      HW#3 : Callback Programming                      */
///*  작성자 : 성열암                            날짜 : 2022년 10월 06일         */
///*                                                                       */
///*  문제 정의 : Idle Callback 응용                                          */
///*                - - - - - - -                                          */
///*  기능 :                                                                */
///*    1. ↑ : 4개의 vertex 좌표가 동일하게 위쪽으로 0.1씩 이동                     */
///*    2. ↓ : 4개의 vertex 좌표가 동일하게 아래쪽으로 0.1씩 이동                    */
///*    3. ← : 4개의 vertex 좌표가 동일하게 왼쪽으로 0.1씩 이동                     */
///*    4. → : 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 이동                    */
///*                - - - - - - -                                          */
///*************************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록

GLint direction; // 상하좌우에 대한 방향의 구분 변수로 사용하고자 선언
GLdouble x, y; // 도형의 x, y위치 값을 변경시키기 위해 좌표 조정을 위한 변수 선언

// 디스플레이 콜백함수 정의
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화
    glColor3f(0, 0.5, 0.8); // 그려지는 개체의 색을 파란색으로 지정
    glBegin(GL_POLYGON); // (다각형)으로 그리기 시작
    glVertex3f(-0.5 + x, -0.5 + y, 0.0); // 첫 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x, -0.5 + y, 0.0); // 두 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x, 0.5 + y, 0.0); // 세 번째 정점의 x, y, z좌표 설정
    glVertex3f(-0.5 + x, 0.5 + y, 0.0); // 네 번째 정점의 x, y, z좌표 설정
    glEnd(); // 그리기 종료
    glutSwapBuffers(); // 개체를 전부 그린 이후에 전면버퍼와 후면버퍼를 교체함
}

// Idle 이벤트에 대한 콜백함수 정의
void MyIdle() {
    // 방향에 대한 변수값을 토대로 switch-case문 내 case값과 비교
    switch (direction) {
        case 1: { // 방향이 1(왼쪽으로)일 때
            // 도형이 왼쪽 테두리에 닿기 전까지 x값을 -0.01 연산하여 왼쪽으로 이동
            if (-0.5 + x > -1) {
                x -= 0.01;
                break;
            } else { // 도형이 왼쪽 테두리에 닿으면 더 이상 x값이 변하지 않도록 설정
                x = -0.5;
                break;
            }
        }
        case 2: { // 방향이 2(오른쪽으로)일 때
            if (0.5 + x < 1) {
                // 도형이 오른쪽 테두리에 닿기 전까지 x값을 +0.01 연산하여 오른쪽으로 이동
                x += 0.01; break;
            } else { // 도형이 오른쪽 테두리에 닿으면 더 이상 x값이 변하지 않도록 설정
                x = 0.5;
                break;
            }
        }
        case 3: { // 방향이 3(위쪽으로)일 때
            // 도형이 위쪽 테두리에 닿기 전까지 y값을 +0.01 연산하여 위쪽으로 이동
            if (0.5 + y < 1) {
                y += 0.01; break;
            } else { // 도형이 위쪽 테두리에 닿으면 더 이상 y값이 변하지 않도록 설정
                y = 0.5;
                break;
            }
        }
        case 4: { // 방향이 4(아래쪽으로)일 때
            // 도형이 아래쪽 테두리에 닿기 전까지 y값을 -0.01 연산하여 아래쪽으로 이동
            if (-0.5 + y > -1) {
                y -= 0.01; break;
            } else { // 도형이 아래쪽 테두리에 닿으면 더 이상 y값이 변하지 않도록 설정
                y = -0.5;
                break;
            }
        }
    }
    glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
}

// 특수키 입력에 대한 콜백함수 정의
void MySpecial(int key, int a, int b) {
    switch (key) { // 입력된 특수키의 값을 토대로 switch-case문 내 case값과 비교
        case GLUT_KEY_LEFT: direction = 1; break; // 좌측 방향키 입력 시 방향 변숫값을 1로 설정
        case GLUT_KEY_RIGHT: direction = 2; break; // 우측 방향키 입력 시 방향 변숫값을 2로 설정
        case GLUT_KEY_UP: direction = 3; break; // 상단 방향키 입력 시 방향 변숫값을 3로 설정
        case GLUT_KEY_DOWN: direction = 4; // 하단 방향키 입력 시 방향 변숫값을 4로 설정
    }
}

// 사용자 초기화 함수 정의
void MyInit() {
    glClearColor (1.0, 1.0, 1.0, 1.0); // 배경색을 흰색, 불투명하게 지정
    glMatrixMode(GL_PROJECTION); // 행렬 모드를 투영행렬로 설정
    glLoadIdentity(); // 행렬을 단위행렬로 초기화
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시부피 설정
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc,argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // 디스플레이 모드를 RGB 및 DOUBLE 모드로 초기화
    glutInitWindowSize(300, 300); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Idle Callback"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutIdleFunc(MyIdle); // Idle 콜백함수 등록
    glutSpecialFunc(MySpecial); // 특수키 입력에 대한 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
