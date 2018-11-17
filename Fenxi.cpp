#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<utility>
#include<set>
#include<map>
#include<fstream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
#define de(x) cout<<#x<<" = "<<x<<endl
#define dd(x) cout<<#x<<" = "<<x
char qLine[4][100005];
const int N=1e4+7;
struct qwe{
	string name,qq;
	int cs,zs;
}a[N];
bool cmp(qwe a,qwe b){
	return a.zs>a.zs;
}
FILE *fp;
string UTF8ToGB(const char* str) {
	string result;
	WCHAR *strSrc;
	LPSTR szRes;
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);
	result = szRes;
	delete[]strSrc;
	delete[]szRes;
	return result;
}

bool qgetline(char s[]){
	if( fgets(s,1024,fp) ){
		return true;
	}
	return false;
}
map<string,string>qq_name;
map<string,string>::iterator it1;
map<string,int>qq_cs;
map<string,int>qq_zs;
map<string,int>::iterator it2;
void getfayan(int i){
	string name="",qq="";
	int zs=0,len=strlen(qLine[1]);
	for(int j=len-1;j>=0&&qLine[1][j]!='#';j++){
		zs++;
	}
	for(i=i+1;qLine[0][i]!='('&&qLine[0][i]!='<';i++){
		name+=qLine[0][i];
	}
	for(i=i+1;qLine[0][i]!=')'&&qLine[0][i]!='>';i++){
		qq+=qLine[0][i];
	}
	qq_name[qq]=name;
	qq_cs[qq]++;
	qq_zs[qq]+=zs;
}
bool chanyucoujiang( char s[],string gjc){
	int i=0,j,len=strlen(s);
	string tmp;
	while(i<len){
		if(s[i]=='#'){
			tmp="";
			for( j=i+1;s[j]!='#';j++){
				tmp+=s[j];
			}
			if(tmp==gjc){
				return true;
			}i=j+1;
		}else i++;
	}
	return false;
}

bool getperson(string gjc){
	gjc=UTF8ToGB(gjc.c_str());
	if(!qgetline(qLine[0]) )return false;
	string str;
	str=UTF8ToGB(qLine[0]);

	if(!qgetline(qLine[1]) )return false;
	str=UTF8ToGB(qLine[1]);
	int j;
	for( j=0;j<str.size();j++){
		qLine[1][j]=str[j];
	}
	qLine[1][j]='\0';
	//de(qLine[1]);
	
	if(!qgetline(qLine[2]) )return false;


	if( !chanyucoujiang(qLine[1],gjc) ){
		return true;
	}
	int i,t=0;
	for(i=0;;i++){
		if(qLine[0][i]==' '){
			t++;
			if(t==2)break;
		}
	}
	getfayan(i);
	return true;
}
int main(){
	FILE *ffp;
	fopen_s(&fp,"record.txt","rt");
	fopen_s(&ffp,"gjc.txt","rt");
	string gjc;
	char ss[1024];
	fgets(ss,1024,ffp);
	gjc=ss;
	gjc=UTF8ToGB(gjc.c_str());
	while(getperson(gjc) ){
		
	}
	//de("-----------------------");
	int cnt=0;

	int zs,cs;
	for( it1=qq_name.begin();it1!=qq_name.end();it1++){
		a[cnt].name=it1->second;
		a[cnt].qq=it1->first;
		a[cnt].zs=qq_zs[ a[cnt].qq ];
		a[cnt].cs=qq_cs[a[cnt].qq];
		cnt++;
	}
	sort(a,a+cnt,cmp);
	freopen("result.txt","w",stdout);
	for(int j=0;j<cnt;j++){
		cout<<a[j].name<<" "<<a[j].qq<<" "<<a[j].cs<<" "<<a[j].zs<<endl;
	}

}