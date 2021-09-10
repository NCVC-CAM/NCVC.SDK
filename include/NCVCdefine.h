/*
	NCVC �萔��` Ver3.20�`
*/
#if !defined(___NCVCDEFINE_H___)
#define	___NCVCDEFINE_H___

/*
-------------------------------------------------------------
	�S��
-------------------------------------------------------------
*/
typedef	struct	tagDPOINT {		/* double�^��3D-POINT�\���� */
	double		x, y, z;
} DPOINT, *LPDPOINT;

typedef	struct	tagRECT3D {		/* double�^��3D-RECT�\���� */
	double		left, top,
				right, bottom,
				high, low;
} RECT3D, *LPRECT3D;

/*
-------------------------------------------------------------
	��޲݂Ɋւ����`
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
	��޲݊֐��������\����
--------------------------- */
typedef struct tagNCVCINITIALIZE {
	/* �K�{���Ұ� */
	DWORD		dwSize;			/* �\���̻��� */
	DWORD		dwType;			/* ��޲�����(�ǂ��ƭ�����Ăɑ����邩) */
	int			nToolBar;		/* °��ް�ɓo�^��������.-1�Ȃ��ԎႢ���߂�o�^ */
	LPCTSTR		lpszMenuName[NCVCADIN_TYPESIZE];	/* �ƭ��ɕ\������镶���� */
	LPCTSTR		lpszFuncName[NCVCADIN_TYPESIZE];	/* ���؊֐���(�v����߰�) */
	/* �ȉ��ͱ�޲ݏ����޲�۸ނɍڂ�܂� */
	LPCTSTR		lpszAddinName;	/* ��޲ݖ� */
	LPCTSTR		lpszCopyright;	/* ��߰ײ� */
	LPCTSTR		lpszSupport;	/* ��߰Đ�Ұٱ��ڽ�Ȃ� */
	LPCTSTR		lpszComment;	/* ���đ� */
} NCVCINITIALIZE, *LPNCVCINITIALIZE;
/* ------------------------
	NCVC-API�ɱ������邽�߂������(���g��CDocument�׽��޼ު�Ăւ��߲��)
--------------------------- */
#define	NCVCHANDLE	void*

/*
-------------------------------------------------------------
	NC�ް��Ɋւ����`
-------------------------------------------------------------
*/
/* G,S,M,O,F */
#define	GTYPESIZE		5
/* X,Y,Z,U,V,W,I,J,K,R,P,L,D,H */
#define	VALUESIZE		14
/* VALUESIZE���̍��W�Ɋւ��镔�� */
#define	GVALSIZE		10
/* XYZ */
#define	NCXYZ			3
/* nGtype */
#define	G_TYPE	0
#define	S_TYPE	1
#define	M_TYPE	2
#define	O_TYPE	3
#define	F_TYPE	4
/* dValue�z�� */
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
/* dwValFlags ���ޯ� */
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
/* �g��dwValFlags ����ޯĂ���g�p */
#define	NCD_CORRECT_L	0x10000000
#define	NCD_CORRECT_R	0x20000000
#define	NCD_CORRECT		(NCD_CORRECT_L | NCD_CORRECT_R)
/* �l�w�� */
#define	NCD_CLEARVALUE	0xffff0000

/* NC���ނ̵�޼ު�����߂�\���� */
enum	ENNCDTYPE {
	NCDBASEDATA = 0, NCDLINEDATA = 1, NCDCYCLEDATA = 2, NCDARCDATA = 3
};
/* NC���ނ̕���(G17,G18,G19)��\���� */
enum	ENPLANE	{
	XY_PLANE =  0, XZ_PLANE =  1, YZ_PLANE =  2
};
/* �eNC�ޭ��̕��ʂ�\���� */
enum	ENNCVPLANE	{
	NC_XYZ_PLANE = 0, NC_XY_PLANE = 1, NC_XZ_PLANE = 2, NC_YZ_PLANE = 3
};
/* ��ۯ����ޯ��׸� */
#define	NCF_BREAK		0x0001
#define	NCF_AUTOREAD	0x0002
#define	NCF_FOLDER		0x0004

/* ------------------------
	NC�ް��\����
--------------------------- */
typedef	struct	tagNCDATA {
	DWORD		dwSize;				/* �\���̻��� */
	UINT		nErrorCode;			/* NC�ް��̴װ���� */
	int			nLine;				/* �s�ԍ� */
	int			nGtype;				/* GSMOF */
	int			nGcode;				/* ���ނɑ����l */
	ENPLANE		enPlane;			/* ���� */
	DWORD		dwValFlags;			/* dValue �Ŏw�肳��Ă���l */
	double		dValue[VALUESIZE];	/* X,Y,Z,U,V,W,I,J,K,R,P,L,D,H */
	double		dLength;			/* �ړ��E�؍풷 */
} NCDATA, *LPNCDATA;
/* --------------
	G68���W��]
----------------- */
typedef	struct	tagG68ROUND {
	BOOL		bG68;			/* G68���W��]�� */
	ENPLANE		enPlane;		/* �������̕��� */
	double		dRound;			/* ��]�p�x(rad) */
	double		dOrg[NCXYZ];	/* ��]���S���W */
} G68ROUND, *LPG68ROUND;
/* --------------
	ð�߉��H���iܲԂ̂݁j
----------------- */
typedef	struct	tagTAPER {
	int		nTaper;		/* 1:G51, -1:G52 */
	double	dTaper;		/* ð�ߊp�x(rad) */
	int		nDiff;		/* �㉺�Ɨ���Ű 0:G60, 1:G61, 2:G62, 3:G63 */
	BOOL	bTonly;		/* T���ޒP�Ǝw�� */
} TAPER, *LPTAPER;
/* ------------------------
	NC��޼ު�č\�z�̈���
--------------------------- */
typedef	struct	tagNCARGV {
	DWORD		dwSize;			/* �\���̻��� */
	NCDATA		nc;				/* NC��b�ް� */
	BOOL		bAbs;			/* TRUE:G90��޿ح��, FALSE:G91�ݸ����� */
	BOOL		bG98;			/* TRUE:G98�Ƽ�ٓ_, FALSE:G99R�_ ���A */
	G68ROUND	g68;			/* ���W��]����ޭ�� */
	TAPER		taper;			/* ð�߉��H��� */
	int			nSpindle;		/* �厲��]�� */
	double		dFeed;			/* ���葬�x */
	double		dEndmill;		/* ���ރ~���a */
	int			nEndmillType;	/* 0:�����, 1:�ް� */
} NCARGV, *LPNCARGV;

/*
-------------------------------------------------------------
	DXF�ް��Ɋւ����`
-------------------------------------------------------------
*/
/* DXF�̵�޼ު�����߂�\���� */
enum	ENDXFTYPE {
	DXFPOINTDATA = 0, DXFLINEDATA = 1, DXFCIRCLEDATA = 2, DXFARCDATA = 3,
	DXFELLIPSEDATA = 4, DXFPOLYDATA = 5, DXFSPLINEDATA = 6,
	DXFTEXTDATA = 7
};

/* ------------------------
	DXF�ǂݍ��ݵ�߼��
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
	LPCTSTR		pszLayer[DXFLAYERSIZE];	/* �e��ڲ� */
	UINT		nRegex,		/* �]���ʂ�(0)���C���K�\����(1) */
				nMatch,		/* ���S��v(0)���C������v(1) */
				nAccept,	/* �Ώ�ڲԂ�F������(0)���C���O���邩(1) */
				nOrgType;	/* ���_ڲԂ������Ƃ��̏��� */
	BOOL		bView;		/* �ϊ����ޭ��N�� */
	LPCTSTR		pszInitList[DXFMAXINITFILE];		/* �؍����̧�ٖ��̗��� */
	LPCTSTR		pszLayerToInitList[DXFMAXINITFILE];	/* ڲԖ��Ə���̧�ق̊֌W̧�ق̗��� */
} DXFOPTION, *LPDXFOPTION;

/* ------------------------
	DXF�ް��\����
--------------------------- */
typedef	struct	tagDXFDATA {
	DWORD		dwSize;				/* �\���̻��� */
	ENDXFTYPE	enType;				/* DXF�ް����� */
	char		szLayer[64];		/* ڲԖ� */
	int			nLayer;				/* ڲ����� */
	DPOINT		ptS;				/* �n�_�܂��͒��S */
	union	tagDXFeach {
		DPOINT	ptE;				/* DXFLINEDATA �I�_ */
		double	dR;					/* DXFCIRCLEDATA ���a */
		struct	tagDXFARC {
			double	r;				/* DXFARCDATA ���a */
			double	sq, eq;			/* DXFARCDATA �J�n�E�I���p�x[deg] */
		} arc;
		struct	tagDXFELLIPSE {
			DPOINT	ptL;			/* DXFELLIPSEDATA ���� */
			double	s;				/* DXFELLIPSEDATA �Z��(�{��) */
			double	sq, eq;			/* DXFELLIPSEDATA �J�n�E�I���p�x[deg] */
		} elli;
		char	szText[256];		/* DXFTEXTDATA ������ */
	} de;
} DXFDATA, *LPDXFDATA;

#endif
