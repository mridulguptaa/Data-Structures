// a linear time solution for stock span problem
#include <iostream>
#include <stack>
using namespace std;

// A stack based efficient method to calculate stock span values
void calculateSpan(long long int price[], long long int n, long long int S[])
{
   // Create a stack and push index of first element to it
   stack<long long int> st;
   st.push(0);

   // Span value of first element is always 1
   S[0] = 1;

   // Calculate span values for rest of the elements
   for (long long int i = 1; i < n; i++)
   {
      // Pop elements from stack while stack is not empty and top of
      // stack is smaller than price[i]
      while (!st.empty() && price[st.top()] <= price[i])
         st.pop();

      // If stack becomes empty, then price[i] is greater than all elements
      // on left of it, i.e., price[0], price[1],..price[i-1].  Else price[i]
      // is greater than elements after top of stack
      S[i] = (st.empty())? (i + 1) : (i - st.top());

      // Push this element to stack
      st.push(i);
   }
}

// A utility function to print elements of array
void printArray(long long int arr[], long long int n)
{
    for (long long int i = 0; i < n; i++)
      cout << arr[i] << " ";
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
    long long int n;
    cin>>n;
    long long int price[n];
    for(long long int i=0;i<n;i++)
        cin>>price[i];
   long long int S[n];

    // Fill the span values in array S[]
    calculateSpan(price, n, S);

    // print the calculated span values
    printArray(S, n);
    }
    return 0;
}
