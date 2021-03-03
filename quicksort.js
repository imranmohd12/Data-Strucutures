// QUICK SORT

// STEP 1 : INITIALIZE variables Loc , inputArray[],UpperBound = 0 and LowerBound = inputArray.length-1

// STEP 2 : Calling QuickSort Function

// STEP 3 : Below is QuickSort function

// Function QuickSort(inputArray,LowerBound,UpperBound)
// If condition LowerBound < UpperBound
//      Loc = Partition(inputArray,LowerBound,UpperBound)
//      QuickSort(inputArray,LowerBound,Loc-1)
//      QuickSort(inputArray,Loc+1,UpperBound)

// Step 4 : QuickSort function recursively calls the partion function and returns the previous pivot 

// Function Partition(inputArray,LowerBound,UpperBound)
//      pivot = inputArray[LowerBound]
//      Start = LowerBound
//      End = Uppperbound
// Outer While loop condition Start < End
//     Inner While loop condition pivot >= inputArray[Start] AND Start < UpperBound
//          Start++
//     [end inner while loop]
//     Inner while loop condition pivot > inputArray[end]
//          End++
//     [end inner while loop]
//     If condition Start < End
//          Swapping inputArray[Start] with inputArray[End]
//     [end if]
// [end outer while loop]
// swapping with inputArray[lowerbound] with inputArray[End]
// Return End

// STEP 5 : Quick Sort Function recursively calls the partion function until the List will be sorted

// STEP 6 : End of Quick sort Function result will be in same array/list

/*** BELOW JAVASCRIPT CODE FOR IMPLEMENTATION OF QUICKSORT***/

function partition(inpArr,lowerbound,uppperbound)
{
    let pivot = inpArr[lowerbound];
    let start = lowerbound;
    let end = uppperbound;
    while(start < end)
    {
        while(pivot >= inpArr[start] && start < uppperbound)
            start++;
        while(pivot < inpArr[end])
            end--;
        if(start < end)
            swap(inpArr,start,end);
    }
    swap(inpArr,lowerbound,end);
    return end; 
}
function swap(inpArr,a,b)
{
    let temp = inpArr[a];
    inpArr[a] = inpArr[b];
    inpArr[b] = temp
}
function qsort(inpArr,lowerbound,uppperbound)
{
    let loc = 0;
    if(lowerbound < uppperbound)
    {
        loc = partition(inpArr,lowerbound,uppperbound);
        qsort(inpArr,lowerbound,(loc-1));
        qsort(inpArr,(loc+1),uppperbound);
    }
}
let inpArr = [8,3,4,2,6,7,8,9];
let uppperbound,lowerbound;
lowerbound = 0;
uppperbound = inpArr.length-1;
console.log(inpArr);
qsort(inpArr,lowerbound,uppperbound);
console.log(inpArr);