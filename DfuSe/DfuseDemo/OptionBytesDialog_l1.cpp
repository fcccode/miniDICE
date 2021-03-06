/******************** (C) COPYRIGHT 2015 STMicroelectronics ********************
* Company            : STMicroelectronics
* Author             : MCD Application Team
* Description        : STMicroelectronics Device Firmware Upgrade  Extension Demo
* Version            : V3.0.5
* Date               : 01-September-2015
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
********************************************************************************
* FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE
* "MCD-ST Liberty SW License Agreement V2.pdf"
*******************************************************************************/

// OptionBytesDialog_l1.cpp : implementation file
//

#include "stdafx.h"
#include "dfusedemo.h"
#include "OptionBytesDialog_l1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionBytesDialog_L1 dialog

static GUID	GUID_DFU = { 0x3fe809ab,0xfb91,0x4cb5,{ 0xa6,0x43,0x69,0x67,0x0d,0x52,0x36,0x6e } };
static GUID GUID_APP = { 0xcb979912, 0x5029, 0x420a, { 0xae, 0xb1, 0x34, 0xfc, 0xa, 0x7d, 0x57, 0x26 } };


COptionBytesDialog_L1::COptionBytesDialog_L1(CWnd* pParent /*=NULL*/)
	: CDialog(COptionBytesDialog_L1::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptionBytesDialog_L1)
	m_RDP_Value = _T("00");
	m_User_Value = _T("00");
	m_WRP0_Value = _T("0000");
	m_WRP2_Value = _T("0000");
	m_WRP4_Value = _T("0000");
	m_WRP6_Value = _T("0000");
	m_WRP8_Value = _T("0000");
	m_WRP10_Value = _T("0000");

	m_nRST_STDBY_Value = FALSE;
	m_nRST_STOP_Value = FALSE;
	m_WDG_SW_Value = FALSE;
	m_BF2_Value = FALSE;
	m_BOR_LEV0_Value = FALSE;
	m_BOR_LEV1_Value = FALSE;
	m_BOR_LEV2_Value = FALSE;
	m_BOR_LEV3_Value = FALSE;

	m_ReadOutProtectionEnabledValue = FALSE;
	m_ReadOutProtectionEnabledValue2 = FALSE;
	m_ReadOutProtectionEnabledValue3 = FALSE;

	//}}AFX_DATA_INIT
}


void COptionBytesDialog_L1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionBytesDialog_L1)
	DDX_Text(pDX, IDC_RDP_EDIT, m_RDP_Value);
	DDV_MaxChars(pDX, m_RDP_Value, 2);
	DDX_Text(pDX, IDC_WRP0_EDIT, m_WRP0_Value);
	DDV_MaxChars(pDX, m_WRP0_Value, 4);
	DDX_Text(pDX, IDC_WRP2_EDIT, m_WRP2_Value);
	DDV_MaxChars(pDX, m_WRP2_Value, 4);
	DDX_Text(pDX, IDC_WRP4_EDIT, m_WRP4_Value);
	DDV_MaxChars(pDX, m_WRP4_Value, 4);
	DDX_Text(pDX, IDC_WRP6_EDIT, m_WRP6_Value);
	DDV_MaxChars(pDX, m_WRP6_Value, 4);
	DDX_Text(pDX, IDC_WRP8_EDIT, m_WRP8_Value);
	DDV_MaxChars(pDX, m_WRP8_Value, 4);
	DDX_Text(pDX, IDC_WRP10_EDIT, m_WRP10_Value);
	DDV_MaxChars(pDX, m_WRP10_Value, 4);

	DDX_Text(pDX, IDC_USER_EDIT, m_User_Value);
	DDV_MaxChars(pDX, m_User_Value, 2);
	DDX_Check(pDX, IDC_NRST_STDBY_CHECK, m_nRST_STDBY_Value);
	DDX_Check(pDX, IDC_NRST_STOP_CHECK2, m_nRST_STOP_Value);
	DDX_Check(pDX, IDC_BF2, m_BF2_Value);
	DDX_Check(pDX, IDC_WDG_SW, m_WDG_SW_Value);
	DDX_Check(pDX, IDC_BOR_LEV0, m_BOR_LEV0_Value);
	DDX_Check(pDX, IDC_BOR_LEV1, m_BOR_LEV1_Value);
	DDX_Check(pDX, IDC_BOR_LEV2, m_BOR_LEV0_Value);
	DDX_Check(pDX, IDC_BOR_LEV3, m_BOR_LEV1_Value);

	DDX_Check(pDX, IDC_READ_OUT_PROTECTION_ENABLED_CHECK, m_ReadOutProtectionEnabledValue);
	DDX_Check(pDX, IDC_READ_OUT_PROTECTION_ENABLED_CHECK2, m_ReadOutProtectionEnabledValue2);
	DDX_Check(pDX, IDC_READ_OUT_PROTECTION_ENABLED_CHECK3, m_ReadOutProtectionEnabledValue3);

	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionBytesDialog_L1, CDialog)
	//{{AFX_MSG_MAP(COptionBytesDialog_L1)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_READ_OUT_PROTECTION_ENABLED_CHECK, OnReadOutProtectionEnabledCheck)
	ON_BN_CLICKED(IDC_READ_OUT_PROTECTION_ENABLED_CHECK2, OnReadOutProtectionEnabledCheck2)
	ON_BN_CLICKED(IDC_READ_OUT_PROTECTION_ENABLED_CHECK3, OnReadOutProtectionEnabledCheck3)
	ON_EN_CHANGE(IDC_USER_EDIT, OnChangeUserEdit)
	ON_BN_CLICKED(IDC_WDG_SW, OnWdgSw)
	ON_BN_CLICKED(IDC_BF2, OnBF2)
	ON_BN_CLICKED(IDC_BOR_LEV0, OnBor0Check)
	ON_BN_CLICKED(IDC_BOR_LEV1, OnBor1Check)
	ON_BN_CLICKED(IDC_BOR_LEV2, OnBor2Check)
	ON_BN_CLICKED(IDC_BOR_LEV3, OnBor3Check)
	ON_BN_CLICKED(IDC_NRST_STOP_CHECK2, OnNrstStopCheck2)
	ON_BN_CLICKED(IDC_NRST_STDBY_CHECK, OnNrstStdbyCheck)
	ON_BN_CLICKED(ID_APPLY, OnApply)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionBytesDialog_L1 message handlers

	/*typedef struct  
	{
		UCHAR bStatus;
		UCHAR bwPollTimeout[3];
		UCHAR bState;
		UCHAR iString;
	}	DFUSTATUS,  *PDFUSTATUS;*/

void* COptionBytesDialog_L1::GetOptions(LPBYTE User, LPBYTE RDP, LPBYTE WRP0 , LPBYTE WRP1, LPBYTE WRP2, LPBYTE WRP3, LPBYTE WRP4, LPBYTE WRP5, LPBYTE WRP6, LPBYTE WRP7, LPBYTE WRP8, LPBYTE WRP9, LPBYTE WRP10, LPBYTE WRP11 )
{
   m_pBuffer = (LPBYTE) malloc(64);
   memset(m_pBuffer, 0x00, 64);
   
   if (STDFU_SelectCurrentConfiguration(&m_phDevice, 0, 0,1)==STDFU_NOERROR)
   {
       DFUSTATUS DFUStatus;

	   STDFU_Getstatus(&m_phDevice, &DFUStatus);
	   while(DFUStatus.bState != STATE_DFU_IDLE)
	   {
			STDFU_Clrstatus(&m_phDevice);
			STDFU_Getstatus(&m_phDevice, &DFUStatus);
	   }
		   
	   m_pBuffer[0] = 0x21;
	   m_pBuffer[1] = 0x00;
	   m_pBuffer[2] = 0x00;
	   m_pBuffer[3] = 0xF8;
	   m_pBuffer[4] = 0x1F;

	   STDFU_Dnload(&m_phDevice, m_pBuffer, 0x05, 0);
	   
	   STDFU_Getstatus(&m_phDevice, &DFUStatus);
	   while(DFUStatus.bState != STATE_DFU_IDLE)
	   {
			STDFU_Clrstatus(&m_phDevice);
			STDFU_Getstatus(&m_phDevice, &DFUStatus);
	   }

	   if(STDFU_Upload(&m_phDevice, m_pBuffer, 0x20, 2) == STDFU_NOERROR)
	   {
		   *RDP   = m_pBuffer[0] ;
		   *User  = m_pBuffer[4];
		   *WRP0   = m_pBuffer[8];
		   *WRP1   = m_pBuffer[9];
		   *WRP2   = m_pBuffer[12];
		   *WRP3   = m_pBuffer[13];
		   *WRP4   = m_pBuffer[16];
		   *WRP5   = m_pBuffer[17];
		   *WRP6   = m_pBuffer[20];
		   *WRP7   = m_pBuffer[21];
		   *WRP8   = m_pBuffer[24];
		   *WRP9   = m_pBuffer[25];
		   *WRP10   = m_pBuffer[28];
		   *WRP11   = m_pBuffer[29];


		   return 0;
	   }
	   return 0;
   }
   return 0;
}

void* COptionBytesDialog_L1::SetOptions(BYTE User, BYTE RDP,  BYTE WRP0, BYTE WRP1 , BYTE WRP2, BYTE WRP3, BYTE WRP4, BYTE WRP5, BYTE WRP6, BYTE WRP7, BYTE WRP8, BYTE WRP9, BYTE WRP10, BYTE WRP11)
{
   m_pBuffer = (LPBYTE) malloc(0x10);
   memset(m_pBuffer, 0xFF, 0x10);
   
   if (STDFU_SelectCurrentConfiguration(&m_phDevice, 0, 0,1)==STDFU_NOERROR)
   {
       DFUSTATUS DFUStatus;

	   STDFU_Getstatus(&m_phDevice, &DFUStatus);
	   while(DFUStatus.bState != STATE_DFU_IDLE)
	   {
			STDFU_Clrstatus(&m_phDevice);
			STDFU_Getstatus(&m_phDevice, &DFUStatus);
	   }
		   
	   m_pBuffer[0] = 0x21;
	   m_pBuffer[1] = 0x00;
	   m_pBuffer[2] = 0x00;
	   m_pBuffer[3] = 0x80;
	   m_pBuffer[4] = 0x1F;

	   STDFU_Dnload(&m_phDevice, m_pBuffer, 0x05, 0);
	   
	   STDFU_Getstatus(&m_phDevice, &DFUStatus);
	   while(DFUStatus.bState != STATE_DFU_DOWNLOAD_IDLE)
	   {
			//STDFU_Clrstatus(&m_phDevice);
			STDFU_Getstatus(&m_phDevice, &DFUStatus);
	   }

	   memset(m_pBuffer, 0xFF, 0x20);

	   m_pBuffer[0]  = RDP;
	   m_pBuffer[1]  = 0x00;
	   m_pBuffer[2]  = ~RDP;
	   m_pBuffer[3]  = 0x00;
	   m_pBuffer[4]  = User;;
       m_pBuffer[5]  = 0x00;
	   m_pBuffer[6]  = ~User;
	   m_pBuffer[7]  = 0x00;
	   m_pBuffer[8]  = WRP0;
	   m_pBuffer[9]  = WRP1;
	   m_pBuffer[10] = ~WRP0;
	   m_pBuffer[11] = ~WRP1;
	   m_pBuffer[12] = WRP2;
	   m_pBuffer[13] = WRP3;
	   m_pBuffer[14] = ~WRP2;
	   m_pBuffer[15] = ~WRP3;
	   m_pBuffer[16] = WRP4;
	   m_pBuffer[17] = WRP5;
	   m_pBuffer[18] = ~WRP4;
	   m_pBuffer[19] = ~WRP5;
	   m_pBuffer[20] = WRP6;
       m_pBuffer[21] = WRP7;
	   m_pBuffer[22] = ~WRP6;
	   m_pBuffer[23] = ~WRP7;
	   m_pBuffer[24] = WRP8;
	   m_pBuffer[25] = WRP9;
	   m_pBuffer[26] = ~WRP8;
	   m_pBuffer[27] = ~WRP9;
	   m_pBuffer[28] = WRP10;
	   m_pBuffer[29] = WRP11;
	   m_pBuffer[30] = ~WRP10;
	   m_pBuffer[31] = ~WRP11;


	   /*#define STATE_IDLE							0x00
#define STATE_DETACH						0x01
#define STATE_DFU_IDLE						0x02
#define STATE_DFU_DOWNLOAD_SYNC				0x03
#define STATE_DFU_DOWNLOAD_BUSY				0x04
#define STATE_DFU_DOWNLOAD_IDLE				0x05
#define STATE_DFU_MANIFEST_SYNC				0x06
#define STATE_DFU_MANIFEST					0x07
#define STATE_DFU_MANIFEST_WAIT_RESET		0x08
#define STATE_DFU_UPLOAD_IDLE				0x09
#define STATE_DFU_ERROR						0x0A

#define STATE_DFU_UPLOAD_SYNC				0x91
#define STATE_DFU_UPLOAD_BUSY				0x92*/

	   if(STDFU_Dnload(&m_phDevice, m_pBuffer, 0x20, 2) == STDFU_NOERROR)
	   {
		   STDFU_Getstatus(&m_phDevice, &DFUStatus);
		   /*while(DFUStatus.bState != STATE_DFU_DOWNLOAD_IDLE)
		   {
				//STDFU_Clrstatus(&m_phDevice);
				STDFU_Getstatus(&m_phDevice, &DFUStatus);
		   }*/

		   return 0;
	   }
	   return 0;
   }
   return 0;
}

void COptionBytesDialog_L1::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	

	BYTE RDP = 0xAA;
	BYTE User = 0x00;
	BYTE WRP0 = 0x00;
	BYTE WRP1 = 0x00;
	BYTE WRP2 = 0x00;
	BYTE WRP3 = 0x00;
	BYTE WRP4 = 0x00;
	BYTE WRP5 = 0x00;
	BYTE WRP6 = 0x00;
	BYTE WRP7 = 0x00;
	BYTE WRP8 = 0x00;
	BYTE WRP9 = 0x00;
	BYTE WRP10 = 0x00;
	BYTE WRP11 = 0x00;



    GetOptions(&User, &RDP, &WRP0, &WRP1, &WRP2, &WRP3, &WRP4, &WRP5, &WRP6, &WRP7, &WRP8, &WRP9, &WRP10, &WRP11 );

	UpdateData(TRUE);

	m_User_Value.Format("%02X",User);
	m_RDP_Value.Format("%02X",RDP);
	m_WRP0_Value.Format("%04X",(WRP0+(WRP1<<8)));
	m_WRP2_Value.Format("%04X",(WRP2+(WRP3<<8)));
	m_WRP4_Value.Format("%04X",(WRP4+(WRP5<<8)));
	m_WRP6_Value.Format("%04X",(WRP6+(WRP7<<8)));
	m_WRP8_Value.Format("%04X",(WRP8+(WRP9<<8)));
	m_WRP10_Value.Format("%04X",(WRP10+(WRP11<<8)));

 

	if(RDP == 0xAA) 
	{   
		m_ReadOutProtectionEnabledValue = TRUE;
	    m_ReadOutProtectionEnabledValue2 = FALSE;
		m_ReadOutProtectionEnabledValue3 = FALSE;
	}
	else 
	if (RDP == 0xCC) 
	{
	    m_ReadOutProtectionEnabledValue = FALSE;
	    m_ReadOutProtectionEnabledValue2 = FALSE;
		m_ReadOutProtectionEnabledValue3 = TRUE;
	}
	else
	{
		m_ReadOutProtectionEnabledValue = FALSE;
	    m_ReadOutProtectionEnabledValue2 = TRUE;
		m_ReadOutProtectionEnabledValue3 = FALSE;
	}

    m_BF2_Value		   = (User & 0x80) >> 7;  
    m_nRST_STDBY_Value = (User & 0x40) >> 6;
	m_nRST_STOP_Value  = (User & 0x20) >> 5;
	m_WDG_SW_Value     = (User & 0x10) >> 4;
	m_BOR_LEV3_Value   = (User & 0x08) >> 3; 
	m_BOR_LEV2_Value   = (User & 0x04) >> 2; 
	m_BOR_LEV1_Value   = (User & 0x02) >> 1; 
	m_BOR_LEV0_Value   = (User & 0x01) >> 0; 
	


	UpdateData(FALSE);
	// TODO: Add your message handler code here
	
}

void COptionBytesDialog_L1::OnReadOutProtectionEnabledCheck()  // No Protection
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE RDP = 0x00;

	if(m_ReadOutProtectionEnabledValue)  
	{ 
		RDP = 0xAA;
		m_ReadOutProtectionEnabledValue = TRUE;
		m_ReadOutProtectionEnabledValue2 = FALSE;
        m_ReadOutProtectionEnabledValue3 = FALSE;
	
	}
	else  	 

	{ 
		RDP = 0xFF;
		m_ReadOutProtectionEnabledValue = FALSE;
		m_ReadOutProtectionEnabledValue2= TRUE;
		m_ReadOutProtectionEnabledValue3 = FALSE;
	
	}
		
	m_RDP_Value.Format("%02x", RDP);

	UpdateData(FALSE);
}

void COptionBytesDialog_L1::OnReadOutProtectionEnabledCheck2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE RDP = 0x00;

	if(m_ReadOutProtectionEnabledValue2)  
	{ 
		RDP = 0xFF;
		m_ReadOutProtectionEnabledValue = FALSE;
        m_ReadOutProtectionEnabledValue3 = FALSE;
		m_ReadOutProtectionEnabledValue2 = TRUE;
	
	}
	else  

	{ 
		RDP = 0xAA;
		m_ReadOutProtectionEnabledValue = TRUE;
        m_ReadOutProtectionEnabledValue2 = FALSE;
        m_ReadOutProtectionEnabledValue3 = FALSE;
	}

	m_RDP_Value.Format("%02x", RDP);

	UpdateData(FALSE);
}


void COptionBytesDialog_L1::OnReadOutProtectionEnabledCheck3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE RDP = 0xCC;

	if(m_ReadOutProtectionEnabledValue3)  
	{ 
		RDP = 0xCC;
		m_ReadOutProtectionEnabledValue2 = FALSE;
        m_ReadOutProtectionEnabledValue = FALSE;
	
	}
	else  

	{ 
		RDP = 0xAA;
        m_ReadOutProtectionEnabledValue = TRUE;
		m_ReadOutProtectionEnabledValue2 = FALSE;
        m_ReadOutProtectionEnabledValue3 = FALSE;
	
	}


	m_RDP_Value.Format("%02x", RDP);

	UpdateData(FALSE);
}


void COptionBytesDialog_L1::OnChangeUserEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
}

void COptionBytesDialog_L1::OnWdgSw() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE USER = _tcstoul(m_User_Value, 0, 16) ;

	if(m_WDG_SW_Value)  USER = USER | 0x10;
	else USER = USER & (~0x10);

	m_User_Value.Format("%02x", USER);

	UpdateData(FALSE);
}

void COptionBytesDialog_L1::OnBF2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE USER = _tcstoul(m_User_Value, 0, 16) ;

	if(m_BF2_Value)  USER = USER | 0x80;
	else USER = USER & (~0x80);

	m_User_Value.Format("%02x", USER);

	UpdateData(FALSE);
}


void COptionBytesDialog_L1::OnNrstStopCheck2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE USER = _tcstoul(m_User_Value, 0, 16) ;

	if(m_nRST_STOP_Value)  USER = USER | 0x60;
	else USER = USER & (~0x60);

	m_User_Value.Format("%02x", USER);

	UpdateData(FALSE);
}

void COptionBytesDialog_L1::OnNrstStdbyCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	BYTE USER = _tcstoul(m_User_Value, 0, 16) ;
    
	if(m_nRST_STDBY_Value)  USER = USER | 0x40;
	else USER = USER & (~0x40);

	m_User_Value.Format("%02x", USER);

	UpdateData(FALSE);
}


void COptionBytesDialog_L1::OnBor0Check() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE USER = _tcstoul(m_User_Value, 0, 16) ;

	if(m_BOR_LEV0_Value)  USER = USER | 0x01;
	else USER = USER & (~0x01);

	m_User_Value.Format("%02x", USER);

	UpdateData(FALSE);
}

void COptionBytesDialog_L1::OnBor1Check() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE USER = _tcstoul(m_User_Value, 0, 16) ;

	if(m_BOR_LEV1_Value)  USER = USER | 0x02;
	else USER = USER & (~0x02);

	m_User_Value.Format("%02x", USER);

	UpdateData(FALSE);
}

void COptionBytesDialog_L1::OnBor2Check() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE USER = _tcstoul(m_User_Value, 0, 16) ;

	if(m_BOR_LEV2_Value)  USER = USER | 0x04;
	else USER = USER & (~0x04);

	m_User_Value.Format("%02x", USER);

	UpdateData(FALSE);
}

void COptionBytesDialog_L1::OnBor3Check() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
	BYTE USER = _tcstoul(m_User_Value, 0, 16) ;

	if(m_BOR_LEV3_Value)  USER = USER | 0x08;
	else USER = USER & (~0x08);

	m_User_Value.Format("%02x", USER);

	UpdateData(FALSE);
}
void COptionBytesDialog_L1::OnApply() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	BYTE User  = _tcstoul(m_User_Value, 0, 16) ;
	BYTE RDP   = _tcstoul(m_RDP_Value, 0, 16) ;
	SHORT WRP01  = _tcstoul(m_WRP0_Value, 0, 16) ;
	BYTE WRP0 = WRP01;
	BYTE WRP1= WRP01>>8;
	SHORT WRP23  = _tcstoul(m_WRP2_Value, 0, 16) ;
	BYTE WRP2 = WRP23;
	BYTE WRP3= WRP23>>8;
	SHORT WRP45  = _tcstoul(m_WRP4_Value, 0, 16) ;
	BYTE WRP4 = WRP45;
	BYTE WRP5= WRP45>>8;
	SHORT WRP67  = _tcstoul(m_WRP6_Value, 0, 16) ;
	BYTE WRP6 = WRP67;
	BYTE WRP7= WRP67>>8;
	SHORT WRP89  = _tcstoul(m_WRP8_Value, 0, 16) ;
	BYTE WRP8 = WRP89;
	BYTE WRP9= WRP89>>8;
	SHORT WRP1011  = _tcstoul(m_WRP10_Value, 0, 16) ;
	BYTE WRP10 = WRP1011;
	BYTE WRP11= WRP1011>>8;



	UpdateData(FALSE);

	SetOptions(User, RDP, WRP0, WRP1 ,WRP2, WRP3 , WRP4, WRP5 , WRP6, WRP7 ,WRP8, WRP9 ,WRP10, WRP11 );

	STDFU_Close(&m_phDevice);
	
	CDialog::OnOK();
}

void COptionBytesDialog_L1::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
