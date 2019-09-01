/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int numSetBits(unsigned int A) {
    int count=0;        //set counter variable to 0.
    while(A){           //if A is 0 the loop would not continue.
        count++;        //increments counter variable by 1;
        A&=(A-1);       //clears the last bit of the binary for the number A
    }                   //the loop basically turns each set bit that is '1' bit to '0'
    return count;       //one by one while counting with the counter variable.
}