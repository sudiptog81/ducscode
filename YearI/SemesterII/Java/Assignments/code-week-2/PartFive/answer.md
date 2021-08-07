# Can Interfaces have Constructors?

All methods in interfaces are `public` and `abstract`. Furthermore, all data members are `static`, `public`, and `final` and are initialized inline.

Constructors cannot be `abstract` and even being an initializer method, it cannot initialize the data members which are `static` and `final`.

Hence, interfaces cannot have constructors.