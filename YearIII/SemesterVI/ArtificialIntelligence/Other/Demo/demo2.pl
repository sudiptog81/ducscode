% KB or Facts
b.
c.
e.

% Rule
a :- b, c, d.
d :- e.
f :- b, (c; not(e)).
hello :- write('Hello from Prolog!\n').
main :- X = 1,
          Y is X + 1,
          format('~w ~w.\n', ['X is', X]),
          format('~w ~w.\n', ['Y is', Y]).
