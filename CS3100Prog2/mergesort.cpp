
/* I furnished parameters c_count and m_count are here, for
   counting list element comparisons and list element moves. */

#include "mergesort.h"

void merge(int theArray[ ], int first, int mid, int last, 
             unsigned long int & c_count, unsigned long int & m_count)
// ---------------------------------------------------------
// Merges two sorted array segments theArray[first..mid] and
// theArray[mid+1..last] into one sorted array.
// Precondition: first <= mid <= last. The subarrays
// theArray[first..mid] and theArray[mid+1..last] are each
// sorted in increasing order.
// Postcondition: theArray[first..last] is sorted.
// Implementation note: This function merges the two
// subarrays into a temporary array and copies the result
// into the original array theArray.
// ---------------------------------------------------------
{
   int tempArray[MAX_SIZE]; // temporary array

   // initialize the local indexes to indicate the subarrays
   int first1 = first; // beginning of first subarray
   int last1 = mid; // end of first subarray
   int first2 = mid + 1; // beginning of second subarray
   int last2 = last; // end of second subarray

   // while both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = first1; // next available location in
		       // tempArray
   for (; (first1 <= last1) && (first2 <= last2); ++index)
   {  // Invariant: tempArray[first1..index-1] is in order

      if ( ++c_count && (theArray[first1] < theArray[first2]) )
      {	 tempArray[index] = theArray[first1];
	 ++first1;
	 ++m_count;
      }
      else
      {	 tempArray[index] = theArray[first2];
	 ++first2;
	 ++m_count;
      } // end if
   } // end for

   // finish off the nonempty subarray

   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
      // Invariant: tempArray[first1..index-1] is in order
   {
      tempArray[index] = theArray[first1];
      ++m_count;
   }

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
   {
      // Invariant: tempArray[first1..index-1] is in order
      tempArray[index] = theArray[first2];
      ++m_count;
   }

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
   {
      theArray[index] = tempArray[index];
      ++m_count;
   }
}  // end merge



void mergesort(int theArray[], int first, int last, 
                 unsigned long int & c_count, unsigned long int & m_count)

// ---------------------------------------------------------
// Sorts the items in an array into ascending order.
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted in
// ascending order.
// Calls: merge.
// ---------------------------------------------------------
{
   if (first < last)
   {  // sort each half
      int mid = (first + last)/2; // index of midpoint
      // sort left half theArray[first..mid]
      mergesort(theArray, first, mid, c_count, m_count);
      // sort right half theArray[mid+1..last]
      mergesort(theArray, mid+1, last, c_count, m_count);

      // merge the two halves
      merge(theArray, first, mid, last, c_count, m_count);
   } // end if
}  // end mergesort

