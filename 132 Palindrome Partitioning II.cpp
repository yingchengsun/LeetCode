#include <iostream>
#include <windows.h>  
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
		int len=s.length();
		//int **c=new int *[len];
		int *c=new int[len];
		int i,j;
	
		if (isPalindrome(s))
			return 0;
		else{
			
		//for(i=0;i<len;i++){
		//	c[i]=new int[len];
		//}

		
		//for (i=0;i<len;i++)
		//	for(j=0;j<len;j++)
		//		c[i][j]=9999;

		int result=minPartition(0,len-1,s,c)-1;

		
		/*for(i=0;i<len;i++){
			delete c[i];
			c[i]=NULL;
		}
		delete [len]c;
		c=NULL;
*/
		return result;
		}

    }

	bool isPalindrome(string str){
		char *w=(char *)str.c_str();
		//char *p=new char[str.length()+1];
		//char *q=new char[str.length()+1];
		//strcpy (p,w);  
		//strcpy (q,w);  
		//strrev(p);
		/*for(int i=0;i<str.length();i++)
			q[i]=p[str.length()-i-1];
		q[str.length()+1]='\0';*/
		//if(!strcmp(p,q))
		//	return 1;
		//else 
		//	return 0;
		int i=0,j=str.length()-1;
		while(i<j){
			if(w[i]!=w[j])
				return 0;
			i++;
			j--;
		}
		return 1;
	}

	int minPartition(int l, int j, string s, int *c){

		for(int i=l;i<=j;i++){
			int temp=9999;
			for(int m=l;m<=i;m++)	
				int cut=9999;
				if (isPalindrome(s.substr(m,i-m+1))){
					c[i]=1;
					if(m==0){
						temp=1;
						break;
					}
					else if((c[l][m-1]+c[m][i])<temp)
						temp=c[l][m-1]+c[m][i];
				}
			c[i]=temp;
		}
		return c[j];
	}


	int minPartition2(int l, int j, string s, int **c){
		if (isPalindrome(s.substr(l,j-l+1))){
			c[l][j]=1;
			return 1;
		}
		if (c[l][j]<9999)
			return c[l][j];
		else{
			int temp=1;
			for(int i=l;i<j;i++){
				int m,n;
				m=minPartition(l,i,s,c);
				n=minPartition(i+1,j,s,c);
				
				temp=m+n;
				//cout<<l<<" "<<j<<" "<<temp<<endl;
				//cout<<l<<" "<<j<<" "<<s.substr(l,i-l+1)<<" "<<m<<" "<<n<<" "<<c[l][j]<<endl;
				if(temp<c[l][j]){
					c[l][j]=temp;
					//cout<<s.substr(l,j-l+1)<<endl;
				}
				
			}
		//	cout<<l<<" "<<j<<" "<<s.substr(l,j-l+1)<<" "<<c[l][j]<<endl;
			return c[l][j];
		}

		}

};

int main(){
	//double start = GetTickCount();  

	Solution s;
	string str="eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj";
	string str2="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string str3="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj
	cout<<s.minCut(str3)<<endl;
	//cout<<str.length();
	//cout<<s.isPalindrome(str2)<<endl;

	//double  end=GetTickCount();  
    //cout << "GetTickCount:" << end-start << endl;  

return 0;
}