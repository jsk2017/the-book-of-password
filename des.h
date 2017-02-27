/*********************************************************
*  des.h
*  �û�ʹ��des�㷨ͷ�ļ�
*
*********************************************************/
#ifndef _OPENDESS_H_
#define _OPENDESS_H_

#ifdef __cplusplus
extern "C" {
#endif

	//����
	int FileEncript(const char *file1, const char *file2);//���������ļ�

	//����
	int FileDecript(const char *file1, const char *file2);//���������ļ�


	//ab\0defg

	//�û�ʹ�õĺ���
	int DesEnc(
		unsigned char *pInData,
		int            nInDataLen,
		unsigned char *pOutData,
		int           *pOutDataLen);

	//�û�ʹ�ú���des����
	int DesDec(
		unsigned char *pInData,
		int            nInDataLen,
		unsigned char *pOutData,
		int           *pOutDataLen);

#ifdef __cplusplus
}
#endif

#endif

#pragma once
