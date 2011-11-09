#if !defined(__MONITOR_H__)
#define __MONITOR_H__

#include "Common.h"

typedef struct _IAT_MONITOR_ITEM {
	struct _IAT_MONITOR_ITEM *pNext;
	__char szName[0x20];//������
} IAT_MONITOR_ITEM, *PIAT_MONITOR_ITEM;

typedef struct _PROC_MONITOR_ITEM {
	struct _PROC_MONITOR_ITEM *pNext;
	__address addrAddress;//ҪHOOK���ڴ��ַ
} PROC_MONITOR_ITEM, *PPROC_MONITOR_ITEM;

typedef struct _MONITOR_CONFIGURE {
	__integer iIatMonitorCount;//�������Ӹ���
	PIAT_MONITOR_ITEM pIatMonitorItems;

	__integer iProcMonitorCount;//�����ĸ���
	PPROC_MONITOR_ITEM pProcMonitorItems;
} MONITOR_CONFIGURE, *PMONITOR_CONFIGURE;

__bool __INTERNAL_FUNC__ Monitor(__memory pMem, __tchar *pResultFilePath, PMONITOR_CONFIGURE pConfigure);

#endif