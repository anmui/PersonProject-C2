#include"pch.h"
#include<iostream> 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<fstream>
#include<Windows.h>
#include"readchars.h"
#include"readlines.h"
#include"readword.h"
#include"sort.h"
#include<map>
using namespace std;

/*****************************主函数****************************/
string GetFileNameFromArgs(int argc, char *argv[]) // 用于从命令行传入的参数中提取出输入文件名
{
	if (argc == 1)//直接运行
	{
		return "input.txt";
	}
	else if (argc == 2)//通过命令行传参打开
	{
		return argv[1];
	}
	else
	{
		throw "参数过多，错误";
	}
}
int main(int argc, char *argv[])
{
	map<string, int> words_m;
	string filename = GetFileNameFromArgs(argc, argv).c_str();
	//struct word *head;

	//head = new word;
	//head->next = NULL;
	int file_lines = 0;
	int file_chars = 0;
	int word_num = 0;
	int i = 0;
	char c;
	/*for (i = 0;(c = getchar()) != '\n'&&i < 59;i++)
	{
		filename[i] = c;
	}
	filename[i] = '\0';*/
	//FILE *file = _fsopen(filename, "r",_SH_DENYNO);
	ifstream file(filename);
	if (!file)
	{
		printf( "打开文件错误！" );
		return 0;
	}
	else
	{
		readchars(filename, file_chars);
		words_m=readword(words_m,filename,word_num);
		readlines(filename, file_lines);
		sort(words_m);
	}

}
