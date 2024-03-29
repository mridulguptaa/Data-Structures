#include <bits/stdc++.h>
using namespace std;

// Function to find all Permutations of a given string str[i..n-1]
// containing all distinct characters
void permutations(string str, int i, int n)
{
	// base condition
	if (i == n - 1)
	{
		cout << str << endl;
		return;
	}

	// process each character of remaining string
	for (int j = i; j < n; j++)
	{
		// swap character at index i with current character
		swap(str[i], str[j]);

	    // recuse for string [i+1, n-1]
		permutations(str, i + 1, n);

		// backtrack (restore the string to its original state)
		swap(str[i], str[j]);
	}
}

// main method
int main()
{
	string str;
	cin>>str;
	cout<<endl;

	permutations(str, 0, str.length());

	return 0;
}
