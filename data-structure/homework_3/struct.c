#include <stdio.h> // 표준출력 함수 사용을 위한 라이브러리 추가

// 첫 번째 학생에 대한 구조체 student1 선언
struct student1 {
    char lastName; // '성'에 대한 데이터가 저장될 문자형 변수를 구조체 멤버로 선언
    int studentId; // '학번'에 대한 데이터가 저장될 정수형 변수를 구조체 멤버로 선언
    char grade; // '학점'에 대한 데이터가 저장될 문자형 변수를 구조체 멤버로 선언
};

// 첫 번째 학생에 대한 구조체를 student2라는 타입으로 선언
typedef struct {
    char lastName; // '성'에 대한 데이터가 저장될 문자형 변수를 구조체 멤버로 선언
    int studentId; // '학번'에 대한 데이터가 저장될 정수형 변수를 구조체 멤버로 선언
    char grade; // '학점'에 대한 데이터가 저장될 문자형 변수를 구조체 멤버로 선언
} student2;

int main() {
    // 구조체 변수 st1을 초기화 및 정의
    struct student1 st1 = {'A', 100, 'A'};

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");
    
    // 구조체 변수 st1의 lastName에 저장된 데이터를 출력
    printf("st1.lastName = %c\n", st1.lastName);
    // 구조체 변수 st1의 studentId에 저장된 데이터를 출력
    printf("st1.studentId = %d\n", st1.studentId);
    // 구조체 변수 st1의 grade 저장된 데이터를 출력
    printf("st1.grade = %c\n", st1.grade);
    
    // 구조체 변수 st2을 초기화 및 정의
    // struct가 생략된 이유는 st2가 typedef로 정의되었기 때문
    student2 st2 = {'B', 200, 'B'};
    
    // 구조체 변수 st2의 lastName에 저장된 데이터를 출력
    printf("\nst2.lastName = %c\n", st2.lastName);
    // 구조체 변수 st2의 studentId 저장된 데이터를 출력
    printf("st2.studentId = %d\n", st2.studentId);
    // 구조체 변수 st2의 grade 저장된 데이터를 출력
    printf("st2.grade = %c\n", st2.grade);
    
    // 구조체 변수 st3 정의
    student2 st3;
    // 구조체 변수 st2를 st3에 대입
    st3 = st2;
    // 구조체 변수 st3의 lastName에 저장된 데이터를 출력
    printf("\nst3.lastName = %c\n", st3.lastName);
    // 구조체 변수 st3의 stuentId 저장된 데이터를 출력
    printf("st3.studentId = %d\n", st3.studentId);
    // 구조체 변수 st3의 grade에 저장된 데이터를 출력
    printf("st3.grade = %c\n", st3.grade);
    
    /* equality test */
    /* 구조체 변수 st3의 모든 멤버 변수와 st2의 모든 멤버 변수를 각각
    비교하여 전부 일치할 때 equal를 출력 */ 
    if (st3.lastName == st2.lastName &&
    st3.studentId == st2.studentId &&
    st3.grade == st2.grade) {
        printf("equal\n");
    }
    else // 위 if문의 조건 중 하나라도 거짓일 시 not equal를 출력
        printf("not equal\n");
    return 0; // 0을 반환함으로써 프로그램을 종료
}