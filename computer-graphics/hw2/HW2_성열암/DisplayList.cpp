/////***********************************************************************/
///  *                           HW#2 : GL, GLU Modeling                    */
/////*  작성자 : 성열암                          날짜 : 2022년 9월 30일   */
/////*                                                                                       */
/////* 문제 정의 : Display List를 사용하여 일부                           */
/////*                  3D Primitive들을 구현                                   * /
/////*                - - - - - - -                                                       */
/////* 기능 :  Display List로 Sphere, Cylinder, Disk,                */
/////*       PartialDisk을 구현                                                       */
/////*       코드의 효율성 향상을 위해 Display List 사용
/////*         glNewList()와 glEndList()사이에 원하는 코드 추가.   */
/////*           - - - - - - -                                                           */
/////**********************************************************************/

#include <GL/glut.h> // GL/GLUT 헤더 파일로 부터 특정 함수들을 호출할 수 있도록 등록
#include <GL/gl.h> // 맥OS 기준 불필요(윈도우 시스템에서는 필요할 것 같아 추가하였습니다.)
#include <GL/glu.h> // 맥OS 기준 불필요(윈도우 시스템에서는 필요할 것 같아 추가하였습니다.)

GLuint list[4]; // 4개의 3D Primitive를 저장할 Display List 생성
GLUquadricObj* qobj = gluNewQuadric(); //새로운 Quadric 객체 생성

void MyInit(void) {
    glClearColor(1, 1, 1, 1); // 배경색을 흰색으로 지정, 불투명하게 설정
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // 프레임 버퍼를 초기화
    glCallList(list[0]); // Display List 실행(Sphere)
    glCallList(list[1]); // Display List 실행(Cylinder)
    glCallList(list[2]); // Display List 실행(Disk)
    glCallList(list[3]); // Display List 실행(Partial Disk)

    glFlush(); // 화면에 출력(버퍼코드를 실행)
}

// 창 크기 조정에 따른 콜백 함수 정의
void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // 뷰포트 설정
    glMatrixMode(GL_PROJECTION); // 투상 좌표계(GL_PROJECTION)의 공간을 앞으로 계산
    glOrtho(-4, 4, -4 * (GLfloat)h / (GLfloat)w, 4 * (GLfloat)h / (GLfloat)w, -10.0, 10.0); // 가시부피 설정
    glMatrixMode(GL_MODELVIEW); // 모델 좌표계와 시점 좌표계(GL_MODELVIEW)의 공간을 앞으로 계산
    glLoadIdentity(); // 여러 개체가 그려짐에 따라 행렬을 단위행렬로 초기화
}

// Display List 사용 함수 정의
void MyCreateList() {
    list[0] = glGenLists(4); //Display List 정수 아이디 할당
    list[1] = list[0] + 1;
    list[2] = list[1] + 1;
    list[3] = list[2] + 1;
    
    glNewList(list[0], GL_COMPILE); // Display List 생성
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 프레임 버퍼 지정
    glMatrixMode(GL_MODELVIEW); // 모델 좌표계와 시점 좌표계(GL_MODELVIEW)의 공간을 앞으로 계산
    glLoadIdentity(); // 여러 개체가 그려짐에 따라 행렬을 단위행렬로 초기화
    glRotatef(50.0, 1.0, 1.0, 0.0); // 50도 만큼 x,y,축 쪽으로 꺾기
    glEnable(GL_LIGHTING); // 조명 사용
    gluQuadricDrawStyle(qobj, GLU_SILHOUETTE); // 어떤 DrawStyle로 나타낼 것인가? 모서리
    gluQuadricNormals(qobj, GLU_SMOOTH); // 법선 벡터를 어떻게 나타낼 것인가?
    gluQuadricOrientation(qobj, GLU_OUTSIDE); // 법선 벡터의 내부 및 외부 등과 같은 방향 지정
    gluQuadricTexture(qobj, GL_FALSE); // Texture 좌표 사용할 것인지에 대한 여부
    gluSphere(qobj, 1.0,  5, 5); // 구 Quadric Object, 반지름, 경도, 위도
    glutSwapBuffers(); // 버퍼 변경
    glEndList(); // Display List 종료 함수

    glNewList(list[1], GL_COMPILE);
    glRotatef(30.0, 1.0, 1.0, 1.0); // 50도 만큼 x,y,z축 쪽으로 꺾기
    glTranslated(1, 3, 0); // 방향을 (1, 3, 0) 쪽으로 옮김
    gluQuadricDrawStyle(qobj, GLU_POINT); // 어떤 DrawStyle로 나타낼 것인가? 점
    gluQuadricNormals(qobj, GLU_SMOOTH); // 법선 벡터를 어떻게 나타낼 것인가?
    gluQuadricOrientation(qobj, GLU_OUTSIDE); // 법선 벡터의 내부 및 외부 등과 같은 방향 지정
    gluQuadricTexture(qobj, GL_FALSE); // Texture 좌표 사용할 것인지에 대한 여부
    gluCylinder(qobj, 0.5, 0.5, 1, 50, 50); // 실린더 모양 Quadric Object, 밑변 반지름, 윗변 반지름, 높이, 슬라이스, 스택
    glEndList();

    glNewList(list[2], GL_COMPILE);
    glRotatef(80.0, 1.0, 1.0, 1.0); // 80도 만큼 x,y,z축 쪽으로 꺾기
    glTranslated(-2, -2, -2); // 방향을 (-2, -2, -2) 쪽으로 옮김
    gluQuadricDrawStyle(qobj, GLU_LINE); // 어떤 DrawStyle로 나타낼 것인가? 선
    gluQuadricNormals(qobj, GLU_SMOOTH); // 법선 벡터를 어떻게 나타낼 것인가?
    gluQuadricOrientation(qobj, GLU_OUTSIDE); // 법선 벡터의 내부 및 외부 등과 같은 방향 지정
    gluQuadricTexture(qobj, GL_FALSE); // Texture 좌표 사용할 것인지에 대한 여부
    gluDisk(qobj, 0.2, 1.0, 20, 3); // 디스크 모양 Quadric Object, 안쪽 반지름, 바깥쪽 반지름, 슬라이스, 루프
    glEndList();
    
    glNewList(list[3], GL_COMPILE);
    glRotatef(0.0, 1.0, 1.0, 1.0); // 0도 만큼 x,y,z축 쪽으로 꺾기
    glTranslated(0, 0, 0.5); // 방향을 (0, 0, 0.5) 쪽으로 옮김
    gluQuadricDrawStyle(qobj, GLU_LINE); // 어떤 DrawStyle로 나타낼 것인가? 선
    gluQuadricNormals(qobj, GLU_SMOOTH); // 법선 벡터를 어떻게 나타낼 것인가?
    gluQuadricOrientation(qobj, GLU_OUTSIDE); // 법선 벡터의 내부 및 외부 등과 같은 방향 지정
    gluQuadricTexture(qobj, GL_FALSE); // Texture 좌표 사용할 것인지에 대한 여부
    gluPartialDisk(qobj, 1.5, 3.0, 26, 13, 50, 35); // PartialDisk Object, 안쪽 반지름, 바깥쪽 반지름, 슬라이스, 루프, 시작, 스윕
    glEndList();
}

int main(int argc, char** argv) { // main 함수 정의
    glutInit(&argc,argv); // GLUT Library를 운영체제 정보에 맞게 초기화
    glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 RGB 모드로 초기화
    glutInitWindowSize(700, 700); // Window(창)의 크기(해상도) 설정
    glutInitWindowPosition(0, 0); // 모니터에서 Window(창)의 위치 시작점 결정
    glutCreateWindow("GLU Modeling – 3D Primitives"); // 인수를 타이틀로 지정한 Window(창) 생성
    MyInit();
    glutDisplayFunc(MyDisplay); // Display 콜백함수 등록
    glutReshapeFunc(Reshape); // 창 크기 재조절 콜백함수 등록
    MyCreateList(); //Display List 생성하기
    glutMainLoop(); // 메시지 무한 루프 시작(이벤트 처리를 가능하게 하기 위해서)
    return 0;
}
