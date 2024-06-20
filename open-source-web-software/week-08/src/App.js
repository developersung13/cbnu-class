import { useEffect, useState } from 'react';
import profileImg from './images/profile.png';
import './App.css';

function App() {
  const [firstNum, setFirstNum] = useState(0);
  const [secondNum, setSecondNum] = useState(0);

  function basicFunction() {
    return 50;
  }

  const arrowFunction = () => {
    return 50;
  };

  const skippedArrowFunction = () => 50;

  useEffect(() => {
    setFirstNum(10);
    setSecondNum(5);
  }, []);

  return (
    <div className='App'>
      <div className='container'>
        <div className='num-sentence'>
          <p>First number is {firstNum}</p>
          <p>Second number is {secondNum}</p>

          <div className='function-result-container'>
            <div>
              <span className='function-title'>Basic function: </span>
              <span>{basicFunction()}</span>
            </div>

            <div>
              <span className='function-title'>Arrow function: </span>
              <span>{arrowFunction()}</span>
            </div>

            <div>
              <span className='function-title'>Skipped arrow function: </span>
              <span>{skippedArrowFunction()}</span>
            </div>
          </div>
        </div>

        <div className='profile-container'>
          <img src={profileImg} alt='' width={225} />
          <p className='name'>Undergrad.Yeol-Am Sung</p>
          <p className='affiliation'>Dept. of Computer Science, CBNU</p>
          <p>Email: hotkimchi14@naver.com</p>
        </div>
      </div>
    </div>
  );
}

export default App;
