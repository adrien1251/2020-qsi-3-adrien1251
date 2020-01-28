[@bs.val] external document: Js.t({..}) = "document";


let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##className #= "containerTitle";
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};

[@react.component]
let make = _ => {
  let deleteContainer = {
    let element = document##getElementsByClassName("container")[0];
    element##parentNode##removeChild(element);
  };

  let url = ReasonReactRouter.useUrl();
  switch (url.path) {
  | ["randomDog"] => ReactDOMRe.render(<FetchRandomDog />, makeContainer("1 random Dog"));
  | ["threeDog"] => ReactDOMRe.render(<FetchedDogPictures />, makeContainer("3 random Dog"));
  | ["blinkingGreeting"] => ReactDOMRe.render(<BlinkingGreeting>{React.string("Blinking dog")}</BlinkingGreeting>, makeContainer("Blinking"));
  | ["myProfile"] => ReactDOMRe.render(<MyProfile />, makeContainer("Profile"));
  |  _ => ReactDOMRe.render(<Navigation />, makeContainer("Navigation"));
  };

  <div></div>
};  

// 5e3d52deaa3f54dd79193266cea5a2db49500175