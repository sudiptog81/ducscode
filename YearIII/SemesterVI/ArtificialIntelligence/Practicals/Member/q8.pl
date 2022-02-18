/**
 * Q8. WAP to impl memb(X, L) to check whether X is a member of L or not.
 * Written by Sudipto Ghosh (19/78003) 
 */

memb(X, [X|_]) :- !.                 % base case
memb(X, [_|L]) :- memb(X, L).   % recursive case