#include <iostream>
#include <string>
using namespace std;

int main(){
	char c;
	string s;
	string t;
	bool flag = true;
	c=cin.get();
	if(c=='"'){
		s.clear;
		s+=c;
		c=cin.get();
		while(c!+'"'){
			if(c=='\n')
				flag = false;
			else if (c=='\\'){
				t.clear();
				t+=c;
				c=cin.get();
				t+=c;
				if(t!="\\\"")
					flag = false;
			}
			s
