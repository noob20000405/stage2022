% nb of generations
n = 10;
% vector length
l = 6;
% estimated condition nb
c = 1;

f = fopen("DotData.txt", 'W');

for i = 1:n
    %fprintf(f, "%d\n", i);
    fprintf("%d\n", i);
    [x, y, d, c] = GenDot(l, c);
    %fprintf(f, "%f\t%f\n", x, y);
    for j = 1:l
        fprintf(f, "%f\t%f\n", x(j), y(j));
        fprintf("%f\t%f\n", x(j), y(j));
    end
    %fprintf("%f, %f\n", x, y);
    fprintf("x = %f\n", x);
    fprintf("d = %f\n", d);
    fprintf("c = %f\n", c);
end


fclose(f);
