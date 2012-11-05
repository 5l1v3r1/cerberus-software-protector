#if !defined(__XDETOURS_H__)
#define __XDETOURS_H__

#define __CONFIGURE_FILE_NAME__							_T("xd_config.cfg")
#define __XDETOURS_CONFIGURE_FILE_KEY__					0x99
#define __MAX_DETOURS_LIB__								0x08							//�����ṩ����Ŀ��������
#define __MAX_DETOURS_LIB_NAME_SIZE__					0x20							//�������Ƶ��������
#define __MAX_DETOURS_PROC__							0x10							//ÿ���ṩ����Ŀ����HOOK����������
#define __MAX_DETOURS_PROC_NAME_SIZE__					0x20							//�������Ƶ��������
#define __MAX_DETOURS_TRAMPOLINE_NAME_SIZE__			__MAX_DETOURS_PROC_NAME_SIZE__	//����trampoline���������

typedef struct _XDETOURS_CONFIGURE {
	DWORD dwLibCount;
	TCHAR LibNames[__MAX_DETOURS_LIB__][__MAX_DETOURS_LIB_NAME_SIZE__];
} XDETOURS_CONFIGURE, *PXDETOURS_CONFIGURE;

typedef struct __XDETOURS_TARGET {
	TCHAR LibName[__MAX_DETOURS_LIB_NAME_SIZE__];
	CHAR ProcName[__MAX_DETOURS_PROC_NAME_SIZE__];
} XDETOURS_TARGET, *PXDETOURS_TARGET;

typedef struct _XDETOURS_LIB_CONFIGURE {
	DWORD dwProcCount;
	CHAR ProcNames[__MAX_DETOURS_PROC__][__MAX_DETOURS_PROC_NAME_SIZE__];
	XDETOURS_TARGET Targets[__MAX_DETOURS_PROC__];
	DWORD dwProcArgCount[__MAX_DETOURS_PROC__];
	
	CHAR TrampolineName[__MAX_DETOURS_TRAMPOLINE_NAME_SIZE__];
} XDETOURS_LIB_CONFIGURE, *PXDETOURS_LIB_CONFIGURE;

// �����ļ��ṹ
typedef struct _XDETOURS_CONFIGURE_FILE {
	XDETOURS_CONFIGURE Names;															//�����·��
	XDETOURS_LIB_CONFIGURE Info[__MAX_DETOURS_LIB__];									//�������Ϣ
} XDETOURS_CONFIGURE_FILE, *PXDETOURS_CONFIGURE_FILE;

#endif
