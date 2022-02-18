/**
 * Q11. WAP to impl palindrome(L) to check wether list L is a palindrome or not.
 * Written by Sudipto Ghosh (19/78003) 
 */

conc([], L, L) :- !.                       % base case
conc([H|T], L2, [H|R]) :- conc(T, L2, R).  % recursive case

reverse([], []) :- !.                      % base case
reverse([H|T], R) :- reverse(T, RT),       % recursive case
                     conc(RT, [H], R).

palindrome(L) :- reverse(L, L).
