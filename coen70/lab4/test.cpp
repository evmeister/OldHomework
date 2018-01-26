//Evan Eberhardt
//Ryan Nakagawa
#include "stack.h"
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	List stack;
	bool whoop=true;
	while(whoop){ //infinate while whoop
		cout<<"enter numbers and operators with a space between each."<<endl;
		cout<<"press 'E' key to exit"<<endl;
		string p;
		getline(cin, p);
		p+=" ";
	//	char* ptr=p.c_str();
		if(p.find("E")){
			whoop=false;
			break;
		}
		while(p.find(" ")!=0){	
			std::size_t len = p.find(" ");
			std::string str = p.substr(0, len);
			str.c_str();
			p.erase(0, len);
			if(str=="+"){
				if(stack.size>=2){
					double a=stack.pop();
					double b=stack.pop();
					a+=b;
					stack.insert(a);
				}
			}
			else if(str=="-"){
				if(stack.size>=2){
					double a=stack.pop();
					double b=stack.pop();
					a-=b;
					stack.insert(a);
				}
			}
			else if(str=="*"){
				if(stack.size>-2){
					double a=stack.pop();
					double b=stack.pop();
					a*=b;
					stack.insert(a);
				}
			}
			else if(str=="/"){
				if(stack.size>=2){
					double a=stack.pop();
					double b=stack.pop();
					a/=b;
					stack.insert(a);
				}
			}
			else
			{
				double d=strtod(str.c_str(), NULL);
				stack.insert(d);
			}
		}
	}
	if(stack.size!=0){
		double ans=stack.pop();
		cout<<"answer: "<<ans<<endl;
	}
return 0;
}
