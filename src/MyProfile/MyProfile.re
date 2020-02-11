open ReasonUrql;
/* Be sure to open the Hooks module to bring necessary types into scope. */
open Hooks;
// open Shared.Types;
// module GQL = Graphql_lwt;

type viewer = {
  login: string,
};

type data = {
  viewer: viewer,
};

let typeDef = {|
  type Author {
    id: Int!
    firstName: String
    lastName: String
    posts: [Post] # the list of Posts by this author
  }
|};


[@react.component]
let make = _ => {
  let key = "b22d9b3c94f93c93eec7b51d0d3f1207056e4d7e";
//   /* Build your request by calling .make on your mutation, passing variables as labeled arguments. */
  // let request = LikeDogMutation.make(key, ());

//   /* Pass the request to useMutation. */
//   let (_, executeMutation) = useMutation("user(login: \"adrien1251\") {id}", ());

  <div>
    <button>
        {React.string("Avatar")}
    </button>
  </div>
}