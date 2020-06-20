table[i]=where to start mathcing in the pattern after a mismatch at i+1[ie the length of the longest suffix which is also a prefix from index 0 to i]
take example dsgadsgz
take two pointers i and j
i=0 j=1 at the beginning
if they are not same then advance j

so by doing this
i=0 j=1 no
j=2 no
j=3	no
j=4 no
j=5 yes then table[5]=i+1 and advance i=1
i=1 j=6 then table[6]=i+1=2 then i+1
i=2 and j=7 table[j]=i+1=3 thne i++;
i=3 and j=8 npw we havea mismatch then we see the value at i-1 which is 0 and then we move i=to that point now i=0 and j=8 dont match then table[8]=0;
so from 0 to 4 it will be 0


vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

z algorithm pattern matching
Z(i)(S)=it the longest substring in S starting at position i  which matches a prefix of S
S=aabcaabxaaz
Z(0)=??
Z(1)=1
Z(2)=0
Z(4)=3

HOW TO USE IN PATTRN matching
CONCANTENATE P AND T
FIND ALL Z(i) VALUES IN S any Z(i)>=|p| indentifies occurences of P in T

S()=aabxaayaab
Z1=1
Z2=0
Z3=0
Z4=2
Z5=1
Z6=0
Z7=3
Z8=1
Z9=0

Z-BOX SAMAJH NAHI aaYA
IN Z BOX WE HAVE TWO INDICES L AND R
L IS I AND THE LENGTH IS Z[I]

WE HAVE ALREADY CALCULATED BEFORE I-1 SOO... WHILE FILLING FROM L TO R WE WILL CHECK
MIN(R-I+1,Z[I-L]) IF I<=R



MANACHER'S
FIND THE LONGEST PALINDROMIC substring
LIKE S[L]=ABABABA
1)PALINDROME ARE SYMMETRIXC AT THE CENTRE

to find the period
N-kmp[N-1]==x
and x is not equal to 0
and n%x===0


1e9+7,1e9+9,(p,M)
M SHOULD ALWAYS BE PRIME
COLLIDE KA CHANCES KAM HOTA 
AGAR 1E5 KA ARRAY HAI TOH 1E10 SUBSTRINGS TOH M KA VALUE 1E9+9 SE ZYADA HONA CHAHIYE
 ISLIYE DO LETE HAIN
 (P1,M1)--->HASH1 AUR (P2,M2)-->HASH2
 THEN WE CHECK BOTH FOR EQUAL string
 COLLIDE KARNE KA CHANCES 1/(M1,M2)

 2-3 HASH KARLO
 P>=33,37
 A YA B KA VALUE KABHI ZERO MAT DENA

