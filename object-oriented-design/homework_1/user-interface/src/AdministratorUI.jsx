function AdministratorUI() {
  return (
    <section className="grid gap-2 grid-cols-4 row-span-3">
      <article>
        <h3>운행 관리</h3>
        <div>
          <button>추가하기</button>
          <button>삭제하기</button>
          <button>수정하기</button>
          <button>검색하기</button>
        </div>
      </article>
      <article>
        <h3>버스 관리</h3>
        <div>
          <button>추가하기</button>
          <button>삭제하기</button>
          <button>변경하기</button>
          <button>검색하기</button>
        </div>
      </article>
      <article>
        <h3>버스 목록 관리</h3>
        <div>
          <button>등록하기</button>
          <button>삭제하기</button>
          <button>수정하기</button>
          <button>검색하기</button>
        </div>
      </article>
      <article>
        <h3>직원 정보 관리</h3>
        <div>
          <button>추가하기</button>
          <button>삭제하기</button>
          <button>수정하기</button>
          <button>검색하기</button>
        </div>
      </article>
    </section>
  );
}

export default AdministratorUI;
