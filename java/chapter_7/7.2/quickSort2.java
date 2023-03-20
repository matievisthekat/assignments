// quickSort2.java
// demonstrates quick sort with median-of-three partitioning
// to run this program: C>java QuickSort2App
////////////////////////////////////////////////////////////////
class ArrayIns
   {
   private long[] theArray;          // ref to array theArray
   private int nElems;     
   private int numCopies;
   private int numComparisons;
//--------------------------------------------------------------
   public ArrayIns(int max)          // constructor
      {
      theArray = new long[max];      // create the array
      nElems = 0;                    // no items yet
      }
//--------------------------------------------------------------
   public void insert(long value)    // put element into array
      {
      theArray[nElems] = value;      // insert it
      nElems++;                      // increment size
      }
//--------------------------------------------------------------
   public void display()             // displays array contents
      {
      System.out.print("A=");
      for(int j=0; j<nElems; j++)    // for each element,
         System.out.print(theArray[j] + " ");  // display it
      System.out.println("");
      }

      public void displayCounts() {
         System.out.println("Number of copies: " + numCopies);
         System.out.println("Number of comparisons: " + numComparisons);
     }
//--------------------------------------------------------------
   public void quickSort()
      {
      recQuickSort(0, nElems-1);
      }
//--------------------------------------------------------------
   public void recQuickSort(int left, int right) {
      int size = right - left + 1;
      if (size <= 3) {
         manualSort(left, right);
      } else {
         long median = medianOf3(left, right);
         int partition = partitionIt(left, right, median);
         recQuickSort(left, partition - 1);
         recQuickSort(partition + 1, right);
      }
   }
//--------------------------------------------------------------
   public long medianOf3(int left, int right) {
      int center = (left + right) / 2;
      if (theArray[left] > theArray[center]) {
         swap(left, center);
      }
      if (theArray[left] > theArray[right]) {
         swap(left, right);
      }
      if (theArray[center] > theArray[right]) {
         swap(center, right);
      }

      swap(center, right - 1);
      return theArray[right - 1];
   }
//--------------------------------------------------------------
   public void swap(int dex1, int dex2) {
      long temp = theArray[dex1];
      theArray[dex1] = theArray[dex2];
      theArray[dex2] = temp;
      numCopies += 3; // increment numCopies by 3 for each swap
   }

//--------------------------------------------------------------
   public int partitionIt(int left, int right, long pivot) {
      int leftPtr = left;
      int rightPtr = right - 1;

      while (true) {
         while (theArray[++leftPtr] < pivot) {
            numComparisons++; // increment numComparisons for each comparison
         }
         while (theArray[--rightPtr] > pivot) {
            numComparisons++;
         }
         if (leftPtr >= rightPtr) {
            break;
         } else {
            swap(leftPtr, rightPtr);
         }
      }
      swap(leftPtr, right - 1);
      return leftPtr;
   }
//--------------------------------------------------------------
   public void manualSort(int left, int right) {
      int size = right - left + 1;
      if (size <= 1) {
         return;
      }
      if (size == 2) {
         if (theArray[left] > theArray[right]) {
            swap(left, right);
         }
         return;
      } else {
         if (theArray[left] > theArray[right - 1]) {
            swap(left, right - 1);
         }
         if (theArray[left] > theArray[right]) {
            swap(left, right);
         }
         if (theArray[right - 1] > theArray[right]) {
            swap(right - 1, right);
         }
      }
   }
//--------------------------------------------------------------
   }  // end class ArrayIns
////////////////////////////////////////////////////////////////
class QuickSort2App
   {
   public static void main(String[] args)
      {
      int maxSize = 16;             // array size
      ArrayIns arr;                 // reference to array
      arr = new ArrayIns(maxSize);  // create the array

      for(int j=0; j<maxSize; j++)  // fill array with
         {                          // random numbers
         long n = (int)(java.lang.Math.random()*99);
         arr.insert(n);
         }
      arr.display();                // display items
      arr.quickSort();              // quicksort them
      arr.display();                // display them again
      arr.displayCounts();
      }  // end main()
   }  // end class QuickSort2App
////////////////////////////////////////////////////////////////
