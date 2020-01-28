open ReasonUrql;
/* Be sure to open the Hooks module to bring necessary types into scope. */
open Hooks;

[@react.component]
let make = _ => {
  let key = "5e3d52deaa3f54dd79193266cea5a2db49500175";
  /* Build your request by calling .make on your mutation, passing variables as labeled arguments. */
  let request = LikeDogMutation.make(key, ());

  /* Pass the request to useMutation. */
  let (_, executeMutation) = useMutation("user(login: \"adrien1251\") {id}", ());

  <div>
    <button onClick=(_e) => executeMutation()>
        "Execute the Mutation (and Reward a Good Dog)"->React.string
    </button>
  </div>
}
 
// 5e3d52deaa3f54dd79193266cea5a2db49500175curl -H "Authorization: bearer mytoken" -X POST -d " \