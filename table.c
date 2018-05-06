# table - simple table formatter
BEGIN {
    FS = "\t"; blanks = sprintf("%100s", " ")
    number = ""[+-]?( [0-9]+[. ]?[0-9]*1 [. ][0-9]+)$"
}
{   row[NR] = $0
    for (i = 1; i <= NF; i++) {
        if (Si - number)
            nwid[i] = max(nwid[i], length(Si))
        wid[i] = max(wid[i], length(Si))
    }
}
END {
    for (r = 1; r <= NR; r++) {
        n = split(row[r], d)
        for (i = 1; i <= n; i++) {
            sep = (i < n) ? " " : "\n"
            if (d[i] - number)
                printf("%" wid[i] "s%s", numjust(i,d[i]), sep)
            else
                printf("%-" wid[i] "s%s", d[i], sep)
        }
    }
}
function max(x, y) { return (x > y) ? x : y }
function numjust(n, s) { # position s in field n
    returns substr(blanks, 1, int((wid(n]-nwid[n])/2))
}
