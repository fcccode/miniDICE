/******************** (C) COPYRIGHT 2015 STMicroelectronics ********************
* Company            : STMicroelectronics
* Author             : MCD Application Team
* Description        : STMicroelectronics Device Firmware Upgrade Extension Demo
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

#ifndef _ENUMERATION_H_
#define _ENUMERATION_H_

class CEnumerator : public CObject
{
// Construction
public:
	bool FindHidDevice (
		OUT PHID_DEVICE*,
		OUT PULONG);

	void CloseHidDevice (
    IN PHID_DEVICE HidDevice);

// Attributes
public:

// Operations
public:

// Implementation
public:

	// Generated message map functions
protected:
	
private:
	BOOLEAN OpenHidDevice (
		IN       HDEVINFO,
		IN       PSP_INTERFACE_DEVICE_DATA,
		IN OUT   PHID_DEVICE
    );	
};

#endif