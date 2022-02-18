nth_element(1, [H|_], H) :- !.
nth_element(N, [_|T], X) :- N1 is N - 1,
                            nth_element(N1, T, X).
