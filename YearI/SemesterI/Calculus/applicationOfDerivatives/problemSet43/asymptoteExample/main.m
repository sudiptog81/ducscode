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

allPoints = [criticalPoints; inflectionPoints; otherPoints; miscPoints];

fh = fplot(f, [-8 8]);
fh.LineWidth = 2;
hold on
grid on
box off
title('Graph of f(x)')
for i = 1:length(allPoints)      
    temp1 = allPoints(i);
    for j = 1:length(allPoints(i))
        temp2 = temp1(j);
        plot(double(temp2), double(subs(f,temp2)),'r.', 'MarkerSize', 20)
    end
end
ax = gca;
ax.XAxisLocation = 'origin';
ax.YAxisLocation = 'origin';
hold off