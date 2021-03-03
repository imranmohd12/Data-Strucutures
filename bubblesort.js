// Step 1: Repeat Step 2 For i = 0 to N-1
// Step 2: Repeat For J = i + 1 to N - I
// Step 3: IF A[J] > A[i]
// SWAP A[J] and A[i]
// [END OF INNER LOOP]
// [END OF OUTER LOOP
// Step 4: EXIT

/* IMPLEMENTATION OF BUBBLE SORT IN JAVASCRIPT */
function bubblesort() {
    let temp = 0
    for(let i = 0 ; i<A.length ; i++)
    {
        for(let j = i+1 ; j<A.length ; j++)
        {
            if(A[j]<A[i])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
let A = [5,6,3,1,9,4,5];
console.log(A);
bubblesort();
console.log(A);