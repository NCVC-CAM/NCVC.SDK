/*
	NCVC アドインヘッダー Ver0.15.00～用
*/
#if !defined(___NCVCADDIN_H___)
#define	___NCVCADDIN_H___

#include <windows.h>
#include "NCVCdefine.h"		/* 本体と共用 */

/* ___NCVC___ は本体定義です．ｱﾄﾞｲﾝ側では定義しないように */
#if defined(___NCVC___)
	#define	NCADDIN		extern "C"
	#define	NCEXPORT	extern "C" __declspec(dllexport)
#else
	#define	NCADDIN		extern "C" __declspec(dllexport)
	#define	NCEXPORT	extern "C"
#endif

/* ------------------------
	Addin-DLL Function
--------------------------- */
/*	NC-Addin Initialize TRUE:OK FALSE:NG */
NCADDIN BOOL NCVC_Initialize(LPNCVCINITIALIZE);
typedef BOOL (*PFNNCVCINITIALIZE)(LPNCVCINITIALIZE);
/*	Menu Event Addin Function */
typedef void (*PFNNCVCADDINFUNC)(void);
/* Create[NC|DXF]Document Serialize Function */
typedef	BOOL (*PFNNCVCSERIALIZEFUNC)(NCVCHANDLE hDoc, LPCTSTR pszPathName);

/* ------------------------
	NCVC Function
--------------------------- */
NCEXPORT HWND		WINAPI NCVC_GetMainWnd(void);
NCEXPORT HINSTANCE	WINAPI NCVC_GetMainInstance(void);
NCEXPORT LONG		WINAPI NCVC_CreateRegKey(LPCTSTR pszAddinName, PHKEY phKey);
NCEXPORT NCVCHANDLE	WINAPI NCVC_GetDocument(LPCTSTR pszPathName);
NCEXPORT int		WINAPI NCVC_GetDocumentFileName(NCVCHANDLE hDoc, LPTSTR pszPathName, int nSize);
NCEXPORT void		WINAPI NCVC_LockDocument(NCVCHANDLE hDoc, HANDLE hThread);
NCEXPORT void		WINAPI NCVC_UnlockDocument(NCVCHANDLE hDoc);
NCEXPORT void		WINAPI NCVC_MainfrmProgressRange(int nMin, int nMax);
NCEXPORT void		WINAPI NCVC_MainfrmProgressPos(int nPos);
NCEXPORT int		WINAPI NCVC_GetSelectMachineFileName(LPTSTR pszPathName, int nSize);
NCEXPORT BOOL		WINAPI NCVC_SetMachineFile(LPCTSTR pszPathName);
/* --- */
NCEXPORT NCVCHANDLE	WINAPI NCVC_CreateNCDocument(LPCTSTR pszPathName, LPCTSTR pszSerialFunc);
NCEXPORT NCVCHANDLE	WINAPI NCVC_CreateDXFDocument(LPCTSTR pszPathName, LPCTSTR pszSerialFunc);
NCEXPORT BOOL		WINAPI NCVC_AddNCDExtensionFunc(LPCTSTR pszExt, LPCTSTR pszModuleName, LPCTSTR pszSerialFunc);
NCEXPORT BOOL		WINAPI NCVC_AddDXFExtensionFunc(LPCTSTR pszExt, LPCTSTR pszModuleName, LPCTSTR pszSerialFunc);
NCEXPORT void		WINAPI NCVC_CloseDocument(NCVCHANDLE hDoc);
NCEXPORT void		WINAPI NCVC_ReDraw(NCVCHANDLE hDoc);
NCEXPORT void		WINAPI NCVC_GetObjectSize(NCVCHANDLE hDoc, LPRECT3D lprc);
/* --- */
NCEXPORT int		WINAPI NCVC_GetNCBlockDataSize(NCVCHANDLE hDoc);
NCEXPORT int		WINAPI NCVC_GetNCBlockData(NCVCHANDLE hDoc, int nIndex, LPSTR pszBuf, int nMax);
NCEXPORT DWORD		WINAPI NCVC_GetNCBlockFlag(NCVCHANDLE hDoc, int nIndex);
NCEXPORT int		WINAPI NCVC_GetNCDataSize(NCVCHANDLE hDoc);
NCEXPORT BOOL		WINAPI NCVC_GetNCData(NCVCHANDLE hDoc, int nIndex, LPNCDATA pData);
NCEXPORT BOOL		WINAPI NCVC_AddNCStrData(NCVCHANDLE hDoc, LPCTSTR pszBuf);
NCEXPORT BOOL		WINAPI NCVC_InsNCStrData(NCVCHANDLE hDoc, int nIndex, LPCTSTR pszBuf);
NCEXPORT BOOL		WINAPI NCVC_ModNCStrData(NCVCHANDLE hDoc, int nIndex, LPCTSTR pszBuf);
NCEXPORT void		WINAPI NCVC_DelNCStrData(NCVCHANDLE hDoc, int nIndex, int nCnt);
NCEXPORT BOOL		WINAPI NCVC_AddNCData(NCVCHANDLE hDoc, LPNCARGV pArgv);
NCEXPORT BOOL		WINAPI NCVC_InsNCData(NCVCHANDLE hDoc, int nIndex, LPNCARGV pArgv);
NCEXPORT BOOL		WINAPI NCVC_ModNCData(NCVCHANDLE hDoc, int nIndex, LPNCARGV pArgv);
NCEXPORT void		WINAPI NCVC_DelNCData(NCVCHANDLE hDoc, int nIndex, int nCnt);
NCEXPORT void		WINAPI NCVC_TraceStart(NCVCHANDLE hDoc);
NCEXPORT void		WINAPI NCVC_TracePause(NCVCHANDLE hDoc);
NCEXPORT void		WINAPI NCVC_TraceStop(NCVCHANDLE hDoc);
NCEXPORT int		WINAPI NCVC_TraceNextDraw(NCVCHANDLE hDoc);
/* --- */
NCEXPORT int		WINAPI NCVC_GetDXFLayerSize(NCVCHANDLE hDoc);
NCEXPORT int		WINAPI NCVC_GetDXFLayerData(NCVCHANDLE hDoc, int nIndex, LPTSTR pszLayerName, int nSize);
NCEXPORT int		WINAPI NCVC_GetDXFDataSize(NCVCHANDLE hDoc, LPCTSTR pszLayer);
NCEXPORT int		WINAPI NCVC_GetDXFTextDataSize(NCVCHANDLE hDoc, LPCTSTR pszLayer);
NCEXPORT BOOL		WINAPI NCVC_GetDXFData(NCVCHANDLE hDoc, int nIndex, LPDXFDATA pData);
NCEXPORT BOOL		WINAPI NCVC_GetDXFTextData(NCVCHANDLE hDoc, int nIndex, LPDXFDATA pData);
NCEXPORT BOOL		WINAPI NCVC_AddDXFData(NCVCHANDLE hDoc, LPDXFDATA pData);
NCEXPORT BOOL		WINAPI NCVC_InsDXFData(NCVCHANDLE hDoc, int nIndex, LPDXFDATA pData);
NCEXPORT BOOL		WINAPI NCVC_ModDXFData(NCVCHANDLE hDoc, int nIndex, LPDXFDATA pData);
NCEXPORT void		WINAPI NCVC_DelDXFData(NCVCHANDLE hDoc, LPCTSTR pszLayer, int nIndex, int nCnt);
NCEXPORT void		WINAPI NCVC_DelDXFTextData(NCVCHANDLE hDoc, LPCTSTR pszLayer, int nIndex, int nCnt);
NCEXPORT BOOL		WINAPI NCVC_GetDXFCutterOrigin(NCVCHANDLE hDoc, LPDPOINT lpptOrg);
NCEXPORT void		WINAPI NCVC_SetDXFCutterOrigin(NCVCHANDLE hDoc, LPDPOINT lpptOrg, double dR, BOOL bRedraw);
NCEXPORT void		WINAPI NCVC_SetDXFLatheLine(NCVCHANDLE hDoc, LPDPOINT lppts, LPDPOINT lppte);
NCEXPORT void		WINAPI NCVC_SetDXFReady(NCVCHANDLE hDoc, BOOL bReady);
/* --- */
NCEXPORT BOOL		WINAPI NCVC_GetDXFoption(LPDXFOPTION pOpt);
NCEXPORT BOOL		WINAPI NCVC_IsOriginLayer(LPCTSTR pszLayer);
NCEXPORT BOOL		WINAPI NCVC_IsCutterLayer(LPCTSTR pszLayer);
NCEXPORT BOOL		WINAPI NCVC_IsStartLayer(LPCTSTR pszLayer);
NCEXPORT BOOL		WINAPI NCVC_IsMoveLayer(LPCTSTR pszLayer);
NCEXPORT BOOL		WINAPI NCVC_IsCommentLayer(LPCTSTR pszLayer);

#endif		/* End of ___NCVCADDIN_H___ */
