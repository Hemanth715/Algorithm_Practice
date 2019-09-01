/**
 * @input A : array of strings termination by '\0'
 * @input n1 : number of strings in array A
 * 
 * @Output string. Make sure the string is '\0' terminated.
 */
char* longestCommonPrefix(char** A, int n1) {
    int i = 0;
    int j = 0;
    char cur = '\0';
    char *res = NULL;
    
    while (1) {
        cur = '\0';
        for (i = 0; i < n1; i++) {
            if (cur == '\0') {
                cur = A[i][j];
            }
            if (A[i][j] == '\0' || A[i][j] != cur) {
                res = (char*)malloc((j + 1) * sizeof(char));
                if (j > 0) {
                    memcpy(res, A[i], j);
                }
                res[j] = '\0';
                return res;
                // Common found
            }
        }
        j++;
    }
}