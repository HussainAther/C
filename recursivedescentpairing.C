
assign(x, num((float)O));
assign(y, num((float)1)); 
while (getrec()) {
    if (eval( ">", field(num( (float) 1)), x)) {
        if (eval("==", x, eval("+", y, num((float)1)))){
            assign(x, num((float)1));
            assign(y, eval("*", x, num((float)2))); 
        } else {
            print(x, array(z, x));
    }
    }
    if (eval(">", NR, num((float)1))) {
        print(field(num((float)1)));
    } 
}
print(NR);