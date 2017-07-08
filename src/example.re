module ExamplePage = {
  let component = ReasonReact.statefulComponent "Greeting";
  let se = ReasonReact.stringToElement;
  let onClick () => Js.log "Hossa";
  let make  _children => {
    let click _event {ReasonReact.state: state} => ReasonReact.Update (state + 1);
    {
      ...component,
      initialState: fun () => 0,
      render: fun {state, update} => {
        let greeting = {j|You've clicked the button $state times(s)!|j};
        let okButton = <MaterialUi.FlatButton label="OK" onClick />;
        let cancelButton = <MaterialUi.FlatButton label="Cancel" onClick />;
        let actions = [|cancelButton, okButton|];
        <div>
          <MaterialUi.MuiThemeProvider>
            <div>
              <MaterialUi.RaisedButton label="Button" onClick />
              <MaterialUi.Dialog onRequestClose=onClick isOpen=true actions>
                (se "Dialog Content")
              </MaterialUi.Dialog>
            </div>
          </MaterialUi.MuiThemeProvider>
          <button onClick=(update click)> (ReasonReact.stringToElement greeting) </button>
        </div>
      }
    }
  };
};

MaterialUi.injectTapEventPlugin();
ReactDOMRe.renderToElementWithId <ExamplePage /> "index";