///*************************************************************************/
///*                      HW#3 : Callback Programming                      */
///*  작성자 : 성열암                            날짜 : 2022년 10월 06일         */
///*                                                                       */
///*  문제 정의 :  Keyboard Callback 응용 II                                  */
///*                - - - - - - -                                          */
///*  기능 :                                                                */
///*    1. ↑ : 4개의 vertex 좌표가 동일하게 위쪽으로 0.1씩 이동                     */
///*    2. ↓ : 4개의 vertex 좌표가 동일하게 아래쪽으로 0.1씩 이동                    */
///*    3. ← : 4개의 vertex 좌표가 동일하게 왼쪽으로 0.1씩 이동                     */
///*    4. → : 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 이동                    */
///*    5. PageUp : 4개의 vertex 좌표로 이루어진 Polygon이 각 방향으로 0.1씩        */
///*       연속적으로 확대(Zoom In)                                            */
///*    6. PageDown : 4개의 vertex 좌표로 이루어진 Polygon이 각 방향으로 0.1씩      */
///*       연속적으로 축소(Zoom Out)                                           */
///*                - - - - - - -                                          */
///*************************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록

// 도형의 x, y위치 값을 변경시키기 위해 좌표 조정을 위한 변수 선언 & 확대값 조정 변수 선언
double x, y, zoom;

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
    glVertex3f(-0.5 + x - zoom, -0.5 + y - zoom, 0.0); // 첫 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x + zoom, -0.5 + y - zoom, 0.0); // 두 번째 정점의 x, y, z좌표 설정
    glVertex3f(0.5 + x + zoom, 0.5 + y + zoom, 0.0); // 세 번째 정점의 x, y, z좌표 설정
    glVertex3f(-0.5 + x - zoom, 0.5 + y + zoom, 0.0); // 네 번째 정점의 x, y, z좌표 설정
    glEnd(); // 그리기 종료
    glFlush(); // 화면에 출력(버퍼코드를 실행)
}

// 특수키 입력에 대한 콜백함수 정의
void MySpecial(int key, int a, int b) {
    switch (key) { // 키보드 입력키를 토대로 switch-case문 내 case값과 비교
        // 좌측 방향키 클릭 시 가시 부피 내에서 이동이 이뤄지도록 조건 설계
        case GLUT_KEY_LEFT: {
            if ((0.5 + x + zoom) - (-0.5 + x - zoom) <= 0.6) {
                if (-0.5 + x - zoom -0.1 < -1) return;
            } else {
                if (-0.5 + x - zoom <= -1) return;
            }
            x -= 0.1; break;
        }
        // 우측 방향키 클릭 시 가시 부피 내에서 이동이 이뤄지도록 조건 설계
        case GLUT_KEY_RIGHT: {
            if ((0.5 + x + zoom) - (-0.5 + x - zoom) <= 0.6) {
                if (0.5 + x + zoom + 0.1 > 1) return;
            } else {
                if (0.5 + x + zoom >= 1) return;
            }
            x += 0.1; break;
        }
        // 상단 방향키 클릭 시 가시 부피 내에서 이동이 이뤄지도록 조건 설계
        case GLUT_KEY_UP: {
            if ((0.5 + y + zoom) - (-0.5 + y - zoom) <= 0.6) {
                if (0.5 + y + zoom + 0.1 > 1) return;
            } else {
                if (0.5 + y + zoom >= 1) return;
            }
            y += 0.1; break;
        }
        // 하단 방향키 클릭 시 가시 부피 내에서 이동이 이뤄지도록 조건 설계
        case GLUT_KEY_DOWN: {
            if ((0.5 + y + zoom) - (-0.5 + y - zoom) <= 0.6) {
                if (-0.5 + y - zoom - 0.1 < -1) return;
            } else {
                if (-0.5 + y - zoom <= -1) return;
            }
            y -= 0.1; break;
        }
        // Page up키 입력 시 가시 부피 내에서 확대가 이뤄지도록 조건 설계
        case GLUT_KEY_PAGE_UP: {
            if ((0.5 + y + zoom) - (-0.5 + y - zoom) <= 0.6) {
                if (-0.5 + x - zoom - 0.1 < -1 ||
                    0.5 + x + zoom + 0.1 > 1 ||
                    0.5 + y + zoom + 0.1 > 1 ||
                    -0.5 + y - zoom - 0.1 < -1) return;
            } else {
                if (-0.5 + x - zoom <= -1 ||
                    0.5 + x + zoom >= 1 ||
                    0.5 + y + zoom >= 1 ||
                    -0.5 + y - zoom <= -1) return;
            }
            zoom += 0.1; break;
        }
        // Page down 입력 시 개체가 완전히 사라지지 않도로 조건 설계
        case GLUT_KEY_PAGE_DOWN: {
            if ((0.5 + x + zoom) - (-0.5 + x - zoom) < 0.2) return;
            zoom -= 0.1; break;
        }
        default: break; // 다른 키 입력이 이뤄졌을 떄에는 아무 수행 안 함
    }
    glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc,argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 RGB 모드로 초기화
    glutInitWindowSize(300, 300); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Keyboard Callback(2)"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutSpecialFunc(MySpecial); // 키보드 이벤트 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}