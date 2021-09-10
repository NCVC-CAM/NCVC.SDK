/*
	NCVC 定数定義 Ver3.20～
*/
#if !defined(___NCVCDEFINE_H___)
#define	___NCVCDEFINE_H___

/*
-------------------------------------------------------------
	全般
-------------------------------------------------------------
*/
typedef	struct	tagDPOINT {		/* double型の3D-POINT構造体 */
	double		x, y, z;
} DPOINT, *LPDPOINT;

typedef	struct	tagRECT3D {		/* double型の3D-RECT構造体 */
	double		left, top,
				right, bottom,
				high, low;
} RECT3D, *LPRECT3D;

/*
-------------------------------------------------------------
	ｱﾄﾞｲﾝに関する定義
-------------------------------------------------------------
*/
#define	NCVCADIN_ARY_APPFILE		0
#define	NCVCADIN_ARY_APPOPTION		1
#define	NCVCADIN_ARY_NCDFILE		2
#define	NCVCADIN_ARY_NCDEDIT		3
#define	NCVCADIN_ARY_NCDVIEW		4
#define	NCVCADIN_ARY_NCDOPTION		5
#define	NCVCADIN_ARY_DXFFILE		6
#define	NCVCADIN_ARY_DXFEDIT		7
#define	NCVCADIN_ARY_DXFVIEW		8
#define	NCVCADIN_ARY_DXFOPTION		9
#define	NCVCADIN_TYPESIZE			10
#define	NCVCADIN_FLG_APPFILE		0x0001
#define	NCVCADIN_FLG_APPOPTION		0x0008
#define	NCVCADIN_FLG_NCDFILE		0x0010
#define	NCVCADIN_FLG_NCDEDIT		0x0020
#define	NCVCADIN_FLG_NCDVIEW		0x0040
#define	NCVCADIN_FLG_NCDOPTION		0x0080
#define	NCVCADIN_FLG_DXFFILE		0x0100
#define	NCVCADIN_FLG_DXFEDIT		0x0200
#define	NCVCADIN_FLG_DXFVIEW		0x0400
#define	NCVCADIN_FLG_DXFOPTION		0x0800
/* ------------------------
	ｱﾄﾞｲﾝ関数初期化構造体
--------------------------- */
typedef struct tagNCVCINITIALIZE {
	/* 必須ﾊﾟﾗﾒｰﾀ */
	DWORD		dwSize;			/* 構造体ｻｲｽﾞ */
	DWORD		dwType;			/* ｱﾄﾞｲﾝﾀｲﾌﾟ(どのﾒﾆｭｰｲﾍﾞﾝﾄに属するか) */
	int			nToolBar;		/* ﾂｰﾙﾊﾞｰに登録するｲﾍﾞﾝﾄ.-1なら一番若いﾀｲﾌﾟを登録 */
	LPCTSTR		lpszMenuName[NCVCADIN_TYPESIZE];	/* ﾒﾆｭｰに表示される文字列 */
	LPCTSTR		lpszFuncName[NCVCADIN_TYPESIZE];	/* ｴﾝﾄﾘ関数名(要ｴｸｽﾎﾟｰﾄ) */
	/* 以下はｱﾄﾞｲﾝ情報のﾀﾞｲｱﾛｸﾞに載ります */
	LPCTSTR		lpszAddinName;	/* ｱﾄﾞｲﾝ名 */
	LPCTSTR		lpszCopyright;	/* ｺﾋﾟｰﾗｲﾄ */
	LPCTSTR		lpszSupport;	/* ｻﾎﾟｰﾄ先ﾒｰﾙｱﾄﾞﾚｽなど */
	LPCTSTR		lpszComment;	/* ｺﾒﾝﾄ他 */
} NCVCINITIALIZE, *LPNCVCINITIALIZE;
/* ------------------------
	NCVC-APIにｱｸｾｽするためのﾊﾝﾄﾞﾙ(中身はCDocumentｸﾗｽｵﾌﾞｼﾞｪｸﾄへのﾎﾟｲﾝﾀ)
--------------------------- */
#define	NCVCHANDLE	void*

/*
-------------------------------------------------------------
	NCﾃﾞｰﾀに関する定義
-------------------------------------------------------------
*/
/* G,S,M,O,F */
#define	GTYPESIZE		5
/* X,Y,Z,U,V,W,I,J,K,R,P,L,D,H */
#define	VALUESIZE		14
/* VALUESIZE中の座標に関する部分 */
#define	GVALSIZE		10
/* XYZ */
#define	NCXYZ			3
/* nGtype */
#define	G_TYPE	0
#define	S_TYPE	1
#define	M_TYPE	2
#define	O_TYPE	3
#define	F_TYPE	4
/* dValue配列 */
#define	NCA_X	0
#define	NCA_Y	1
#define	NCA_Z	2
#define	NCA_U	3
#define	NCA_V	4
#define	NCA_W	5
#define	NCA_I	6
#define	NCA_J	7
#define	NCA_K	8
#define	NCA_R	9
#define	NCA_P	10
#define	NCA_L	11
#define	NCA_D	12
#define	NCA_H	13
/* dwValFlags のﾋﾞｯﾄ */
#define	NCD_X			0x00000001
#define	NCD_Y			0x00000002
#define	NCD_Z			0x00000004
#define	NCD_U			0x00000010
#define	NCD_V			0x00000020
#define	NCD_W			0x00000040
#define	NCD_I			0x00000100
#define	NCD_J			0x00000200
#define	NCD_K			0x00000400
#define	NCD_R			0x00000800
#define	NCD_P			0x00001000
#define	NCD_L			0x00002000
#define	NCD_D			0x00004000
#define	NCD_H			0x00008000
/* 拡張dwValFlags 上位ﾋﾞｯﾄから使用 */
#define	NCD_CORRECT_L	0x10000000
#define	NCD_CORRECT_R	0x20000000
#define	NCD_CORRECT		(NCD_CORRECT_L | NCD_CORRECT_R)
/* 値指定 */
#define	NCD_CLEARVALUE	0xffff0000

/* NCｺｰﾄﾞのｵﾌﾞｼﾞｪｸﾄﾀｲﾌﾟを表す列挙 */
enum	ENNCDTYPE {
	NCDBASEDATA = 0, NCDLINEDATA = 1, NCDCYCLEDATA = 2, NCDARCDATA = 3
};
/* NCｺｰﾄﾞの平面(G17,G18,G19)を表す列挙 */
enum	ENPLANE	{
	XY_PLANE =  0, XZ_PLANE =  1, YZ_PLANE =  2
};
/* 各NCﾋﾞｭｰの平面を表す列挙 */
enum	ENNCVPLANE	{
	NC_XYZ_PLANE = 0, NC_XY_PLANE = 1, NC_XZ_PLANE = 2, NC_YZ_PLANE = 3
};
/* ﾌﾞﾛｯｸのﾋﾞｯﾄﾌﾗｸﾞ */
#define	NCF_BREAK		0x0001
#define	NCF_AUTOREAD	0x0002
#define	NCF_FOLDER		0x0004

/* ------------------------
	NCﾃﾞｰﾀ構造体
--------------------------- */
typedef	struct	tagNCDATA {
	DWORD		dwSize;				/* 構造体ｻｲｽﾞ */
	UINT		nErrorCode;			/* NCﾃﾞｰﾀのｴﾗｰｺｰﾄﾞ */
	int			nLine;				/* 行番号 */
	int			nGtype;				/* GSMOF */
	int			nGcode;				/* ｺｰﾄﾞに続く値 */
	ENPLANE		enPlane;			/* 平面 */
	DWORD		dwValFlags;			/* dValue で指定されている値 */
	double		dValue[VALUESIZE];	/* X,Y,Z,U,V,W,I,J,K,R,P,L,D,H */
	double		dLength;			/* 移動・切削長 */
} NCDATA, *LPNCDATA;
/* --------------
	G68座標回転
----------------- */
typedef	struct	tagG68ROUND {
	BOOL		bG68;			/* G68座標回転中 */
	ENPLANE		enPlane;		/* 処理中の平面 */
	double		dRound;			/* 回転角度(rad) */
	double		dOrg[NCXYZ];	/* 回転中心座標 */
} G68ROUND, *LPG68ROUND;
/* --------------
	ﾃｰﾊﾟ加工情報（ﾜｲﾔのみ）
----------------- */
typedef	struct	tagTAPER {
	int		nTaper;		/* 1:G51, -1:G52 */
	double	dTaper;		/* ﾃｰﾊﾟ角度(rad) */
	int		nDiff;		/* 上下独立ｺｰﾅｰ 0:G60, 1:G61, 2:G62, 3:G63 */
	BOOL	bTonly;		/* Tｺｰﾄﾞ単独指示 */
} TAPER, *LPTAPER;
/* ------------------------
	NCｵﾌﾞｼﾞｪｸﾄ構築の引数
--------------------------- */
typedef	struct	tagNCARGV {
	DWORD		dwSize;			/* 構造体ｻｲｽﾞ */
	NCDATA		nc;				/* NC基礎ﾃﾞｰﾀ */
	BOOL		bAbs;			/* TRUE:G90ｱﾌﾞｿﾘｭｰﾄ, FALSE:G91ｲﾝｸﾘﾒﾝﾀﾙ */
	BOOL		bG98;			/* TRUE:G98ｲﾆｼｬﾙ点, FALSE:G99R点 復帰 */
	G68ROUND	g68;			/* 座標回転ｱﾄﾘﾋﾞｭｰﾄ */
	TAPER		taper;			/* ﾃｰﾊﾟ加工情報 */
	int			nSpindle;		/* 主軸回転数 */
	double		dFeed;			/* 送り速度 */
	double		dEndmill;		/* ｴﾝﾄﾞミル径 */
	int			nEndmillType;	/* 0:ｽｸｳｪｱ, 1:ﾎﾞｰﾙ */
} NCARGV, *LPNCARGV;

/*
-------------------------------------------------------------
	DXFﾃﾞｰﾀに関する定義
-------------------------------------------------------------
*/
/* DXFのｵﾌﾞｼﾞｪｸﾄﾀｲﾌﾟを表す列挙 */
enum	ENDXFTYPE {
	DXFPOINTDATA = 0, DXFLINEDATA = 1, DXFCIRCLEDATA = 2, DXFARCDATA = 3,
	DXFELLIPSEDATA = 4, DXFPOLYDATA = 5, DXFSPLINEDATA = 6,
	DXFTEXTDATA = 7
};

/* ------------------------
	DXF読み込みｵﾌﾟｼｮﾝ
--------------------------- */
#define	DXFORGLAYER		0
#define	DXFCAMLAYER		1
#define	DXFSTRLAYER		2
#define	DXFMOVLAYER		3
#define	DXFCOMLAYER		4
#define	DXFLAYERSIZE	5
#define	DXFMAXINITFILE	10
typedef	struct	tagDXFOPTION {
	DWORD		dwSize;
	LPCTSTR		pszLayer[DXFLAYERSIZE];	/* 各種ﾚｲﾔ */
	UINT		nRegex,		/* 従来通り(0)か，正規表現で(1) */
				nMatch,		/* 完全一致(0)か，部分一致(1) */
				nAccept,	/* 対象ﾚｲﾔを認識する(0)か，除外するか(1) */
				nOrgType;	/* 原点ﾚｲﾔが無いときの処理 */
	BOOL		bView;		/* 変換後ﾋﾞｭｰ起動 */
	LPCTSTR		pszInitList[DXFMAXINITFILE];		/* 切削条件ﾌｧｲﾙ名の履歴 */
	LPCTSTR		pszLayerToInitList[DXFMAXINITFILE];	/* ﾚｲﾔ名と条件ﾌｧｲﾙの関係ﾌｧｲﾙの履歴 */
} DXFOPTION, *LPDXFOPTION;

/* ------------------------
	DXFﾃﾞｰﾀ構造体
--------------------------- */
typedef	struct	tagDXFDATA {
	DWORD		dwSize;				/* 構造体ｻｲｽﾞ */
	ENDXFTYPE	enType;				/* DXFﾃﾞｰﾀﾀｲﾌﾟ */
	char		szLayer[64];		/* ﾚｲﾔ名 */
	int			nLayer;				/* ﾚｲﾔﾀｲﾌﾟ */
	DPOINT		ptS;				/* 始点または中心 */
	union	tagDXFeach {
		DPOINT	ptE;				/* DXFLINEDATA 終点 */
		double	dR;					/* DXFCIRCLEDATA 半径 */
		struct	tagDXFARC {
			double	r;				/* DXFARCDATA 半径 */
			double	sq, eq;			/* DXFARCDATA 開始・終了角度[deg] */
		} arc;
		struct	tagDXFELLIPSE {
			DPOINT	ptL;			/* DXFELLIPSEDATA 長軸 */
			double	s;				/* DXFELLIPSEDATA 短軸(倍率) */
			double	sq, eq;			/* DXFELLIPSEDATA 開始・終了角度[deg] */
		} elli;
		char	szText[256];		/* DXFTEXTDATA 文字列 */
	} de;
} DXFDATA, *LPDXFDATA;

#endif
