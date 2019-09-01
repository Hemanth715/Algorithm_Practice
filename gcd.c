/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer
 */
int gcd(int A, int B) {
    int gcd = 1, min, i;
    if (A == 0)
        return B;
    if (B == 0)
        return A;
    if (A == B)
        return A;
    if (A > B)
        min = B;
    else
        min = A;
    for (i = 2; i <= min; ++i)
    {
        if (A % i == 0 && B % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}