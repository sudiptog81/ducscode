delete_nth(1, [_|L], L) :- !.
delete_nth(P, [H|L], [H|R]) :- P1 is P - 1,
                               delete_nth(P1, L, R).
