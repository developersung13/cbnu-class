///*************************************************************************/
///*                      HW#3 : Callback Programming                      */
///*  작성자 : 성열암                            날짜 : 2022년 10월 06일         */
///*                                                                       */
///*  문제 정의 :  Menu Callback 응용                                         */
///*                - - - - - - -                                          */
///*  기능 :                                                                */
///*    주메뉴 : Draw Sphere, Draw Torus, Draw Teapot, Change Color, Exit    */
///*    Draw Sphere 하부 메뉴 : Small Sphere, Large Sphere                   */
///*    Draw Torus 하부 메뉴 : Small Torus , Large Torus                     */
///*    Draw Teapot 하부 메뉴 : Small Teapot , Large Teapot                  */
///*    Change Color 하부 메뉴 : Red, Green, Blue                            */
///*                - - - - - - -                                          */
///*************************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록

GLint setColor; // 색 지정시 조건식에서 사용될 변수 선언
GLboolean isSphere = true, // 도형 지정 시 조건식에서 사용될 변수 선언
isTorus,
isTeapot;
GLboolean isSmall = true; // 크기 지정 시 조건식에서 사용될 변수 선언

// 디스플레이 콜백함수 정의
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화
    switch (setColor) { // 색 지정에 대한 변숫값을 토대로 switch-case문 내 case값과 비교
        case 0: glColor3f(0, 0.5, 0.5); break; // 남색 지정
        case 1: glColor3f(1, 0, 0); break; // 빨간색 지정
        case 2: glColor3f(0, 1, 0); break; // 초록색 지정
        case 3: glColor3f(0, 0, 1); // 파란색 지정
    }
    
    if ((isSphere) && (isSmall)) // 'Sphere'이면서 'small'이 선택되었을 때
        glutWireSphere(0.5, 30, 30); // 선으로 작은 Sphere 그림
    else if ((isSphere) && (!isSmall)) // 'Sphere'이면서 'large'이 선택되었을 때
        glutWireSphere(0.7, 30, 30); // 선으로 큰 Sphere 그림
    else if ((isTorus) && (isSmall)) // 'Torus'이면서 'small'이 선택되었을 때
        glutWireTorus(0.1, 0.3, 40, 20); // 선으로 작은 Torus 그림
    else if ((isTorus) && (!isSmall)) // 'Torus'이면서 'large'이 선택되었을 때
        glutWireTorus(0.2, 0.5, 40, 20); // 선으로 큰 Torus 그림
    else if ((isTeapot) && (isSmall)) // 'Teapot'이면서 'small'이 선택되었을 때
        glutWireTeapot(0.3); // 선으로 작은 Teapot 그림
    else if ((isTeapot) && (!isSmall)) // 'Teapot'이면서 'large'이 선택되었을 때
        glutWireTeapot(0.5); // 선으로 큰 Teapot 그림
    glFlush(); // 화면에 출력(버퍼코드를 실행)
}

// 메인메뉴 함수 정의
void MyMainMenu(int entryID) {
    if(entryID == 1) exit(0); // 1번으로 등록되었던 메뉴 선택 시 프로그램 종료
}

// Sphere메뉴 함수 정의
void mySpherMenu(int entryID) {
    // 1번으로 등록되었던 메뉴 선택 시 isSphere만 true, isSmall도 참
    if (entryID == 1)  {
        isSphere = true;
        isTorus = false;
        isTeapot = false;
        isSmall = true;
    // 2번으로 등록되었던 메뉴 선택 시 isSphere만 true, isSmall은 거짓
    } else if(entryID == 2) {
        isSphere = true;
        isTorus = false;
        isTeapot = false;
        isSmall = false;
    }
    glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
}

// Torus메뉴 함수 정의
void myTorusMenu(int entryID) {
    // 1번으로 등록되었던 메뉴 선택 시 isTorus만 true, isSmall도 참
    if (entryID == 1) {
        isSphere = false;
        isTorus = true;
        isTeapot = false;
        isSmall = true;
    }
    // 2번으로 등록되었던 메뉴 선택 시 isTorus만 true, isSmall은 거짓
    else if(entryID == 2) {
        isSphere = false;
        isTorus = true;
        isTeapot = false;
        isSmall = false;
    }
    glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
}

// Teapot 메뉴 함수 정의
void myTeapotMenu(int entryID) {
    // 1번으로 등록되었던 메뉴 선택 시 isTeapot true, isSmall도 참
    if (entryID == 1) {
        isSphere = false;
        isTorus = false;
        isTeapot = true;
        isSmall = true;
    // 2번으로 등록되었던 메뉴 선택 시 isTeapot true, isSmall은 거짓
    } else if(entryID == 2) {
        isSphere = false;
        isTorus = false;
        isTeapot = true;
        isSmall = false;
    }
    glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
}

// 색상 변경 메뉴 함수 정의
void myChangingColorMenu(int entryID) {
    // 1번으로 등록되었던 메뉴 선택 시 1번 색상(빨간색)으로 선택
    if (entryID == 1) setColor = 1;
    // 2번으로 등록되었던 메뉴 선택 시 2번 색상(파란색)으로 선택
    else if(entryID == 2) setColor = 2;
    // 3번으로 등록되었던 메뉴 선택 시 3번 색상(초록색)으로 선택
    else if(entryID == 3) setColor = 3;
    glutPostRedisplay(); // display 콜백함수의 실행을 요구(화면에 변경사항 반영)
}

// 사용자 초기화 함수 정의
void MyInit() {
    glClearColor (1.0, 1.0, 1.0, 1.0); // 배경색을 흰색, 불투명하게 지정
    glMatrixMode(GL_PROJECTION); // 행렬 모드를 투영행렬로 설정
    glLoadIdentity(); // 행렬을 단위행렬로 초기화
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시부피 설정
    
    // Sphere메뉴 생성 및 서브 메뉴 등록
    GLint mySpherID = glutCreateMenu(mySpherMenu);
    glutAddMenuEntry("Small Sphere", 1); // entryId 1
    glutAddMenuEntry("Large Sphere", 2); // entryId 2
    
    // Torus메뉴 생성 및 서브 메뉴 등록
    GLint myTorusID = glutCreateMenu(myTorusMenu);
    glutAddMenuEntry("Small Torus", 1); // entryId 1
    glutAddMenuEntry("Large Torus", 2); // entryId 2
    
    // Teapot메뉴 생성 및 서브 메뉴 등록
    GLint myTeapotID = glutCreateMenu(myTeapotMenu);
    glutAddMenuEntry("Small Teapot", 1); // entryId 1
    glutAddMenuEntry("Large Teapot", 2); // entryId 2
    
    // 색상 변경 메뉴 생성 및 서브 메뉴 등록
    GLint myChangingColorID = glutCreateMenu(myChangingColorMenu);
    glutAddMenuEntry("RED", 1); // entryId 1
    glutAddMenuEntry("Green", 2); // entryId 2
    glutAddMenuEntry("Blue", 3); // entryId 3
    
    // 메인 메뉴 생성 및 서브 메뉴 등록
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddSubMenu("Draw Sphere", mySpherID); // entryId mySpherID
    glutAddSubMenu("Draw Torus", myTorusID); // entryId myTorusID
    glutAddSubMenu("Draw Teapot", myTeapotID); // entryId myTeapotID
    glutAddSubMenu("Change Color", myChangingColorID); // entryId myChangingColorIDID
    glutAddMenuEntry("Exit", 1); // entryId 1
    glutAttachMenu(GLUT_RIGHT_BUTTON); // 메뉴 사용 가능 설정 및 마우스 우클릭 시 메뉴 출력
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc,argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 RGB 모드로 초기화
    glutInitWindowSize(500, 500); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("Menu Callback"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit(); // 사용자 초기화 함수 호출
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0; // 0을 반환함으로써 main함수 종료
}
