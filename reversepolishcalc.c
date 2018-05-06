# reverse-Polish calculator
# input: arithmetic expressions in reverse Polish
# output: values of expressions
{   for (i=1; i <=NF; i++)
    if ($i ~ IA[+-]?([0-9]+[.]?[0-9]*1[.][0-9]+)$1) {
        stack[++top] = $i
    } else if ($i == "+" && top> 1) {
        stack[top-1] += stack[top]; top--
    } else if ($i == "-" && top > 1) {
        stack[top-1] -= stack[top]; top--
    } else if ($i == "*" && top > 1) {
        stack[top-1] *= stack[top]; top--
    } else if ($i == "/" && top> 1) {
        stack[top-1] /= stack[top]; top--
    } else if ($i == "^" && top > 1) {
        stack[top-1] ^= stack[top]; top--
    } else {
        printf("error: cannot evaluate %s,n", $i)
        top = 0
        next
    }
    if (top== 1)
        printf("\t%.8g,n11", stack[top--])
    else if (top> 1) {
        printf("error: too many operands,\n")
        top =0
    }
}
