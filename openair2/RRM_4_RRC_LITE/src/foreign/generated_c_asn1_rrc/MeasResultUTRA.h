/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "./ASN1_files/EUTRA-RRC-Definitions.asn"
 * 	`asn1c -gen-PER -fcompound-names -fnative-types`
 */

#ifndef	_MeasResultUTRA_H_
#define	_MeasResultUTRA_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PhysCellIdUTRA-FDD.h"
#include "PhysCellIdUTRA-TDD.h"
#include <constr_CHOICE.h>
#include "CellGlobalIdUTRA.h"
#include <BIT_STRING.h>
#include <constr_SEQUENCE.h>
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MeasResultUTRA__physCellId_PR {
	MeasResultUTRA__physCellId_PR_NOTHING,	/* No components present */
	MeasResultUTRA__physCellId_PR_fdd,
	MeasResultUTRA__physCellId_PR_tdd
} MeasResultUTRA__physCellId_PR;

/* Forward declarations */
struct PLMN_IdentityList2;

/* MeasResultUTRA */
typedef struct MeasResultUTRA {
	struct MeasResultUTRA__physCellId {
		MeasResultUTRA__physCellId_PR present;
		union MeasResultUTRA__physCellId_u {
			PhysCellIdUTRA_FDD_t	 fdd;
			PhysCellIdUTRA_TDD_t	 tdd;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} physCellId;
	struct MeasResultUTRA__cgi_Info {
		CellGlobalIdUTRA_t	 cellGlobalId;
		BIT_STRING_t	*locationAreaCode	/* OPTIONAL */;
		BIT_STRING_t	*routingAreaCode	/* OPTIONAL */;
		struct PLMN_IdentityList2	*plmn_IdentityList	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *cgi_Info;
	struct MeasResultUTRA__measResult {
		long	*utra_RSCP	/* OPTIONAL */;
		long	*utra_EcN0	/* OPTIONAL */;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} measResult;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MeasResultUTRA_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasResultUTRA;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PLMN-IdentityList2.h"

#endif	/* _MeasResultUTRA_H_ */
#include <asn_internal.h>
