#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<fstream>
#include <cstdlib>
#include<string>
#include <sstream>
#include<vector>
#include "DLL1.h"
#include "stdafx.h"
using namespace std;
class people1 {
public:
	string name;
	string QQ;
	int cs;
	int zongzishu;
	int zhongjiangdown;
	int zhongjiangup;
};
people1 p[2000];

using namespace std;

void choujiang(char *filename)
{
	char word[1000];
	string a;

	ifstream in(filename);

	int num = 0;
	int k = 0;
	while (in.getline(word, 1000))
	{
		a = word;
		cout << a << endl;
		string b = "";
		vector<string> res;
		//暂存从word中读取的字符串 
		string result;
		//将字符串读到input中 
		stringstream input(a);
		//依次输出到result中，并存入res中 
		while (input >> result)
			res.push_back(result);
		//输出res 
		p[k].name = res[0];
		p[k].QQ = res[1];
		if (k <= 30 && k != 0)
		{
			p[k].zhongjiangdown = p[k - 1].zhongjiangup + 1;
			p[k].zhongjiangup = p[k].zhongjiangdown + 9;
		}
		else if (k == 0)
		{
			p[k].zhongjiangdown = 0;
			p[k].zhongjiangup = p[k].zhongjiangdown + 9;
		}
		else {
			p[k].zhongjiangdown = p[k - 1].zhongjiangup + 1;
			p[k].zhongjiangup = p[k].zhongjiangdown + 1;
		}
		k++;

	}
	int jieguo = 0;
	srand(time(0));
	if (k <= 30)
		jieguo = rand() % (k * 10 - 1);
	else
		jieguo = rand() % (k + 269);
	cout << jieguo;
	ofstream fout("final.txt");
	for (int i = 0; i < k; i++)
	{
		if (jieguo <= p[i].zhongjiangup && jieguo >= p[i].zhongjiangdown)
			fout << "恭喜 " << p[i].name << " (" << p[i].QQ << ") " << "中奖！" << endl;
	}
	fout.close();
}
