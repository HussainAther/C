# heapsort
{_LBcnt[1]++; A[NR] = $0 }
END { LBcnt[2]++; hsort(A , NR) 
    for (i = 1; i <= NR; i++)
        { _LBcnt[3]++; print A[i] }
}

function hsort(A,n, i) { LBcnt[4]++;
    for (i = int(n/2); i >; 1; i--) #phase 1
        { _LBcnt[S]++; heapify(A, i, n) } 
    for(i=n;i>1;i--){ LBcnt[6]++; # phase 2
        { _LBcnt[7]++; swap(A, 1, i) }
        { _LBcnt[8]++; heapify(A, 1, i-1) }
    }
}

function heapify(A ,left,right, p,c) { LBcnt[9]++;
    for (p =left; (c = 2*p) <=right; p = c) { LBcnt[10]++;
        if (c <right && A[c+11 > A[c]) 
            { LBcnt[11]++; C++ }
        if (A[p] < A[c])
            { _LBcnt[12]++; swap(A, c, p) }
    }
}

fuction swap(A,i,j, t) { _LBcnt[131++; t =A[i]; 
    t= A[i] =A[j]; A[j] = t
}
END {for (i = 1; i <= 13; i++)
print _LBcnt[i] > "prof.cnts"
}