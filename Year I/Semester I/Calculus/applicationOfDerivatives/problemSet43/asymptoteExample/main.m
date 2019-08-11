syms x

num = (x ^ 3 + 1)
denom = (x ^ 3 - 8)
f = num / denom

disp('Calculating first derivative...')
f_dash = simplify(diff(f))
disp('Calculating second derivative...')
f_double_dash = simplify(diff(diff(f)))

hAsymptote = limit(f, inf)
vAsymptote = solve(denom, 'Real', true)
criticalPoints = solve(f_dash, 'Real', true)
inflectionPoints = solve(f_double_dash, 'Real', true)
otherPoints = solve(f, 'Real', true)
miscPoints = [1; 2.5; 3]

fplot(f, [-8 8])
hold on
grid on
title('Graph of f(x)')
xlabel('x')
ylabel('f(x)')
plot(double(inflectionPoints), double(subs(f,inflectionPoints)),'ro')
plot(double(otherPoints), double(subs(f, otherPoints)), 'ro')
plot(double(miscPoints), double(subs(f, miscPoints)), 'ro')
for i = (1:length(miscPoints))
    text(miscPoints(i) + 0.45, subs(f, miscPoints(i)), ...
        string(double(miscPoints(i))) + ', ' ...
        + string(double(subs(f, miscPoints(i))))) 
end
for i = (1:length(otherPoints))
    text(otherPoints(i) - 0.45, subs(f, inflectionPoints(i)) - 0.35, ...
        string(double(otherPoints(i))) + ', ' ...
        + string(double(subs(f, otherPoints(i))))) 
end
for i = (1:length(inflectionPoints))
    text(inflectionPoints(i) - 0.25, subs(f, inflectionPoints(i)) + 0.45, ...
        string(double(inflectionPoints(i))) + ', ' ... 
        + string(double(subs(f, inflectionPoints(i)))))
end
hold off