/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "./ASN1_files/EUTRA-RRC-Definitions.asn"
 * 	`asn1c -gen-PER -fcompound-names -fnative-types`
 */

#ifndef	_AllowedMeasBandwidth_H_
#define	_AllowedMeasBandwidth_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum AllowedMeasBandwidth {
	AllowedMeasBandwidth_mbw6	= 0,
	AllowedMeasBandwidth_mbw15	= 1,
	AllowedMeasBandwidth_mbw25	= 2,
	AllowedMeasBandwidth_mbw50	= 3,
	AllowedMeasBandwidth_mbw75	= 4,
	AllowedMeasBandwidth_mbw100	= 5
} e_AllowedMeasBandwidth;

/* AllowedMeasBandwidth */
typedef long	 AllowedMeasBandwidth_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AllowedMeasBandwidth;
asn_struct_free_f AllowedMeasBandwidth_free;
asn_struct_print_f AllowedMeasBandwidth_print;
asn_constr_check_f AllowedMeasBandwidth_constraint;
ber_type_decoder_f AllowedMeasBandwidth_decode_ber;
der_type_encoder_f AllowedMeasBandwidth_encode_der;
xer_type_decoder_f AllowedMeasBandwidth_decode_xer;
xer_type_encoder_f AllowedMeasBandwidth_encode_xer;
per_type_decoder_f AllowedMeasBandwidth_decode_uper;
per_type_encoder_f AllowedMeasBandwidth_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _AllowedMeasBandwidth_H_ */
#include <asn_internal.h>
