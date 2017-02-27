/*********************************************************
*  des.h
*  用户使用des算法头文件
*
*********************************************************/
#ifndef _OPENDESS_H_
#define _OPENDESS_H_

#ifdef __cplusplus
extern "C" {
#endif

	//加密
	int FileEncript(const char *file1, const char *file2);//输入两个文件

	//解密
	int FileDecript(const char *file1, const char *file2);//输入两个文件


	//ab\0defg

	//用户使用的函数
	int DesEnc(
		unsigned char *pInData,
		int            nInDataLen,
		unsigned char *pOutData,
		int           *pOutDataLen);

	//用户使用函数des解密
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
