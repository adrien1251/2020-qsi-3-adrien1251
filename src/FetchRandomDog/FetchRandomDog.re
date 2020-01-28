[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type state =
  | LoadingDogs
  | ErrorFetchingDogs
  | LoadedDogs(array(string));

let createPromiseDog = (setState) => { 
  Js.Promise.(
      fetch("https://dog.ceo/api/breeds/image/random/1")
      |> then_(response => response##json())
      |> then_(jsonResponse => {
           setState(_previousState => LoadedDogs(jsonResponse##message));
           Js.Promise.resolve();
         })
      |> catch(_err => {
           setState(_previousState => ErrorFetchingDogs);
           Js.Promise.resolve();
         })
      |> ignore
    );
};

[@react.component]
let make = () => {
  let (state, setState) = React.useState(() => LoadingDogs);
  if(state == LoadingDogs) {
    createPromiseDog(setState);
  };

  <>
    <div
      style={ReactDOMRe.Style.make(
        ~height="120px",
        ~display="flex",
        ~alignItems="center",
        ~justifyContent="center",
        (),
      )}>
      {switch (state) {
       | ErrorFetchingDogs => React.string("An error occurred!")
       | LoadingDogs => React.string("Loading...")
       | LoadedDogs(dogs) =>
         dogs
         ->Belt.Array.mapWithIndex((i, dog) => {
             let imageStyle =
               ReactDOMRe.Style.make(
                 ~height="120px",
                 ~display="flex",
                 ~width="30%",
                 ~marginRight=i === Js.Array.length(dogs) - 1 ? "0px" : "8px",
                 ~borderRadius="8px",
                 ~boxShadow="0px 4px 16px rgb(200, 200, 200)",
                 ~backgroundSize="cover",
                 ~backgroundImage={j|url($dog)|j},
                 ~backgroundPosition="center",
                 (),
               ); 
             <div key=dog style=imageStyle />;
           })
         ->React.array
       }}
    </div>
    <button onClick={_event => setState(_previousState => LoadingDogs) } > {React.string("New dog")} </button>
  </>;
};