max(X, Y) :- X == Y -> (format('X and Y are Equal'), nl);
             X > Y -> (Z is X, write(Z), nl);
             X < Y -> (Z is Y, write(Z), nl).
