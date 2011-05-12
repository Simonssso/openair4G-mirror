/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "./ASN1_files/EUTRA-RRC-Definitions.asn"
 * 	`asn1c -gen-PER -fcompound-names -fnative-types`
 */

#include "RadioResourceConfigCommonSIB.h"

static asn_TYPE_member_t asn_MBR_RadioResourceConfigCommonSIB_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, rach_ConfigCommon),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RACH_ConfigCommon,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rach-ConfigCommon"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, bcch_Config),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BCCH_Config,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"bcch-Config"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, pcch_Config),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PCCH_Config,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pcch-Config"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, prach_Config),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PRACH_ConfigSIB,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"prach-Config"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, pdsch_ConfigCommon),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PDSCH_ConfigCommon,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pdsch-ConfigCommon"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, pusch_ConfigCommon),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PUSCH_ConfigCommon,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pusch-ConfigCommon"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, pucch_ConfigCommon),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PUCCH_ConfigCommon,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"pucch-ConfigCommon"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, soundingRS_UL_ConfigCommon),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_SoundingRS_UL_ConfigCommon,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"soundingRS-UL-ConfigCommon"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, uplinkPowerControlCommon),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UplinkPowerControlCommon,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"uplinkPowerControlCommon"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RadioResourceConfigCommonSIB, ul_CyclicPrefixLength),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UL_CyclicPrefixLength,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ul-CyclicPrefixLength"
		},
};
static ber_tlv_tag_t asn_DEF_RadioResourceConfigCommonSIB_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_RadioResourceConfigCommonSIB_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* rach-ConfigCommon at 1414 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* bcch-Config at 1415 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* pcch-Config at 1416 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* prach-Config at 1417 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* pdsch-ConfigCommon at 1418 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* pusch-ConfigCommon at 1419 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* pucch-ConfigCommon at 1420 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* soundingRS-UL-ConfigCommon at 1421 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* uplinkPowerControlCommon at 1422 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 } /* ul-CyclicPrefixLength at 1423 */
};
static asn_SEQUENCE_specifics_t asn_SPC_RadioResourceConfigCommonSIB_specs_1 = {
	sizeof(struct RadioResourceConfigCommonSIB),
	offsetof(struct RadioResourceConfigCommonSIB, _asn_ctx),
	asn_MAP_RadioResourceConfigCommonSIB_tag2el_1,
	10,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	9,	/* Start extensions */
	11	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RadioResourceConfigCommonSIB = {
	"RadioResourceConfigCommonSIB",
	"RadioResourceConfigCommonSIB",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_RadioResourceConfigCommonSIB_tags_1,
	sizeof(asn_DEF_RadioResourceConfigCommonSIB_tags_1)
		/sizeof(asn_DEF_RadioResourceConfigCommonSIB_tags_1[0]), /* 1 */
	asn_DEF_RadioResourceConfigCommonSIB_tags_1,	/* Same as above */
	sizeof(asn_DEF_RadioResourceConfigCommonSIB_tags_1)
		/sizeof(asn_DEF_RadioResourceConfigCommonSIB_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RadioResourceConfigCommonSIB_1,
	10,	/* Elements count */
	&asn_SPC_RadioResourceConfigCommonSIB_specs_1	/* Additional specs */
};

