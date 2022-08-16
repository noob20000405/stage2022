% nb of generations
n = 20;
% nb of sum
l = 10;
% estimated condition nb
c = 1;

f = fopen("SumData.txt", 'W');

for i = 1:n
    %fprintf(f, "%d\n", i);
    fprintf("%d\n", i);
    [p, c] = GenSum(l, c);
    %fprintf(f, "%f\t%f\n", x, y);
    for j = 1:l
        fprintf(f, "%f ", p(j));
        fprintf("%f\t", p(j));
    end
    fprintf(f, "\n");
    fprintf("\n");
    fprintf("c = %f\n", c);
end


fclose(f);
