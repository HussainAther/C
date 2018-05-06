# qawk - awk relational database query processor
BEGIN{readrel("relfile")}
{doquery($0) }
function readrel(f){
    while (getline <f > 0) # parse relfile
        if ($0 - /A(A-Za-z]+ *:/) { # name:
            gsub(/[AA-Za-z]+/, "" , $0) #remove all but name
            relname[++nrel] = SO
        }else if ($0- /A[ \t]*l/) # !command ...
            cmd[nrel, ++ncmd[nrel]] substr($0,index(SO,"I")+1)
        else if ($0 - /A[ \t]*[A-Za-z]+[ \t]*$/) # attribute
            attr[nrei, $1] ; ++nattr[nrel]
        else if (SO 1- /A[ \t]*$/) #not white space
        print "bad line in relfile: "", $0
}
function doquery(s, i,j) {
for (i in qattr) # clean up for next query
delete qattr[i]
query = s # put Snames in query into qattr, without $
while (match(s, /\$(A-Za-z]+/)) {
qattr[substr(s, RSTART+1, RLENGTH-1)] = 1
s = substr(s, RSTART+RLENGTH+1)
}
    for (i = 1; i <= nrel && lsubset(qattr, attr, i); )
        i++
    if (i > nrel) # didn't find a table with all attributes
        missing(qattr)
    else { # table i contains attributes in query
        for (j in qattr) #create awk program
            gsub("\\$" j, "$" attr[i,j], query)
        for (j = 1; j <= ncmd[i]; j++) #create table i
            if (system(cmd[i, j]) I= 0) {
                print "command failed, query skipped\n11 , cmd[i,j]
                return
            }
        awkcmd = sprintf("awk -F'\t' '%s' %s", query, relname(i])
        printf("query: %s\n", awkcmd) #for debugging
        system(awkcmd)
    }
}
function subset(q, a, r, i) { # is q a subset of a[r]?
    for (i in q)
        if ( I ( ( r, i) in a) )
            return 0
    return 1
}
function missing(x, i) {
    print "no table contains all of the following attributes: 11
    for (i in x)
        print i
}
