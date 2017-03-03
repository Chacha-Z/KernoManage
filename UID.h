#pragma once
#include<iostream>
# include<string>
using namespace std;

const int UID_MAX_LEN = 54;
typedef   const unsigned char*  type_uid;

class UID
{
	unsigned char Uid[UID_MAX_LEN];
	int Len= 54;
	string strUid;
public:
	UID()
	{
		Uid[0] = 0;
    }
    UID(const string strUid);
    //Ĭ��Ϊ0
    UID(const unsigned char *u, const int &len=UID_MAX_LEN);
	UID(UID &u);
	~UID();

	void setUid(const unsigned char *u, const int len);//����uid

	const unsigned char *getUid();//����uid
	const int getLen();//��ȡuid�ĳ���
	const string convert(const unsigned char* bits,int len);//��uidת�����ַ���
	const string stringValue(int number);//����covert����uid��ת��

    void setStrUid(const string uid);

	string getStrUid();//��ȡ�ַ������͵�uid���ڴ������ݿ�

	friend bool operator ==(UID &u1,UID &u2);
	friend bool operator ==(UID u, unsigned char *data);
};


