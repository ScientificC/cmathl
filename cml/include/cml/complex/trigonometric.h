#ifndef CML_COMPLEX_TRIG_FUNC_H
#define CML_COMPLEX_TRIG_FUNC_H

__CML_BEGIN_DECLS

cml_complex_t cml_complex_cos(cml_complex_t z);
cml_complex_t cml_complex_cot(cml_complex_t z);
cml_complex_t cml_complex_csc(cml_complex_t z);
cml_complex_t cml_complex_sec(cml_complex_t z);
cml_complex_t cml_complex_sin(cml_complex_t z);
cml_complex_t cml_complex_tan(cml_complex_t a);

cml_complex_t cml_complex_asin(cml_complex_t a);
cml_complex_t cml_complex_asin_real(double a);
cml_complex_t cml_complex_acos(cml_complex_t a);
cml_complex_t cml_complex_acos_real(double a);
cml_complex_t cml_complex_atan(cml_complex_t a);
cml_complex_t cml_complex_asec(cml_complex_t a);
cml_complex_t cml_complex_asec_real(double a);
cml_complex_t cml_complex_acsc(cml_complex_t a);
cml_complex_t cml_complex_acsc_real(double a);
cml_complex_t cml_complex_acot(cml_complex_t z);

__CML_END_DECLS

#endif
