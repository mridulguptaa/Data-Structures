#include<iostream>
using namespace std;
int flag=0;

void ACODE(string in,char out[],int i,int j){
	//Base Case
	if(in[i]=='\0'){
		out[j] = '\0';
		if(flag!=0)
            cout<<", ";
		cout<<out;
		flag++;
		return;
	}
	//Recusive Case

	//Convert 1 char at a time starting at index i
	int digit = in[i] - '0';
	char ch = 'a' - 1 + digit;
	if(digit!=0){
		out[j] = ch;
		ACODE(in,out,i+1,j+1);
	}
	//Convert 2 char at a time starting index i
	if(in[i+1]!='\0'){
		int secondDigit = in[i+1]-'0';
		int no = digit*10 + secondDigit;
		if(no<=26){
			ch = 96 + no;
			out[j] = ch;
			ACODE(in,out,i+2,j+1);
		}
	}
	return;
}

int main(){
	string input;
	cin>>input;
	int len;
	len=input.length();

	char output[len];
	cout<<"[";
	ACODE(input,output,0,0);
	cout<<"]";


return 0;
}
