#pragma once
#include"WINSCARD.H"
#include<QMutex>
#pragma comment (lib, "winscard.lib")
class SCard
{
private:
    SCARDCONTEXT hSC;										//OK
    LONG lReturn;											//OK
    char mszReaders[1024];									//OK
    LPTSTR pReader, pReaderName;							//pReader is OK
    DWORD dwLen;											//OK
    int nReaders, nCurrentReader;							//
    SCARDHANDLE hCardHandle;								//OK
    DWORD dwAP;
    QMutex mutex;
    static SCard* reader;
    SCard(); //���������ġ�ȡ�������б�
    ~SCard(); //�ͷ�������

public:
    static SCard* getReader();
                                                                            //������������
    void SetReader();
    int ConnectReader(); //�뵱ǰ��������������
    int DisConnectReader(); //�뵱ǰ�������Ͽ�����
    int SendCommand(BYTE command[], DWORD commandLength, BYTE result[], DWORD *resultLength); //�������������������շ��ص����ݡ�����ֵΪsw
    int ReadTheCard(BYTE *recvBuffer, DWORD &recvlen);//������������
};

