function CustomerUI() {
  return (
    <section className="grid gap-2 grid-cols-2 row-span-3">
      <article className="busReservation">
        <h3>버스 예약 관리</h3>
        <div>
          <button>추가하기</button>
          <button>취소하기</button>
          <button>변경하기</button>
          <button>조회하기</button>
        </div>
      </article>
      <article className="memberInfoManaging">
        <h3>회원 정보 관리</h3>
        <div>
          <button>등록하기</button>
          <button>삭제하기</button>
          <button>수정하기</button>
          <button>조회하기</button>
        </div>
      </article>
    </section>
  );
}

export default CustomerUI;
