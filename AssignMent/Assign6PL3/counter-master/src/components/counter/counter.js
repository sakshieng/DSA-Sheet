import React, { useState } from 'react';

function Counter() {
  const [count, setCount] = useState(0);

  const handleIncrement = () => {
    setCount(count + 1);
  };

  const handleDecrement = () => {
    if (count > 0) {
      setCount(count - 1);
    }
  };

  const handleReset = () => {
    setCount(0);
  };

  return (
    <div className="container-fluid text-center mt-5">
      <h1 className="text-uppercase text-info h1">Counter</h1>
      <div className="text-success display-3 my-4 font-weight-bold">{count}</div>
      <button className="btn btn-primary mx-2 border border-success" onClick={handleIncrement}>
        Increment
      </button>
      <button className="btn btn-danger mx-2 border border-primary" onClick={handleDecrement}>
        Decrement
      </button>
      <button className="btn btn-warning mx-2 border border-danger" onClick={handleReset}>
        Reset
      </button>
    </div>
  );
}

export default Counter;
