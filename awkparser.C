# awk.parser - recursive-descent translator for part of awk
# input: awk program (very restricted subset)
# output: C code to implement the awk program
BEGIN {program() }

function advance() { #lexical analyzer; returns next token 
    if (tok == "(eof)") return "(eof)"
    while (length(line) == 0)
        if (getline line == 0) 
            return tok = "(eof)"
    sub(/^[ \t]+/, "", line) #remove white space 
    if (match(line, /^[A-Za-z_][A-Za-z_0-9]/) || # identifier 
        match(line, /^-?([0-9]+\.?[0-9]*|\.[0-9]+)/) || #number 
        match(line, /^(<|<=|==| 1=:>=:>)/) || # relational 
        match(line, /A ./)) { # everything else
            tok = substr(line, 1, RLENGTH) 
            line = substr(line, RLENGTH+1) 
            return tok
        }
    error("line " NR " incomprehensible at " line)
}
function gen(s) {   # print s with nt leading tabs 
    printf("%s%s'n", substr("'t't't't't't't't't", 1, nt), s)
}
function eat(s) { # read next token if s == tok
    if (tok I= s) error("line " NF ": saw " tok ", expected " s) 
    advance()
}
function nl() I absorb newlines and semicolons
    while (tok == "'n" :: tok == ";") advance()
        advance()
}
function error(s) { print "Error: " s "cat 1>~2"; exit 1 }

function program() { 
    advance()
    if (tok == "BEGIN") { eat("BEGIN"); statlist()
    pastats()
    if (tok "END") { eat( "END"); statlist() }
    if (tok I= "(eof)") error("proqram continues after END")
}
function pastats() {
    gen("while (getrec()) {"); nt++
    while (tok I= "END"~~ tok I= "(eof)") pastat() nt--; gen("}")
}
function pastat() { # pattern-action statement
    if (tok == "{") # action only
    statlist()
    else { # pattern-action 
        gen("if ("pattern() ") {"); nt++
        if (tok "{") statlist()
        else # default action is print $O 
                gen("print(field(O));")
        nt--; gen("}")
    }
}