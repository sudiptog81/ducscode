animal(dog).
animal(python).
snake(python).
not(snake(dog)).

likes(mary, X) :- snake(X), !, fail.
likes(mary, X) :- animal(X).

different(X, X) :- !, fail.
different(X, Y).