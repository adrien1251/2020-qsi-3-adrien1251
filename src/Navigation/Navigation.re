[@react.component]
let make = _ => {
  <div>
      <button onClick={_event => {ReasonReactRouter.push("/randomDog")}}>
        {React.string("RandomDog :D")}
      </button>
      <button onClick={_event => ReasonReactRouter.push("/threeDog")}>
        {React.string("threeDog :D")}
      </button>
      <button onClick={_event => ReasonReactRouter.push("/blinkingGreeting")}>
        {React.string("blinkingGreeting :D")}
      </button>
  </div>;
};