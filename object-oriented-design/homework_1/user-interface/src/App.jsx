import AdministratorUI from "./AdministratorUI";
import "./App.scss";
import CustomerUI from "./CustomerUI";

function App() {
  return (
    <div className="App">
      <div className="grid gap-2 grid-cols-1 grid-rows-5">
        <header className="row-span-2">
          <h1>🚌고속버스 예약 관리 시스템</h1>
          <button className="float-right border border-[#bdbfc5] rounded px-2 py-1 bg-[#f7f7f7] text-[#222] font-semibold">
            로그인
          </button>
        </header>
        <CustomerUI />
        {/* <AdministratorUI /> */}
      </div>
    </div>
  );
}

export default App;
