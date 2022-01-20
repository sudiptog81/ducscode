gcd(X, Y) :- X == 0 -> write(Y);
             Y == 0 -> write(X);
             X == Y -> write(X);
             X > Y -> (Z is X - Y, gcd(Z, Y));
             Y > X -> (C is Y - X, gcd(X, C)).
