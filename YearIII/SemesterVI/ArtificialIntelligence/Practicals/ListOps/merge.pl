merge(X, [], X).
merge([], Y, Y).
merge([X|X1], [Y|Y1], [X|Z]) :- X < Y, !, merge(X1, [Y|Y1], Z).
merge([X|X1], [Y|Y1], [X,Y|Z]) :- X == Y, !, merge(X1, Y1, Z).
merge([X|X1], [Y|Y1], [Y|Z]) :- X > Y, !, merge([X|X1], Y1, Z).
