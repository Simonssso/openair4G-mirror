/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "./ASN1_files/EUTRA-RRC-Definitions.asn"
 * 	`asn1c -gen-PER -fcompound-names -fnative-types`
 */

#ifndef	_SystemInformationBlockType8_H_
#define	_SystemInformationBlockType8_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "PreRegistrationInfoHRPD.h"
#include <constr_SEQUENCE.h>
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SystemTimeInfoCDMA2000;
struct CellReselectionParametersCDMA2000;
struct CSFB_RegistrationParam1XRTT;

/* SystemInformationBlockType8 */
typedef struct SystemInformationBlockType8 {
	struct SystemTimeInfoCDMA2000	*systemTimeInfo	/* OPTIONAL */;
	long	*searchWindowSize	/* OPTIONAL */;
	struct SystemInformationBlockType8__parametersHRPD {
		PreRegistrationInfoHRPD_t	 preRegistrationInfoHRPD;
		struct CellReselectionParametersCDMA2000	*cellReselectionParametersHRPD	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *parametersHRPD;
	struct SystemInformationBlockType8__parameters1XRTT {
		struct CSFB_RegistrationParam1XRTT	*csfb_RegistrationParam1XRTT	/* OPTIONAL */;
		BIT_STRING_t	*longCodeState1XRTT	/* OPTIONAL */;
		struct CellReselectionParametersCDMA2000	*cellReselectionParameters1XRTT	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *parameters1XRTT;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SystemInformationBlockType8_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SystemInformationBlockType8;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SystemTimeInfoCDMA2000.h"
#include "CellReselectionParametersCDMA2000.h"
#include "CSFB-RegistrationParam1XRTT.h"

#endif	/* _SystemInformationBlockType8_H_ */
#include <asn_internal.h>
