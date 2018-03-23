dat = fopen ("complex.dat", mode="w");
cfunctions = ["sqrt", "log", "cos", "sin", "tan", "cosh", "sinh", "tanh"];

for func=cfunctions
    for i=(1:10)
        arg_r = grand(1,1,'uin', 1, 10);
        arg_i = grand(1,1,'uin', 1, 10);
        arg = arg_r + arg_i * %i;
        res = evstr(func + "(" + string(arg_r) + "+ %i *" + string(arg_i) + ")");
        fprintf(dat,"{ ""cml_complex_%s"", cml_complex_%s, %.18f, %.18f, %.18f, %.18f },\n", func, func, arg_r, arg_i, real(res), imag(res))
    end
end


cfunctions = ["sqrt",  "cos", "sin", "tan", "cosh", "sinh", "tanh"];

for func=cfunctions
    for i=(1:10)
        arg_r = - grand(1,1,'uin', 1, 10);
        arg_i = grand(1,1,'uin', 1, 10);
        arg = arg_r + arg_i * %i;
        res = evstr(func + "(" + string(arg_r) + "+ %i *" + string(arg_i) + ")");
        fprintf(dat,"{ ""cml_complex_%s"", cml_complex_%s, %.18f, %.18f, %.18f, %.18f },\n", func, func, arg_r, arg_i, real(res), imag(res))
    end
end

cfunctions = ["sqrt",  "cos", "sin", "tan", "cosh", "sinh", "tanh"];

for func=cfunctions
    for i=(1:10)
        arg_r =  grand(1,1,'uin', 1, 10);
        arg_i = - grand(1,1,'uin', 1, 10);
        arg = arg_r + arg_i * %i;
        res = evstr(func + "(" + string(arg_r) + "+ %i *" + string(arg_i) + ")");
        fprintf(dat,"{ ""cml_complex_%s"", cml_complex_%s, %.18f, %.18f, %.18f, %.18f },\n", func, func, arg_r, arg_i, real(res), imag(res))
    end
end

cfunctions = ["sqrt",  "cos", "sin", "tan", "cosh", "sinh", "tanh"];

for func=cfunctions
    for i=(1:10)
        arg_r = - grand(1,1,'uin', 1, 10);
        arg_i = - grand(1,1,'uin', 1, 10);
        arg = arg_r + arg_i * %i;
        res = evstr(func + "(" + string(arg_r) + "+ %i *" + string(arg_i) + ")");
        fprintf(dat,"{ ""cml_complex_%s"", cml_complex_%s, %.18f, %.18f, %.18f, %.18f },\n", func, func, arg_r, arg_i, real(res), imag(res))
    end
end

dat.close[];
