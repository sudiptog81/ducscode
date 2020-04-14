# The Delegation Event Model
The Delegation Event Model defines standard and consistent mechanisms to generate and process events. In this model, a source generates an event and sends it to one or more listeners. The listener simply waits until it receives an event. Once an event is received, the listener processes the event and then returns. The advantage of this design is that the application logic that processes events is cleanly separated from the user interface logic that generates those events. Therefore, a user interface element is able to 'delegate' the processing of an event to a separate piece of code.

The components of the Delegation Event Model are as follows:

## Events
An event is an object that describes a state change in a source. An event can be generated as a consequence of a person interacting with the elements in a graphical user interface. Events may also occur that are not directly caused by interactions with a user interface.

## Event Sources
An event source is an object that generates an event. This occurs when the internal state of that object changes in some way. Sources may generate more than one type of event. When an event occurs, all registered listeners are notified and receive a copy of the event object.

## Event Listeners
An event listener is an object that is notified when an event occurs. It has two major requirements. First, it must have been registered with one or more sources to receive notifications about specific types of events. Second, it must implement methods to receive and process these notifications