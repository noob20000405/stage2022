% nb of generations
n = 10;
% vector length
l = 6;
% estimated condition nb
c = 10000;

f = fopen("DotData.txt", 'W');

for i = 1:n
    fprintf(f, "%d\n", i);
    fprintf("%d\n", i);
    [x, y] = GenDot(l, c);
    fprintf(f, "%f\t%f\n", x, y);
    fprintf("%f, %f\n", x, y);
end


fclose(f);