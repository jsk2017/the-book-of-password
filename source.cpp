#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "map"
#include "string"
#include "source.h"
#include "fstream"
#include "itcastlog.h"
using namespace std;

//map<string,string> InitMap()
//{
//	map<string,string> my_map;
//	ifstream in("c:\\Windows\\system32\\password_edit.ini");
//	if (!in.is_open())
//	{
//		cout<<"open error!\n";
//	}
//	return my_map;
//}

//{
//	const char *file：文件名称
//		int line：文件行号
//		int level：错误级别
//		0 -- 没有日志
//		1 -- debug级别
//		2 -- info级别
//		3 -- warning级别
//		4 -- err级别
//		int status：错误码
//		const char *fmt：可变参数
//		*/
//		/************************************************************************/
//		//实际使用的Level
//		extern int  LogLevel[5];
//	void ITCAST_LOG(const char *file, int line, int level, int status, const char *fmt, ...);
//
//}
int Start(void)
{
	FILE *fp=fopen("c:\\Windows\\system32\\password_edit.ini","a");
	cout<<"Hello!"<<endl;
	cout<<"Welcome to use the Password_Edit!"<<endl;
	cout<<"Please input below numbers."<<endl;
	cout<<"1. Add item."<<endl;
	cout<<"2. Delete item."<<endl;
	cout<<"3. Change item."<<endl;
	cout<<"4. Check items."<<endl;
	cout<<"5. Clear items."<<endl;
	cout<<"6. Quit."<<endl;
	cout<<"Your choose : ";
	fclose(fp);
	ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Begin.....\n",0);
	return 0;
}

int AddItem()
{
	//InitMap();
	string Username;
	string Password;
	map<string,string> item;

	ifstream in("c:\\Windows\\system32\\password_edit.ini");
	if (!in.is_open())
	{
		cout<<"open error!\n";
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Function:AddItemOpen error....\n",0);
	}
	while (!in.eof())
	{
		in>>Username>>Password;
		item.insert(make_pair(Username,Password));
	}

	ofstream out("c:\\Windows\\system32\\password_edit.ini");
	if (!out.is_open())//muo ren wei 'out'
	{
		cout<<"open error!\n";
	}
	//Echo
	cout<<"Please input  username: ";
	cin>>Username;
	//cout<<Username<<endl;
	cout<<"Please input password: ";
	cin>>Password;

	//traverse print
	for (map<string,string>::iterator it2 = item.begin();it2!=item.end();it2++)
	{
		cout<<it2->first<<"\t"<<it2->second<<endl;
	}

	//insert items
	item.insert(make_pair(Username,Password));
	map<string,string>::iterator it=item.begin();
	for (;it!=item.end();it++)
	{
		out<<it->first<<" "<<it->second<<endl;
	}

	cout<<"Add successfully!"<<endl;
	ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Add succeed...",0);
	return 0;
	
}

int DeleteItem()
{
	//init
	string Username;
	string Password;
	map<string,string> item;

	ifstream in("c:\\Windows\\system32\\password_edit.ini");
	
	if (!in.is_open())
	{
		cout<<"open error!\n";
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Function:DeleteItem Open error....\n",0);
	}
	while (!in.eof())
	{
		in>>Username>>Password;
		item.insert(make_pair(Username,Password));
	}
	//print test
	for (map<string,string>::iterator it2 = item.begin();it2!=item.end();it2++)
	{
		cout<<it2->first<<"\t"<<it2->second<<endl;
	}
	cout<<"Please input username: ";
	cin>>Username;

	//find items
	//map<string,string>::iterator it=item.begin();
	int tag=0;
	for (map<string,string>::iterator it2 = item.begin();it2!=item.end();it2++)
	{

		if (it2->first==Username)
		{
			tag=1;
			it2 = item.erase(it2);
		}
	}
	if (tag==0)
	{
		cout<<"can't find!"<<endl;
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Function:Delete can't find....\n",0);
	}
	//
	ofstream out("c:\\Windows\\system32\\password_edit.ini");
	map<string,string>::iterator it=item.begin();
	for (;it!=item.end();it++)
	{
		out<<it->first<<" "<<it->second<<endl;
	}
	cout<<"Delete succeed!"<<endl;
	ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Delete succeed....\n",0);
	return 0;
}

int ChangeItem()
{
	//init
	string Username;
	string Password;
	map<string,string> item;

	ifstream in("c:\\Windows\\system32\\password_edit.ini");
	
	if (!in.is_open())
	{
		cout<<"open error!\n";
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Function:ChangeItem Open error!....\n",0);
	}
	while (!in.eof())
	{
		in>>Username>>Password;
		item.insert(make_pair(Username,Password));
	}
	//print test
	for (map<string,string>::iterator it2 = item.begin();it2!=item.end();it2++)
	{
		cout<<it2->first<<"\t"<<it2->second<<endl;
	}
	cout<<"Please input username: ";
	cin>>Username;
	cout<<"Please input new password: ";
	cin>>Password;

	//find items
	//map<string,string>::iterator it=item.begin();
	for (map<string,string>::iterator it2 = item.begin();it2!=item.end();it2++)
	{
		if (it2->first==Username)
		{
			item.insert(make_pair(Username,Password));
		}
		else
		{
			cout<<"can't find"<<endl;
			ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Function:Change can't find...\n",0);
		}
	}
	ofstream out("c:\\Windows\\system32\\password_edit.ini");
	map<string,string>::iterator it=item.begin();
	for (;it!=item.end();it++)
	{
		out<<it->first<<" "<<it->second<<endl;
	}
	cout<<"Change succeed!"<<endl;
	ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Change succeed!...",0);
	return 0;
}

int CheckItem()
{
	string Username;
	string Password;
	map<string,string> item;

	ifstream in("c:\\Windows\\system32\\password_edit.ini");
	if (!in.is_open())
	{
		cout<<"open error!\n";
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Function:CheckItem Open error!....\n",0);
	}
	while (!in.eof())
	{
		in>>Username>>Password;
		item.insert(make_pair(Username,Password));
	}
	//print test
	for (map<string,string>::iterator it2 = item.begin();it2!=item.end();it2++)
	{
		cout<<it2->first<<"\t"<<it2->second<<endl;
	}
	ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Function:CheckItem succeed!....\n",0);
	return 0;
}

int ClearItem()
{

	ofstream out("c:\\Windows\\system32\\password_edit.ini");
	if (!out.is_open())
	{
		cout<<"open error"<<endl;
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Function:ClearItem Open error!....\n",0);
	}
	map<string,string> item;
	map<string,string>::iterator it=item.begin();
	for (;it!=item.end();it++)
	{
		out<<it->first<<" "<<it->second<<endl;
	}
	if (!out.eof())
	{
		cout<<"succeed!"<<endl;
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Clear succeed....\n",0);
	}
	else
	{
		cout<<"error\n";
		ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"Clear error....\n",0);
	}
	return 0;
}
int Quit()
{
	ITCAST_LOG(__FILE__,__LINE__,LogLevel[2],0,"End....\n",0);
	exit(0);
	return 0;
}