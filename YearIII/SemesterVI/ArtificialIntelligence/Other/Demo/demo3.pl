% Knowledge Base
human(a).
human(b).
human(c).
male(a).
male(b).
female(c).
sibling(a, b).
sibling(b, a).
sibling(a, c).
sibling(c, a).

% Rules
brother(X, Y) :- sibling(X, Y), male(X).
sister(X, Y) :- sibling(X, Y), female(X).
